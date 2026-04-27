////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRenderDevice.h"

// Core includes
#include "Algo/AllOf.h"
#include "CoreGlobals.h"
#include "Misc/ConfigCacheIni.h"

// Engine includes
#include "EngineModule.h"
#include "LocalVertexFactory.h"
#include "Engine/RendererSettings.h"
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Rendering/Texture2DResource.h"
#include "Materials/Material.h"
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "MaterialShared.h"
#else
#include "Materials/MaterialRenderProxy.h"
#endif
#include "SceneView.h"
#if UE_VERSION_OLDER_THAN(5, 6, 0)
#else
#include "PSOPrecache.h"
#include "PSOPrecacheValidation.h"
#endif

// RHI includes
#include "RHI.h"
#include "RHICommandList.h"
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "RHIDefinitions.h"
#else
#include "DataDrivenShaderPlatformInfo.h"
#endif

// MediaAsset includes
#include "MediaTexture.h"

// RenderCore includes
#include "ClearQuad.h"

// Renderer includes
#include "SystemTextures.h"
#include "SceneRendering.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "Render/NoesisShaders.h"
#include "NoesisSettings.h"

class FNoesisTexture : public Noesis::Texture
{
public:
	FNoesisTexture() = delete;
	FNoesisTexture(const FNoesisTexture&) = delete;
	FNoesisTexture(FNoesisTexture&& Other)
		: ShaderResourceTexture(Other.ShaderResourceTexture), Width(Other.Width), Height(Other.Height), NumMipMaps(Other.NumMipMaps), Alpha(Other.Alpha)
	{
	}

	FNoesisTexture(UTexture2D* Texture2D)
	{
		Width = (uint32)Texture2D->GetSizeX();
		Height = (uint32)Texture2D->GetSizeY();
		NumMipMaps = (uint32)Texture2D->GetNumMips();
		Alpha = Texture2D->HasAlphaChannel();

		InitShaderResourceTexture(Texture2D);
	}

	FNoesisTexture(UTextureRenderTarget2D* TextureRenderTarget2D)
	{
		Width = (uint32)TextureRenderTarget2D->SizeX;
		Height = (uint32)TextureRenderTarget2D->SizeY;
		NumMipMaps = (uint32)TextureRenderTarget2D->GetNumMips();
		Alpha = true; // Guess

		InitShaderResourceTexture(TextureRenderTarget2D);
	}

	FNoesisTexture(UMediaTexture* MediaTexture)
	{
		Width = (uint32)MediaTexture->GetWidth();
		Height = (uint32)MediaTexture->GetHeight();
#if UE_VERSION_OLDER_THAN(5, 6, 0)
		NumMipMaps = (uint32)MediaTexture->NumMips;
#else
		NumMipMaps = MediaTexture->EnableGenMips ? FMath::FloorLog2(FMath::Max(Width, Height)) + 1 : 1;
#endif
		Alpha = false; // Guess

		InitShaderResourceTexture(MediaTexture);
	}

	FNoesisTexture(FRHITexture* RHITexture, bool InIgnoreAlpha = false)
	{
		auto TextureRefSize = RHITexture->GetSizeXYZ();
		ShaderResourceTexture = RHITexture;
		Width = (uint32)TextureRefSize.X;
		Height = (uint32)TextureRefSize.Y;
		NumMipMaps = RHITexture->GetNumMips();
		Alpha = EnumHasAnyFlags(GetPixelFormatValidChannels(RHITexture->GetFormat()), EPixelFormatChannelFlags::A);
		IgnoreAlpha = InIgnoreAlpha;
	}

	void SetRHITexture(FRHITexture* Texture)
	{
		ShaderResourceTexture = Texture;
	}

	FRHITexture* GetTexture2D()
	{
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		if (ShaderResourceTexture != nullptr)
		{
			auto TextureReference = ShaderResourceTexture->GetTextureReference();
			if (TextureReference != nullptr)
			{
				auto ReferencedTexture = TextureReference->GetReferencedTexture();
				if (ReferencedTexture != nullptr)
				{
					return ReferencedTexture->GetTexture2D();
				}
			}
			return ShaderResourceTexture->GetTexture2D();
		}
		return nullptr;
#else
		return ShaderResourceTexture;
#endif
	}

	// Texture interface
	virtual uint32 GetWidth() const override
	{
		return Width;
	}

	virtual uint32 GetHeight() const override
	{
		return Height;
	}

	virtual bool HasMipMaps() const override
	{
		return NumMipMaps > 1;
	}

	virtual bool IsInverted() const override
	{
		return (bool)false;
	}
	
	virtual bool HasAlpha() const override
	{
		return Alpha;
	}
	// End of Texture interface

	// Different than HasAlpha. Means we should ignore the sampled value and use 1.
	bool MustIgnoreAlpha() const
	{
		return IgnoreAlpha;
	}

private:

	void InitShaderResourceTexture(UTexture* Texture)
	{
		auto& TextureReference = Texture->TextureReference;
		ENQUEUE_RENDER_COMMAND(FNoesisTexture_InitShaderResourceTexture)
		(
			[TexturePtr = Noesis::Ptr<FNoesisTexture>(this), &TextureReference](FRHICommandListImmediate&)
			{
				auto& TextureRef = TextureReference.TextureReferenceRHI;
				if (TextureRef != nullptr && TextureRef->IsValid())
				{
					TexturePtr->ShaderResourceTexture = TextureRef;
				}
			}
		);
	}

	FTextureRHIRef ShaderResourceTexture;
	uint32 Width;
	uint32 Height;
	uint32 NumMipMaps;
	bool Alpha;
	bool IgnoreAlpha = false;
};

#if UE_VERSION_OLDER_THAN(5, 0, 0)
typedef FTicker FTSTicker;
#endif
class FNoesisMaterial
{
public:
	FNoesisMaterial(UMaterialInterface* InMaterial)
		: MaterialPtr(InMaterial)
	{
#if !UE_VERSION_OLDER_THAN(5, 6, 0) && UE_WITH_PSO_PRECACHING
		if (GetPSOPrecacheProxyCreationStrategy() == EPSOPrecacheProxyCreationStrategy::DelayUntilPSOPrecached)
		{
			FPSOPrecacheParams DefaultParams;
			FPSOPrecacheVertexFactoryDataList VertexFactoryDataList;
			VertexFactoryDataList.Emplace(&FLocalVertexFactory::StaticType);

			//Set high priority to precache Noesis materials as soon as possible, typically UI materials are needed right away and compile quickly.
			//UMaterial::PostLoad does this depending on platform, but we need the MaterialPSOPrecacheRequestIDs to know if it's done
			//We purposely don't release MaterialPSOPrecacheRequestIDs since they aren't valid after a call ClearMaterialPSORequests() and actually releasing them doesn't really do anything
			GraphEvents = InMaterial->PrecachePSOs(VertexFactoryDataList, DefaultParams, EPSOPrecachePriority::High, MaterialPSOPrecacheRequestIDs);
		}
#endif
	}

	FMaterialRenderProxy* GetRenderProxy() const
	{
		if (auto Material = MaterialPtr.Get(); IsValid(Material))
		{
			return Material->GetRenderProxy();
		}

		return nullptr;
	}

#if !UE_VERSION_OLDER_THAN(5, 6, 0) && UE_WITH_PSO_PRECACHING
	bool IsPrecachePendingAndBoost()
	{
		if (!MaterialPtr.IsValid() || Algo::AllOf(GraphEvents, [](const FGraphEventRef& Event) { return Event->IsComplete(); }))
		{
			MaterialPSOPrecacheRequestIDs.Empty();
			GraphEvents.Empty();
		}

		if (!GraphEvents.IsEmpty())
		{
			if (!MaterialPSOPrecacheRequestIDs.IsEmpty())
			{
				BoostPSOPriority(EPSOPrecachePriority::Highest, MaterialPSOPrecacheRequestIDs);
				MaterialPSOPrecacheRequestIDs.Empty();
			}
			return true;
		}

		return false;
	}
#endif

private:
	TWeakObjectPtr<UMaterialInterface> MaterialPtr;
#if !UE_VERSION_OLDER_THAN(5, 6, 0) && UE_WITH_PSO_PRECACHING
	TArray<FMaterialPSOPrecacheRequestID> MaterialPSOPrecacheRequestIDs;
	FGraphEventArray GraphEvents;
#endif
};

class FNoesisRenderTarget : public Noesis::RenderTarget
{
public:

	FNoesisRenderTarget(FRHITexture* InShaderResourceTexture, FRHITexture* InColorTarget, FRHITexture* InDepthStencilTarget)
		: Texture(Noesis::MakePtr<FNoesisTexture>(InShaderResourceTexture)), ColorTarget(InColorTarget), DepthStencilTarget(InDepthStencilTarget)
	{
	}

	FRHITexture* GetShaderResourceTexture()
	{
		return Texture->GetTexture2D();
	}

	FRHITexture* GetColorTarget()
	{
		return ColorTarget;
	}

	FRHITexture* GetDepthStencilTarget()
	{
		return DepthStencilTarget;
	}

	void SetRenderTarget(FRHICommandList* RHICmdList)
	{
		FRHITexture* ShaderResourceTexture = Texture->GetTexture2D();
		bool NeedsResolve = (ColorTarget != ShaderResourceTexture) && ColorTarget->IsMultisampled();
		if (ColorTarget == ShaderResourceTexture)
		{
			RHICmdList->Transition(FRHITransitionInfo(ColorTarget, ERHIAccess::SRVGraphics, ERHIAccess::RTV));
		}
		else if (NeedsResolve)
		{
			RHICmdList->Transition(FRHITransitionInfo(ShaderResourceTexture, ERHIAccess::SRVGraphics, ERHIAccess::RTV | ERHIAccess::ResolveDst));
		}

		constexpr uint8 DontLoad_Resolve = (((uint8)ERenderTargetLoadAction::ENoAction << (uint8)ERenderTargetActions::LoadOpMask) | (uint8)ERenderTargetStoreAction::EMultisampleResolve);
		ERenderTargetActions ColorTargetActions = NeedsResolve ? (ERenderTargetActions)DontLoad_Resolve : ERenderTargetActions::DontLoad_Store;

		if (DepthStencilTarget != nullptr)
		{
			bool HasStencil = DepthStencilTarget != nullptr;
			EDepthStencilTargetActions DepthStencilTargetActions =
				MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, HasStencil ? ERenderTargetActions::DontLoad_DontStore : ERenderTargetActions::DontLoad_DontStore);

			FRHIRenderPassInfo RPInfo(ColorTarget, ColorTargetActions, nullptr,
				DepthStencilTarget, DepthStencilTargetActions, nullptr, FExclusiveDepthStencil::DepthNop_StencilWrite);

			// There's a bug in FRHIRenderPassInfo constructors. Can't pass it there.
			// check(!ResolveColorRT || ResolveColorRT->IsMultisampled()) should be
			// check(!ResolveColorRT || !ResolveColorRT->IsMultisampled());
			RPInfo.ColorRenderTargets[0].ResolveTarget = NeedsResolve ? ShaderResourceTexture : nullptr;
			RHICmdList->BeginRenderPass(RPInfo, TEXT("NoesisOffScreen"));
		}
		else
		{
			FRHIRenderPassInfo RPInfo(ColorTarget, ColorTargetActions, nullptr);

			// There's a bug in FRHIRenderPassInfo constructors. Can't pass it there.
			// check(!ResolveColorRT || ResolveColorRT->IsMultisampled()) should be
			// check(!ResolveColorRT || !ResolveColorRT->IsMultisampled());
			RPInfo.ColorRenderTargets[0].ResolveTarget = NeedsResolve ? ShaderResourceTexture : nullptr;
			RHICmdList->BeginRenderPass(RPInfo, TEXT("NoesisOffScreen"));
		}
		RHICmdList->SetViewport(0, 0, 0.0f, ColorTarget->GetSizeX(), ColorTarget->GetSizeY(), 1.0f);
	}

	void BeginTile(FRHICommandList* RHICmdList, const Noesis::Tile& Tile)
	{
		auto RenderTargetHeight = ColorTarget->GetSizeY();
		RHICmdList->SetScissorRect(true, Tile.x, (int32)((uint32)RenderTargetHeight - (Tile.y + Tile.height)), Tile.x + Tile.width, (int32)((uint32)RenderTargetHeight - Tile.y));
	}

	void EndTile(FRHICommandList* RHICmdList)
	{
		RHICmdList->SetScissorRect(false, 0, 0, 0, 0);
	}

	void ResolveRenderTarget(FRHICommandList* RHICmdList, const Noesis::Tile* Tiles, uint32 NumTiles)
	{
		RHICmdList->EndRenderPass();
		FRHITexture* ShaderResourceTexture = Texture->GetTexture2D();
		if (ColorTarget != ShaderResourceTexture)
		{
			if (!ColorTarget->IsMultisampled())
			{
				RHICmdList->Transition(FRHITransitionInfo(ColorTarget, ERHIAccess::RTV, ERHIAccess::CopySrc));
				RHICmdList->Transition(FRHITransitionInfo(ShaderResourceTexture, ERHIAccess::SRVGraphics, ERHIAccess::CopyDest));

				for (uint32 TileIndex = 0; TileIndex != (uint32)NumTiles; ++TileIndex)
				{
					const Noesis::Tile& Tile = Tiles[TileIndex];

					FRHICopyTextureInfo CopyTextureInfo;
					CopyTextureInfo.Size = FIntVector(Tile.width, Tile.height, 1);
					auto RenderTargetHeight = ShaderResourceTexture->GetSizeY();
					CopyTextureInfo.SourcePosition = FIntVector((int32)Tile.x, (int32)((uint32)RenderTargetHeight - (Tile.y + Tile.height)), 0);
					CopyTextureInfo.DestPosition = CopyTextureInfo.SourcePosition;
					RHICmdList->CopyTexture(ColorTarget, ShaderResourceTexture, CopyTextureInfo);
				}

				RHICmdList->Transition(FRHITransitionInfo(ColorTarget, ERHIAccess::CopySrc, ERHIAccess::RTV));
				RHICmdList->Transition(FRHITransitionInfo(ShaderResourceTexture, ERHIAccess::CopyDest, ERHIAccess::SRVGraphics));
			}
			else
			{
				RHICmdList->Transition(FRHITransitionInfo(ShaderResourceTexture, ERHIAccess::RTV | ERHIAccess::ResolveDst, ERHIAccess::SRVGraphics));
			}
		}
		else
		{
			RHICmdList->Transition(FRHITransitionInfo(ColorTarget, ERHIAccess::RTV, ERHIAccess::SRVGraphics));
		}
	}

	// RenderTarget interface
	virtual Noesis::Texture* GetTexture() override
	{
		return Texture;
	}
	// End of RenderTarget interface

private:

	Noesis::Ptr<FNoesisTexture> Texture;
	FTextureRHIRef ColorTarget;
	FTextureRHIRef DepthStencilTarget;
};

static const TCHAR* NoesisGlobalPSOCollectorName = TEXT("NoesisGlobalPSOCollector");
static const TCHAR* NoesisMaterialPSOCollectorName = TEXT("NoesisMaterialPSOCollector");

FRHIVertexDeclaration* GetVertexDelcaration(Noesis::Shader::Vertex::Format::Enum VertexShaderFormat)
{
	static FVertexDeclarationRHIRef VertexDeclarations[Noesis::Shader::Vertex::Format::Count] =
	{
		GNoesisPosVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosColorVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0RectVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0RectTileVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosColorCoverageVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0CoverageRectVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0CoverageRectTileVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0Tex1RectVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosColorTex0Tex1VertexDeclaration.VertexDeclarationRHI,
		GNoesisPosColorTex1RectVertexDeclaration.VertexDeclarationRHI,
		GNoesisPosColorTex0RectImagePosVertexDeclaration.VertexDeclarationRHI
	};

	return VertexDeclarations[VertexShaderFormat];
}

template <typename T>
static TShaderRef<T> GetMaterialPixelShader(const FMaterial& Material, const typename T::FPermutationDomain& Permutation)
{

#if UE_VERSION_OLDER_THAN(4, 27, 0)
	const FMaterialShaderMap* MaterialShaderMap = Material.GetRenderingThreadShaderMap();
	return MaterialShaderMap->GetShader<T>(Permutation);
#else
	FMaterialShaderTypes ShaderTypes;
	ShaderTypes.AddShaderType<T>(Permutation.ToDimensionValueId());
	FMaterialShaders Shaders;
	Material.TryGetShaders(ShaderTypes, nullptr, Shaders);

	TShaderRef<T> FoundShader;
	Shaders.TryGetPixelShader(FoundShader);
	return FoundShader;
#endif
}

template<ESamplerFilter Filter = SF_Point,
	ESamplerAddressMode AddressU = AM_Clamp,
	ESamplerAddressMode AddressV = AM_Clamp,
	int MaxMipLevel = 1>
class TNoesisStaticSamplerState : public TStaticStateRHI<TNoesisStaticSamplerState<Filter, AddressU, AddressV, MaxMipLevel>, FSamplerStateRHIRef, FRHISamplerState*>
{
public:
	static FSamplerStateRHIRef CreateRHI()
	{
		FSamplerStateInitializerRHI Initializer(Filter, AddressU, AddressV, AM_Clamp, -0.75f, 1, 0, MaxMipLevel == 0 ? 0.0f : FLT_MAX, 0, SCF_Never);
		return RHICreateSamplerState(Initializer);
	}
};

static FRHIDepthStencilState* GetDepthStencilState(uint8 State, bool AlphaMask)
{
	static FRHIDepthStencilState* DepthStencilStates[Noesis::StencilMode::Count] =
	{
		TStaticDepthStencilState<false, CF_Always>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep,      true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment, true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement, true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Always, SO_Keep, SO_Keep, SO_Zero,      true, CF_Always, SO_Keep, SO_Keep, SO_Zero>::GetRHI(),
		TStaticDepthStencilState<false>::GetRHI(),
		TStaticDepthStencilState<false, CF_DepthNearOrEqual, true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep,      true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep>::GetRHI()
	};

	static FRHIDepthStencilState* DepthStencilStatesAlphaMask[Noesis::StencilMode::Count] =
	{
		TStaticDepthStencilState<false, CF_Always>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep,      true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment, true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement, true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement>::GetRHI(),
		TStaticDepthStencilState<false, CF_Always,           true, CF_Always, SO_Keep, SO_Keep, SO_Zero,      true, CF_Always, SO_Keep, SO_Keep, SO_Zero>::GetRHI(),
		TStaticDepthStencilState<true>::GetRHI(),
		TStaticDepthStencilState<true,  CF_DepthNearOrEqual, true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep,      true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep>::GetRHI()
	};

	return AlphaMask ? DepthStencilStatesAlphaMask[State] : DepthStencilStates[State];
}

static FRHIBlendState* GetBlendState(uint8 State)
{
	static FRHIBlendState* BlendStates[Noesis::BlendMode::Count] =
	{
		TStaticBlendState<CW_RGBA>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceAlpha,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_DestColor, BF_InverseSourceAlpha,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceColor,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_One,                 BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSource1Color, BO_Add, BF_One, BF_InverseSource1Alpha>::GetRHI()
	};

	return BlendStates[State];
}

static FRHIBlendState* GetBlendStateWorldUI(uint8 State)
{
	static FRHIBlendState* BlendStatesWorldUI[Noesis::BlendMode::Count] =
	{
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_Zero,                BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceAlpha,  BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_DestColor, BF_InverseSourceAlpha,  BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceColor,  BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_One,                 BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI(),
		TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSource1Color, BO_Add, BF_Zero, BF_InverseSource1Alpha>::GetRHI()
	};

	return BlendStatesWorldUI[State];
}

static FRHISamplerState* GetSamplerState(uint8 State)
{
	//FRHISamplerState* SamplerStates[Noesis::WrapMode::Count * Noesis::MinMagFilter::Count * Noesis::MipFilter::Count];
	static FRHISamplerState* SamplerStates[48] =
	{
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Point,    AM_Clamp,  AM_Clamp,  0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Point,    AM_Border, AM_Border, 0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Point,    AM_Wrap,   AM_Wrap,   0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Point,    AM_Mirror, AM_Wrap,   0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Point,    AM_Wrap,   AM_Mirror, 0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Point,    AM_Mirror, AM_Mirror, 0>::GetRHI(),
		nullptr,
		nullptr,
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear, AM_Clamp,  AM_Clamp,  0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear, AM_Border, AM_Border, 0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear, AM_Wrap,   AM_Wrap,   0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Wrap,   0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear, AM_Wrap,   AM_Mirror, 0>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Mirror, 0>::GetRHI(),
		nullptr,
		nullptr,
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Point,     AM_Clamp,  AM_Clamp>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Point,     AM_Border, AM_Border>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Mirror>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Mirror>::GetRHI(),
		nullptr,
		nullptr,
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear,  AM_Clamp,  AM_Clamp>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear,  AM_Border, AM_Border>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear,  AM_Wrap,   AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear,  AM_Mirror, AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear,  AM_Wrap,   AM_Mirror>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] = */ TNoesisStaticSamplerState<SF_Bilinear,  AM_Mirror, AM_Mirror>::GetRHI(),
		nullptr,
		nullptr,
		// Can't do linear mip sampling and point UV sampling. We have to choose between SF_Point or SF_Trilinear.
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Point,      AM_Clamp,  AM_Clamp>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Point,      AM_Border, AM_Border>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Point,      AM_Wrap,   AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Point,      AM_Mirror, AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Point,      AM_Wrap,   AM_Mirror>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Point,      AM_Mirror, AM_Mirror>::GetRHI(),
		nullptr,
		nullptr,
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Trilinear,  AM_Clamp,  AM_Clamp>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Trilinear,  AM_Border, AM_Border>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Trilinear,  AM_Wrap,   AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Trilinear,  AM_Mirror, AM_Wrap>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Trilinear,  AM_Wrap,   AM_Mirror>::GetRHI(),
		/* SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] = */ TNoesisStaticSamplerState<SF_Trilinear,  AM_Mirror, AM_Mirror>::GetRHI(),
		nullptr,
		nullptr
	};

	return SamplerStates[State];
}

FNoesisRenderDevice::FNoesisRenderDevice(bool LinearColor)
	: IsLinearColor(LinearColor)
{
	auto VBName = TEXT("Noesis.VertexBuffer");
	auto IBName = TEXT("Noesis.IndexBuffer");
#if UE_VERSION_OLDER_THAN(5, 6, 0)
	FRHIResourceCreateInfo CreateInfo(VBName);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
	DynamicVertexBuffer = RHICreateVertexBuffer(DYNAMIC_VB_SIZE, BUF_Volatile, CreateInfo);
#else
	DynamicVertexBuffer = FRHICommandListExecutor::GetImmediateCommandList().CreateVertexBuffer(DYNAMIC_VB_SIZE, BUF_Volatile, CreateInfo);
#endif
	CreateInfo.DebugName = IBName;
#if UE_VERSION_OLDER_THAN(5, 3, 0)
	DynamicIndexBuffer = RHICreateIndexBuffer(sizeof(int16), DYNAMIC_IB_SIZE, BUF_Volatile, CreateInfo);
#else
	DynamicIndexBuffer = FRHICommandListExecutor::GetImmediateCommandList().CreateIndexBuffer(sizeof(int16), DYNAMIC_IB_SIZE, BUF_Volatile, CreateInfo);
#endif
#else
	EBufferUsageFlags VBUsage = EBufferUsageFlags::Volatile | EBufferUsageFlags::VertexBuffer;
	ERHIAccess VBState = RHIGetDefaultResourceState(VBUsage, false);
	FRHIBufferCreateDesc VBDesc = FRHIBufferCreateDesc::Create(VBName, DYNAMIC_VB_SIZE, 0, VBUsage).SetInitialState(VBState);
	DynamicVertexBuffer = FRHICommandListExecutor::GetImmediateCommandList().CreateBuffer(VBDesc);
	EBufferUsageFlags IBUsage = EBufferUsageFlags::Volatile | EBufferUsageFlags::IndexBuffer;
	ERHIAccess IBState = RHIGetDefaultResourceState(IBUsage, false);
	FRHIBufferCreateDesc IBDesc = FRHIBufferCreateDesc::Create(IBName, DYNAMIC_IB_SIZE, sizeof(int16), IBUsage).SetInitialState(IBState);
	DynamicIndexBuffer = FRHICommandListExecutor::GetImmediateCommandList().CreateBuffer(IBDesc);
#endif
	NOESIS_BIND_DEBUG_BUFFER_LABEL(FRHICommandListExecutor::GetImmediateCommandList(), DynamicVertexBuffer, VBName);
	NOESIS_BIND_DEBUG_BUFFER_LABEL(FRHICommandListExecutor::GetImmediateCommandList(), DynamicIndexBuffer, IBName);

	VSConstantBuffer = TUniformBufferRef<FNoesisVSConstants>::CreateUniformBufferImmediate(FNoesisVSConstants(), UniformBuffer_MultiFrame);
	VSConstantBufferStereo = TUniformBufferRef<FNoesisVSConstantsStereo>::CreateUniformBufferImmediate(FNoesisVSConstantsStereo(), UniformBuffer_MultiFrame);
	TextureSizeBuffer = TUniformBufferRef<FNoesisTextureSize>::CreateUniformBufferImmediate(FNoesisTextureSize(), UniformBuffer_MultiFrame);
	PSRgbaConstantBuffer = TUniformBufferRef<FNoesisPSRgbaConstants>::CreateUniformBufferImmediate(FNoesisPSRgbaConstants(), UniformBuffer_MultiFrame);
	PSOpacityConstantBuffer = TUniformBufferRef<FNoesisPSOpacityConstants>::CreateUniformBufferImmediate(FNoesisPSOpacityConstants(), UniformBuffer_MultiFrame);
	PSRadialGradConstantBuffer = TUniformBufferRef<FNoesisPSRadialGradConstants>::CreateUniformBufferImmediate(FNoesisPSRadialGradConstants(), UniformBuffer_MultiFrame);
	BlurConstantsBuffer = TUniformBufferRef<FNoesisBlurConstants>::CreateUniformBufferImmediate(FNoesisBlurConstants(), UniformBuffer_MultiFrame);
	ShadowConstantsBuffer = TUniformBufferRef<FNoesisShadowConstants>::CreateUniformBufferImmediate(FNoesisShadowConstants(), UniformBuffer_MultiFrame);

	const auto FeatureLevel = GMaxRHIFeatureLevel;

	PixelShaderConstantBuffer0[Noesis::Shader::RGBA] = &PSRgbaConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Shadow] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Blur] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Custom_Effect] = nullptr;

	PixelShaderConstantBuffer1[Noesis::Shader::RGBA] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Shadow] = &ShadowConstantsBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Blur] = &BlurConstantsBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Custom_Effect] = nullptr;

	PixelShaderConstantBuffer0Hash[Noesis::Shader::RGBA] = &PSRgbaConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Shadow] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Blur] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Custom_Effect] = nullptr;

	PixelShaderConstantBuffer1Hash[Noesis::Shader::RGBA] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Shadow] = &ShadowConstantsHash;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Blur] = &BlurConstantsHash;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Custom_Effect] = nullptr;
}

FNoesisRenderDevice::~FNoesisRenderDevice()
{
	DynamicVertexBuffer.SafeRelease();
	DynamicIndexBuffer.SafeRelease();
	VSConstantBuffer.SafeRelease();
	VSConstantBufferStereo.SafeRelease();
	TextureSizeBuffer.SafeRelease();
	PSRgbaConstantBuffer.SafeRelease();
	PSOpacityConstantBuffer.SafeRelease();
	PSRadialGradConstantBuffer.SafeRelease();
	BlurConstantsBuffer.SafeRelease();
	ShadowConstantsBuffer.SafeRelease();
}

uint32 GlyphCacheWidth[] = { 256, 512, 1024, 2048, 4096 };
uint32 GlyphCacheHeight[] = { 256, 512, 1024, 2048, 4096 };
static FNoesisRenderDevice* NoesisRenderDevice = nullptr;
static FNoesisRenderDevice* LinearNoesisRenderDevice = nullptr;

FNoesisRenderDevice* FNoesisRenderDevice::Get()
{
	if (!NoesisRenderDevice)
	{
		NoesisRenderDevice = new FNoesisRenderDevice(false);
		NoesisRenderDevice->SetOffscreenWidth((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureWidth));
		NoesisRenderDevice->SetOffscreenHeight((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureHeight));
		NoesisRenderDevice->SetOffscreenSampleCount((uint32)GetDefault<UNoesisSettings>()->OffscreenTextureSampleCount);
		NoesisRenderDevice->SetOffscreenDefaultNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenInitSurfaces));
		NoesisRenderDevice->SetOffscreenMaxNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenMaxSurfaces));
		NoesisRenderDevice->SetGlyphCacheWidth(GlyphCacheWidth[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
		NoesisRenderDevice->SetGlyphCacheHeight(GlyphCacheHeight[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
	}
	return NoesisRenderDevice;
}

FNoesisRenderDevice* FNoesisRenderDevice::GetLinear()
{
	if (!LinearNoesisRenderDevice)
	{
		LinearNoesisRenderDevice = new FNoesisRenderDevice(true);
		LinearNoesisRenderDevice->SetOffscreenWidth((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureWidth));
		LinearNoesisRenderDevice->SetOffscreenHeight((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureHeight));
		LinearNoesisRenderDevice->SetOffscreenSampleCount((uint32)GetDefault<UNoesisSettings>()->OffscreenTextureSampleCount);
		LinearNoesisRenderDevice->SetOffscreenDefaultNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenInitSurfaces));
		LinearNoesisRenderDevice->SetOffscreenMaxNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenMaxSurfaces));
		LinearNoesisRenderDevice->SetGlyphCacheWidth(GlyphCacheWidth[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
		LinearNoesisRenderDevice->SetGlyphCacheHeight(GlyphCacheHeight[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
	}
	return LinearNoesisRenderDevice;
}

void FNoesisRenderDevice::Destroy()
{
	delete NoesisRenderDevice;
	NoesisRenderDevice = nullptr;
	delete LinearNoesisRenderDevice;
	LinearNoesisRenderDevice = nullptr;
}

void FNoesisRenderDevice::SetRHICmdList(FRHICommandList* InRHICmdList)
{
	RHICmdList = InRHICmdList;
}

void FNoesisRenderDevice::SetWorldTime(FGameTime InWorldTime)
{
	WorldTime = InWorldTime;
}

void FNoesisRenderDevice::SetScene(FSceneInterface* InScene)
{
	Scene = InScene;
}

void FNoesisRenderDevice::CreateView(uint32 Left, uint32 Top, uint32 Right, uint32 Bottom, const FIntRect& ViewRect, const FMatrix& ViewProjectionMatrix)
{
	ViewLeft = Left;
	ViewTop = Top;
	ViewRight = Right;
	ViewBottom = Bottom;

	FSceneViewFamily::ConstructionValues ViewFamilyConstruction
	(
		nullptr,
		Scene,
		FEngineShowFlags(ESFIM_Game)
	);

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	ViewFamilyConstruction.SetWorldTimes(WorldTime.GetWorldTimeSeconds(), WorldTime.GetDeltaWorldTimeSeconds(), WorldTime.GetRealTimeSeconds());
#else
	ViewFamilyConstruction.SetTime(WorldTime);
#endif
	ViewFamily = new FSceneViewFamily(ViewFamilyConstruction);
	FSceneViewInitOptions ViewInitOptions;
	memset(&ViewInitOptions, 0, sizeof(ViewInitOptions));
	ViewInitOptions.ViewFamily = ViewFamily;
	ViewInitOptions.SetViewRectangle(ViewRect);
	ViewInitOptions.ViewOrigin = FVector::ZeroVector;
	ViewInitOptions.ViewRotationMatrix = FMatrix::Identity;
	ViewInitOptions.ProjectionMatrix = ViewProjectionMatrix;
	GetRendererModule().CreateAndInitSingleView(FRHICommandListExecutor::GetImmediateCommandList(), ViewFamily, &ViewInitOptions);
	View = (FViewInfo*)ViewFamily->Views[0];
	ViewUniformBuffer = View->ViewUniformBuffer;
}

void FNoesisRenderDevice::DestroyView()
{
	if (View != nullptr)
	{
		delete View;
		View = nullptr;
	}

	if (ViewFamily != nullptr)
	{
		delete ViewFamily;
		ViewFamily = nullptr;
	}
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(FRHITexture* Texture, bool IgnoreAlpha)
{
	if (Texture == nullptr)
		return nullptr;

	return Noesis::MakePtr<FNoesisTexture>(Texture, IgnoreAlpha);
}

FRHITexture* FNoesisRenderDevice::GetRHITexture(Noesis::Texture* InTexture)
{
	FNoesisTexture* Texture = (FNoesisTexture*)InTexture;
	return Texture->GetTexture2D();
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(UTexture* InTexture)
{
#if UE_VERSION_OLDER_THAN(4, 27, 0)
	if (!InTexture || !InTexture->Resource)
		return nullptr;

	FTextureResource* TextureResource = InTexture->Resource;
#else
	if (!InTexture || !InTexture->GetResource())
		return nullptr;

	FTextureResource* TextureResource = InTexture->GetResource();
#endif

	Noesis::Ptr<FNoesisTexture> Texture;
	if (InTexture->IsA<UTexture2D>())
	{
		UTexture2D* Texture2D = (UTexture2D*)InTexture;
		Texture = *new FNoesisTexture(Texture2D);
	}
	else if (InTexture->IsA<UTextureRenderTarget2D>())
	{
		UTextureRenderTarget2D* TextureRenderTarget2D = (UTextureRenderTarget2D*)InTexture;
		Texture = *new FNoesisTexture(TextureRenderTarget2D);
	}
	else if (InTexture->IsA<UMediaTexture>())
	{
		UMediaTexture* MediaTexture = (UMediaTexture*)InTexture;
		Texture = *new FNoesisTexture(MediaTexture);
	}
	else
	{
		return nullptr;
	}

	return Texture;
}

void* FNoesisRenderDevice::CreateMaterial(UMaterialInterface* InMaterial)
{
	if (!InMaterial)
		return nullptr;

	FNoesisMaterial* Material = new FNoesisMaterial(InMaterial);
	return Material;
}

void FNoesisRenderDevice::DestroyMaterial(void* InMaterial)
{
	if (!InMaterial)
		return;

	FNoesisMaterial* Material = (FNoesisMaterial*)InMaterial;
	ENQUEUE_RENDER_COMMAND(FNoesisDestroyMaterial)
	(
		[Material](FRHICommandListImmediate&)
		{
			delete Material;
		}
	);
}

const Noesis::DeviceCaps& FNoesisRenderDevice::GetCaps() const
{
	static Noesis::DeviceCaps Caps;
	Caps.linearRendering = IsLinearColor;
	return Caps;
}

static void NoesisCreateTargetableShaderResource2D(
	const TCHAR* Name,
	uint32 SizeX,
	uint32 SizeY,
	EPixelFormat Format,
	uint32 NumMips,
	ETextureCreateFlags Flags,
	ETextureCreateFlags TargetableTextureFlags,
	bool bForceSeparateTargetAndShaderResource,
	bool bForceSharedTargetAndShaderResource,
	FClearValueBinding ClearValue,
	FTextureRHIRef& OutTargetableTexture,
	FTextureRHIRef& OutShaderResourceTexture,
	uint32 NumSamples = 1
)
{
	// Ensure none of the usage flags are passed in.
	check(!EnumHasAnyFlags(Flags, TexCreate_RenderTargetable | TexCreate_ResolveTargetable));

	// Ensure we aren't forcing separate and shared textures at the same time.
	check(!(bForceSeparateTargetAndShaderResource && bForceSharedTargetAndShaderResource));

	// Ensure that the targetable texture is either render or depth-stencil targetable.
	check(EnumHasAnyFlags(TargetableTextureFlags, TexCreate_RenderTargetable | TexCreate_DepthStencilTargetable | TexCreate_UAV));

	if (NumSamples > 1 && !bForceSharedTargetAndShaderResource)
	{
		bForceSeparateTargetAndShaderResource = RHISupportsSeparateMSAAAndResolveTextures(GMaxRHIShaderPlatform);
		if (bForceSeparateTargetAndShaderResource)
		{
			TargetableTextureFlags |= TexCreate_Memoryless;
		}
	}

	if (!bForceSeparateTargetAndShaderResource)
	{
		// Create a single texture that has both TargetableTextureFlags and TexCreate_ShaderResource set.
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FRHIResourceCreateInfo CreateInfo(Name);
		CreateInfo.ClearValueBinding = ClearValue;
		OutTargetableTexture = OutShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags | TargetableTextureFlags | TexCreate_ShaderResource, ERHIAccess::SRVGraphics, CreateInfo);
#else
		auto TextureDesc = FRHITextureCreateDesc::Create2D(Name)
			.SetExtent(SizeX, SizeY)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(NumSamples)
			.SetFlags(Flags | TargetableTextureFlags | TexCreate_ShaderResource)
			.SetInitialState(ERHIAccess::SRVGraphics)
			.SetClearValue(ClearValue);
		OutTargetableTexture = OutShaderResourceTexture = RHICreateTexture(TextureDesc);
#endif
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(FRHICommandListExecutor::GetImmediateCommandList(), OutTargetableTexture, Name);
	}
	else
	{
		ETextureCreateFlags ResolveTargetableTextureFlags = TexCreate_ResolveTargetable;
		if (EnumHasAnyFlags(TargetableTextureFlags, TexCreate_DepthStencilTargetable))
		{
			ResolveTargetableTextureFlags |= TexCreate_DepthStencilResolveTarget;
		}
		// Create a texture that has TargetableTextureFlags set, and a second texture that has TexCreate_ResolveTargetable and TexCreate_ShaderResource set.
		TStringBuilder<64> RTName;
		RTName.Append(Name).Append(TEXT("_RT"));
		TStringBuilder<64> SRName;
		SRName.Append(Name).Append(TEXT("_SR"));
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FRHIResourceCreateInfo CreateInfo(*RTName);
		CreateInfo.ClearValueBinding = ClearValue;
		OutTargetableTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags | TargetableTextureFlags, ERHIAccess::RTV, CreateInfo);
		CreateInfo.DebugName = *SRName;
		OutShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, 1, Flags | ResolveTargetableTextureFlags | TexCreate_ShaderResource, ERHIAccess::SRVGraphics, CreateInfo);
#else
		auto TargetableTextureDesc = FRHITextureCreateDesc::Create2D(*RTName)
			.SetExtent(SizeX, SizeY)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(NumSamples)
			.SetFlags(Flags | TargetableTextureFlags)
			.SetInitialState(ERHIAccess::RTV)
			.SetClearValue(ClearValue);
		OutTargetableTexture = RHICreateTexture(TargetableTextureDesc);
		auto ShaderResourceTextureDesc = FRHITextureCreateDesc::Create2D(*SRName)
			.SetExtent(SizeX, SizeY)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(1)
			.SetFlags(Flags | ResolveTargetableTextureFlags | TexCreate_ShaderResource)
			.SetInitialState(ERHIAccess::SRVGraphics)
			.SetClearValue(ClearValue);
		OutShaderResourceTexture = RHICreateTexture(ShaderResourceTextureDesc);
#endif
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(FRHICommandListExecutor::GetImmediateCommandList(), OutTargetableTexture, *RTName);
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(FRHICommandListExecutor::GetImmediateCommandList(), OutShaderResourceTexture, *SRName);
	}
}

static Noesis::Ptr<Noesis::RenderTarget> CreateRenderTarget(const TCHAR* Name, uint32 Width, uint32 Height, uint32 SampleCount, FRHITexture* DepthStencilTarget, bool IsLinearColor)
{
	EPixelFormat Format = PF_R8G8B8A8;
	uint32 NumMips = 1;
	ETextureCreateFlags Flags = IsLinearColor ? TexCreate_SRGB : TexCreate_None;
	ETextureCreateFlags TargetableTextureFlags = TexCreate_RenderTargetable | (IsLinearColor ? TexCreate_SRGB : TexCreate_None);
	bool bForceSeparateTargetAndShaderResource = false;
	FClearValueBinding ClearValue;
	FTextureRHIRef ColorTarget;
	FTextureRHIRef ShaderResourceTexture;
	NoesisCreateTargetableShaderResource2D(Name, Width, Height, Format, NumMips, Flags, TargetableTextureFlags, bForceSeparateTargetAndShaderResource, false, ClearValue, ColorTarget, ShaderResourceTexture, SampleCount);

	FNoesisRenderTarget* RenderTarget = new FNoesisRenderTarget(ShaderResourceTexture, ColorTarget, DepthStencilTarget);

	return Noesis::Ptr<Noesis::RenderTarget>(*RenderTarget);
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CreateRenderTarget(const char* Label, uint32 Width, uint32 Height, uint32 SampleCount, bool NeedsStencil)
{
	TStringBuilder<64> Name;
	Name.Append(TEXT("Noesis.RenderTarget.")).Append(StringCast<TCHAR>((UTF8CHAR*)Label).Get());
	FTextureRHIRef DepthStencilTarget;

	if (NeedsStencil)
	{
		TStringBuilder<64> DSName;
		DSName.Append(*Name).Append(TEXT("_DS"));
		uint32 NumMips = 1;
		EPixelFormat Format = PF_DepthStencil;
		ETextureCreateFlags TargetableTextureFlags = TexCreate_DepthStencilTargetable | TexCreate_Memoryless;
		ERHIAccess Access = ERHIAccess::DSVWrite;
		FClearValueBinding ClearValue(0.f, 0);
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FRHIResourceCreateInfo CreateInfo(*DSName);
		CreateInfo.ClearValueBinding = ClearValue;
		DepthStencilTarget = RHICreateTexture2D(Width, Height, Format, NumMips, SampleCount, TargetableTextureFlags, Access, CreateInfo);
#else
		auto DepthStencilTargetDesc = FRHITextureCreateDesc::Create2D(*DSName)
			.SetExtent(Width, Height)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(SampleCount)
			.SetFlags(TargetableTextureFlags)
			.SetInitialState(Access)
			.SetClearValue(ClearValue);
		DepthStencilTarget = RHICreateTexture(DepthStencilTargetDesc);
#endif
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(FRHICommandListExecutor::GetImmediateCommandList(), DepthStencilTarget, *DSName);
	}

	return ::CreateRenderTarget(*Name, Width, Height, SampleCount, DepthStencilTarget, IsLinearColor);
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CloneRenderTarget(const char* Label, Noesis::RenderTarget* InSharedRenderTarget)
{
	TStringBuilder<64> Name;
	Name.Append(TEXT("Noesis.RenderTarget.")).Append(StringCast<TCHAR>((UTF8CHAR*)Label).Get());
	FNoesisRenderTarget* SharedRenderTarget = (FNoesisRenderTarget*)InSharedRenderTarget;

	FRHITexture* ColorTarget = SharedRenderTarget->GetColorTarget();
	uint32 Width = ColorTarget->GetSizeX();
	uint32 Height = ColorTarget->GetSizeY();
	uint32 SampleCount = ColorTarget->GetNumSamples();
	FRHITexture* DepthStencilTarget = SharedRenderTarget->GetDepthStencilTarget();

	return ::CreateRenderTarget(*Name, Width, Height, SampleCount, DepthStencilTarget, IsLinearColor);
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(const char* Label, uint32 Width, uint32 Height, uint32 NumLevels, Noesis::TextureFormat::Enum TextureFormat, const void** Data)
{
	TStringBuilder<64> Name;
	Name.Append(TEXT("Noesis.Texture.")).Append(StringCast<TCHAR>((UTF8CHAR*)Label).Get());
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	EPixelFormat Formats[Noesis::TextureFormat::Count] = { PF_R8G8B8A8, PF_R8G8B8A8, PF_G8 };
	EPixelFormat Format = Formats[TextureFormat];
	uint32 NumMips = (uint32)NumLevels;
	uint32 NumSamples = 1;
	ETextureCreateFlags Flags = IsLinearColor ? TexCreate_SRGB : TexCreate_None;
	ERHIAccess Access = ERHIAccess::SRVGraphics;
#if UE_VERSION_OLDER_THAN(5, 1, 0)
	FRHIResourceCreateInfo CreateInfo(*Name);
	FTextureRHIRef ShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags, Access, CreateInfo);
#else
	auto ShaderResourceTextureDesc = FRHITextureCreateDesc::Create2D(*Name)
		.SetExtent(SizeX, SizeY)
		.SetFormat(Format)
		.SetNumMips(NumMips)
		.SetNumSamples(NumSamples)
		.SetFlags(Flags)
		.SetInitialState(Access);
	FTextureRHIRef ShaderResourceTexture = RHICreateTexture(ShaderResourceTextureDesc);
#endif
	NOESIS_BIND_DEBUG_TEXTURE_LABEL(FRHICommandListExecutor::GetImmediateCommandList(), ShaderResourceTexture, *Name);

	Noesis::Ptr<FNoesisTexture> Texture = Noesis::MakePtr<FNoesisTexture>(ShaderResourceTexture);

	if (Data != nullptr)
	{
		for (uint32 Level = 0; Level < NumMips; ++Level)
		{
			UpdateTexture(Texture, Level, 0, 0, Width, Height, Data[Level]);
			Width >>= 1;
			Height >>= 1;
		}
	}

	return Texture;
}

void FNoesisRenderDevice::UpdateTexture(Noesis::Texture* InTexture, uint32 Level, uint32 X, uint32 Y, uint32 Width, uint32 Height, const void* Data)
{
	FNoesisTexture* Texture = (FNoesisTexture*)InTexture;

	int32 MipIndex = (int32)Level;
	FUpdateTextureRegion2D UpdateRegion;
	UpdateRegion.SrcX = 0;
	UpdateRegion.SrcY = 0;
	UpdateRegion.DestX = (uint32)X;
	UpdateRegion.DestY = (uint32)Y;
	UpdateRegion.Width = (uint32)Width;
	UpdateRegion.Height = (uint32)Height;
	uint32 SourcePitch = (uint32)(Width * GPixelFormats[Texture->GetTexture2D()->GetFormat()].BlockBytes);
	const uint8* SourceData = (const uint8*)Data;

	RHIUpdateTexture2D(Texture->GetTexture2D(), MipIndex, UpdateRegion, SourcePitch, SourceData);
}

static void SetStaticUniformBuffer(FRHICommandList* RHICmdList, FRHIUniformBuffer* UniformBuffer)
{
	const FRHIUniformBufferLayout& Layout = UniformBuffer->GetLayout();

	const FUniformBufferStaticSlot Slot = Layout.StaticSlot;
	checkf(IsUniformBufferStaticSlotValid(Slot), TEXT("Attempted to set a global uniform buffer %s with an invalid slot."), *Layout.GetDebugName());

	RHICmdList->SetStaticUniformBuffer(Slot, UniformBuffer);
}

void FNoesisRenderDevice::BeginOffscreenRender()
{
	if (SceneTexturesUniformBuffer)
	{
		SetStaticUniformBuffer(RHICmdList, SceneTexturesUniformBuffer);
	}

	if (MobileSceneTexturesUniformBuffer)
	{
		SetStaticUniformBuffer(RHICmdList, MobileSceneTexturesUniformBuffer);
	}

	if (ViewUniformBuffer)
	{
		SetStaticUniformBuffer(RHICmdList, ViewUniformBuffer);
	}
}

void FNoesisRenderDevice::EndOffscreenRender()
{
}

void FNoesisRenderDevice::BeginOnscreenRender()
{
	if (SceneTexturesUniformBuffer)
	{
		SetStaticUniformBuffer(RHICmdList, SceneTexturesUniformBuffer);
	}

	if (MobileSceneTexturesUniformBuffer)
	{
		SetStaticUniformBuffer(RHICmdList, MobileSceneTexturesUniformBuffer);
	}

	if (ViewUniformBuffer)
	{
		SetStaticUniformBuffer(RHICmdList, ViewUniformBuffer);
	}
}

void FNoesisRenderDevice::EndOnscreenRender()
{
}

void FNoesisRenderDevice::SetRenderTarget(Noesis::RenderTarget* Surface)
{
	check(RHICmdList);
#if UE_VERSION_OLDER_THAN(5, 5, 0)
#if WANTS_DRAW_MESH_EVENTS
	BEGIN_DRAW_EVENTF(*RHICmdList, SetRenderTarget, SetRenderTargetEvent, TEXT("SetRenderTarget"));
#endif
#else
#if WITH_RHI_BREADCRUMBS
#if UE_VERSION_OLDER_THAN(5, 6, 0)
	SetRenderTargetBreadcrumb.Emplace(*RHICmdList, FRHIBreadcrumbData(__FILE__, __LINE__, TStatId(), NAME_None), TEXT("SetRenderTarget"));
#else
#if CSV_PROFILER
	if (FCsvProfiler::Get()->IsCapturing_Renderthread())
	{
		SetRenderTargetBreadcrumb.Emplace(*RHICmdList, RHI_BREADCRUMB_DESC_FORWARD_VALUES(TEXT("SetRenderTarget"), nullptr, RHI_GPU_STAT_ARGS_NONE)());
	}
	else
#endif
	{
		SetRenderTargetBreadcrumb.Emplace(*RHICmdList, RHI_BREADCRUMB_DESC_FORWARD_VALUES(TEXT("SetRenderTarget"), nullptr, RHI_GPU_STAT_ARGS_NONE)());
	}
#endif
#endif
#endif
	check(Surface);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;

	check(RHICmdList->IsOutsideRenderPass());
	RenderTarget->SetRenderTarget(RHICmdList);

	FRHITexture* ColorTarget = RenderTarget->GetColorTarget();
	auto ColorTargetSize = ColorTarget->GetSizeXY();
	CreateView(0, 0, ColorTargetSize.X, ColorTargetSize.Y, FIntRect(0, 0, ColorTargetSize.X, ColorTargetSize.Y), FMatrix::Identity);
}

void FNoesisRenderDevice::BeginTile(Noesis::RenderTarget* Surface, const Noesis::Tile& Tile)
{
	check(RHICmdList);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
	RenderTarget->BeginTile(RHICmdList, Tile);
}

void FNoesisRenderDevice::EndTile(Noesis::RenderTarget* Surface)
{
	check(RHICmdList);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
	RenderTarget->EndTile(RHICmdList);
}

void FNoesisRenderDevice::ResolveRenderTarget(Noesis::RenderTarget* Surface, const Noesis::Tile* Tiles, uint32 NumTiles)
{
	check(RHICmdList);
	check(RHICmdList->IsInsideRenderPass());
	
	{
		SCOPED_DRAW_EVENT(*RHICmdList, Resolve);
		FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
		RenderTarget->ResolveRenderTarget(RHICmdList, Tiles, NumTiles);
	}

#if UE_VERSION_OLDER_THAN(5, 5, 0)
#if WANTS_DRAW_MESH_EVENTS
	STOP_DRAW_EVENT(SetRenderTargetEvent);
#endif
#else
#if WITH_RHI_BREADCRUMBS
	SetRenderTargetBreadcrumb->End(*RHICmdList);
	SetRenderTargetBreadcrumb.Reset();
#endif
#endif

	DestroyView();
}

void* FNoesisRenderDevice::MapVertices(uint32 Bytes)
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	void* Result = RHILockVertexBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	void* Result = RHILockBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#else
	void* Result = RHICmdList->LockBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#endif
	return Result;
}

void FNoesisRenderDevice::UnmapVertices()
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	RHIUnlockVertexBuffer(DynamicVertexBuffer);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	RHIUnlockBuffer(DynamicVertexBuffer);
#else
	RHICmdList->UnlockBuffer(DynamicVertexBuffer);
#endif
}

void* FNoesisRenderDevice::MapIndices(uint32 Bytes)
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	void* Result = RHILockIndexBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	void* Result = RHILockBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#else
	void* Result = RHICmdList->LockBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#endif
	return Result;
}

void FNoesisRenderDevice::UnmapIndices()
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	RHIUnlockIndexBuffer(DynamicIndexBuffer);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	RHIUnlockBuffer(DynamicIndexBuffer);
#else
	RHICmdList->UnlockBuffer(DynamicIndexBuffer);
#endif
}

template<>
bool FNoesisRenderDevice::SetPatternMaterialParameters<FNoesisPS>(const Noesis::Batch& Batch, const FMaterialRenderProxy* MaterialProxy, const FMaterial* Material, const TShaderRef<FNoesisPS>& PixelShader)
{
	if (Batch.pattern != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
		FRHITexture* PatternTexture = Texture->GetTexture2D();

		if (PatternTexture == nullptr)
			return false;

		FRHISamplerState* PatternSamplerState = GetSamplerState(Batch.patternSampler.v);
		PixelShader->SetPatternTexture(*RHICmdList, PatternTexture, PatternSamplerState);
	}

	return true;
}

template<>
bool FNoesisRenderDevice::SetPatternMaterialParameters<FNoesisMaterialPS>(const Noesis::Batch& Batch, const FMaterialRenderProxy* MaterialProxy, const FMaterial* Material, const TShaderRef<FNoesisMaterialPS>& PixelShader)
{
	FRHIPixelShader* ShaderRHI = PixelShader.GetPixelShader();
	PixelShader->SetViewParameters(*RHICmdList, ShaderRHI, *View, ViewUniformBuffer);
#if UE_VERSION_OLDER_THAN(5, 1, 0)
	PixelShader->SetParameters<FRHIPixelShader>(*RHICmdList, ShaderRHI, MaterialProxy, *Material, *View);
#else
	PixelShader->SetParameters<FRHIPixelShader, FRHICommandList>(*RHICmdList, ShaderRHI, MaterialProxy, *Material, *View);
#endif

	return true;
}

template<class PixelShaderClass>
bool FNoesisRenderDevice::SetPixelShaderParameters(const Noesis::Batch& Batch, const FMaterialRenderProxy* MaterialProxy, const FMaterial* Material, const TShaderRef<PixelShaderClass>& PixelShader, const FUniformBufferRHIRef& PSUniformBuffer0, const FUniformBufferRHIRef& PSUniformBuffer1)
{
	if (Batch.pixelUniforms[0].values != nullptr)
	{
		PixelShader->SetPSConstants(*RHICmdList, PSUniformBuffer0);
	}

	if (Batch.pixelUniforms[1].values != nullptr)
	{
		PixelShader->SetEffects(*RHICmdList, PSUniformBuffer1);
	}

	if (!SetPatternMaterialParameters(Batch, MaterialProxy, Material, PixelShader))
		return false;

	if (Batch.ramps != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.ramps);
		FRHITexture* RampsTexture = Texture->GetTexture2D();
		FRHISamplerState* RampsSamplerState = GetSamplerState(Batch.rampsSampler.v);
		PixelShader->SetRampsTexture(*RHICmdList, RampsTexture, RampsSamplerState);
	}

	if (Batch.image != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.image);
		FRHITexture* ImageTexture = Texture->GetTexture2D();
		FRHISamplerState* ImageSamplerState = GetSamplerState(Batch.imageSampler.v);
		PixelShader->SetImageTexture(*RHICmdList, ImageTexture, ImageSamplerState);
	}

	if (Batch.glyphs != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.glyphs);
		FRHITexture* GlyphsTexture = Texture->GetTexture2D();
		FRHISamplerState* GlyphsSamplerState = GetSamplerState(Batch.glyphsSampler.v);
		PixelShader->SetGlyphsTexture(*RHICmdList, GlyphsTexture, GlyphsSamplerState);
	}

	if (Batch.shadow != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.shadow);
		FRHITexture* ShadowTexture = Texture->GetTexture2D();
		FRHISamplerState* ShadowSamplerState = GetSamplerState(Batch.shadowSampler.v);
		PixelShader->SetShadowTexture(*RHICmdList, ShadowTexture, ShadowSamplerState);
	}

	return true;
}

template<>
bool FNoesisRenderDevice::SetPixelShaderParameters<FNoesisCustomEffectPS>(const Noesis::Batch& Batch, const FMaterialRenderProxy* MaterialProxy, const FMaterial* Material, const TShaderRef<FNoesisCustomEffectPS>& PixelShader, const FUniformBufferRHIRef& PSUniformBuffer0, const FUniformBufferRHIRef& PSUniformBuffer1)
{
	FRHIPixelShader* ShaderRHI = PixelShader.GetPixelShader();
	PixelShader->SetViewParameters(*RHICmdList, ShaderRHI, *View, ViewUniformBuffer);

	FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
	FRHITexture* PatternTexture = Texture->GetTexture2D();
	//FRHISamplerState* PatternSamplerState = SamplerStates[Batch.patternSampler.v];
	FRHISamplerState* PatternSamplerState = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp>::GetRHI(); // This should be point samplig for the behavior to be the same as UE4's
	FNoesisPostProcessMaterialParameters Params = {};
	Params.View = ViewUniformBuffer;
	Params.SceneTextures.SceneTextures = SceneTexturesUniformBuffer;
    Params.SceneTextures.MobileSceneTextures = MobileSceneTexturesUniformBuffer;
	Params.PostProcessInput_BilinearSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp>::GetRHI();
	Params.PostProcessInput_0_Texture = PatternTexture;
	Params.PostProcessInput_0_Sampler = PatternSamplerState;
	// Texture extent in pixels.
	{
		const FVector2f Extent(Texture->GetWidth(), Texture->GetHeight());
		const FVector2f ViewportMin(0.0f, 0.0f);
		const FVector2f ViewportMax(Texture->GetWidth(), Texture->GetHeight());
		const FVector2f ViewportSize = ViewportMax - ViewportMin;

		FScreenPassTextureViewportParameters& Viewport = Params.PostProcessInput;

		Viewport.Extent = Extent;
		Viewport.ExtentInverse = FVector2f(1.0f / Extent.X, 1.0f / Extent.Y);

		Viewport.ScreenPosToViewportScale = FVector2f(0.5f, -0.5f) * ViewportSize;
		Viewport.ScreenPosToViewportBias = (0.5f * ViewportSize) + ViewportMin;

		Viewport.ViewportMin = FIntPoint(0, 0);
		Viewport.ViewportMax = FIntPoint(Texture->GetWidth(), Texture->GetHeight());

		Viewport.ViewportSize = ViewportSize;
		Viewport.ViewportSizeInverse = FVector2f(1.0f / Viewport.ViewportSize.X, 1.0f / Viewport.ViewportSize.Y);

		Viewport.UVViewportMin = ViewportMin * Viewport.ExtentInverse;
		Viewport.UVViewportMax = ViewportMax * Viewport.ExtentInverse;

		Viewport.UVViewportSize = Viewport.UVViewportMax - Viewport.UVViewportMin;
		Viewport.UVViewportSizeInverse = FVector2f(1.0f / Viewport.UVViewportSize.X, 1.0f / Viewport.UVViewportSize.Y);

		Viewport.UVViewportBilinearMin = Viewport.UVViewportMin + 0.5f * Viewport.ExtentInverse;
		Viewport.UVViewportBilinearMax = Viewport.UVViewportMax - 0.5f * Viewport.ExtentInverse;
	}

	{
		const FVector2f Extent(ViewRight - ViewLeft, ViewBottom - ViewTop);
		const FVector2f ViewportMin(ViewLeft, ViewTop);
		const FVector2f ViewportMax(ViewRight, ViewBottom);
		const FVector2f ViewportSize = ViewportMax - ViewportMin;

		FScreenPassTextureViewportParameters& Viewport = Params.PostProcessOutput;

		Viewport.Extent = Extent;
		Viewport.ExtentInverse = FVector2f(1.0f / Extent.X, 1.0f / Extent.Y);

		Viewport.ScreenPosToViewportScale = FVector2f(0.5f, -0.5f) * ViewportSize;
		Viewport.ScreenPosToViewportBias = (0.5f * ViewportSize) + ViewportMin;

		Viewport.ViewportMin = FIntPoint(ViewLeft, ViewTop);
		Viewport.ViewportMax = FIntPoint(ViewRight, ViewBottom);

		Viewport.ViewportSize = ViewportSize;
		Viewport.ViewportSizeInverse = FVector2f(1.0f / Viewport.ViewportSize.X, 1.0f / Viewport.ViewportSize.Y);

		Viewport.UVViewportMin = ViewportMin * Viewport.ExtentInverse;
		Viewport.UVViewportMax = ViewportMax * Viewport.ExtentInverse;

		Viewport.UVViewportSize = Viewport.UVViewportMax - Viewport.UVViewportMin;
		Viewport.UVViewportSizeInverse = FVector2f(1.0f / Viewport.UVViewportSize.X, 1.0f / Viewport.UVViewportSize.Y);

		Viewport.UVViewportBilinearMin = Viewport.UVViewportMin + 0.5f * Viewport.ExtentInverse;
		Viewport.UVViewportBilinearMax = Viewport.UVViewportMax - 0.5f * Viewport.ExtentInverse;
	}

	FNoesisCustomEffectPS::SetParameters(*RHICmdList, PixelShader, *View, MaterialProxy, *Material, Params);

	return true;
}

static inline bool BufferNeedsUpdate(uint32& BufferHash, const Noesis::UniformData& UniformData)
{
	// There's no data.
	if (UniformData.values == nullptr)
		return false;

	// Buffer is up to date.
	if (BufferHash == UniformData.hash)
		return false;

	return true;
}

static inline void UpdateUniformBuffer(FRHICommandList* RHICmdList, FUniformBufferRHIRef& UniformBuffer, uint32 UniformDataSize, const void* UniformDataValues)
{
	check(UniformBuffer != nullptr);

	const auto& UniformBufferLayout = UniformBuffer->GetLayout();
	uint32 UniformBufferSize = UniformBufferLayout.ConstantBufferSize;

	// Need a copy on the stack because RHI requires a 16 byte alignment and 16 byte padding.
	// Reading from UniformData.values can cause an OOB read if UniformDataSize < UniformBufferSize.
	// We allocate UniformBufferSize bytes but only memcpy UniformDataSize bytes.
	check(UniformDataSize <= UniformBufferSize);
	void* UniformBufferData = FMemory_Alloca(UniformBufferSize);
	FMemory::Memcpy(UniformBufferData, UniformDataValues, UniformDataSize);

#if PLATFORM_APPLE
	// UniformBuffers on Metal are broken. They are all treated as Volatile, and new data is not pushed to the GPU after an update.
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	UniformBuffer = RHICreateUniformBuffer(UniformBufferData, UniformBufferLayout, UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#else
	UniformBuffer = RHICreateUniformBuffer(UniformBufferData, &UniformBufferLayout, UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#endif
#else
#if UE_VERSION_OLDER_THAN(5, 3, 0)
	RHIUpdateUniformBuffer(UniformBuffer, UniformBufferData);
#else
	RHICmdList->UpdateUniformBuffer(UniformBuffer, UniformBufferData);
#endif
#endif
}

static inline bool ConditionalUpdateUniformBuffer(FRHICommandList* RHICmdList, FUniformBufferRHIRef& UniformBuffer, uint32& BufferHash, const Noesis::UniformData& UniformData)
{
	if (!BufferNeedsUpdate(BufferHash, UniformData))
		return false;

	uint32 UniformDataSize = UniformData.numDwords * 4;
	const void* UniformDataValues = UniformData.values;
	UpdateUniformBuffer(RHICmdList, UniformBuffer, UniformDataSize, UniformDataValues);

	BufferHash = UniformData.hash;

	return true;
}

void FNoesisRenderDevice::DrawBatch(const Noesis::Batch& Batch)
{
	check(RHICmdList);
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList->ApplyCachedRenderTargets(GraphicsPSOInit);

	GraphicsPSOInit.DepthStencilState = GetDepthStencilState(Batch.renderState.f.stencilMode, AlphaMask);

	GraphicsPSOInit.BlendState = AlphaMask ? TStaticBlendState<CW_RGBA>::GetRHI() : (Batch.renderState.f.colorEnable ? (IsWorldUI ? GetBlendStateWorldUI(Batch.renderState.f.blendMode) : GetBlendState(Batch.renderState.f.blendMode)) : TStaticBlendState<CW_NONE>::GetRHI());

	GraphicsPSOInit.RasterizerState = Batch.renderState.f.wireframe ? TStaticRasterizerState<FM_Wireframe, CM_None>::GetRHI() : TStaticRasterizerState<FM_Solid, CM_None>::GetRHI();

	const ERHIFeatureLevel::Type FeatureLevel = Scene ? Scene->GetFeatureLevel() : GMaxRHIFeatureLevel;
	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);

	Noesis::Shader::Enum ShaderCode = (Noesis::Shader::Enum)Batch.shader.v;

	bool GammaCorrection = !FMath::IsNearlyEqual(Gamma, 2.2f) || !FMath::IsNearlyEqual(Contrast, 1.0f);
	bool UsingMaterialShader = Batch.pixelShader != nullptr;
	bool UsingCustomEffect = ShaderCode == Noesis::Shader::Custom_Effect;
	TShaderRef<FNoesisMaterialPS> MaterialPixelShader;
	TShaderRef<FNoesisCustomEffectPS> CustomEffectPixelShader;
	const FMaterialRenderProxy* MaterialProxy = nullptr;
	const FMaterial* Material = nullptr;
	if (UsingMaterialShader)
	{
		FNoesisMaterial* NoesisMaterial = (FNoesisMaterial*)Batch.pixelShader;
		MaterialProxy = NoesisMaterial->GetRenderProxy();
		if (MaterialProxy == nullptr)
			return;

#if !UE_VERSION_OLDER_THAN(5, 6, 0) && UE_WITH_PSO_PRECACHING
		if (GetPSOPrecacheProxyCreationStrategy() == EPSOPrecacheProxyCreationStrategy::DelayUntilPSOPrecached && NoesisMaterial->IsPrecachePendingAndBoost())
		{
			if (UE_LOG_ACTIVE(LogNoesis, Display))
			{
				//Only output this once a frame since it can be spammy
				static uint64 FrameCountPrev = 0;
				if (GFrameCounterRenderThread != FrameCountPrev)
				{
					UE_LOG(LogNoesis, Display, TEXT("Skipping some Noesis draws due to incomplete material PSOs: %s"), *MaterialProxy->GetMaterialName());
					FrameCountPrev = GFrameCounterRenderThread;
				}
			}
			return;
		}
#endif

#if UE_VERSION_OLDER_THAN(4, 27, 0)
		Material = MaterialProxy->GetMaterial(FeatureLevel);
#else
		Material = &MaterialProxy->GetIncompleteMaterialWithFallback(FeatureLevel);
#endif
		if (UsingCustomEffect)
		{
			UsingMaterialShader = false;

			FNoesisCustomEffectPS::FPermutationDomain Permutation;
			Permutation.Set<FNoesisCustomEffectPS::FGammaCorrection>(GammaCorrection);
			Permutation.Set<FNoesisCustomEffectPS::FAlphaMask>(AlphaMask);

			CustomEffectPixelShader = GetMaterialPixelShader<FNoesisCustomEffectPS>(*Material, Permutation);
		}
		else
		{
			FNoesisMaterialPS::FPermutationDomain Permutation;
			Permutation.Set<FNoesisMaterialPS::FEffect>(ShaderCode);
			Permutation.Set<FNoesisMaterialPS::FLinearColor>(IsLinearColor);
			Permutation.Set<FNoesisMaterialPS::FGammaCorrection>(GammaCorrection);
			Permutation.Set<FNoesisMaterialPS::FAlphaMask>(AlphaMask);

			MaterialPixelShader = GetMaterialPixelShader<FNoesisMaterialPS>(*Material, Permutation);
		}
	}

	bool PatternLinear = false;
	bool PatternIgnoreAlpha = false;
	if (Batch.pattern != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
		FRHITexture* PatternTexture = Texture->GetTexture2D();
		if (PatternTexture != nullptr)
		{
			PatternLinear = EnumHasAnyFlags(PatternTexture->GetFlags(), TexCreate_SRGB);
		}

		PatternIgnoreAlpha = Texture->MustIgnoreAlpha();
	}

	const uint8_t VertexShaderCode = Noesis::VertexForShader[ShaderCode];

	FNoesisVS::FPermutationDomain VSPermutation;
	VSPermutation.Set<FNoesisVS::FVertexShader>(VertexShaderCode);
	VSPermutation.Set<FNoesisVS::FStereo>(Batch.singlePassStereo);
	VSPermutation.Set<FNoesisVS::FLinearColor>(IsLinearColor);

	TShaderRef<FNoesisVS> VertexShader = GlobalShaderMap->GetShader<FNoesisVS>(VSPermutation);

	FVertexDeclarationRHIRef VertexDeclaration = GetVertexDelcaration((Noesis::Shader::Vertex::Format::Enum)Noesis::FormatForVertex[VertexShaderCode]);

	TShaderRef<FNoesisPS> PixelShader;
	if (!UsingCustomEffect && !UsingMaterialShader)
	{
		FNoesisPS::FPermutationDomain Permutation;
		Permutation.Set<FNoesisPS::FEffect>(ShaderCode);
		if (AlphaMask)
		{
			Permutation.Set<FNoesisPS::FLinearColor>(IsLinearColor);
			Permutation.Set<FNoesisPS::FAlphaMask>(AlphaMask);
		}
		else
		{
			Permutation.Set<FNoesisPS::FGammaCorrection>(GammaCorrection);
			if (NoesisShaderHasPattern[ShaderCode])
			{
				Permutation.Set<FNoesisPS::FPatternIgnoreAlpha>(PatternIgnoreAlpha);
				// The combinations where IsLinearColor == PatternLinear are the same. We only build the (false, false) shader permutation.
				Permutation.Set<FNoesisPS::FPatternLinear>(!IsLinearColor && PatternLinear);
				Permutation.Set<FNoesisPS::FLinearColor>(IsLinearColor && !PatternLinear);
			}
		}
		PixelShader = GlobalShaderMap->GetShader<FNoesisPS>(Permutation);
	}

	FUniformBufferRHIRef& PSUniformBuffer0 = *PixelShaderConstantBuffer0[ShaderCode];
	FUniformBufferRHIRef& PSUniformBuffer1 = *PixelShaderConstantBuffer1[ShaderCode];
	uint32& PSUniformBuffer0Hash = *PixelShaderConstantBuffer0Hash[ShaderCode];
	uint32& PSUniformBuffer1Hash = *PixelShaderConstantBuffer1Hash[ShaderCode];
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = UsingCustomEffect ? CustomEffectPixelShader.GetPixelShader() : (UsingMaterialShader ? MaterialPixelShader.GetPixelShader() : PixelShader.GetPixelShader());
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;

	// This can happen when the shaders are being recompiled in the editor.
	if (!VertexShader.IsValid())
		return;

	if (UsingCustomEffect)
	{
#if UE_VERSION_OLDER_THAN(5, 6, 0)
#else
#if PSO_PRECACHING_VALIDATE
		if (PSOCollectorStats::IsFullPrecachingValidationEnabled())
		{
			static const int32 MaterialPSOCollectorIndex = FPSOCollectorCreateManager::GetIndex(GetFeatureLevelShadingPath(FeatureLevel), NoesisMaterialPSOCollectorName);
			PSOCollectorStats::CheckFullPipelineStateInCache(GraphicsPSOInit, EPSOPrecacheResult::Unknown, MaterialProxy, nullptr, nullptr, MaterialPSOCollectorIndex);
		}
#endif // PSO_PRECACHING_VALIDATE
#endif

		if (!CustomEffectPixelShader.IsValid() || !ViewUniformBuffer.IsValid() || (!SceneTexturesUniformBuffer.IsValid() && !MobileSceneTexturesUniformBuffer.IsValid()) || (View == nullptr))
			return;
	}
	else if (UsingMaterialShader)
	{
#if UE_VERSION_OLDER_THAN(5, 6, 0)
#else
#if PSO_PRECACHING_VALIDATE
		if (PSOCollectorStats::IsFullPrecachingValidationEnabled())
		{
			static const int32 MaterialPSOCollectorIndex = FPSOCollectorCreateManager::GetIndex(GetFeatureLevelShadingPath(FeatureLevel), NoesisMaterialPSOCollectorName);
			PSOCollectorStats::CheckFullPipelineStateInCache(GraphicsPSOInit, EPSOPrecacheResult::Unknown, MaterialProxy, nullptr, nullptr, MaterialPSOCollectorIndex);
		}
#endif // PSO_PRECACHING_VALIDATE
#endif

		if (!MaterialPixelShader.IsValid() || !ViewUniformBuffer.IsValid() || (View == nullptr))
			return;
	}
	else
	{
#if UE_VERSION_OLDER_THAN(5, 6, 0)
#else
#if PSO_PRECACHING_VALIDATE
		if (PSOCollectorStats::IsFullPrecachingValidationEnabled())
		{
			static const int32 GlobalPSOCollectorIndex = FGlobalPSOCollectorManager::GetIndex(NoesisGlobalPSOCollectorName);
			PSOCollectorStats::CheckGlobalGraphicsPipelineStateInCache(GraphicsPSOInit, GlobalPSOCollectorIndex);
		}
#endif // PSO_PRECACHING_VALIDATE
#endif

		if (!PixelShader.IsValid())
			return;
	}

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	SetGraphicsPipelineState(*RHICmdList, GraphicsPSOInit);
#else
	SetGraphicsPipelineState(*RHICmdList, GraphicsPSOInit, Batch.stencilRef);
#endif

	uint32 NumInstances = 1;

	// Update the uniform buffers
	if (Batch.singlePassStereo)
	{
		//GraphicsPSOInit.MultiViewCount = 2;
		if (GraphicsPSOInit.MultiViewCount == 0)
		{
			NumInstances = 2;
		}

		ConditionalUpdateUniformBuffer(RHICmdList, VSConstantBufferStereo, VSConstantsHash, Batch.vertexUniforms[0]);
		VertexShader->SetVSConstantsStereo(*RHICmdList, VSConstantBufferStereo);
	}
	else
	{
		ConditionalUpdateUniformBuffer(RHICmdList, VSConstantBuffer, VSConstantsHash, Batch.vertexUniforms[0]);
		VertexShader->SetVSConstants(*RHICmdList, VSConstantBuffer);
	}

	ConditionalUpdateUniformBuffer(RHICmdList, TextureSizeBuffer, TextureSizeHash, Batch.vertexUniforms[1]);

	ConditionalUpdateUniformBuffer(RHICmdList, PSUniformBuffer0, PSUniformBuffer0Hash, Batch.pixelUniforms[0]);

	ConditionalUpdateUniformBuffer(RHICmdList, PSUniformBuffer1, PSUniformBuffer1Hash, Batch.pixelUniforms[1]);

	if (Batch.vertexUniforms[1].values != nullptr)
	{
		VertexShader->SetTextureSize(*RHICmdList, TextureSizeBuffer);
	}

	if (UsingCustomEffect)
	{
		if (GammaCorrection)
		{
			CustomEffectPixelShader->SetDisplayGammaAndInvertAlphaAndContrast(*RHICmdList, Gamma, 0.0f, Contrast);
		}
		if (!SetPixelShaderParameters(Batch, MaterialProxy, Material, CustomEffectPixelShader, PSUniformBuffer0, PSUniformBuffer1))
			return;
	}
	else if (UsingMaterialShader)
	{
		if (GammaCorrection)
		{
			MaterialPixelShader->SetDisplayGammaAndInvertAlphaAndContrast(*RHICmdList, Gamma, 0.0f, Contrast);
		}
		if (!SetPixelShaderParameters(Batch, MaterialProxy, Material, MaterialPixelShader, PSUniformBuffer0, PSUniformBuffer1))
			return;
	}
	else
	{
		if (GammaCorrection)
		{
			PixelShader->SetDisplayGammaAndInvertAlphaAndContrast(*RHICmdList, Gamma, 0.0f, Contrast);
		}
		if (!SetPixelShaderParameters(Batch, nullptr, nullptr, PixelShader, PSUniformBuffer0, PSUniformBuffer1))
			return;
	}

	RHICmdList->SetStencilRef(Batch.stencilRef);
	RHICmdList->SetStreamSource(0, DynamicVertexBuffer, Batch.vertexOffset);

	RHICmdList->DrawIndexedPrimitive(DynamicIndexBuffer, 0, 0, Batch.numVertices, Batch.startIndex, Batch.numIndices / 3, NumInstances);
}

#if UE_VERSION_OLDER_THAN(5, 6, 0)
#else
static void AddPSOInitializer(FRHIDepthStencilState* DepthStencilState, FRHIBlendState* BlendState, FRHIRasterizerState* RasterizerState,
	FRHIVertexShader* VertexShader, FRHIVertexDeclaration* VertexDeclaration, FRHIPixelShader* PixelShader,
	const FGraphicsPipelineRenderTargetsInfo& RenderTargetsInfo,
	int32 PSOCollectorIndex, TArray<FPSOPrecacheData>& PSOInitializers)
{
	FGraphicsPipelineStateInitializer GraphicsPSOInit;

	GraphicsPSOInit.DepthStencilState = DepthStencilState;
	GraphicsPSOInit.BlendState = BlendState;
	GraphicsPSOInit.RasterizerState = RasterizerState;
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader;
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader;
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;
	ApplyTargetsInfo(GraphicsPSOInit, RenderTargetsInfo);
	//This could use RenderTargetsInfo depending on the platform
	GraphicsPSOInit.StatePrecachePSOHash = RHIComputeStatePrecachePSOHash(GraphicsPSOInit);

	FPSOPrecacheData PSOPrecacheData;
	PSOPrecacheData.bRequired = true;
	PSOPrecacheData.Type = FPSOPrecacheData::EType::Graphics;
	PSOPrecacheData.GraphicsPSOInitializer = GraphicsPSOInit;
#if PSO_PRECACHING_VALIDATE
	PSOPrecacheData.PSOCollectorIndex = PSOCollectorIndex;
	PSOPrecacheData.VertexFactoryType = nullptr;
#endif // PSO_PRECACHING_VALIDATE

	PSOInitializers.Add(MoveTemp(PSOPrecacheData));
}

static void AddPSOInitializers(FGlobalShaderMap* GlobalShaderMap, const FSceneTexturesConfig& SceneTexturesConfig,
	uint8 ShaderCode, uint8 StateCode, FRHIPixelShader* PixelShader,
	bool IsLinearColor, bool SinglePassStereo, bool GammaCorrection, bool AlphaMask,
	int32 PSOCollectorIndex, TArray<FPSOPrecacheData>& PSOInitializers)
{
	Noesis::Shader Shader;
	Shader.v = ShaderCode;

	Noesis::RenderState RenderState;
	RenderState.v = StateCode;

	if (Noesis::RenderDevice::IsValidState(Shader, RenderState))
	{
		const uint32 VertexShaderCode = Noesis::VertexForShader[ShaderCode];
		const int32 VertexFormatCode = Noesis::FormatForVertex[VertexShaderCode];
		FRHIVertexDeclaration* VertexDeclaration = GetVertexDelcaration((Noesis::Shader::Vertex::Format::Enum)VertexFormatCode);
		
		FRHIDepthStencilState* DepthStencilState = GetDepthStencilState(RenderState.f.stencilMode, AlphaMask);
		FRHIBlendState* BlendState = RenderState.f.colorEnable ? GetBlendState(RenderState.f.blendMode) : TStaticBlendState<CW_NONE>::GetRHI();
		FRHIBlendState* BlendStateWorldUI = AlphaMask ? TStaticBlendState<CW_RGBA>::GetRHI() : (RenderState.f.colorEnable ? GetBlendStateWorldUI(RenderState.f.blendMode) : TStaticBlendState<CW_NONE>::GetRHI());
		FRHIRasterizerState* RasterizerState = RenderState.f.wireframe ? TStaticRasterizerState<FM_Wireframe, CM_None>::GetRHI() : TStaticRasterizerState<FM_Solid, CM_None>::GetRHI();

		FNoesisVS::FPermutationDomain VSPermutation;
		VSPermutation.Set<FNoesisVS::FVertexShader>(VertexShaderCode);
		VSPermutation.Set<FNoesisVS::FStereo>(SinglePassStereo);
		VSPermutation.Set<FNoesisVS::FLinearColor>(IsLinearColor);

		TShaderRef<FNoesisVS> VertexShaderRef = GlobalShaderMap->GetShader<FNoesisVS>(VSPermutation);
		FRHIVertexShader* VertexShader = VertexShaderRef.GetVertexShader();

		if (IsLinearColor)
		{
			FGraphicsPipelineRenderTargetsInfo RenderTargetsInfo;
			AddRenderTargetInfo(AlphaMask ? PF_A16B16G16R16 : PF_FloatRGBA, TexCreate_RenderTargetable, RenderTargetsInfo);
			RenderTargetsInfo.NumSamples = 1;
			SetupDepthStencilInfo(PF_DepthStencil, TexCreate_DepthStencilTargetable | TexCreate_Memoryless, ERenderTargetLoadAction::ENoAction, ERenderTargetLoadAction::EClear, AlphaMask ? FExclusiveDepthStencil::DepthWrite_StencilWrite : FExclusiveDepthStencil::DepthRead_StencilWrite, RenderTargetsInfo);

			AddPSOInitializer(DepthStencilState, BlendStateWorldUI, RasterizerState,
				VertexShader, VertexDeclaration, PixelShader,
				RenderTargetsInfo,
				PSOCollectorIndex, PSOInitializers);
		}
		else
		{
			static const auto CVarDefaultBackBufferPixelFormat = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.DefaultBackBufferPixelFormat"));
			EPixelFormat SceneTargetFormat = EDefaultBackBufferPixelFormat::Convert2PixelFormat(EDefaultBackBufferPixelFormat::FromInt(CVarDefaultBackBufferPixelFormat->GetValueOnAnyThread()));
			SceneTargetFormat = RHIPreferredPixelFormatHint(SceneTargetFormat);
				
			FGraphicsPipelineRenderTargetsInfo RenderTargetsInfo;
			AddRenderTargetInfo(SceneTargetFormat, TexCreate_RenderTargetable, RenderTargetsInfo);
			RenderTargetsInfo.NumSamples = 1;
			SetupDepthStencilInfo(PF_DepthStencil, TexCreate_DepthStencilTargetable | TexCreate_Memoryless, ERenderTargetLoadAction::ENoAction, ERenderTargetLoadAction::EClear, FExclusiveDepthStencil::DepthNop_StencilWrite, RenderTargetsInfo);

			AddPSOInitializer(DepthStencilState, BlendState, RasterizerState,
				VertexShader, VertexDeclaration, PixelShader,
				RenderTargetsInfo,
				PSOCollectorIndex, PSOInitializers);

			if (GRHISupportsHDROutput && GRHIHDRDisplayOutputFormat != SceneTargetFormat)
			{
				RenderTargetsInfo.RenderTargetFormats[0] = GRHIHDRDisplayOutputFormat;
				AddPSOInitializer(DepthStencilState, BlendState, RasterizerState,
					VertexShader, VertexDeclaration, PixelShader,
					RenderTargetsInfo,
					PSOCollectorIndex, PSOInitializers);
			}
		}

		if (!GammaCorrection)
		{
			{
				FGraphicsPipelineRenderTargetsInfo RenderTargetsInfo;
				AddRenderTargetInfo(PF_R8G8B8A8, TexCreate_RenderTargetable | TexCreate_ShaderResource | (IsLinearColor ? TexCreate_SRGB : TexCreate_None), RenderTargetsInfo);
				RenderTargetsInfo.NumSamples = 1;
				SetupDepthStencilInfo(PF_DepthStencil, TexCreate_DepthStencilTargetable | TexCreate_Memoryless, ERenderTargetLoadAction::ENoAction, ERenderTargetLoadAction::EClear, FExclusiveDepthStencil::DepthNop_StencilWrite, RenderTargetsInfo);

				AddPSOInitializer(DepthStencilState, BlendState, RasterizerState,
					VertexShader, VertexDeclaration, PixelShader,
					RenderTargetsInfo,
					PSOCollectorIndex, PSOInitializers);
			}

			{
				FGraphicsPipelineRenderTargetsInfo RenderTargetsInfo;
				AddRenderTargetInfo(PF_R8G8B8A8, TexCreate_RenderTargetable | TexCreate_ShaderResource | (IsLinearColor ? TexCreate_SRGB : TexCreate_None), RenderTargetsInfo);
				RenderTargetsInfo.NumSamples = 1;

				AddPSOInitializer(DepthStencilState, BlendState, RasterizerState,
					VertexShader, VertexDeclaration, PixelShader,
					RenderTargetsInfo,
					PSOCollectorIndex, PSOInitializers);
			}
		}
	}
}

void NoesisGlobalPSOCollector(const FSceneTexturesConfig& SceneTexturesConfig, int32 PSOCollectorIndex, TArray<FPSOPrecacheData>& PSOInitializers)
{
	FGlobalShaderMap* ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	UE::StereoRenderUtils::FStereoShaderAspects Aspects(SceneTexturesConfig.ShaderPlatform);
	for (int32 PermutationIdx = 0; PermutationIdx < FNoesisPS::FPermutationDomain::PermutationCount; PermutationIdx++)
	{
		FNoesisPS::FPermutationDomain Permutation(PermutationIdx);
		const bool GammaCorrection = Permutation.Get<FNoesisPS::FGammaCorrection>();
		const bool LinearColor = Permutation.Get<FNoesisPS::FLinearColor>();
		const bool AlphaMask = Permutation.Get<FNoesisPS::FAlphaMask>();
		const Noesis::Shader::Enum ShaderCode = (Noesis::Shader::Enum)Permutation.Get<FNoesisPS::FEffect>();

		if (!ShaderMap->HasShader(&FNoesisPS::GetStaticType(), PermutationIdx))
		{
			continue;
		}

		if (LinearColor && GammaCorrection)
		{
			continue;
		}

		TShaderRef<FNoesisPS> PixelShader = ShaderMap->GetShader<FNoesisPS>(Permutation);
		for (bool SinglePassStereo : { false, true })
		{
			for (uint32 StateCode = 0; StateCode < 256; StateCode++)
			{
				AddPSOInitializers(ShaderMap, SceneTexturesConfig, ShaderCode, StateCode, PixelShader.GetPixelShader(), LinearColor, SinglePassStereo, GammaCorrection, AlphaMask, PSOCollectorIndex, PSOInitializers);
			}

			if (!Aspects.IsInstancedStereoEnabled())
			{
				break;
			}
		}
	}
}

// If this is enabled, FGlobalPSOCollectorManager::MaxPSOCollectorCount needs to be increased because Unreal already registers
// the default 4
constexpr static bool HasExtendedCollectorCount = FGlobalPSOCollectorManager::MaxPSOCollectorCount > 4;
std::conditional_t<HasExtendedCollectorCount, FRegisterGlobalPSOCollectorFunction, TTuple<GlobalPSOCollectorFunction , const TCHAR*>> RegisterNoesisGlobalPSOCollector(&NoesisGlobalPSOCollector, NoesisGlobalPSOCollectorName);

class FNoesisMaterialPSOCollector : public IPSOCollector
{
public:
	FNoesisMaterialPSOCollector(ERHIFeatureLevel::Type InFeatureLevel) :
		IPSOCollector(FPSOCollectorCreateManager::GetIndex(GetFeatureLevelShadingPath(InFeatureLevel), NoesisMaterialPSOCollectorName)),
		FeatureLevel(InFeatureLevel)
	{
	}

	virtual void CollectPSOInitializers(
		const FSceneTexturesConfig& SceneTexturesConfig,
		const FMaterial& Material,
		const FPSOPrecacheVertexFactoryData& VertexFactoryData,
		const FPSOPrecacheParams& PreCacheParams,
		TArray<FPSOPrecacheData>& PSOInitializers
	) override final;

private:

	ERHIFeatureLevel::Type FeatureLevel;
};

void FNoesisMaterialPSOCollector::CollectPSOInitializers(
	const FSceneTexturesConfig& SceneTexturesConfig,
	const FMaterial& Material,
	const FPSOPrecacheVertexFactoryData& VertexFactoryData,
	const FPSOPrecacheParams& PreCacheParams,
	TArray<FPSOPrecacheData>& PSOInitializers
)
{
	if (VertexFactoryData.VertexFactoryType != &FLocalVertexFactory::StaticType)
		return;

	if (Material.IsUIMaterial() || Material.IsPostProcessMaterial())
	{
		UE::StereoRenderUtils::FStereoShaderAspects Aspects(SceneTexturesConfig.ShaderPlatform);
		FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);

		if (Material.IsPostProcessMaterial())
		{
			for (int32 PermutationIdx = 0; PermutationIdx < FNoesisCustomEffectPS::FPermutationDomain::PermutationCount; PermutationIdx++)
			{
				FNoesisCustomEffectPS::FPermutationDomain Permutation(PermutationIdx);
				const bool GammaCorrection = Permutation.Get<FNoesisCustomEffectPS::FGammaCorrection>();
				const bool AlphaMask = Permutation.Get<FNoesisCustomEffectPS::FAlphaMask>();
				TShaderRef<FNoesisCustomEffectPS> PixelShader = GetMaterialPixelShader<FNoesisCustomEffectPS>(Material, Permutation);
				if (!PixelShader.IsValid())
				{
					continue;
				}

				for (bool LinearColor : { false, true })
				{
					if (LinearColor && GammaCorrection)
						continue;

					for (bool SinglePassStereo : { false, true })
					{
						for (uint32 StateCode = 0; StateCode < 256; StateCode++)
						{
							AddPSOInitializers(GlobalShaderMap, SceneTexturesConfig, Noesis::Shader::Custom_Effect, StateCode, PixelShader.GetPixelShader(), LinearColor, SinglePassStereo, GammaCorrection, AlphaMask, PSOCollectorIndex, PSOInitializers);
						}

						if (!Aspects.IsInstancedStereoEnabled())
						{
							break;
						}
					}
				}
			}
		}
		else if (Material.IsUIMaterial())
		{
			for (int32 PermutationIdx = 0; PermutationIdx < FNoesisMaterialPS::FPermutationDomain::PermutationCount; PermutationIdx++)
			{
				FNoesisMaterialPS::FPermutationDomain Permutation(PermutationIdx);
				const bool GammaCorrection = Permutation.Get<FNoesisMaterialPS::FGammaCorrection>();
				const bool AlphaMask = Permutation.Get<FNoesisMaterialPS::FAlphaMask>();
				const bool LinearColor = Permutation.Get<FNoesisMaterialPS::FLinearColor>();
				const Noesis::Shader::Enum ShaderCode = (Noesis::Shader::Enum)Permutation.Get<FNoesisMaterialPS::FEffect>();

				TShaderRef<FNoesisMaterialPS> PixelShader = GetMaterialPixelShader<FNoesisMaterialPS>(Material, Permutation);
				if (!PixelShader.IsValid())
				{
					continue;
				}

				if (LinearColor && GammaCorrection)
					continue;

				for (bool SinglePassStereo : { false, true })
				{
					for (uint32 StateCode = 0; StateCode < 256; StateCode++)
					{
						AddPSOInitializers(GlobalShaderMap, SceneTexturesConfig, ShaderCode, StateCode, PixelShader.GetPixelShader(), LinearColor, SinglePassStereo, GammaCorrection, AlphaMask, PSOCollectorIndex, PSOInitializers);
					}

					if (!Aspects.IsInstancedStereoEnabled())
					{
						break;
					}
				}
			}
		}
	}
}

IPSOCollector* CreateNoesisMaterialPSOCollector(ERHIFeatureLevel::Type FeatureLevel)
{
	return new FNoesisMaterialPSOCollector(FeatureLevel);
}

FRegisterPSOCollectorCreateFunction RegisterNoesisMaterialPSOCollector(&CreateNoesisMaterialPSOCollector, EShadingPath::Deferred, NoesisMaterialPSOCollectorName);
#endif
