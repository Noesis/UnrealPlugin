////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisEditorModule.h"

// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"

// Core includes
#include "CoreMinimal.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/EngineVersionComparison.h"

// CoreUObject includes
#include "UObject/UObjectGlobals.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInterface.h"
#include "TextureCompiler.h"
#include "Widgets/SWindow.h"
#include "Widgets/Docking/SDockTab.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"
#include "Misc/App.h"
#include "DesktopPlatformModule.h"
#include "IDesktopPlatform.h"
#include "Interfaces/IPluginManager.h"
#include "Interfaces/IMainFrameModule.h"

// UnrealEd includes
#include "Editor.h"
#include "EditorReimportHandler.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "FileHelpers.h"
#include "Settings/LevelEditorPlaySettings.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisSettings.h"
#include "NoesisSupport.h"
#include "NoesisTypeClass.h"
#include "NoesisXaml.h"
#include "NoesisRive.h"
#include "NoesisTextureAssetUserData.h"
#include "NoesisInstance.h"
#include "NoesisAssetDependency.h"

// NoesisEditor includes
#include "NoesisBlueprintAssetTypeActions.h"
#include "NoesisXamlAssetTypeActions.h"
#include "NoesisRiveAssetTypeActions.h"
#include "NoesisBlueprintCompiler.h"
#include "NoesisBlueprintCompilerContext.h"
#include "NoesisXamlThumbnailRenderer.h"
#include "NoesisRiveThumbnailRenderer.h"
#include "NoesisStyle.h"
#include "NoesisLangServerResourceProvider.h"
#include "SNoesisStudioWidget.h"
#include "NoesisBlueprint.h"
#include "NoesisBlueprintGeneratedClass.h"

// KismetCompiler includes
#include "KismetCompiler.h"

// LevelEditor includes
#include "LevelEditor.h"

// Settings includes
#include "ISettingsModule.h"

// Slate includes
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"

// LangServer includes
#include "NsGui/LangServer.h"

// ContentBrowser includes
#include "ContentBrowserMenuContexts.h"

// ToolMenus includes
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

static void PremultiplyAlpha(UTexture2D* Texture)
{
	FTextureSource& TextureSource = Texture->Source;
	const ETextureSourceFormat SourceFormat = TextureSource.GetFormat();
	int32 TextureWidth = TextureSource.GetSizeX();
	int32 TextureHeight = TextureSource.GetSizeY();

	switch (SourceFormat)
	{
	case TSF_BGRA8:
	{
		int32 MipSizeX = TextureWidth;
		int32 MipSizeY = TextureHeight;

		for (int32 MipLevel = 0; MipLevel < TextureSource.GetNumMips(); ++MipLevel)
		{
			uint8* SourceData = TextureSource.LockMip(MipLevel);
			for (int32 Y = 0; Y < MipSizeY; ++Y)
			{
				for (int32 X = 0; X < MipSizeX; ++X)
				{
					uint8* PixelData = SourceData + (Y * MipSizeX + X) * 4;
					uint32 Alpha = (uint32)PixelData[3];
					PixelData[0] = (uint8)(((uint32)PixelData[0] * Alpha) / 255);
					PixelData[1] = (uint8)(((uint32)PixelData[1] * Alpha) / 255);
					PixelData[2] = (uint8)(((uint32)PixelData[2] * Alpha) / 255);
				}
			}
			TextureSource.UnlockMip(MipLevel);

			MipSizeX <<= 2;
			MipSizeY <<= 2;
		}
		break;
	}

	case TSF_RGBA16:
	{
		int32 MipSizeX = TextureWidth;
		int32 MipSizeY = TextureHeight;

		for (int32 MipLevel = 0; MipLevel < TextureSource.GetNumMips(); ++MipLevel)
		{
			uint16* SourceData = (uint16*)TextureSource.LockMip(MipLevel);
			for (int32 Y = 0; Y < MipSizeY; ++Y)
			{
				for (int32 X = 0; X < MipSizeX; ++X)
				{
					uint16* PixelData = SourceData + (Y * MipSizeX + X) * 4;
					uint32 Alpha = (uint32)PixelData[3];
					PixelData[0] = (uint8)(((uint32)PixelData[0] * Alpha) / 255);
					PixelData[1] = (uint8)(((uint32)PixelData[1] * Alpha) / 255);
					PixelData[2] = (uint8)(((uint32)PixelData[2] * Alpha) / 255);
				}
			}
			TextureSource.UnlockMip(MipLevel);

			MipSizeX <<= 2;
			MipSizeY <<= 2;
		}
		break;
	}

	default:
		UE_LOG(LogNoesisEditor, Warning, TEXT("Texture %s format invalid"), *Texture->GetPathName());
		break;
	}
}

static void EnsurePremultiplyAlpha(class UTexture2D* Texture)
{
	auto NoesisTextureData = (UNoesisTextureAssetUserData*)Texture->GetAssetUserDataOfClass(UNoesisTextureAssetUserData::StaticClass());
	if (NoesisTextureData == nullptr)
	{
		NoesisTextureData = NewObject<UNoesisTextureAssetUserData>(Texture, NAME_None, RF_Public | RF_Transactional);

		Texture->PreEditChange(nullptr);
		Texture->AddAssetUserData(NoesisTextureData);
		PremultiplyAlpha(Texture);
		Texture->PostEditChange();
	}
}

static void SetLangServerCallbacks(FNoesisLangServerTextureProvider* textureProvider)
{
	Noesis::LangServer::SetDocumentClosedCallback(textureProvider, [](void* user, const Noesis::Uri& uri)
		{
			FNoesisLangServerTextureProvider* provider = (FNoesisLangServerTextureProvider*)user;
			provider->ClearShrinkTextures();
		});
}

static void DestroyThumbnails()
{
	for (TObjectIterator<UNoesisXaml> It; It; ++It)
	{
		UNoesisXaml* Xaml = *It;
		Xaml->DestroyThumbnailRenderData();
	}

	for (TObjectIterator<UNoesisRive> It; It; ++It)
	{
		UNoesisRive* Rive = *It;
		Rive->DestroyThumbnailRenderData();
	}
}

static void OnAssetPostImport(UFactory* ImportFactory, UObject* InObject)
{
	if (!IsValid(InObject))
		return;

	DestroyThumbnails();

	if (InObject->IsA<UNoesisXaml>())
	{
		if (GetDefault<UNoesisSettings>()->ReloadEnabled)
		{
			UNoesisXaml* Xaml = (UNoesisXaml*)InObject;
			INoesisRuntimeModuleInterface::Get().OnXamlChanged(Xaml);
		}
	}

	if (auto Texture = Cast<UTexture2D>(InObject); Texture != nullptr)
	{
		auto NoesisTextureData = (UNoesisTextureAssetUserData*)Texture->GetAssetUserDataOfClass(UNoesisTextureAssetUserData::StaticClass());
		if (NoesisTextureData != nullptr)
		{
			PremultiplyAlpha(Texture);
		}
	}
}

static void OnObjectPropertyChanged(UObject* Object, struct FPropertyChangedEvent& Event)
{
	if (!IsValid(Object)) // Don't think this is possible, but better safe than sorry
		return;

	static uint32 ReentryGuard = 0;
	if (!ReentryGuard)
	{
		ReentryGuard = 1;

		DestroyThumbnails();

		if (Object->IsA<UTexture2D>())
		{
			UTexture2D* Texture = (UTexture2D*)Object;
			INoesisRuntimeModuleInterface::Get().OnTextureChanged(Texture);
		}

		if (Object->IsA<UMaterialInterface>())
		{
			NoesisDestroyTypeClassForMaterial((UMaterialInterface*)Object);
		}

		ReentryGuard = 0;
	}
}

static bool CanSetPremultiplyAlpha(const FToolMenuContext& InContext)
{
	if (GetDefault<UNoesisSettings>()->PremultiplyAlpha)
	{
		const UContentBrowserAssetContextMenuContext* CBContext = UContentBrowserAssetContextMenuContext::FindContextWithAssets(InContext);
		for (UTexture2D* Texture : CBContext->LoadSelectedObjects<UTexture2D>())
		{
			if (IsValid(Texture))
			{
				auto NoesisTextureData = (UNoesisTextureAssetUserData*)Texture->GetAssetUserDataOfClass(UNoesisTextureAssetUserData::StaticClass());
				if (NoesisTextureData == nullptr)
				{
					return true;
				}
			}
		}
	}
	return false;
}

static void ExecuteSetPremultiplyAlpha(const FToolMenuContext& InContext)
{
	const UContentBrowserAssetContextMenuContext* CBContext = UContentBrowserAssetContextMenuContext::FindContextWithAssets(InContext);
	for (UTexture2D* Texture : CBContext->LoadSelectedObjects<UTexture2D>())
	{
		if (IsValid(Texture))
		{
			EnsurePremultiplyAlpha(Texture);
		}
	}
}

static bool CanResetPremultiplyAlpha(const FToolMenuContext& InContext)
{
	if (GetDefault<UNoesisSettings>()->PremultiplyAlpha)
	{
		const UContentBrowserAssetContextMenuContext* CBContext = UContentBrowserAssetContextMenuContext::FindContextWithAssets(InContext);
		for (UTexture2D* Texture : CBContext->LoadSelectedObjects<UTexture2D>())
		{
			if (IsValid(Texture))
			{
				auto NoesisTextureData = (UNoesisTextureAssetUserData*)Texture->GetAssetUserDataOfClass(UNoesisTextureAssetUserData::StaticClass());
				if (NoesisTextureData != nullptr)
				{
					return true;
				}
			}
		}
	}
	return false;
}

static void ExecuteResetPremultiplyAlpha(const FToolMenuContext& InContext)
{
	TArray<UObject*> SelectedObjects;
	const UContentBrowserAssetContextMenuContext* CBContext = UContentBrowserAssetContextMenuContext::FindContextWithAssets(InContext);
	for (UTexture2D* Texture : CBContext->LoadSelectedObjects<UTexture2D>())
	{
		if (IsValid(Texture))
		{
			auto NoesisTextureData = (UNoesisTextureAssetUserData*)Texture->GetAssetUserDataOfClass(UNoesisTextureAssetUserData::StaticClass());
			if (NoesisTextureData != nullptr)
			{
				Texture->RemoveUserDataOfClass(UNoesisTextureAssetUserData::StaticClass());

				SelectedObjects.Add(Texture);
			}
		}
	}

	if (SelectedObjects.Num() > 0)
	{
		FReimportManager::Instance()->ValidateAllSourceFileAndReimport(SelectedObjects, true, INDEX_NONE, false);
	}
}

TSharedPtr<FKismetCompilerContext> GetCompilerForNoesisBlueprint(UBlueprint* Blueprint, FCompilerResultsLog& Results, const FKismetCompilerOptions& CompilerOptions)
{
	UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
	return TSharedPtr<FKismetCompilerContext>(new FNoesisBlueprintCompilerContext(NoesisBlueprint, Results, CompilerOptions));
}

#if UE_VERSION_OLDER_THAN(5, 0, 0)
typedef FTicker FTSTicker;
#endif

// Forward declare functions used to fix NoesisXaml dependencies
FString GetDependencyPath(const Noesis::Uri& Uri);
void ConfigureFilter(FARFilter& Filter, UClass* Class, bool RecursiveClasses);

class FNoesisEditorModule : public INoesisEditorModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		NoesisEditorModuleInterface = this;

#if UE_VERSION_OLDER_THAN(5, 8, 0)
		FCoreDelegates::OnPostEngineInit.AddRaw(this, &FNoesisEditorModule::OnPostEngineInit);
#else
		FCoreDelegates::GetOnPostEngineInit().AddRaw(this, &FNoesisEditorModule::OnPostEngineInit);
#endif
	}

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	static bool IsRunningCookCommandlet()
	{
		FString Commandline = FCommandLine::Get();
		const bool bIsCookCommandlet = IsRunningCommandlet() && Commandline.Contains(TEXT("run=cook"));
		return bIsCookCommandlet;
	}
#endif

	void OnPostEngineInit()
	{
		// Register slate style overrides
		FNoesisStyle::Initialize();

		Noesis::Ptr<FNoesisLangServerTextureProvider> LangTextureProvider = Noesis::MakePtr<FNoesisLangServerTextureProvider>();

		// Set LangServer Scheme Providers
		Noesis::LangServer::SetXamlProvider(Noesis::MakePtr<FNoesisLangServerXamlProvider>());
		Noesis::LangServer::SetTextureProvider(LangTextureProvider);
		Noesis::LangServer::SetFontProvider(Noesis::MakePtr<FNoesisLangServerFontProvider>());

		SetLangServerCallbacks(LangTextureProvider);

		// Initialize LangServer
		Noesis::LangServer::SetName("Unreal");
		Noesis::LangServer::Init();

		// Register asset type actions
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		EAssetTypeCategories::Type Category = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("NoesisGUI")), LOCTEXT("NoesisGUIAssetCategory", "NoesisGUI"));

		NoesisBlueprintAssetTypeActions = MakeShareable(new FNoesisBlueprintAssetTypeActions(Category));
		AssetTools.RegisterAssetTypeActions(NoesisBlueprintAssetTypeActions.ToSharedRef());
		NoesisXamlAssetTypeActions = MakeShareable(new FNoesisXamlAssetTypeActions(Category));
		AssetTools.RegisterAssetTypeActions(NoesisXamlAssetTypeActions.ToSharedRef());
		NoesisRiveAssetTypeActions = MakeShareable(new FNoesisRiveAssetTypeActions(Category));
		AssetTools.RegisterAssetTypeActions(NoesisRiveAssetTypeActions.ToSharedRef());

		// Register blueprint compiler
		NoesisBlueprintCompiler = MakeShareable(new FNoesisBlueprintCompiler());
		IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
		KismetCompilerModule.GetCompilers().Insert(NoesisBlueprintCompiler.Get(), 0); // Make sure our compiler goes before the WidgetBlueprint compiler
		FKismetCompilerContext::RegisterCompilerForBP(UNoesisBlueprint::StaticClass(), &GetCompilerForNoesisBlueprint);
		KismetCompilerModule.OverrideBPTypeForClass(UNoesisInstance::StaticClass(), UNoesisBlueprint::StaticClass());
		KismetCompilerModule.OverrideBPGCTypeForBPType(UNoesisBlueprint::StaticClass(),
			UNoesisBlueprintGeneratedClass::StaticClass());

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
		UThumbnailManager::Get().RegisterCustomRenderer(UNoesisRive::StaticClass(), UNoesisRiveThumbnailRenderer::StaticClass());

		AssetPostImportHandle = GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetPostImport.AddStatic(&OnAssetPostImport);

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

		// Register ticker
		TickerHandle = FTSTicker::GetCoreTicker().AddTicker(TEXT("NoesisEditor"), 0.0f, [this](float DeltaTime)
		{
			Noesis::GUI::UpdateInspector();
			Noesis::LangServer::RunTick();
			return true;
		});

		if (IsRunningCookCommandlet())
		{
			GetDefault<UNoesisSettings>()->LoadWorldUIXaml();
		}

		FToolMenuOwnerScoped OwnerScoped(UE_MODULE_NAME);
		UToolMenu* Menu = UE::ContentBrowser::ExtendToolMenu_AssetContextMenu(UTexture2D::StaticClass());

		FToolMenuSection& Section = Menu->AddSection("NoesisGUI", LOCTEXT("NoesisGUI", "NoesisGUI"), FToolMenuInsert("GetAssetActions", EToolMenuInsertType::After));
		Section.AddDynamicEntry(NAME_None, FNewToolMenuSectionDelegate::CreateLambda([](FToolMenuSection& InSection)
		{
			{
				const TAttribute<FText> Label = LOCTEXT("SetPremultiplyAlpha", "Set Premultiply Alpha");
				const TAttribute<FText> ToolTip = LOCTEXT("SetPremultiplyAlphaTooltip", "Multiplies the RGB components of each texel by its A component. This will happen every time the texture is reimported.");
				const FSlateIcon Icon = FSlateIcon(FAppStyle::GetAppStyleSetName(), "ContentBrowser.AssetActions");

				FToolUIAction UIAction;
				UIAction.ExecuteAction = FToolMenuExecuteAction::CreateStatic(&ExecuteSetPremultiplyAlpha);
				UIAction.CanExecuteAction = FToolMenuCanExecuteAction::CreateStatic(&CanSetPremultiplyAlpha);
				InSection.AddMenuEntry("Noesis_Texture2D_SetPremultiplyAlpha", Label, ToolTip, Icon, UIAction);
			}

			{
				const TAttribute<FText> Label = LOCTEXT("ResetPremultiplyAlpha", "Reset Premultiply Alpha");
				const TAttribute<FText> ToolTip = LOCTEXT("ResetPremultiplyAlphaTooltip", "Reimports the texture to restore the original content.");
				const FSlateIcon Icon = FSlateIcon(FAppStyle::GetAppStyleSetName(), "ContentBrowser.AssetActions");

				FToolUIAction UIAction;
				UIAction.ExecuteAction = FToolMenuExecuteAction::CreateStatic(&ExecuteResetPremultiplyAlpha);
				UIAction.CanExecuteAction = FToolMenuCanExecuteAction::CreateStatic(&CanResetPremultiplyAlpha);
				InSection.AddMenuEntry("Noesis_Texture2D_ResetPremultiplyAlpha", Label, ToolTip, Icon, UIAction);
			}
		}));

		FGlobalTabmanager::Get()->RegisterNomadTabSpawner("NoesisStudioWindow",
			FOnSpawnTab::CreateStatic(FNoesisEditorModule::OnSpawnPluginTab))
			.SetDisplayName(FText::FromString("Noesis Studio"))
			.SetMenuType(ETabSpawnerMenuType::Hidden);

		// Automatically check and show the Welcome Screen once the Main Editor Frame is ready
		if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
		{
			IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");

			if (MainFrameModule.IsWindowInitialized())
			{
				ShowWelcomeScreenFirstTime();
			}
			else
			{
				MainFrameModule.OnMainFrameCreationFinished().AddLambda([](TSharedPtr<SWindow> RootWindow, bool bIsProjectReloaded)
				{
					ShowWelcomeScreenFirstTime();
				});
			}
		}
	}

	static TSharedRef<SDockTab> OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
	{
		TSharedRef<SDockTab> Tab = SNew(SDockTab)
			.TabRole(ETabRole::NomadTab);

		FString RelProjectPath;
		GConfig->GetString(
			TEXT("/Script/NoesisEditor.Studio"),
			TEXT("ProjectPath"),
			RelProjectPath,
			GEditorPerProjectIni
		);

		if (!RelProjectPath.IsEmpty())
		{
			UpdateStudioTab(Tab, RelProjectPath);
		}

		return Tab;
	}

	virtual void ShutdownModule() override
	{
		NoesisEditorModuleInterface = nullptr;

		// Unregister slate style overrides
		FNoesisStyle::Shutdown();

		// Disable LangServer
		Noesis::LangServer::Shutdown();

		// Unregister asset type actions
		if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
		{
			IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
			AssetTools.UnregisterAssetTypeActions(NoesisBlueprintAssetTypeActions.ToSharedRef());
			AssetTools.UnregisterAssetTypeActions(NoesisXamlAssetTypeActions.ToSharedRef());
			AssetTools.UnregisterAssetTypeActions(NoesisRiveAssetTypeActions.ToSharedRef());
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

			if (AssetPostImportHandle.IsValid())
			{
				GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetPostImport.Remove(AssetPostImportHandle);
			}
		}

		if (ObjectPropertyChangedHandle.IsValid())
		{
			FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(ObjectPropertyChangedHandle);
		}

		// Unregister ticker
		FTSTicker::GetCoreTicker().RemoveTicker(TickerHandle);
	}
	// End of IModuleInterface interface

	void EnsurePremultiplyAlpha(class UTexture2D* Texture) override
	{
		::EnsurePremultiplyAlpha(Texture);
	}

	void AddSamplePlugin(const FString& PluginName, int Order) override
	{
		const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(PluginName);
		if (!Plugin.IsValid())
		{
			return;
		}
		FString AbsProjectDir(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()));
		FString PluginDir(FPaths::ConvertRelativePathToFull(Plugin->GetBaseDir()).RightChop(AbsProjectDir.Len()));
		FString ProjectPath(FPaths::Combine(PluginDir, FString::Printf(TEXT("Assets/%s.noesis"), *PluginName)));
		FString Assembly;
		AddStudioProjectInternal(ProjectPath, Assembly, Order);
	}

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
			LOCTEXT("NoesisWelcome", "Welcome"),
			FText::GetEmpty(),
			FSlateIcon("NoesisStyle", "MenuIcon.About"),
			FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenWelcomeDialog))
		);
		MenuBuilder.AddMenuEntry(
			LOCTEXT("NoesisSettings", "Settings"),
			FText::GetEmpty(),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "ProjectSettings.TabIcon"),
			FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenSettingsDialog))
		);
		MenuBuilder.BeginSection("NoesisLinks", LOCTEXT("NoesisLinks", "External links"));
		{
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisDocumentation", "Documentation"),
				FText::GetEmpty(),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.BrowseDocumentation"),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenDocumentation))
			);
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisChangeLog", "Release Notes"),
				FText::GetEmpty(),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.BrowseDocumentation"),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenChangeLog))
			);
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisForums", "Forums"),
				FText::GetEmpty(),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "MainFrame.VisitForums"),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenForums))
			);
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisBugTracker", "Report a Bug"),
				FText::GetEmpty(),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "MainFrame.ReportABug"),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenBugTracker))
			);
		}
		MenuBuilder.EndSection();
		MenuBuilder.BeginSection("NoesisStudio", LOCTEXT("NoesisStudio", "Studio Projects"));
		{
			MenuBuilder.AddMenuEntry(
				LOCTEXT("NoesisCreateStudioProject", "New Project..."),
				FText::GetEmpty(),
				FSlateIcon("NoesisStyle", "MenuIcon.NewProject"),
				FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::CreateStudioProject))
			);
			TArray<FStudioProjectConfig> StudioProjects = GetDefault<UNoesisSettings>()->StudioProjects;
			StudioProjects.Sort(
				[](const FStudioProjectConfig& A,const FStudioProjectConfig& B)
				{
					if (A.Order == -1)
					{
						return false;
					}
					if (B.Order == -1)
					{
						return true;
					}
					return A.Order < B.Order;
				}
			);
			for (int Index = 0; Index < StudioProjects.Num(); Index++)
			{
				FString ProjectPath(StudioProjects[Index].ProjectPath);
				FString ProjectName = FPaths::GetBaseFilename(ProjectPath, true);
				MenuBuilder.AddMenuEntry(
					FText::FromString(ProjectName),
					FText::GetEmpty(),
					FSlateIcon("NoesisStyle", "MenuIcon.Studio"),
					FUIAction(FExecuteAction::CreateStatic(&FNoesisEditorModule::OpenStudio, ProjectPath))
				);
			}
		}
		MenuBuilder.EndSection();
		MenuBuilder.AddMenuSeparator();
		MenuBuilder.AddMenuEntry(
			LOCTEXT("NoesisAbout", "About NoesisGUI"),
			FText::GetEmpty(),
			FSlateIcon("NoesisStyle", "MenuIcon.About"),
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

	static TWeakPtr<SWindow> WeakWelcomeWindow;

	struct DelegateCommand : public Noesis::BaseCommand
	{
		Noesis::Delegate<void (Noesis::BaseComponent*)> _execute;
		void Execute(BaseComponent* param) const override { _execute(param); }
		bool CanExecute(BaseComponent*) const override { return true; }
		NS_IMPLEMENT_INLINE_REFLECTION_(DelegateCommand, Noesis::BaseCommand)
	};

	struct ViewModel : public Noesis::BaseComponent
	{
		ViewModel()
		{
			_openSample._execute = Noesis::MakeDelegate(this, &ViewModel::OpenSample);
		}

		const char* GetVersion() const { return Noesis::GetBuildVersion(); }

		DelegateCommand _openSample;
		const DelegateCommand* GetOpenSample() const { return &_openSample; }

		void OpenSample(Noesis::BaseComponent* Param)
		{
			if (!Noesis::Boxing::CanUnbox<Noesis::String>(Param)) return;

			FString Sample = NsStringToFString(Noesis::Boxing::Unbox<Noesis::String>(Param).Str());

			// Check if the sample plugin is installed and enabled
			TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(Sample);
			if (!Plugin.IsValid() || !Plugin->IsEnabled())
			{
				// Show a clean, custom message dialog
				FText DialogTitle = LOCTEXT("MissingSampleTitle", "Missing sample");
				FText ErrorMessage = FText::Format(
					LOCTEXT("MissingSamplePlugin", "The '{0}' sample plugin is either missing or disabled.\n\nTo explore this sample, please copy it into the project's Plugins/Samples folder and enable it via the Plugins window."),
					FText::FromString(Sample)
				);
				FMessageDialog::Open(EAppMsgType::Ok, ErrorMessage, DialogTitle);
				return;
			}

			// Close the Welcome Screen
			if (WeakWelcomeWindow.IsValid())
			{
				WeakWelcomeWindow.Pin()->RequestDestroyWindow();
			}

			// Focus the Content Browser on the Plugin's folder
			if (FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
			{
				FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
				FString SampleFolder = TEXT("/") + Sample;
				TArray<FString> FoldersToSync = { SampleFolder };
				ContentBrowserModule.Get().SyncBrowserToFolders(FoldersToSync);
			}

			// Load the Map (this automatically prompts to save current work)
			FString SampleMap = TEXT("/") + Sample + "/" + Sample + "." + Sample;
			FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([SampleMap](float DeltaTime)
			{
				bool bMapLoaded = FEditorFileUtils::LoadMap(SampleMap);
				if (bMapLoaded && GEditor)
				{
					// Play the map
					ULevelEditorPlaySettings* PlaySettings = GetMutableDefault<ULevelEditorPlaySettings>();
					EPlayModeType PreviousPlayMode = PlaySettings->LastExecutedPlayModeType;
					PlaySettings->LastExecutedPlayModeType = PlayMode_InViewPort;
					FRequestPlaySessionParams PlayParams;
					if (FModuleManager::Get().IsModuleLoaded("LevelEditor"))
					{
						FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>("LevelEditor");
						PlayParams.DestinationSlateViewport = LevelEditorModule.GetFirstActiveViewport();
					}
					GEditor->RequestPlaySession(PlayParams);
					PlaySettings->LastExecutedPlayModeType = PreviousPlayMode;
				}
				else if (!bMapLoaded)
				{
					UE_LOG(LogNoesisEditor, Warning, TEXT("Failed to load sample map: %s"), *SampleMap);
				}

				// Return false to ensure this ticker only executes once
				return false;
			}));
		}

		NS_IMPLEMENT_INLINE_REFLECTION(ViewModel, Noesis::BaseComponent)
		{
			NsProp("Version", &ViewModel::GetVersion);
			NsProp("OpenSample", &ViewModel::GetOpenSample);
		}
	};

	static void OpenWelcomeDialog()
	{
		// Bring window to the front if it is already opened
		if (WeakWelcomeWindow.IsValid())
		{
			TSharedPtr<SWindow> ExistingWindow = WeakWelcomeWindow.Pin();
			ExistingWindow->BringToFront();
			return;
		}

		// Create the window
		TSharedRef<SWindow> WelcomeWindow = SNew(SWindow)
			.Title(LOCTEXT("NoesisWelcome", "Welcome to NoesisGUI!"))
			.SizingRule(ESizingRule::UserSized)
			.ClientSize(FVector2D(1320.0f, 720.0f))
			.AutoCenter(EAutoCenter::PreferredWorkArea)
			.SupportsMinimize(false);

		WeakWelcomeWindow = WelcomeWindow;

		UNoesisXaml* XamlAsset = LoadObject<UNoesisXaml>(nullptr, TEXT("/NoesisGUI/Welcome/MainPage.MainPage"));

		if (XamlAsset)
		{
			UWorld* EditorWorld = GEditor->GetEditorWorldContext().World();
			UNoesisInstance* NoesisInstance = CreateWidget<UNoesisInstance>(EditorWorld, UNoesisInstance::StaticClass());
			NoesisInstance->BaseXaml = XamlAsset;
			NoesisInstance->DataContext = Noesis::MakePtr<ViewModel>();
			NoesisInstance->TessellationQuality = ENoesisTessellationQuality::High;
			NoesisInstance->EnablePPAA = true;
			NoesisInstance->DPIScale = true;

			WelcomeWindow->SetContent(NoesisInstance->TakeWidget());
		}
		else
		{
			UE_LOG(LogNoesisEditor, Error, TEXT("Failed to load Welcome Screen XAML."));
		}

		TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
		if (RootWindow.IsValid())
		{
			FSlateApplication::Get().AddWindowAsNativeChild(WelcomeWindow, RootWindow.ToSharedRef());
		}
		else
		{
			FSlateApplication::Get().AddWindow(WelcomeWindow);
		}
	}

	static void ShowWelcomeScreenFirstTime()
	{
		// Avoid showing dialogs during cooking, commandlets, or unattended builds
		if (IsRunningCommandlet() || FApp::IsUnattended()) return;

		// Target the shared DefaultEditor.ini in the project's Config folder
		FString DefaultEditorPath = FPaths::ProjectConfigDir() / TEXT("DefaultEditor.ini");
		FConfigFile DefaultEditorConfig;
		DefaultEditorConfig.Read(DefaultEditorPath);

		// Check if Welcome screen has already been shown
		bool bHasShownWelcome = false;
		DefaultEditorConfig.GetBool(TEXT("/Script/NoesisEditor.Welcome"),TEXT("bHasShownWelcomeScreen"), bHasShownWelcome);

		if (!bHasShownWelcome)
		{
			// Open the Welcome screen
			OpenWelcomeDialog();

			// Mark as shown so it doesn't open automatically next time this project is loaded
			DefaultEditorConfig.SetBool(TEXT("/Script/NoesisEditor.Welcome"), TEXT("bHasShownWelcomeScreen"), true);
			DefaultEditorConfig.Write(DefaultEditorPath);
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

	static void AddStudioProjectInternal(const FString& RelStudioPath, FString& Assembly, int Order)
	{
		// Find if this project is the main one or a plugin
		Assembly = TEXT("Game");

		FString AbsProjectDir(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()));
		int32 ProjectDirLen = AbsProjectDir.Len();
		FString RelStudioDir(FPaths::GetPath(RelStudioPath));

		IPluginManager& PluginManager = IPluginManager::Get();
		for (const TSharedRef<IPlugin>& Plugin : PluginManager.GetDiscoveredPlugins())
		{
			if (Plugin->GetLoadedFrom() == EPluginLoadedFrom::Project)
			{
				FString AbsPluginDir(FPaths::ConvertRelativePathToFull(Plugin->GetBaseDir()));
				if (!AbsPluginDir.StartsWith(AbsProjectDir))
				{
					continue;
				}
				FString RelPluginDir(AbsPluginDir.RightChop(ProjectDirLen));
				if (!RelStudioDir.StartsWith(RelPluginDir))
				{
					continue;
				}

				Assembly = Plugin->GetName();
				RelStudioDir.RightChopInline(RelPluginDir.Len() + 1);
				break;
			}
		}

		// Add Studio project to Noesis Settings list
		UNoesisSettings* Settings = (UNoesisSettings*)GetDefault<UNoesisSettings>();

		int NumProjects = Settings->StudioProjects.Num();
		int InsertIndex = NumProjects;
		for (int i = 0; i < NumProjects; i++)
		{
			const FStudioProjectConfig& Config = Settings->StudioProjects[i];

			if (Config.ProjectPath == RelStudioPath)
			{
				return;
			}

			if (Order != -1 && InsertIndex == NumProjects &&
				(Config.Order == -1 || Config.Order >= Order))
			{
				InsertIndex = i;
			}
		}

		FStudioProjectConfig NewStudioConfig;
		NewStudioConfig.ProjectPath = RelStudioPath;
		NewStudioConfig.Order = Order;
		Settings->StudioProjects.Insert(NewStudioConfig, InsertIndex);
		Settings->TryUpdateDefaultConfigFile();

		// Add Auto Reimport entry for this project
		UEditorLoadingSavingSettings* LoadingSettings = GetMutableDefault<UEditorLoadingSavingSettings>();
		if (!LoadingSettings)
		{
			return;
		}

		FString SourceDir = FString::Printf(TEXT("/%s/../%s"), *Assembly, *RelStudioDir);
		for (const FAutoReimportDirectoryConfig& Setting : LoadingSettings->AutoReimportDirectorySettings)
		{
			if (Setting.SourceDirectory == SourceDir)
			{
				return;
			}
		}

		FAutoReimportDirectoryConfig NewConfig;
		NewConfig.SourceDirectory = SourceDir;
		NewConfig.MountPoint = FString::Printf(TEXT("/%s/"), *Assembly);
		LoadingSettings->AutoReimportDirectorySettings.Add(NewConfig);
		LoadingSettings->SaveConfig();
	}

	static bool ShowUnsavedChangesModal(const TSharedPtr<SNoesisStudioWidget>& StudioWidget, bool CanCancel)
	{
		EAppReturnType::Type Result = FMessageDialog::Open(
			CanCancel ? EAppMsgType::YesNoCancel : EAppMsgType::YesNo,
			FText::FromString("Do you want to save your changes?")
		);

		switch (Result)
		{
			case EAppReturnType::Yes:
				// Save
				StudioWidget->SaveAllChanges();
				return true;
			case EAppReturnType::No:
				// Discard
				StudioWidget->DiscardAllChanges();
				return true;
			default:
				// Cancel
				return false;
		}
	}

	static void UpdateStudioTab(const TSharedPtr<SDockTab>& Tab, const FString& RelProjectPath)
	{
		FString AbsProjectDir(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()));
		FString ProjectPath(FPaths::Combine(AbsProjectDir, RelProjectPath));

		Tab->SetLabel(FText::FromString(FString::Printf(TEXT("Studio - %s"), *FPaths::GetBaseFilename(RelProjectPath))));

		StudioOptions Options;
		Options.ProjectPath = ProjectPath;

		Options.SaveStateChanged = [RelProjectPath](bool bHasUnsavedChanges)
			{
				TSharedPtr<SDockTab> Tab = FGlobalTabmanager::Get()->FindExistingLiveTab(FName("NoesisStudioWindow"));

				if (!Tab.IsValid())
				{
					return;
				}
				if (bHasUnsavedChanges)
				{
					Tab->SetLabel(FText::FromString(FString::Printf(TEXT("Studio - %s*"), *FPaths::GetBaseFilename(RelProjectPath))));
				}
				else
				{
					Tab->SetLabel(FText::FromString(FString::Printf(TEXT("Studio - %s"), *FPaths::GetBaseFilename(RelProjectPath))));
				}
			};

		TSharedRef<SNoesisStudioWidget> Content = SNew(SNoesisStudioWidget)
			.Options(Options);

		Tab->SetContent(Content);

		Tab->SetCanCloseTab(SDockTab::FCanCloseTab::CreateLambda([Content]()
			{
				TSharedPtr<SDockTab> Tab = FGlobalTabmanager::Get()->FindExistingLiveTab(FName("NoesisStudioWindow"));

				if (!Tab.IsValid() || !Tab->GetTabLabel().ToString().EndsWith(TEXT("*")))
				{
					return true;
				}

				Tab->SetLabel(FText::FromString(TEXT("Noesis Studio")));

				return ShowUnsavedChangesModal(Content.ToSharedPtr(), true);
			}));

		Tab->SetOnTabClosed(SDockTab::FOnTabClosedCallback::CreateLambda([Content](TSharedRef<SDockTab>)
			{
				TSharedPtr<SDockTab> Tab = FGlobalTabmanager::Get()->FindExistingLiveTab(FName("NoesisStudioWindow"));

				if (!Tab.IsValid() || !Tab->GetTabLabel().ToString().EndsWith(TEXT("*")))
				{
					return;
				}

				ShowUnsavedChangesModal(Content.ToSharedPtr(), false);
			}));

		Tab->SetOnTabDrawerClosed(FSimpleDelegate::CreateLambda([Content]()
			{
				TSharedPtr<SDockTab> Tab = FGlobalTabmanager::Get()->FindExistingLiveTab(FName("NoesisStudioWindow"));

				if (!Tab.IsValid() || !Tab->GetTabLabel().ToString().EndsWith(TEXT("*")))
				{
					return;
				}

				ShowUnsavedChangesModal(Content.ToSharedPtr(), false);
			}));
	}

	static bool IsDirectoryEmpty(const FString& DirectoryPath)
	{
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

		if (!PlatformFile.DirectoryExists(*DirectoryPath))
		{
			return true;
		}

		struct FCheckEmptyVisitor: public IPlatformFile::FDirectoryVisitor
		{
			bool IsEmpty = true;

			virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override
			{
				IsEmpty = false;
				return false; // abort iteration immediately
			}
		} Visitor;

		PlatformFile.IterateDirectory(*DirectoryPath, Visitor);

		return Visitor.IsEmpty;
	}

	static void OpenStudio(FString RelProjectPath)
	{
		FString PrevRelProjectPath;
		GConfig->GetString(
			TEXT("/Script/NoesisEditor.Studio"),
			TEXT("ProjectPath"),
			PrevRelProjectPath,
			GEditorPerProjectIni
		);

		GConfig->RemoveKey(
			TEXT("/Script/NoesisEditor.Studio"),
			TEXT("ProjectPath"),
			GEditorPerProjectIni
		);

		TSharedPtr<SDockTab> Tab = FGlobalTabmanager::Get()->TryInvokeTab(FName("NoesisStudioWindow"));
		if (!Tab.IsValid())
		{
			return;
		}

		if (Tab->GetTabLabel().ToString().EndsWith(TEXT("*")))
		{
			TSharedPtr<SNoesisStudioWidget> StudioWidget = StaticCastSharedPtr<SNoesisStudioWidget>(Tab->GetContent().ToSharedPtr());

			if (!ShowUnsavedChangesModal(StudioWidget, true))
			{
				GConfig->SetString(
					TEXT("/Script/NoesisEditor.Studio"),
					TEXT("ProjectPath"),
					*PrevRelProjectPath,
					GEditorPerProjectIni
				);
				GConfig->Flush(false, GEditorPerProjectIni);
				return;
			}
		}

		UpdateStudioTab(Tab, RelProjectPath);

		GConfig->SetString(
			TEXT("/Script/NoesisEditor.Studio"), // Custom section
			TEXT("ProjectPath"),             // Key
			*RelProjectPath,                         // Value
			GEditorPerProjectIni                    // File
		);
		GConfig->Flush(false, GEditorPerProjectIni);
	}

	static void CreateStudioProject()
	{
		IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
		if (!DesktopPlatform)
		{
			return;
		}

		FString AbsProjectDir(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()));

		TArray<FString> OutFilenames;
		const void* ParentWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);

		bool bSaved = DesktopPlatform->SaveFileDialog(
			ParentWindowHandle,
			TEXT("Create a Noesis Studio project"),
			AbsProjectDir,
			TEXT("Game.noesis"),
			TEXT("Studio project (*.noesis)|*.noesis"),
			EFileDialogFlags::None,
			OutFilenames
		);

		if (!bSaved || OutFilenames.IsEmpty())
		{
			return;
		}

		FString StudioPath(FPaths::ConvertRelativePathToFull(OutFilenames[0]));

		if (!StudioPath.StartsWith(AbsProjectDir))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create new Noesis Studio project file '%s', projects must be contained within the Unreal project folder"), *StudioPath);
			return;
		}

		FString RelStudioPath(StudioPath.RightChop(AbsProjectDir.Len()));

		FString Assembly;
		AddStudioProjectInternal(RelStudioPath, Assembly, -1);

		FString Extension = FPaths::GetExtension(StudioPath, true);
		if (Extension != TEXT(".noesis"))
		{
			if (Extension.IsEmpty())
			{
				StudioPath.Append(TEXT(".noesis"));
			}
			else
			{
				StudioPath = FPaths::ChangeExtension(StudioPath, TEXT(".noesis"));
			}
		}

		FString ProjectPath(FPaths::GetPath(StudioPath));
		FString ProjectName(FPaths::GetBaseFilename(StudioPath));

		bool MainPageCreated = false;
		bool ResourcesCreated = false;

		if (IsDirectoryEmpty(ProjectPath))
		{
			{
				FString FilePath = ProjectPath / "MainPage.xaml";
				FString FileContents =
					TEXT("<Page\n")
					TEXT("  xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\"\n")
					TEXT("  xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\"\n")
					TEXT("  xmlns:d=\"http://schemas.microsoft.com/expression/blend/2008\"\n")
					TEXT("  xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\"\n")
					TEXT("  mc:Ignorable=\"d\"\n")
					TEXT("  d:DesignWidth=\"1920\"\n")
					TEXT("  d:DesignHeight=\"1080\"\n")
					TEXT("  Background=\"#FF4D5052\">\n")
					TEXT("  <Grid>\n")
					TEXT("  </Grid>\n")
					TEXT("</Page>\n");

				MainPageCreated = FFileHelper::SaveStringToFile(FileContents, *FilePath);
			}
			{
				FString FilePath = ProjectPath / "GlobalResources.xaml";
				FString FileContents =
					TEXT("<ResourceDictionary\n")
					TEXT("  xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\"\n")
					TEXT("  xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\">\n")
					TEXT("  <ResourceDictionary.MergedDictionaries>\n")
					TEXT("    <ResourceDictionary Source=\"/Noesis.GUI.Extensions;component/Theme/NoesisTheme.DarkBlue.xaml\"/>\n")
					TEXT("  </ResourceDictionary.MergedDictionaries>\n")
					TEXT("</ResourceDictionary>\n");

				ResourcesCreated = FFileHelper::SaveStringToFile(FileContents, *FilePath);
			}
		}

		FString ProjectContents;
		ProjectContents.Append(TEXT("<Project>\n"));
		ProjectContents.Appendf(TEXT("  <Assembly>%s</Assembly>\n"), *Assembly);
		ProjectContents.Appendf(TEXT("  <DefaultDataNamespace>%s</DefaultDataNamespace>\n"), *Assembly);
		if (MainPageCreated) ProjectContents.Append(TEXT("  <StartupDocument>MainPage.xaml</StartupDocument>\n"));
		if (ResourcesCreated) ProjectContents.Append(TEXT("  <GlobalResources>GlobalResources.xaml</GlobalResources>\n"));
		ProjectContents.Append(TEXT("</Project>"));

		if (!FFileHelper::SaveStringToFile(ProjectContents, *StudioPath))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create new Noesis Studio project file '%s'"), *StudioPath);
			return;
		}

		OpenStudio(RelStudioPath);
	}

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
	TSharedPtr<FNoesisRiveAssetTypeActions> NoesisRiveAssetTypeActions;
	TSharedPtr<FNoesisBlueprintCompiler> NoesisBlueprintCompiler;
	FDelegateHandle AssetPostImportHandle;
	FDelegateHandle ObjectPropertyChangedHandle;
	SDockTab* StudioTab = nullptr;
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	FDelegateHandle TickerHandle;
#else
	FTSTicker::FDelegateHandle TickerHandle;
#endif
};

TWeakPtr<SWindow> FNoesisEditorModule::WeakWelcomeWindow;
INoesisEditorModuleInterface* FNoesisEditorModule::NoesisEditorModuleInterface = 0;

INoesisEditorModuleInterface& INoesisEditorModuleInterface::Get()
{
	return *FNoesisEditorModule::NoesisEditorModuleInterface;
}

IMPLEMENT_MODULE(FNoesisEditorModule, NoesisEditor);
DEFINE_LOG_CATEGORY(LogNoesisEditor);

#undef LOCTEXT_NAMESPACE
