////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisEditorModule.h"

// NoesisEditor includes
#include "NoesisBlueprintAssetTypeActions.h"
#include "NoesisXamlAssetTypeActions.h"
#include "NoesisBlueprintCompiler.h"
#include "NoesisXamlThumbnailRenderer.h"
#include "NoesisStyle.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

class FNoesisEditorModule : public INoesisEditorModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
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

		// Register settings
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->RegisterSettings("Project", "Plugins", "NoesisGUI",
				LOCTEXT("NoesisSettingsName", "NoesisGUI"),
				LOCTEXT("NoesisSettingsDescroption", "Configure the NoesisGUI plugin"),
				GetMutableDefault<UNoesisSettings>());
		}

		// Register thumbnail renderers
		UThumbnailManager::Get().RegisterCustomRenderer(UNoesisXaml::StaticClass(), UNoesisXamlThumbnailRenderer::StaticClass());

		NoesisEditorModuleInterface = this;
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
		}
	}
	// End of IModuleInterface interface

	static INoesisEditorModuleInterface* NoesisEditorModuleInterface;

private:
	TSharedPtr<FNoesisBlueprintAssetTypeActions> NoesisBlueprintAssetTypeActions;
	TSharedPtr<FNoesisXamlAssetTypeActions> NoesisXamlAssetTypeActions;
	TSharedPtr<FNoesisBlueprintCompiler> NoesisBlueprintCompiler;
};

INoesisEditorModuleInterface* FNoesisEditorModule::NoesisEditorModuleInterface = 0;

INoesisEditorModuleInterface* INoesisEditorModuleInterface::Get()
{
	return FNoesisEditorModule::NoesisEditorModuleInterface;
}

IMPLEMENT_MODULE(FNoesisEditorModule, NoesisEditor);
DEFINE_LOG_CATEGORY(LogNoesisEditor);

#undef LOCTEXT_NAMESPACE
