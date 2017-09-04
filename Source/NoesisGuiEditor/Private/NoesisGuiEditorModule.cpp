////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorModule.h"

class FNoesisGuiEditorModule : public INoesisGuiEditorModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		// Register asset type actions
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		NoesisBlueprintAssetTypeActions = MakeShareable(new FNoesisBlueprintAssetTypeActions());
		AssetTools.RegisterAssetTypeActions(NoesisBlueprintAssetTypeActions.ToSharedRef());

		// Register blueprint compiler
		NoesisBlueprintCompiler = MakeShareable(new FNoesisBlueprintCompiler());
		IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
		KismetCompilerModule.GetCompilers().Add(NoesisBlueprintCompiler.Get());

		NoesisGuiEditorModuleInterface = this;
	}

	virtual void ShutdownModule() override
	{
		NoesisGuiEditorModuleInterface = 0;

		// Unregister asset type actions
		if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
		{
			IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
			AssetTools.UnregisterAssetTypeActions(NoesisBlueprintAssetTypeActions.ToSharedRef());
		}

		// Unregister blueprint compiler
		if (FModuleManager::Get().IsModuleLoaded("KismetCompiler"))
		{
			IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
			KismetCompilerModule.GetCompilers().Remove(NoesisBlueprintCompiler.Get());
		}
	}
	// End of IModuleInterface interface

	static INoesisGuiEditorModuleInterface* NoesisGuiEditorModuleInterface;

private:
	TSharedPtr<FNoesisBlueprintAssetTypeActions> NoesisBlueprintAssetTypeActions;
	TSharedPtr<FNoesisBlueprintCompiler> NoesisBlueprintCompiler;
};

INoesisGuiEditorModuleInterface* FNoesisGuiEditorModule::NoesisGuiEditorModuleInterface = 0;

INoesisGuiEditorModuleInterface* INoesisGuiEditorModuleInterface::Get()
{
	return FNoesisGuiEditorModule::NoesisGuiEditorModuleInterface;
}

IMPLEMENT_MODULE(FNoesisGuiEditorModule, NoesisGuiEditor);
DEFINE_LOG_CATEGORY(LogNoesisGuiEditor);
