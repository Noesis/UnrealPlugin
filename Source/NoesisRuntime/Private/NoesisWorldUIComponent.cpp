////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisWorldUIComponent.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

// UMG includes
#include "Blueprint/UserWidget.h"

// Engine includes
#include "PrimitiveSceneProxy.h"
#if UE_VERSION_OLDER_THAN(5, 6, 0)
#else
#include "MeshElementCollector.h"
#include "PrimitiveDrawingUtils.h"
#endif
#include "DynamicMeshBuilder.h"
#include "Materials/Material.h"
#include "MaterialDomain.h"
#include "SceneManagement.h"
#include "Rendering/PositionVertexBuffer.h"
#include "LocalVertexFactory.h"
#include "SceneInterface.h"

// RenderCore includes
#include "GlobalRenderResources.h"

// RHI includes
#include "RHIResourceUtils.h"

// NoesisRuntime includes
#include "NoesisSupport.h"
#include "NoesisTypeClass.h"
#include "NoesisXaml.h"
#include "NoesisSettings.h"

class FNoesisWorldUIIndexBuffer : public FIndexBuffer
{
public:
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
	{
		IndexBufferRHI = UE::RHIResourceUtils::CreateIndexBufferFromArray(RHICmdList, TEXT("FNoesisWorldUIIndexBuffer"),
			EBufferUsageFlags::Static, MakeConstArrayView<uint16>({ 0, 0, 0 }));
	}
};

TGlobalResource<FNoesisWorldUIIndexBuffer, FRenderResource::EInitPhase::Pre> GNoesisWorldUIIndexBuffer;

class FNoesisWorldUISceneProxy final : public FPrimitiveSceneProxy
{
public:
	FNoesisWorldUISceneProxy(const UNoesisWorldUIComponent* InComponent)
		: FPrimitiveSceneProxy(InComponent),
		  VertexFactory(GetScene().GetFeatureLevel(), "FNoesisWorldUISceneProxy")
	{
		bAlwaysHasVelocity = GetDefault<UNoesisSettings>()->UpdateVelocities;

		FMeshBatchElement& BatchElement = Mesh.Elements[0];
		BatchElement.IndexBuffer = &GNoesisWorldUIIndexBuffer;
		Mesh.VertexFactory = &VertexFactory;
		Mesh.MaterialRenderProxy = UMaterial::GetDefaultMaterial(MD_Surface)->GetRenderProxy();
		BatchElement.FirstIndex = 0;
		BatchElement.NumPrimitives = 1;
		BatchElement.MinVertexIndex = 0;
		BatchElement.MaxVertexIndex = 0;
		Mesh.ReverseCulling = IsLocalToWorldDeterminantNegative();
		Mesh.bDisableBackfaceCulling = false;
		Mesh.Type = PT_TriangleList;
		Mesh.DepthPriorityGroup = SDPG_World;
		Mesh.LODIndex = 0;
	}

	virtual void CreateRenderThreadResources(FRHICommandListBase& RHICmdList) override
	{
		FLocalVertexFactory::FDataType Data;
		Data.PositionComponent = FVertexStreamComponent(&GNullVertexBuffer, 0, 12, VET_Float3);
		Data.ColorComponent = FVertexStreamComponent(&GNullColorVertexBuffer, 0, 0, VET_Color, EVertexStreamUsage::ManualFetch);
		Data.TangentBasisComponents[0] = FVertexStreamComponent(&GNullColorVertexBuffer, 0, 0, VET_PackedNormal, EVertexStreamUsage::ManualFetch);
		Data.TangentBasisComponents[1] = FVertexStreamComponent(&GNullColorVertexBuffer, 0, 0, VET_PackedNormal, EVertexStreamUsage::ManualFetch);

		if (RHISupportsManualVertexFetch(GMaxRHIShaderPlatform))
		{
			Data.PositionComponentSRV = GNullVertexBuffer.VertexBufferSRV;
			Data.ColorComponentsSRV = GNullColorVertexBuffer.VertexBufferSRV;
			Data.TangentsSRV = GNullColorVertexBuffer.VertexBufferSRV;
			Data.TextureCoordinatesSRV = GNullColorVertexBuffer.VertexBufferSRV;
		}
		VertexFactory.SetData(RHICmdList, Data);
		VertexFactory.InitResource(RHICmdList);
	}
	virtual void DestroyRenderThreadResources() override
	{
		VertexFactory.ReleaseResource();
	}

	virtual void DrawStaticElements(FStaticPrimitiveDrawInterface* PDI) override
	{
		PDI->DrawMesh(Mesh, 1.0f);
	}

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View);
		Result.bStaticRelevance = true;
		Result.bVelocityRelevance = true;
		return Result;
	}

	virtual SIZE_T GetTypeHash() const override
	{
		static size_t UniquePointer;
		return reinterpret_cast<size_t>(&UniquePointer);
	}

	virtual uint32 GetMemoryFootprint(void) const override
	{
		return sizeof(*this) + GetAllocatedSize();
	}

	uint32 GetAllocatedSize(void) const
	{
		return FPrimitiveSceneProxy::GetAllocatedSize();
	}

private:
	FLocalVertexFactory VertexFactory;
	FMeshBatch Mesh;
};

UNoesisWorldUIComponent::UNoesisWorldUIComponent(): Xaml(nullptr), Scale(1.0f), Center(true)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UNoesisWorldUIComponent::Add3DElement()
{
	Element = Noesis::DynamicPtrCast<Noesis::FrameworkElement>(Xaml->LoadXaml());
	if (Element != nullptr)
	{
		Noesis::MatrixTransform3D* Transform3D = Noesis::DynamicCast<Noesis::MatrixTransform3D*>(Element->GetTransform3D());
		if (Transform3D == nullptr)
		{
			Transform3D = new Noesis::MatrixTransform3D();
			Element->SetTransform3D(Transform3D);
			Transform3D->Release();
		}
		TransformUpdatedDelegateHandle = TransformUpdated.AddUObject(this, &UNoesisWorldUIComponent::OnTransformUpdated);
		UNoesisInstance::Add3DElement(GetWorld(), Element);

		OnTransformUpdated(this, EUpdateTransformFlags::None, ETeleportType::None);
	}
}

void UNoesisWorldUIComponent::Remove3DElement()
{
	if (Element != nullptr)
	{
		UNoesisInstance::Remove3DElement(GetWorld(), Element);
		TransformUpdated.Remove(TransformUpdatedDelegateHandle);
		Element.Reset();
	}
}

FPrimitiveSceneProxy* UNoesisWorldUIComponent::CreateSceneProxy()
{
	return new FNoesisWorldUISceneProxy(this);
}

FBoxSphereBounds UNoesisWorldUIComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	return FBoxSphereBounds(ProxyBox.TransformBy(LocalToWorld));
}

void UNoesisWorldUIComponent::BeginPlay()
{
	Super::BeginPlay();

	Add3DElement();
}

void UNoesisWorldUIComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Remove3DElement();

	Super::EndPlay(EndPlayReason);
}

void UNoesisWorldUIComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FTransform Transform = GetComponentToWorld();
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	FVector MonoLocation;
	FRotator MonoRotation;
	PlayerController->GetPlayerViewPoint(MonoLocation, MonoRotation);
	FVector CameraForward = MonoRotation.RotateVector(FVector(-1.0f, 0.0f, 0.0f));
	int32 ZIndex = (int32)CameraForward.Dot(Transform.GetLocation() - MonoLocation);
	Element->SetValue<int32>(Noesis::Panel::ZIndexProperty, ZIndex);
}

void UNoesisWorldUIComponent::OnTransformUpdated(USceneComponent*, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	FTransform Transform = GetComponentToWorld();
	FMatrix Matrix = Transform.ToMatrixWithScale();

	/// Transform = BaseChange * UnrealTransform * Inverse(BaseChange), where
	/// BaseChange = Matrix4(
	///		 0.f, -1.f,  0.f, 0.f,
	///		 0.f,  0.f, -1.f, 0.f,
	///		-1.f,  0.f,  0.f, 0.f,
	///		 0.f,  0.f,  0.f, 1.f
	///	);
	/// BaseChange transforms from Unreal's coordinate system to what we need.
	/// Doing it this way we can skip a lot of multiplies by 0.0f and 1.0f.

	 Noesis::Transform3 NoesisTransform(
		 Matrix.M[1][1],  Matrix.M[1][2],  Matrix.M[1][0],
		 Matrix.M[2][1],  Matrix.M[2][2],  Matrix.M[2][0],
		 Matrix.M[0][1],  Matrix.M[0][2],  Matrix.M[0][0],
		-Matrix.M[3][1], -Matrix.M[3][2], -Matrix.M[3][0]
	);

	float OffsetX = 0.0f;
	float OffsetY = 0.0f;

	Element->Measure(Noesis::Size(FLT_INF, FLT_INF));
	auto& DesiredSize = Element->GetDesiredSize();

	if (Center)
	{
		Element->Measure(Noesis::Size(FLT_INF, FLT_INF));
		OffsetX = -0.5f * DesiredSize.width;
		OffsetY = -0.5f * DesiredSize.height;
	}

	Noesis::Transform3 OffsetScale = Noesis::Transform3::Trans(OffsetX, OffsetY, 0.0f) * Noesis::Transform3::Scale(Scale, Scale, Scale);

	Noesis::MatrixTransform3D* Transform3D = Noesis::DynamicCast<Noesis::MatrixTransform3D*>(Element->GetTransform3D());
	Transform3D->SetMatrix(OffsetScale * NoesisTransform);

	auto BoundsZMin = Noesis::VisualTreeHelper::GetDescendantBoundsMinZ(Element);
	auto BoundsZMax = Noesis::VisualTreeHelper::GetDescendantBoundsMaxZ(Element);

	FVector ProxyMin = { -BoundsZMin, OffsetX, OffsetY };
	FVector ProxyMax = { -BoundsZMax, DesiredSize.width + OffsetX, DesiredSize.height + OffsetY };
	ProxyBox = { ProxyMin, ProxyMax };

	UpdateBounds();
	MarkRenderStateDirty();
}

void UNoesisWorldUIComponent::SetDataContext(UObject* InDataContext)
{
	if (Element)
	{
		Noesis::Ptr<Noesis::BaseComponent> DataContext = NoesisCreateComponentForUObject(InDataContext);
		Element->SetDataContext(DataContext);
	}
}
