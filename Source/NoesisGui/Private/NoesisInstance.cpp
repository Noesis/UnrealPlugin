////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisInstance.h"

// NoesisGui includes
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisWidget.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisGuiModule.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

UNoesisInstance::UNoesisInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisInstance::InitInstance()
{
	ULocalPlayer* Player = 0;
	int32 ZOrder = 0;

	UNoesisBlueprintGeneratedClass* NoesisBlueprintGeneratedClass = CastChecked<UNoesisBlueprintGeneratedClass>(GetClass());
	check(NoesisBlueprintGeneratedClass);
	BaseXaml = NoesisBlueprintGeneratedClass->BaseXaml;

	if (!BaseXaml)
		return;

	Xaml = Noesis::GUI::LoadXaml<Noesis::FrameworkElement>(StringCast<NsChar>(*(FString::FromInt(BaseXaml->GetUniqueID()) / BaseXaml->GetName() + TEXT(".xaml"))).Get());

	if (Xaml)
	{
		RenderDevice = new FNoesisRenderDevice();
		Noesis::Gui::VGOptions VgOptions;
		VgOptions.offscreenWidth = 1024;
		VgOptions.offscreenHeight = 1024;
		VgOptions.offscreenSampleCount = 1;
		VgOptions.offscreenDefaultNumSurfaces = 1;
		VgOptions.offscreenMaxNumSurfaces = 2;
		VgOptions.glyphCacheTextureWidth = 1024;
		VgOptions.glyphCacheTextureHeight = 1024;
		VgOptions.glyphCacheMeshTreshold = 1024;
		VgContext = Noesis::GUI::CreateVGContext(RenderDevice, VgOptions);
		XamlView = Noesis::GUI::CreateView(Xaml.GetPtr());
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Init(VgContext.GetPtr());

		NoesisBlueprintGeneratedClass->InitComponents(this);

		EventInitInstance();
	}
}

void UNoesisInstance::Update(float InLeft, float InTop, float InWidth, float InHeight)
{
	Left = InLeft;
	Top = InTop;
	Width = InWidth;
	Height = InHeight;
	if (Xaml && VgContext && XamlView && RenderDevice)
	{
		XamlView->SetSize(Width, Height);
		XamlView->Update(GWorld->GetTimeSeconds());
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->UpdateRenderTree();
	}
}

void UNoesisInstance::DrawOffscreen_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	if (RenderDevice)
	{
		// Rendering triggers loads.
		UNoesisBlueprintGeneratedClass* NoesisBlueprintGeneratedClass = CastChecked<UNoesisBlueprintGeneratedClass>(GetClass());
		check(NoesisBlueprintGeneratedClass);

		RenderDevice->RHICmdList = &RHICmdList;
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		if (Renderer->NeedsOffscreen())
		{
			Renderer->RenderOffscreen();
		}
		RenderDevice->RHICmdList = 0;
	}
}

void UNoesisInstance::Draw_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	if (RenderDevice)
	{
		// Rendering triggers loads.
		UNoesisBlueprintGeneratedClass* NoesisBlueprintGeneratedClass = CastChecked<UNoesisBlueprintGeneratedClass>(GetClass());
		check(NoesisBlueprintGeneratedClass);

		RenderDevice->RHICmdList = &RHICmdList;
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		RHICmdList.SetViewport(Left, Top, 0.0f, Left + Width, Top + Height, 1.0f);
		Renderer->Render();
		RenderDevice->RHICmdList = 0;
	}
}

void UNoesisInstance::MouseButtonDown(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
		Noesis::Gui::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::Gui::MouseButton_XButton2;
		}
		XamlView->MouseButtonDown(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);
	}
}

void UNoesisInstance::MouseButtonUp(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
		Noesis::Gui::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::Gui::MouseButton_XButton2;
		}
		XamlView->MouseButtonUp(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);
	}
}

void UNoesisInstance::MouseDoubleClick(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
		Noesis::Gui::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::Gui::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::Gui::MouseButton_XButton2;
		}
		XamlView->MouseDoubleClick(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);
	}
}

void UNoesisInstance::MouseMove(FVector2D Position)
{
	if (XamlView)
	{
		XamlView->MouseMove(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y));
	}
}

void UNoesisInstance::MouseWheel(FVector2D Position, float WheelDelta)
{
	if (XamlView)
	{
		XamlView->MouseWheel(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), FPlatformMath::RoundToInt(WheelDelta));
	}
}

void UNoesisInstance::KeyDown(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyDown((Noesis::Gui::Key)Key);
	}
}

void UNoesisInstance::KeyUp(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyUp((Noesis::Gui::Key)Key);
	}
}

void UNoesisInstance::Char(TCHAR Character)
{
	if (XamlView)
	{
		XamlView->Char(CharCast<NsChar>(Character));
	}
}

FVector2D UNoesisInstance::GetSize() const
{
	if (Xaml)
	{
		return FVector2D(Xaml->GetActualWidth(), Xaml->GetActualHeight());
	}
	return FVector2D();
}

class UWorld* UNoesisInstance::GetWorld() const
{
	UObject* Outer = GetOuter();

	while (Outer)
	{
		UWorld* World = Outer->GetWorld();
		if (World)
		{
			return World;
		}

		Outer = Outer->GetOuter();
	}

	return 0;
}

void UNoesisInstance::BeginDestroy()
{
	Super::BeginDestroy();

	if (RenderDevice)
	{
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Shutdown();
		RenderDevice->Release();
		RenderDevice = nullptr;
		XamlView.Reset();
		VgContext.Reset();
		Xaml.Reset();
	}
}

void UNoesisInstance::InitializeNativeClassData()
{
	Super::InitializeNativeClassData();

	InitInstance();
}

TSharedRef<SWidget> UNoesisInstance::RebuildWidget()
{
	return SNew(SNoesisWidget).NoesisInstance(this);
}
