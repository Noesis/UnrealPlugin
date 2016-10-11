////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiInstance.h"

// NoesisGui includes
#include "NoesisGuiBlueprintGeneratedClass.h"
#include "NoesisGuiWidget.h"
#include "Render/NoesisGuiRenderDevice.h"
#include "NoesisGuiModule.h"
#include "NoesisGuiCreateClass.h"
#include "NoesisGuiCreateInterface.h"

UNoesisGuiInstance::UNoesisGuiInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInstance::InitInstance()
{
	ULocalPlayer* Player = 0;
	int32 ZOrder = 0;

	UNoesisGuiBlueprintGeneratedClass* NoesisGuiBlueprintGeneratedClass = CastChecked<UNoesisGuiBlueprintGeneratedClass>(GetClass());
	check(NoesisGuiBlueprintGeneratedClass);
	BaseXaml = NoesisGuiBlueprintGeneratedClass->BaseXaml;

	INoesisGuiModuleInterface::Get()->SetResourceProvider(BaseXaml);
	Xaml = Noesis::GUI::LoadXaml<Noesis::FrameworkElement>(StringCast<NsChar>(*(BaseXaml->GetPathName() + TEXT(".xaml"))).Get());

	if (Xaml)
	{
		NoesisGuiRenderDevice = new FNoesisGuiRenderDevice();
		Noesis::Gui::VGOptions VgOptions;
		VgOptions.offscreenWidth = 1024;
		VgOptions.offscreenHeight = 1024;
		VgOptions.offscreenSampleCount = 1;
		VgOptions.offscreenDefaultNumSurfaces = 1;
		VgOptions.offscreenMaxNumSurfaces = 2;
		VgOptions.glyphCacheTextureWidth = 1024;
		VgOptions.glyphCacheTextureHeight = 1024;
		VgOptions.glyphCacheMeshTreshold = 1024;
		VgContext = Noesis::GUI::CreateVGContext(NoesisGuiRenderDevice, VgOptions);
		XamlView = Noesis::GUI::CreateView(Xaml.GetPtr());
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Init(VgContext.GetPtr());

		TSharedRef<SWidget> NoesisGuiWidget = SNew(SNoesisGuiWidget).NoesisGuiInstance(this);

		// If this is a game world add the widget to the current worlds viewport.
		UWorld* World = GetWorld();
		if (World && World->IsGameWorld())
		{
			if (UGameViewportClient* ViewportClient = World->GetGameViewport())
			{
				if (Player)
				{
					ViewportClient->AddViewportWidgetForPlayer(Player, NoesisGuiWidget, ZOrder);
				}
				else
				{
					// We add 10 to the zorder when adding to the viewport to avoid 
					// displaying below any built-in controls, like the virtual joysticks on mobile builds.
					ViewportClient->AddViewportWidgetContent(NoesisGuiWidget, ZOrder + 10);
				}

				//// Just in case we already hooked this delegate, remove the handler.
				//FWorldDelegates::LevelRemovedFromWorld.RemoveAll(this);

				//// Widgets added to the viewport are automatically removed if the persistent level is unloaded.
				//FWorldDelegates::LevelRemovedFromWorld.AddUObject(this, &UUserWidget::OnLevelRemovedFromWorld);
			}
		}

		NoesisGuiBlueprintGeneratedClass->InitInstance(this);

		EventInitInstance();
	}
}

void UNoesisGuiInstance::Update(float InLeft, float InTop, float InWidth, float InHeight)
{
	Left = InLeft;
	Top = InTop;
	Width = InWidth;
	Height = InHeight;
	if (Xaml && VgContext && XamlView && NoesisGuiRenderDevice)
	{
		XamlView->SetSize(Width, Height);
		XamlView->Update(GWorld->GetTimeSeconds());
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->UpdateRenderTree();
	}
}

void UNoesisGuiInstance::DrawOffscreen_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	// Rendering triggers loads.
	UNoesisGuiBlueprintGeneratedClass* NoesisGuiBlueprintGeneratedClass = CastChecked<UNoesisGuiBlueprintGeneratedClass>(GetClass());
	check(NoesisGuiBlueprintGeneratedClass);

	NoesisGuiRenderDevice->RHICmdList = &RHICmdList;
	Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
	if (Renderer->NeedsOffscreen())
	{
		Renderer->RenderOffscreen();
	}
	NoesisGuiRenderDevice->RHICmdList = 0;
}

void UNoesisGuiInstance::Draw_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	// Rendering triggers loads.
	UNoesisGuiBlueprintGeneratedClass* NoesisGuiBlueprintGeneratedClass = CastChecked<UNoesisGuiBlueprintGeneratedClass>(GetClass());
	check(NoesisGuiBlueprintGeneratedClass);

	NoesisGuiRenderDevice->RHICmdList = &RHICmdList;
	Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
	RHICmdList.SetViewport(Left, Top, 0.0f, Left + Width, Top + Height, 1.0f);
	Renderer->Render();
	NoesisGuiRenderDevice->RHICmdList = 0;
}

void UNoesisGuiInstance::MouseButtonDown(FVector2D Position, FKey Button)
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

void UNoesisGuiInstance::MouseButtonUp(FVector2D Position, FKey Button)
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

void UNoesisGuiInstance::MouseDoubleClick(FVector2D Position, FKey Button)
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

void UNoesisGuiInstance::MouseMove(FVector2D Position)
{
	if (XamlView)
	{
		XamlView->MouseMove(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y));
	}
}

void UNoesisGuiInstance::MouseWheel(FVector2D Position, float WheelDelta)
{
	if (XamlView)
	{
		XamlView->MouseWheel(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), FPlatformMath::RoundToInt(WheelDelta));
	}
}

void UNoesisGuiInstance::KeyDown(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyDown((Noesis::Gui::Key)Key);
	}
}

void UNoesisGuiInstance::KeyUp(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyUp((Noesis::Gui::Key)Key);
	}
}

void UNoesisGuiInstance::Char(TCHAR Character)
{
	if (XamlView)
	{
		XamlView->Char(CharCast<NsChar>(Character));
	}
}

FVector2D UNoesisGuiInstance::GetSize() const
{
	if (Xaml)
	{
		return FVector2D(Xaml->GetActualWidth(), Xaml->GetActualHeight());
	}
	return FVector2D();
}

void UNoesisGuiInstance::SetComponentFor(Noesis::Core::BaseComponent* NoesisComponent, UNoesisGuiBaseComponent* UnrealComponent)
{
	UnrealComponent->SetNoesisComponent(NoesisComponent);
	UnrealComponent->Instance = this;
	ComponentMap.Add(NoesisComponent, UnrealComponent);
}

UNoesisGuiBaseComponent* UNoesisGuiInstance::FindUnrealComponentForNoesisComponent(const Noesis::Core::BaseComponent* NoesisComponent)
{
	UNoesisGuiBaseComponent** UnrealComponentPtr = ComponentMap.Find(NoesisComponent);
	if (UnrealComponentPtr)
		return *UnrealComponentPtr;

	UNoesisGuiBaseComponent* UnrealComponent = CreateClassFor((Noesis::Core::BaseComponent*)NoesisComponent, this);
	SetComponentFor((Noesis::Core::BaseComponent*)NoesisComponent, UnrealComponent);
	CreatedComponents.Add(UnrealComponent);
	return UnrealComponent;
}

UNoesisGuiBaseComponent* UNoesisGuiInstance::FindUnrealComponentForNoesisComponent(const Noesis::Core::Ptr<Noesis::Core::BaseComponent> NoesisComponent)
{
	UNoesisGuiBaseComponent** UnrealComponentPtr = ComponentMap.Find(NoesisComponent.GetPtr());
	if (UnrealComponentPtr)
		return *UnrealComponentPtr;

	UNoesisGuiBaseComponent* UnrealComponent = CreateClassFor((Noesis::Core::BaseComponent*)NoesisComponent.GetPtr(), this);
	SetComponentFor((Noesis::Core::BaseComponent*)NoesisComponent.GetPtr(), UnrealComponent);
	CreatedComponents.Add(UnrealComponent);
	return UnrealComponent;
}

void UNoesisGuiInstance::SetInterfaceFor(Noesis::Core::Interface* NoesisInterface, UNoesisGuiInterface* UnrealInterface)
{
	UnrealInterface->SetNoesisInterface(NoesisInterface);
	UnrealInterface->Instance = this;
	InterfaceMap.Add(NoesisInterface, UnrealInterface);
}

UNoesisGuiInterface* UNoesisGuiInstance::FindUnrealInterfaceForNoesisInterface(const Noesis::Core::Interface* NoesisInterface)
{
	UNoesisGuiInterface** UnrealInterfacePtr = InterfaceMap.Find(NoesisInterface);
	if (UnrealInterfacePtr)
		return *UnrealInterfacePtr;

	UNoesisGuiInterface* UnrealInterface = CreateInterfaceFor((Noesis::Core::Interface*)NoesisInterface, this);
	SetInterfaceFor((Noesis::Core::Interface*)NoesisInterface, UnrealInterface);
	CreatedInterfaces.Add(UnrealInterface);
	return UnrealInterface;
}

UNoesisGuiInterface* UNoesisGuiInstance::FindUnrealInterfaceForNoesisInterface(const Noesis::Core::Ptr<Noesis::Core::Interface> NoesisInterface)
{
	UNoesisGuiInterface** UnrealInterfacePtr = InterfaceMap.Find(NoesisInterface.GetPtr());
	if (UnrealInterfacePtr)
		return *UnrealInterfacePtr;

	UNoesisGuiInterface* UnrealInterface = CreateInterfaceFor((Noesis::Core::Interface*)NoesisInterface.GetPtr(), this);
	SetInterfaceFor((Noesis::Core::Interface*)NoesisInterface.GetPtr(), UnrealInterface);
	CreatedInterfaces.Add(UnrealInterface);
	return UnrealInterface;
}

class UWorld* UNoesisGuiInstance::GetWorld() const
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

void UNoesisGuiInstance::BeginDestroy()
{
	Super::BeginDestroy();

	if (NoesisGuiRenderDevice)
	{
		Noesis::Gui::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Shutdown();
		NoesisGuiRenderDevice->Release();
		NoesisGuiRenderDevice = nullptr;
		XamlView.Reset();
		VgContext.Reset();
		Xaml.Reset();
	}
}
