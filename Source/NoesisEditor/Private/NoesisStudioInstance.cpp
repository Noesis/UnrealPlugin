////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisStudioInstance.h"

// NoesisEditor includes
#include "NoesisStudioResourceProvider.h"

// NoesisRuntime includes
#include "NoesisTypeClass.h"
#include "NoesisSettings.h"

// UnrealEd includes
#include "ClassViewerProjectSettings.h"

// Engine includes
#include "AssetRegistry/AssetRegistryModule.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"
#include "UObject/UObjectIterator.h"
#include "Misc/PackageName.h"

// AssetRegistry includes
#include "AssetRegistry/AssetData.h"

// Slate includes
#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"

UNoesisStudioInstance::UNoesisStudioInstance(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
}

void UNoesisStudioInstance::InitInstance()
{
	EnablePPAA = true;
	Xaml = Noesis::MakePtr<Noesis::ContentControl>();
	InitView();
}

void UNoesisStudioInstance::Update()
{
	if (Xaml && XamlView)
	{
		Noesis::ContentControl* root = Noesis::DynamicCast<Noesis::ContentControl*>(XamlView->GetContent());
		if (root->GetContent() == nullptr)
		{
			// Creating the FileManager
			IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

			if (!FileManager.FileExists(*Options.ProjectPath))
			{
				UE_LOG(LogTemp, Warning, TEXT("Noesis Studio project file '%s' does not exist"), *Options.ProjectPath);
				return;
			}

			Noesis::Studio::Options options;
			options.GetXamlProvider = [](const char*, const char* path) -> Noesis::Ptr<Noesis::XamlProvider>
				{
					return Noesis::MakePtr<FNoesisStudioXamlProvider>(path);
				};
			options.GetTextureProvider = [](const char*, const char* path) -> Noesis::Ptr<Noesis::TextureProvider>
				{
					return Noesis::MakePtr<FNoesisStudioTextureProvider>(path);
				};
			options.GetFontProvider = [](const char*, const char* path) -> Noesis::Ptr<Noesis::FontProvider>
				{
					return Noesis::MakePtr<FNoesisStudioFontProvider>(path);
				};

			options.FileCreated = Options.FileCreated;
			options.FileWritten = Options.FileWritten;
			options.FileMoved = Options.FileMoved;
			options.SaveStateChanged = Options.SaveStateChanged;
			options.Exit = Options.Exit;

			Noesis::Ptr<Noesis::FrameworkElement> studioContent = Noesis::Studio::Create(
				TCHAR_TO_UTF8(*Options.ProjectPath), options);

			root->SetContent(studioContent);
		}

		XamlView->SetSize(Width, Height);

		float Scale = 1.0f;
		TSharedPtr<SWidget> SlateWidget = TakeWidget();
		if (SlateWidget.IsValid())
		{
			TSharedPtr<SWindow> CurrentWindow = FSlateApplication::Get().FindWidgetWindow(SlateWidget.ToSharedRef());
			if (CurrentWindow.IsValid())
			{
				Scale = FSlateApplication::Get().GetApplicationScale() * CurrentWindow->GetDPIScaleFactor();
			}
		}

		XamlView->SetScale(Scale);

		if (PixelDepthBias >= 0.f)
		{
			float D = PixelDepthBias / 1000.f;
			float W = D * Width;
			float H = D * Height;

			Noesis::Matrix4 Projection
			(
				PixelDepthBias,             0.0f, 0.0f, 0.0f,
				            0.0f, PixelDepthBias, 0.0f, 0.0f,
				        0.5f * W,         0.5f * H, 0.0f, D,
				            0.0f,             0.0f, 10.f, PixelDepthBias
			);

			XamlView->SetProjectionMatrix(Projection);
		}

		XamlView->SetTessellationMaxPixelError(Noesis::TessellationMaxPixelError::HighQuality());
		XamlView->SetFlags(Noesis::RenderFlags_PPAA | Noesis::RenderFlags_LCD);
		XamlView->SetEmulateTouch(EmulateTouch);
		XamlView->Update(CurrentTime);
		UpdateWorldTime();
	}
}

void UNoesisStudioInstance::SetOptions(StudioOptions& InOptions)
{
	Options = InOptions;
}

void UNoesisStudioInstance::SaveAllChanges()
{
	Noesis::ContentControl* root = Noesis::DynamicCast<Noesis::ContentControl*>(XamlView->GetContent());
	Noesis::FrameworkElement* Studio = Noesis::DynamicCast<Noesis::FrameworkElement*>(root->GetContent());
	if (Studio == nullptr)
	{
		return;
	}
	Noesis::Studio::SaveAllChanges(Studio);
}

void UNoesisStudioInstance::DiscardAllChanges()
{
	Noesis::ContentControl* root = Noesis::DynamicCast<Noesis::ContentControl*>(XamlView->GetContent());
	Noesis::FrameworkElement* Studio = Noesis::DynamicCast<Noesis::FrameworkElement*>(root->GetContent());
	if (Studio == nullptr)
	{
		return;
	}
	Noesis::Studio::DiscardAllChanges(Studio);
}
