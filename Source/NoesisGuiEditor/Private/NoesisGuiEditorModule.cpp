////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisGuiEditorModule.h"

class FNoesisGuiEditorModule : public INoesisGuiEditorModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		// Register asset type actions
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		NoesisGuiBlueprintAssetTypeActions = MakeShareable(new FNoesisGuiBlueprintAssetTypeActions());
		AssetTools.RegisterAssetTypeActions(NoesisGuiBlueprintAssetTypeActions.ToSharedRef());

		// Register blueprint compiler
		NoesisGuiBlueprintCompiler = MakeShareable(new FNoesisGuiBlueprintCompiler());
		IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
		KismetCompilerModule.GetCompilers().Add(NoesisGuiBlueprintCompiler.Get());

		NoesisGuiEditorModuleInterface = this;
	}

	virtual void ShutdownModule() override
	{
		NoesisGuiEditorModuleInterface = 0;

		// Unregister asset type actions
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		AssetTools.UnregisterAssetTypeActions(NoesisGuiBlueprintAssetTypeActions.ToSharedRef());

		// Unregister blueprint compiler
		IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
		KismetCompilerModule.GetCompilers().Remove(NoesisGuiBlueprintCompiler.Get());
	}
	// End of IModuleInterface interface

	static INoesisGuiEditorModuleInterface* NoesisGuiEditorModuleInterface;

private:
	TSharedPtr<FNoesisGuiBlueprintAssetTypeActions> NoesisGuiBlueprintAssetTypeActions;
	TSharedPtr<FNoesisGuiBlueprintCompiler> NoesisGuiBlueprintCompiler;
};

INoesisGuiEditorModuleInterface* FNoesisGuiEditorModule::NoesisGuiEditorModuleInterface = 0;

INoesisGuiEditorModuleInterface* INoesisGuiEditorModuleInterface::Get()
{
	return FNoesisGuiEditorModule::NoesisGuiEditorModuleInterface;
}

IMPLEMENT_MODULE(FNoesisGuiEditorModule, NoesisGuiEditor);
DEFINE_LOG_CATEGORY(LogNoesisGuiEditor);
