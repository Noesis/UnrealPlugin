////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisEditorModule.h"

// CoreUObject includes
#include "UObject/UObjectGlobals.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"

// UnrealEd includes
#include "Editor.h"

// NoesisRuntime includes
#include "NoesisXaml.h"
#include "NoesisBlueprint.h"

// NoesisEditor includes
#include "NoesisBlueprintAssetTypeActions.h"
#include "NoesisXamlAssetTypeActions.h"
#include "NoesisBlueprintCompiler.h"
#include "NoesisBlueprintCompilerContext.h"
#include "NoesisXamlThumbnailRenderer.h"
#include "NoesisStyle.h"

// KismetCompiler includes
#include "KismetCompiler.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

void FixPremultipliedPNGTexture(UTexture2D* Texture)
{
	UAssetImportData* TextureImportData = Texture->AssetImportData;
	if (!TextureImportData->GetFirstFilename().ToLower().EndsWith(".png"))
	{
		return;
	}

	FTextureSource& TextureSource = Texture->Source;
	const ETextureSourceFormat SourceFormat = TextureSource.GetFormat();
	int32 TextureWidth = TextureSource.GetSizeX();
	int32 TextureHeight = TextureSource.GetSizeY();

	switch (SourceFormat)
	{
	case TSF_BGRA8:
		{
			uint8* SourceData = TextureSource.LockMip(0);
			for (int32 Y = 0; Y < TextureHeight; ++Y)
			{
				for (int32 X = 0; X < TextureWidth; ++X)
				{
					uint8* PixelData = SourceData + (Y * TextureWidth + X) * 4;

					if (PixelData[3] == 0)
					{
						uint32* ColorData = (uint32*)PixelData;
						*ColorData = 0;
					}
				}
			}
			TextureSource.UnlockMip(0);
			Texture->PostEditChange();
			break;
		}

	case TSF_RGBA16:
		{
			uint16* SourceData = (uint16*)TextureSource.LockMip(0);
			for (int32 Y = 0; Y < TextureHeight; ++Y)
			{
				for (int32 X = 0; X < TextureWidth; ++X)
				{
					uint16* PixelData = SourceData + (Y * TextureWidth + X) * 4;

					if (PixelData[3] == 0)
					{
						uint64* ColorData = (uint64*)PixelData;
						*ColorData = 0;
					}
				}
			}
			TextureSource.UnlockMip(0);
			Texture->PostEditChange();
			break;
		}

	default:
		UE_LOG(LogNoesisEditor, Warning, TEXT("Texture %s format invalid"), *Texture->GetPathName());
		break;
	}
}

void PremultiplyAlpha(UTexture2D* Texture)
{
	FTextureSource& TextureSource = Texture->Source;
	const ETextureSourceFormat SourceFormat = TextureSource.GetFormat();
	int32 TextureWidth = TextureSource.GetSizeX();
	int32 TextureHeight = TextureSource.GetSizeY();

	switch (SourceFormat)
	{
	case TSF_BGRA8:
	{
		uint8* SourceData = TextureSource.LockMip(0);
		for (int32 Y = 0; Y < TextureHeight; ++Y)
		{
			for (int32 X = 0; X < TextureWidth; ++X)
			{
				uint8* PixelData = SourceData + (Y * TextureWidth + X) * 4;
				uint32 Alpha = (uint32)PixelData[3];
				PixelData[0] = (uint8)(((uint32)PixelData[0] * Alpha) / 255);
				PixelData[1] = (uint8)(((uint32)PixelData[1] * Alpha) / 255);
				PixelData[2] = (uint8)(((uint32)PixelData[2] * Alpha) / 255);
			}
		}
		TextureSource.UnlockMip(0);
		Texture->PostEditChange();
		break;
	}

	case TSF_RGBA16:
	{
		uint16* SourceData = (uint16*)TextureSource.LockMip(0);
		for (int32 Y = 0; Y < TextureHeight; ++Y)
		{
			for (int32 X = 0; X < TextureWidth; ++X)
			{
				uint16* PixelData = SourceData + (Y * TextureWidth + X) * 4;
				uint32 Alpha = (uint32)PixelData[3];
				PixelData[0] = (uint8)(((uint32)PixelData[0] * Alpha) / 255);
				PixelData[1] = (uint8)(((uint32)PixelData[1] * Alpha) / 255);
				PixelData[2] = (uint8)(((uint32)PixelData[2] * Alpha) / 255);
			}
		}
		TextureSource.UnlockMip(0);
		Texture->PostEditChange();
		break;
	}

	default:
		UE_LOG(LogNoesisEditor, Warning, TEXT("Texture %s format invalid"), *Texture->GetPathName());
		break;
	}
}

void OnObjectImported(UFactory* ImportFactory, UObject* InObject)
{
	for (TObjectIterator<UNoesisXaml> It; It; ++It)
	{
		UNoesisXaml* Xaml = *It;
		Xaml->DestroyThumbnailRenderData();
	}

	if (InObject->IsA<UTexture2D>())
	{
		UTexture2D* Texture = (UTexture2D*)InObject;
		if (Texture->LODGroup == TEXTUREGROUP_UI &&
			!Texture->SRGB)
		{
			if (GetDefault<UNoesisSettings>()->PremultiplyAlpha)
			{
				PremultiplyAlpha(Texture);
			}
			if (GetDefault<UNoesisSettings>()->RestoreUITexturePNGPremultipliedAlpha)
			{
				FixPremultipliedPNGTexture(Texture);
			}
		}
	}
}

void OnObjectPropertyChanged(UObject* Object, struct FPropertyChangedEvent& Event)
{
	static uint32 ReentryGuard = 0;
	if (!ReentryGuard)
	{
		ReentryGuard = 1;
		for (TObjectIterator<UNoesisXaml> It; It; ++It)
		{
			UNoesisXaml* Xaml = *It;
			Xaml->DestroyThumbnailRenderData();
		}

		if (Object->IsA<UTexture2D>())
		{
			UTexture2D* Texture = (UTexture2D*)Object;
			if (Texture->LODGroup == TEXTUREGROUP_UI &&
				!Texture->SRGB)
			{
				// Avoid reimporting the texture unless one of these properties has changed
				if (Event.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UTexture, SRGB) ||
					Event.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UTexture, LODGroup))
				{
					if (GetDefault<UNoesisSettings>()->PremultiplyAlpha)
					{
						// We need to reimport the texture here in case the Texture's Source has already been premultiplied
						FReimportManager::Instance()->Reimport(Texture);

						// Important!!!
						// PremultiplyAlpha will be called from the ObjectImported callback
					}
				}

				if (GetDefault<UNoesisSettings>()->RestoreUITexturePNGPremultipliedAlpha)
				{
					FixPremultipliedPNGTexture(Texture);
				}
			}
		}
		ReentryGuard = 0;
	}
}

TSharedPtr<FKismetCompilerContext> GetCompilerForNoesisBlueprint(UBlueprint* Blueprint, FCompilerResultsLog& Results, const FKismetCompilerOptions& CompilerOptions)
{
	UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
	return TSharedPtr<FKismetCompilerContext>(new FNoesisBlueprintCompilerContext(NoesisBlueprint, Results, CompilerOptions));
}

class FNoesisEditorModule : public INoesisEditorModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		FCoreDelegates::OnPostEngineInit.AddRaw(this, &FNoesisEditorModule::OnPostEngineInit);
	}

	void OnPostEngineInit()
	{
		// Register slate style overrides
		FNoesisStyle::Initialize();

		// Register asset type actions
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		EAssetTypeCategories::Type Category = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("NoesisGUI")), LOCTEXT("NoesisGUIAssetCategory", "NoesisGUI"));

		NoesisBlueprintAssetTypeActions = MakeShareable(new FNoesisBlueprintAssetTypeActions(Category));
		AssetTools.RegisterAssetTypeActions(NoesisBlueprintAssetTypeActions.ToSharedRef());
		NoesisXamlAssetTypeActions = MakeShareable(new FNoesisXamlAssetTypeActions(Category));
		AssetTools.RegisterAssetTypeActions(NoesisXamlAssetTypeActions.ToSharedRef());

		// Register blueprint compiler
		NoesisBlueprintCompiler = MakeShareable(new FNoesisBlueprintCompiler());
		IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
		KismetCompilerModule.GetCompilers().Add(NoesisBlueprintCompiler.Get());
		FKismetCompilerContext::RegisterCompilerForBP(UNoesisBlueprint::StaticClass(), &GetCompilerForNoesisBlueprint);

		// Register settings
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->RegisterSettings("Project", "Plugins", "NoesisGUI",
				LOCTEXT("NoesisSettingsName", "NoesisGUI"),
				LOCTEXT("NoesisSettingsDescroption", "Configure the NoesisGUI plugin."),
				GetMutableDefault<UNoesisSettings>());
		}

		// Register thumbnail renderers
		UThumbnailManager::Get().RegisterCustomRenderer(UNoesisXaml::StaticClass(), UNoesisXamlThumbnailRenderer::StaticClass());

		NoesisEditorModuleInterface = this;

		AssetImportHandle = GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetPostImport.AddStatic(&OnObjectImported);

		ObjectPropertyChangedHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddStatic(&OnObjectPropertyChanged);

		// Register level editor menu
		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuBarExtension(
			"Edit",
			EExtensionHook::After,
			NULL,
			FMenuBarExtensionDelegate::CreateStatic(&FNoesisEditorModule::AddNoesisMenu)
		);
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}

	virtual void ShutdownModule() override
	{
		NoesisEditorModuleInterface = 0;

		// Unregister slate style overrides
		FNoesisStyle::Shutdown();

		// Unregister asset type actions
		if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
		{
			IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
			AssetTools.UnregisterAssetTypeActions(NoesisBlueprintAssetTypeActions.ToSharedRef());
			AssetTools.UnregisterAssetTypeActions(NoesisXamlAssetTypeActions.ToSharedRef());
		}

		// Unregister blueprint compiler
		if (FModuleManager::Get().IsModuleLoaded("KismetCompiler"))
		{
			IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
			KismetCompilerModule.GetCompilers().Remove(NoesisBlueprintCompiler.Get());
		}

		// Unregister settings
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->UnregisterSettings("Project", "Plugins", "NoesisGUI");
		}

		// Unregister thumbnail renderers
		if (UObjectInitialized())
		{
			UThumbnailManager::Get().UnregisterCustomRenderer(UNoesisXaml::StaticClass());

			if (AssetImportHandle.IsValid())
			{
				GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetPostImport.Remove(AssetImportHandle);
			}
		}

		if (ObjectPropertyChangedHandle.IsValid())
		{
			FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(ObjectPropertyChangedHandle);
		}
	}
	// End of IModuleInterface interface

	static void AddNoesisMenu(FMenuBarBuilder& MenuBarBuilder)
	{
		MenuBarBuilder.AddPullDownMenu(
			LOCTEXT("NoesisMenu", "NoesisGUI"),
			FText::GetEmpty(),
			FNewMenuDelegate::CreateStatic(&FNoesisEditorModule::FillNoesisMenu),
			"Noesis");
	}

	static void FillNoesisMenu(FMenuBuilder& MenuBuilder)
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("NoesisSettings", "Settings"),
			FText::GetEmpty(),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenSettingsDialog))
		);
		MenuBuilder.BeginSection("NoesisLinks", LOCTEXT("NoesisLinks", "External links"));
		{
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisDocumentation", "Documentation"),
				FText::GetEmpty(),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenDocumentation))
			);
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisForums", "Forums"),
				FText::GetEmpty(),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenForums))
			);
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisChangeLog", "Release Notes"),
				FText::GetEmpty(),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenChangeLog))
			);
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisBugTracker", "Report a bug"),
				FText::GetEmpty(),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenBugTracker))
			);
		}
		MenuBuilder.EndSection();
		MenuBuilder.AddMenuSeparator();
		MenuBuilder.AddMenuEntry(
			LOCTEXT("NoesisAbout", "About NoesisGUI"),
			FText::GetEmpty(),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenAbout))
		);
	}

	static void OpenSettingsDialog()
	{
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->ShowViewer("Project", "Plugins", "NoesisGUI");
		}
	}

	static void OpenDocumentation()
	{
		FPlatformProcess::LaunchURL(TEXT("https://noesisengine.com/docs/Gui.Core.Index.html"), nullptr, nullptr);
	}

	static void OpenForums()
	{
		FPlatformProcess::LaunchURL(TEXT("https://noesisengine.com/forums/"), nullptr, nullptr);
	}

	static void OpenChangeLog()
	{
		FPlatformProcess::LaunchURL(TEXT("https://noesisengine.com/docs/Gui.Core.Changelog.html"), nullptr, nullptr);
	}

	static void OpenBugTracker()
	{
		FPlatformProcess::LaunchURL(TEXT("https://noesisengine.com/bugs/my_view_page.php"), nullptr, nullptr);
	}

	class SNoesisAboutScreen : public SCompoundWidget
	{
	public:
		SLATE_BEGIN_ARGS(SNoesisAboutScreen)
		{}
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs)
		{
			FText Version = FText::Format(LOCTEXT("VersionLabel", "Version: {0}"), FText::FromString(Noesis::GetBuildVersion()));

			ChildSlot
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(0.0f, 0.0f, 0.0f, 0.0f))
				.VAlign(VAlign_Top)
				[
					SNew(SImage)
					.Image(FNoesisStyle::Get()->GetBrush("NoesisEditor.About"))
					.ColorAndOpacity(FSlateColor::UseForeground())
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(0.0f, 20.0f, 0.0f, 0.0f))
				[
					SNew(STextBlock)
					.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 11))
					.Justification(ETextJustify::Center)
					.Text(Version)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(50.0f, 20.0f, 50.0f, 0.0f))
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.Text(LOCTEXT("NoesisChangeLog", "Release Notes"))
					.ButtonColorAndOpacity(FLinearColor(0.6f, 0.6f, 0.6f))
					.OnClicked(this, &SNoesisAboutScreen::OnReleaseNotesClicked)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(50.0f, 5.0f, 50.0f, 0.0f))
				[
					SNew(SButton)
					.HAlign(HAlign_Center)
					.Text(FText::FromString("Noesis Technologies"))
					.ButtonColorAndOpacity(FLinearColor(0.6f, 0.6f, 0.6f))
					.OnClicked(this, &SNoesisAboutScreen::OnNoesisTechnologiesClicked)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(0.0f, 30.0f, 0.0f, 0.0f))
				[
					SNew(STextBlock)
					.ColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f))
					.Font(FCoreStyle::GetDefaultFontStyle("Regular", 7))
					.Justification(ETextJustify::Center)
					.Text(LOCTEXT("NoesisCopyright2", "(c) 2013 Noesis Technologies S.L. All Rights Reserved."))
				]
			];
		}

	private:

		FReply OnReleaseNotesClicked()
		{
			FPlatformProcess::LaunchURL(TEXT("https://noesisengine.com/docs/Gui.Core.Changelog.html"), nullptr, nullptr);
			return FReply::Handled();
		}

		FReply OnNoesisTechnologiesClicked()
		{
			FPlatformProcess::LaunchURL(TEXT("https://noesisengine.com"), nullptr, nullptr);
			return FReply::Handled();
		}
	};

	static void OpenAbout()
	{
		TSharedRef<SWindow> AboutWindow = SNew(SWindow)
			.Title(LOCTEXT("NoesisAbout", "About NoesisGUI"))
			.SizingRule(ESizingRule::Autosized)
			.AutoCenter(EAutoCenter::PreferredWorkArea)
			.SupportsMinimize(false);

		TSharedRef<SWidget> Content = SNew(SNoesisAboutScreen);

		AboutWindow->SetContent(Content);
		TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
		if (RootWindow.IsValid())
		{
			FSlateApplication::Get().AddWindowAsNativeChild(AboutWindow, RootWindow.ToSharedRef());
		}
		else
		{
			FSlateApplication::Get().AddWindow(AboutWindow);
		}
	}

	static INoesisEditorModuleInterface* NoesisEditorModuleInterface;

private:
	TSharedPtr<FNoesisBlueprintAssetTypeActions> NoesisBlueprintAssetTypeActions;
	TSharedPtr<FNoesisXamlAssetTypeActions> NoesisXamlAssetTypeActions;
	TSharedPtr<FNoesisBlueprintCompiler> NoesisBlueprintCompiler;
	FDelegateHandle AssetImportHandle;
	FDelegateHandle ObjectPropertyChangedHandle;
};

INoesisEditorModuleInterface* FNoesisEditorModule::NoesisEditorModuleInterface = 0;

INoesisEditorModuleInterface* INoesisEditorModuleInterface::Get()
{
	return FNoesisEditorModule::NoesisEditorModuleInterface;
}

IMPLEMENT_MODULE(FNoesisEditorModule, NoesisEditor);
DEFINE_LOG_CATEGORY(LogNoesisEditor);

#undef LOCTEXT_NAMESPACE
