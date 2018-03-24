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
#include "NoesisEditorUserSettings.h"

// KismetCompiler includes
#include "KismetCompiler.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

void FixPremultipliedPNGTexture(UTexture2D* Texture)
{
	if (!GetDefault<UNoesisSettings>()->RestoreUITexturePNGPremultipliedAlpha)
	{
		return;
	}

	if (Texture->LODGroup != TEXTUREGROUP_UI)
	{
		return;
	}

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

void OnObjectReimported(UFactory* ImportFactory, UObject* InObject)
{
	for (TObjectIterator<UNoesisXaml> It; It; ++It)
	{
		UNoesisXaml* Xaml = *It;
		Xaml->DestroyThumbnailRenderData();
	}

	if (InObject->IsA<UTexture2D>())
	{
		UTexture2D* Texture = (UTexture2D*)InObject;
		FixPremultipliedPNGTexture(Texture);
	}
}

void OnObjectPropertyChanged(UObject* Object, struct FPropertyChangedEvent& Event)
{
	static FName LODGroup = "LODGroup";
	if (Object->IsA<UTexture2D>() && Event.Property && Event.Property->GetFName() == LODGroup)
	{
		UTexture2D* Texture = (UTexture2D*)Object;
		FixPremultipliedPNGTexture(Texture);
	}
}

TSharedPtr<FKismetCompilerContext> GetCompilerForNoesisBlueprint(UBlueprint* Blueprint, FCompilerResultsLog& Results, const FKismetCompilerOptions& CompilerOptions)
{
	UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
	return TSharedPtr<FKismetCompilerContext>(new FNoesisBlueprintCompilerContext(NoesisBlueprint, Results, CompilerOptions, nullptr));
}

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
		FKismetCompilerContext::RegisterCompilerForBP(UNoesisBlueprint::StaticClass(), &GetCompilerForNoesisBlueprint);

		// Register settings
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->RegisterSettings("Project", "Plugins", "NoesisGUI",
				LOCTEXT("NoesisSettingsName", "NoesisGUI"),
				LOCTEXT("NoesisSettingsDescroption", "Configure the NoesisGUI plugin."),
				GetMutableDefault<UNoesisSettings>());

			SettingsModule->RegisterSettings("Editor", "Plugins", "NoesisGUI",
				LOCTEXT("NoesisEditorUserSettingsName", "NoesisGUI Editor"),
				LOCTEXT("NoesisEditorUserSettingsDescription", "Configure the NoesisGUI editor."),
				GetMutableDefault<UNoesisEditorUserSettings>()
			);
		}

		// Register thumbnail renderers
		UThumbnailManager::Get().RegisterCustomRenderer(UNoesisXaml::StaticClass(), UNoesisXamlThumbnailRenderer::StaticClass());

		NoesisEditorModuleInterface = this;

		AssetImportHandle = FEditorDelegates::OnAssetPostImport.AddStatic(&OnObjectReimported);

		ObjectPropertyChangedHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddStatic(&OnObjectPropertyChanged);
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

		if (AssetImportHandle.IsValid())
		{
			FEditorDelegates::OnAssetPostImport.Remove(AssetImportHandle);
		}

		if (ObjectPropertyChangedHandle.IsValid())
		{
			FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(ObjectPropertyChangedHandle);
		}
	}
	// End of IModuleInterface interface

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
