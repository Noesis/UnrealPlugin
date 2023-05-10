////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlAssetTypeActions.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"

// BlueprintGraph includes
#include "BlueprintNodeTemplateCache.h"
#include "K2Node_CallFunction.h"
#include "K2Node_Event.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"
#include "Engine/LevelScriptBlueprint.h"
#include "Kismet/GameplayStatics.h"

// NoesisRuntime includes
#include "NoesisBlueprint.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisInstance.h"
#include "NoesisXaml.h"

// Slate includes
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBorder.h"

// SlateCore includes
#include "Styling/SlateIconFinder.h"

// ToolMenus includes
#include "ToolMenuSection.h"

// UMG includes
#include "Blueprint/WidgetBlueprintLibrary.h"

// UnrealEd includes
#include "ObjectTools.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

FNoesisXamlAssetTypeActions::FNoesisXamlAssetTypeActions(EAssetTypeCategories::Type InCategories)
	: Categories(InCategories)
{
};

bool FNoesisXamlAssetTypeActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return true;
}

void FNoesisXamlAssetTypeActions::GetActions(const TArray<UObject*>& InObjects, FToolMenuSection& Section)
{
	auto Xamls = GetTypedWeakObjectPtrs<UNoesisXaml>(InObjects);

	Section.AddMenuEntry(
		"NoesisXaml_AddToViewport",
		LOCTEXT("NoesisXaml_AddToViewport", "Add to Viewport"),
		LOCTEXT("NoesisXaml_AddToViewportTooltip", "Create a NoesisView and add it to the Viewport in the current Level."),
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FSlateIcon(FEditorStyle::GetStyleSetName(), "ClassIcon.Widget"),
#else
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.Widget"),
#endif
		FUIAction(
			FExecuteAction::CreateSP(this, &FNoesisXamlAssetTypeActions::AddToViewport, Xamls),
			FCanExecuteAction()
		)
	);
}

FText FNoesisXamlAssetTypeActions::GetName() const
{
	return LOCTEXT("NoesisXamlAssetTypeActions_Name", "NoesisGUI");
}

UClass* FNoesisXamlAssetTypeActions::GetSupportedClass() const
{
	return UNoesisXaml::StaticClass();
}

FColor FNoesisXamlAssetTypeActions::GetTypeColor() const
{
	return FColor(42, 166, 226);
}

uint32 FNoesisXamlAssetTypeActions::GetCategories()
{
	return Categories;
}

// This is copied from SAssetThumbnail::ShouldRender
static bool ShouldRender(const FAssetData& AssetData)
{
	// Never render a thumbnail for an invalid asset
	if (!AssetData.IsValid())
	{
		return false;
	}

	if (AssetData.IsAssetLoaded())
	{
		// Loaded asset, return true if there is a rendering info for it
		UObject* Asset = AssetData.GetAsset();
		FThumbnailRenderingInfo* RenderInfo = GUnrealEd->GetThumbnailManager()->GetRenderingInfo(Asset);
		if (RenderInfo != NULL && RenderInfo->Renderer != NULL)
		{
			return true;
		}
	}

	const FObjectThumbnail* CachedThumbnail = ThumbnailTools::FindCachedThumbnail(*AssetData.GetFullName());
	if (CachedThumbnail != NULL)
	{
		// There is a cached thumbnail for this asset, we should render it
		return !CachedThumbnail->IsEmpty();
	}

#if UE_VERSION_OLDER_THAN(5, 1, 0)
	if (AssetData.AssetClass != UBlueprint::StaticClass()->GetFName())
#else
	if (AssetData.AssetClassPath != UBlueprint::StaticClass()->GetClassPathName())
#endif
	{
		// If we are not a blueprint, see if the CDO of the asset's class has a rendering info
		// Blueprints can't do this because the rendering info is based on the generated class
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		UClass* AssetClass = FindObject<UClass>(nullptr, *AssetData.AssetClass.ToString());
#else
		UClass* AssetClass = FindObject<UClass>(nullptr, *AssetData.AssetClassPath.ToString());
#endif

		if (AssetClass)
		{
			FThumbnailRenderingInfo* RenderInfo = GUnrealEd->GetThumbnailManager()->GetRenderingInfo(AssetClass->GetDefaultObject());
			if (RenderInfo != NULL && RenderInfo->Renderer != NULL)
			{
				return true;
			}
		}
	}

	// Unloaded blueprint or asset that may have a custom thumbnail, check to see if there is a thumbnail in the package to render
	FString PackageFilename;
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	if (FPackageName::DoesPackageExist(AssetData.PackageName.ToString(), NULL, &PackageFilename))
#else
	if (FPackageName::DoesPackageExist(AssetData.PackageName.ToString(), &PackageFilename))
#endif
	{
		TSet<FName> ObjectFullNames;
		FThumbnailMap ThumbnailMap;

		FName ObjectFullName = FName(*AssetData.GetFullName());
		ObjectFullNames.Add(ObjectFullName);

		ThumbnailTools::LoadThumbnailsFromPackage(PackageFilename, ObjectFullNames, ThumbnailMap);

		const FObjectThumbnail* ThumbnailPtr = ThumbnailMap.Find(ObjectFullName);
		if (ThumbnailPtr)
		{
			const FObjectThumbnail& ObjectThumbnail = *ThumbnailPtr;
			return ObjectThumbnail.GetImageWidth() > 0 && ObjectThumbnail.GetImageHeight() > 0 && ObjectThumbnail.GetUncompressedImageData().Num() > 0;
		}
	}

	return false;
}

void FNoesisXamlAssetTypeActions::GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const
{
	for (auto& Asset : TypeAssets)
	{
		UNoesisXaml* Xaml = CastChecked<UNoesisXaml>(Asset);
		Xaml->AssetImportData->ExtractFilenames(OutSourceFilePaths);
	}
}

TSharedPtr<SWidget> FNoesisXamlAssetTypeActions::GetThumbnailOverlay(const FAssetData& AssetData) const
{
	/*if (!ShouldRender(AssetData))
	{
		return nullptr;
	}*/
	
	const FSlateBrush* Icon = FSlateIconFinder::FindIconBrushForClass(UNoesisXaml::StaticClass());

	return SNew(SBorder)
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		.BorderImage(FEditorStyle::GetNoBrush())
#else
		.BorderImage(FAppStyle::GetNoBrush())
#endif
		.Visibility(EVisibility::HitTestInvisible)
		.Padding(FMargin(0.0f, 0.0f, 0.0f, 3.0f))
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SImage)
			.Image(Icon)
		];
}

void FNoesisXamlAssetTypeActions::AddToViewport(TArray<TWeakObjectPtr<UNoesisXaml>> Objects)
{
#if WITH_EDITORONLY_DATA
	if (GEditor == nullptr)
		return;
	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (World == nullptr)
		return;
	ULevel* Level = World->GetCurrentLevel();
	if (Level == nullptr)
		return;
	ULevelScriptBlueprint* LevelScriptBlueprint = Level->GetLevelScriptBlueprint();
	if (LevelScriptBlueprint == nullptr)
		return;
	UEdGraph* LevelEventGraph = FBlueprintEditorUtils::FindEventGraph(LevelScriptBlueprint);
	if (LevelEventGraph == nullptr)
		return;

	bool const bIsTemplateNode = FBlueprintNodeTemplateCache::IsTemplateOuter(LevelEventGraph);

	// Create the new NoesisBlueprint, if it doesn't already exist.
	FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
	UNoesisXaml* Xaml = Objects[0].Get();
	UPackage* Package = Xaml->GetOutermost();
	FString PackageRoot;
	FString PackagePath;
	FString PackageName;
	FPackageName::SplitLongPackageName(Package->GetPathName(), PackageRoot, PackagePath, PackageName, false);
	UNoesisBlueprint* View = LoadObject<UNoesisBlueprint>(nullptr, *(PackageRoot + PackagePath + "View." + "View"), nullptr, LOAD_NoWarn);
	if (View == nullptr)
	{
		FString ViewPackageName, ViewAssetName;
		AssetToolsModule.Get().CreateUniqueAssetName(PackageRoot + PackagePath, TEXT("View"), ViewPackageName, ViewAssetName);
		UPackage* ViewPackage = CreatePackage(*ViewPackageName);
		View = CastChecked<UNoesisBlueprint>(FKismetEditorUtilities::CreateBlueprint(UNoesisInstance::StaticClass(), ViewPackage, FName(*ViewAssetName), BPTYPE_Normal, UNoesisBlueprint::StaticClass(), UNoesisBlueprintGeneratedClass::StaticClass(), "UNoesisBlueprintFactory"));
		View->EnablePPAA = true;
		FAssetRegistryModule::AssetCreated(View);
	}
	if (View->BaseXaml != Xaml)
	{
		View->BaseXaml = Xaml;
		FKismetEditorUtilities::CompileBlueprint(View, EBlueprintCompileOptions::None);
		View->MarkPackageDirty();
	}

	UEdGraphPin* ContinuationExecPin = nullptr;

	// Create the BeginPlay event node, if it doesn't exist.
	UClass* ActorClass = AActor::StaticClass();
	UK2Node_Event* BeginPlayNode = FBlueprintEditorUtils::FindOverrideForFunction(LevelScriptBlueprint, ActorClass, TEXT("ReceiveBeginPlay"));
	if (BeginPlayNode == nullptr)
	{
		UClass* EventClass = LoadObject<UClass>(nullptr, TEXT("/Script/BlueprintGraph.K2Node_Event"));

		BeginPlayNode = NewObject<UK2Node_Event>(LevelEventGraph, EventClass);
		check(BeginPlayNode != nullptr);
		BeginPlayNode->CreateNewGuid();

		UFunction* ReceiveBeginPlay = ActorClass->FindFunctionByName(TEXT("ReceiveBeginPlay"));
		BeginPlayNode->EventReference.SetFromField<UFunction>(ReceiveBeginPlay, false);
		BeginPlayNode->bOverrideFunction = true;

		BeginPlayNode->NodePosX = 0;
		BeginPlayNode->NodePosY = 0;

		if (!bIsTemplateNode)
		{
			BeginPlayNode->SetFlags(RF_Transactional);
			BeginPlayNode->AllocateDefaultPins();
			BeginPlayNode->PostPlacedNewNode();
			LevelEventGraph->AddNode(BeginPlayNode, false, false);
		}
	}

	UEdGraphPin* BeginPlayNodeThenPin = BeginPlayNode->FindPin(UEdGraphSchema_K2::PN_Then);

	// Create the CreateWidget node, if it doesn't exist
	UClass* CreateWidgetClass = LoadObject<UClass>(nullptr, TEXT("/Script/UMGEditor.K2Node_CreateWidget"));
	UEdGraphNode* CreateWidgetNode = nullptr;
	TArray<UEdGraphPin*> BeginPlayNodeThenLinks = BeginPlayNodeThenPin->LinkedTo;
	if (BeginPlayNodeThenLinks.Num() > 0)
	{
		UEdGraphPin* BeginPlayNodeThenLink = BeginPlayNodeThenLinks[0];
		UEdGraphNode* BeginPlayNodeThenNode = BeginPlayNodeThenLink->GetOuter();
		if (BeginPlayNodeThenNode->GetClass() == CreateWidgetClass)
		{
			CreateWidgetNode = BeginPlayNodeThenNode;
		}
		else
		{
			ContinuationExecPin = BeginPlayNodeThenLink;
			BeginPlayNodeThenPin->BreakAllPinLinks();
		}
	}
	if (CreateWidgetNode == nullptr)
	{
		CreateWidgetNode = NewObject<UEdGraphNode>(LevelEventGraph, CreateWidgetClass);
		check(CreateWidgetNode != nullptr);
		CreateWidgetNode->CreateNewGuid();

		CreateWidgetNode->NodePosX = 200;
		CreateWidgetNode->NodePosY = 0;

		if (!bIsTemplateNode)
		{
			CreateWidgetNode->SetFlags(RF_Transactional);
			CreateWidgetNode->AllocateDefaultPins();
			CreateWidgetNode->PostPlacedNewNode();
			LevelEventGraph->AddNode(CreateWidgetNode, false, false);
		}
	}

	UEdGraphPin* CreateWidgetNodeExecPin = CreateWidgetNode->FindPin(UEdGraphSchema_K2::PN_Execute);
	UEdGraphPin* CreateWidgetNodeThenPin = CreateWidgetNode->FindPin(UEdGraphSchema_K2::PN_Then);
	UEdGraphPin* CreateWidgetNodeClassPin = CreateWidgetNode->FindPin(TEXT("Class"));
	UEdGraphPin* CreateWidgetNodeReturnValuePin = CreateWidgetNode->FindPin(UEdGraphSchema_K2::PN_ReturnValue);

	// Create the AddToViewport node, if it doesn't exist
	UClass* CallFunctionClass = UK2Node_CallFunction::StaticClass();
	UK2Node_CallFunction* AddToViewportNode = nullptr;
	TArray<UEdGraphPin*> CreateWidgetNodeThenLinks = CreateWidgetNodeThenPin->LinkedTo;
	if (CreateWidgetNodeThenLinks.Num() > 0)
	{
		UEdGraphPin* CreateWidgetNodeThenLink = CreateWidgetNodeThenLinks[0];
		UK2Node_CallFunction* CreateWidgetNodeThenNode = Cast< UK2Node_CallFunction>(CreateWidgetNodeThenLink->GetOuter());
		if (CreateWidgetNodeThenNode != nullptr &&
			CreateWidgetNodeThenNode->FunctionReference.GetMemberName() == TEXT("AddToViewport") &&
			CreateWidgetNodeThenNode->FunctionReference.GetMemberParentClass() == UUserWidget::StaticClass())
		{
			AddToViewportNode = CreateWidgetNodeThenNode;
		}
		else
		{
			ContinuationExecPin = CreateWidgetNodeThenLink;
			CreateWidgetNodeThenPin->BreakAllPinLinks();
		}
	}
	if (AddToViewportNode == nullptr)
	{
		AddToViewportNode = NewObject<UK2Node_CallFunction>(LevelEventGraph, CallFunctionClass);
		check(AddToViewportNode != nullptr);
		AddToViewportNode->CreateNewGuid();

		AddToViewportNode->FunctionReference.SetExternalMember(TEXT("AddToViewport"), UUserWidget::StaticClass());

		AddToViewportNode->NodePosX = 600;
		AddToViewportNode->NodePosY = 0;

		if (!bIsTemplateNode)
		{
			AddToViewportNode->SetFlags(RF_Transactional);
			AddToViewportNode->AllocateDefaultPins();
			AddToViewportNode->PostPlacedNewNode();
			LevelEventGraph->AddNode(AddToViewportNode, false, false);
		}
	}

	UEdGraphPin* AddToViewportNodeExecPin = AddToViewportNode->FindPin(UEdGraphSchema_K2::PN_Execute);
	UEdGraphPin* AddToViewportNodeThenPin = AddToViewportNode->FindPin(UEdGraphSchema_K2::PN_Then);
	UEdGraphPin* AddToViewportNodeSelfPin = AddToViewportNode->FindPin(UEdGraphSchema_K2::PN_Self);

	// Create the SetInputMode node, if it doesn't exist
	UK2Node_CallFunction* SetInputModeNode = nullptr;
	TArray<UEdGraphPin*> AddToViewportNodeThenLinks = AddToViewportNodeThenPin->LinkedTo;
	if (AddToViewportNodeThenLinks.Num() > 0)
	{
		UEdGraphPin* AddToViewportNodeThenLink = AddToViewportNodeThenLinks[0];
		UK2Node_CallFunction* AddToViewportNodeThenNode = Cast< UK2Node_CallFunction>(AddToViewportNodeThenLink->GetOuter());
		if (AddToViewportNodeThenNode != nullptr &&
			AddToViewportNodeThenNode->FunctionReference.GetMemberName() == TEXT("SetInputMode_GameAndUIEx") &&
			AddToViewportNodeThenNode->FunctionReference.GetMemberParentClass() == UWidgetBlueprintLibrary::StaticClass())
		{
			SetInputModeNode = AddToViewportNodeThenNode;
		}
		else
		{
			ContinuationExecPin = AddToViewportNodeThenLink;
			AddToViewportNodeThenPin->BreakAllPinLinks();
		}
	}
	if (SetInputModeNode == nullptr)
	{
		SetInputModeNode = NewObject<UK2Node_CallFunction>(LevelEventGraph, CallFunctionClass);
		check(SetInputModeNode != nullptr);
		SetInputModeNode->CreateNewGuid();

		SetInputModeNode->FunctionReference.SetExternalMember(TEXT("SetInputMode_GameAndUIEx"), UWidgetBlueprintLibrary::StaticClass());

		SetInputModeNode->NodePosX = 900;
		SetInputModeNode->NodePosY = 0;

		if (!bIsTemplateNode)
		{
			SetInputModeNode->SetFlags(RF_Transactional);
			SetInputModeNode->AllocateDefaultPins();
			SetInputModeNode->PostPlacedNewNode();
			LevelEventGraph->AddNode(SetInputModeNode, false, false);
		}
	}

	UEdGraphPin* SetInputModeNodeExecPin = SetInputModeNode->FindPin(UEdGraphSchema_K2::PN_Execute);
	UEdGraphPin* SetInputModeNodeThenPin = SetInputModeNode->FindPin(UEdGraphSchema_K2::PN_Then);
	UEdGraphPin* SetInputModeNodePlayerControllerPin = SetInputModeNode->FindPin(TEXT("PlayerController"));
	UEdGraphPin* SetInputModeNodeWidgetPin = SetInputModeNode->FindPin(TEXT("InWidgetToFocus"));

	// Create the SetKeyboardFocus node, if it doesn't exist
	UK2Node_CallFunction* SetKeyboardFocusNode = nullptr;
	TArray<UEdGraphPin*> SetInputModeNodeThenLinks = SetInputModeNodeThenPin->LinkedTo;
	if (SetInputModeNodeThenLinks.Num() > 0)
	{
		UEdGraphPin* SetInputModeNodeThenLink = SetInputModeNodeThenLinks[0];
		UK2Node_CallFunction* SetInputModeNodeThenNode = Cast< UK2Node_CallFunction>(SetInputModeNodeThenLink->GetOuter());
		if (SetInputModeNodeThenNode != nullptr &&
			SetInputModeNodeThenNode->FunctionReference.GetMemberName() == TEXT("SetKeyboardFocus") &&
			SetInputModeNodeThenNode->FunctionReference.GetMemberParentClass() == UWidget::StaticClass())
		{
			SetKeyboardFocusNode = SetInputModeNodeThenNode;
		}
		else
		{
			ContinuationExecPin = SetInputModeNodeThenLink;
			SetInputModeNodeThenPin->BreakAllPinLinks();
		}
	}
	if (SetKeyboardFocusNode == nullptr)
	{
		SetKeyboardFocusNode = NewObject<UK2Node_CallFunction>(LevelEventGraph, CallFunctionClass);
		check(SetKeyboardFocusNode != nullptr);
		SetKeyboardFocusNode->CreateNewGuid();

		SetKeyboardFocusNode->FunctionReference.SetExternalMember(TEXT("SetKeyboardFocus"), UWidget::StaticClass());

		SetKeyboardFocusNode->NodePosX = 1200;
		SetKeyboardFocusNode->NodePosY = 0;

		if (!bIsTemplateNode)
		{
			SetKeyboardFocusNode->SetFlags(RF_Transactional);
			SetKeyboardFocusNode->AllocateDefaultPins();
			SetKeyboardFocusNode->PostPlacedNewNode();
			LevelEventGraph->AddNode(SetKeyboardFocusNode, false, false);
		}
	}

	UEdGraphPin* SetKeyboardFocusNodeExecPin = SetKeyboardFocusNode->FindPin(UEdGraphSchema_K2::PN_Execute);
	UEdGraphPin* SetKeyboardFocusNodeThenPin = SetKeyboardFocusNode->FindPin(UEdGraphSchema_K2::PN_Then);
	UEdGraphPin* SetKeyboardFocusNodeSelfPin = SetKeyboardFocusNode->FindPin(UEdGraphSchema_K2::PN_Self);

	// Create the GetPlayerController node, if it doesn't exist
	UK2Node_CallFunction* GetPlayerControllerNode = nullptr;
	TArray<UEdGraphPin*> SetInputModeNodePlayerControllerLinks = SetInputModeNodePlayerControllerPin->LinkedTo;
	if (SetInputModeNodePlayerControllerLinks.Num() > 0)
	{
		UEdGraphPin* SetInputModeNodePlayerControllerLink = SetInputModeNodePlayerControllerLinks[0];
		UK2Node_CallFunction* SetInputModeNodePlayerControllerNode = Cast< UK2Node_CallFunction>(SetInputModeNodePlayerControllerLink->GetOuter());
		if (SetInputModeNodePlayerControllerNode != nullptr &&
			SetInputModeNodePlayerControllerNode->FunctionReference.GetMemberName() == TEXT("GetPlayerController") &&
			SetInputModeNodePlayerControllerNode->FunctionReference.GetMemberParentClass() == UGameplayStatics::StaticClass())
		{
			GetPlayerControllerNode = SetInputModeNodePlayerControllerNode;
		}
	}
	if (GetPlayerControllerNode == nullptr)
	{
		GetPlayerControllerNode = NewObject<UK2Node_CallFunction>(LevelEventGraph, CallFunctionClass);
		check(GetPlayerControllerNode != nullptr);
		GetPlayerControllerNode->CreateNewGuid();

		GetPlayerControllerNode->FunctionReference.SetExternalMember(TEXT("GetPlayerController"), UGameplayStatics::StaticClass());

		GetPlayerControllerNode->NodePosX = 600;
		GetPlayerControllerNode->NodePosY = 200;

		if (!bIsTemplateNode)
		{
			GetPlayerControllerNode->SetFlags(RF_Transactional);
			GetPlayerControllerNode->AllocateDefaultPins();
			GetPlayerControllerNode->PostPlacedNewNode();
			LevelEventGraph->AddNode(GetPlayerControllerNode, false, false);
		}
	}

	UEdGraphPin* GetPlayerControllerNodeReturnValuePin = GetPlayerControllerNode->FindPin(UEdGraphSchema_K2::PN_ReturnValue);

	LevelEventGraph->Modify();

	// Route the execution pins
	BeginPlayNodeThenPin->MakeLinkTo(CreateWidgetNodeExecPin);
	CreateWidgetNodeThenPin->MakeLinkTo(AddToViewportNodeExecPin);
	AddToViewportNodeThenPin->MakeLinkTo(SetInputModeNodeExecPin);
	SetInputModeNodeThenPin->MakeLinkTo(SetKeyboardFocusNodeExecPin);
	if (ContinuationExecPin != nullptr)
	{
		SetKeyboardFocusNodeThenPin->BreakAllPinLinks();
		SetKeyboardFocusNodeThenPin->MakeLinkTo(ContinuationExecPin);
	}

	// Route the data pins
	CreateWidgetNodeClassPin->DefaultObject = View->GeneratedClass;
	CreateWidgetNodeReturnValuePin->MakeLinkTo(SetInputModeNodeWidgetPin);
	CreateWidgetNodeReturnValuePin->MakeLinkTo(AddToViewportNodeSelfPin);
	CreateWidgetNodeReturnValuePin->MakeLinkTo(SetKeyboardFocusNodeSelfPin);
	GetPlayerControllerNodeReturnValuePin->MakeLinkTo(SetInputModeNodePlayerControllerPin);

	FKismetEditorUtilities::CompileBlueprint(LevelScriptBlueprint, EBlueprintCompileOptions::None);
#endif
}

#undef LOCTEXT_NAMESPACE
