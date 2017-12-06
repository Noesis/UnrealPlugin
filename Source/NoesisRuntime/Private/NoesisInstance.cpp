////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisInstance.h"

// NoesisRuntime includes
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisWidget.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"

UNoesisInstance::UNoesisInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisInstance::InitInstance()
{
	ULocalPlayer* Player = 0;
	int32 ZOrder = 0;

	if (!BaseXaml)
	{
		UNoesisBlueprintGeneratedClass* NoesisBlueprintGeneratedClass = CastChecked<UNoesisBlueprintGeneratedClass>(GetClass());
		check(NoesisBlueprintGeneratedClass);
		BaseXaml = NoesisBlueprintGeneratedClass->BaseXaml;
		EnablePPAA = NoesisBlueprintGeneratedClass->EnablePPAA;
		TessellationQuality = NoesisBlueprintGeneratedClass->TessellationQuality;

		if (!BaseXaml)
			return;
	}

	Noesis::Ptr<Noesis::BaseComponent> DataContext = Noesis::Ptr<Noesis::BaseComponent>(NoesisCreateComponentForUObject(this));

	Xaml.Reset(NsDynamicCast<Noesis::FrameworkElement*>(BaseXaml->LoadXaml().GetPtr()));

	if (Xaml)
	{
		Xaml->SetDataContext(DataContext.GetPtr());

		XamlView = Noesis::GUI::CreateView(Xaml.GetPtr());

		if (XamlView)
		{
			Noesis::IRenderer* Renderer = XamlView->GetRenderer();
			Renderer->Init(FNoesisRenderDevice::Get());

			StartTime = GetTimeSeconds();

			EventInitInstance();
		}
	}
}

void UNoesisInstance::SetDataContext(UObject* InDataContext)
{
	if (Xaml)
	{
		Noesis::Ptr<Noesis::BaseComponent> DataContext = Noesis::Ptr<Noesis::BaseComponent>(NoesisCreateComponentForUObject(InDataContext));

		Xaml->SetDataContext(DataContext.GetPtr());
	}
}

UObject* UNoesisInstance::FindName(FString Name)
{
	Noesis::BaseComponent* Component = Xaml->FindName(TCHARToNsString(*Name).c_str());
	return NoesisCreateUObjectForComponent(Component);
}

UObject* UNoesisInstance::FindResource(FString Name)
{
	Noesis::Ptr<Noesis::ResourceKeyString> Key = Noesis::ResourceKeyString::Create(TCHARToNsString(*Name).c_str());
	Noesis::BaseComponent* Resource = Xaml->FindResource(Key.GetPtr());
	return NoesisCreateUObjectForComponent(Resource);
}

float UNoesisInstance::GetTimeSeconds() const
{
	APlayerController* OwningPlayer = GetOwningPlayer();
	if (OwningPlayer)
	{
		UWorld* World = OwningPlayer->GetWorld();
		if (World)
		{
			return World->GetTimeSeconds();
		}
	}

	if (GWorld)
	{
		return GWorld->GetTimeSeconds();
	}

	return -1.f;
}

void UNoesisInstance::ExecuteConsoleCommand(FString Command, class APlayerController* SpecificPlayer)
{
	APlayerController* TargetPC = SpecificPlayer;
	if (!TargetPC)
	{
		APlayerController* OwningPlayer = GetOwningPlayer();
		if (OwningPlayer)
		{
			UWorld* World = OwningPlayer->GetWorld();
			if (World)
			{
				TargetPC = World->GetFirstPlayerController();
			}
		}
	}

	if (TargetPC)
	{
		TargetPC->ConsoleCommand(*Command);
	}
}

void UNoesisInstance::Update(float InLeft, float InTop, float InWidth, float InHeight)
{
	Left = InLeft;
	Top = InTop;
	Width = InWidth;
	Height = InHeight;
	if (Xaml && XamlView)
	{
		XamlView->SetSize(Width, Height);
		XamlView->SetIsPPAAEnabled(EnablePPAA);
		XamlView->SetTessellationQuality((Noesis::TessellationQuality)TessellationQuality);
		XamlView->SetFlags((uint32)RenderFlags);
		XamlView->Update(GetTimeSeconds() - StartTime);
	}
}

void UNoesisInstance::DrawOffscreen_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	if (XamlView)
	{
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->UpdateRenderTree();
		if (Renderer->NeedsOffscreen())
		{
			Renderer->RenderOffscreen();
		}
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);
	}
}

void UNoesisInstance::Draw_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget)
{
	if (XamlView)
	{
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(&RHICmdList);
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		RHICmdList.SetViewport(Left, Top, 0.0f, Left + Width, Top + Height, 1.0f);
		Renderer->Render();
		FNoesisRenderDevice::ThreadLocal_SetRHICmdList(nullptr);
	}
}

void UNoesisInstance::MouseButtonDown(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
		Noesis::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::MouseButton_XButton2;
		}
		XamlView->MouseButtonDown(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);
	}
}

void UNoesisInstance::MouseButtonUp(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
		Noesis::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::MouseButton_XButton2;
		}
		XamlView->MouseButtonUp(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), MouseButton);
	}
}

void UNoesisInstance::MouseDoubleClick(FVector2D Position, FKey Button)
{
	if (XamlView)
	{
		Noesis::MouseButton MouseButton;
		if (Button == EKeys::LeftMouseButton)
		{
			MouseButton = Noesis::MouseButton_Left;
		}
		else if (Button == EKeys::RightMouseButton)
		{
			MouseButton = Noesis::MouseButton_Right;
		}
		else if (Button == EKeys::MiddleMouseButton)
		{
			MouseButton = Noesis::MouseButton_Middle;
		}
		else if (Button == EKeys::ThumbMouseButton)
		{
			MouseButton = Noesis::MouseButton_XButton1;
		}
		else
		{
			MouseButton = Noesis::MouseButton_XButton2;
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
		XamlView->MouseWheel(FPlatformMath::RoundToInt(Position.X), FPlatformMath::RoundToInt(Position.Y), FPlatformMath::RoundToInt(WheelDelta * 120.f));
	}
}

void UNoesisInstance::KeyDown(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyDown((Noesis::Key)Key);
	}
}

void UNoesisInstance::KeyUp(uint32 Key)
{
	if (XamlView)
	{
		XamlView->KeyUp((Noesis::Key)Key);
	}
}

void UNoesisInstance::Char(TCHAR Character)
{
	if (XamlView)
	{
		XamlView->Char(CharCast<char>(Character));
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

	if (XamlView)
	{
		Noesis::IRenderer* Renderer = XamlView->GetRenderer();
		Renderer->Shutdown();
		XamlView.Reset();
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
