////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintEditorToolbar.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

// Kismet includes
#include "BlueprintEditorContext.h"
#include "WorkflowOrientedApp/SModeWidget.h"

// NoesisEditor includes
#include "NoesisBlueprintEditor.h"
#include "NoesisBlueprintApplicationModes.h"
#include "SBlueprintModeSeparator.h"
#include "NoesisBlueprintEditorCommands.h"

// Slate includes
#include "Widgets/Layout/SSpacer.h"

// ToolMenus includes
#include "ToolMenuSection.h"
#include "ToolMenu.h"

// UnrealEd includes
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

FNoesisBlueprintEditorToolbar::FNoesisBlueprintEditorToolbar(TSharedPtr<FNoesisBlueprintEditor>& InBlueprintEditor)
	: BlueprintEditor(InBlueprintEditor)
{
}

void FNoesisBlueprintEditorToolbar::AddNoesisBlueprintEditorModesToolbar(TSharedPtr<FExtender> Extender)
{
	TSharedPtr<FNoesisBlueprintEditor> BlueprintEditorPtr = BlueprintEditor.Pin();

	Extender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		BlueprintEditorPtr->GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateSP(this, &FNoesisBlueprintEditorToolbar::FillNoesisBlueprintEditorModesToolbar));
}

void FNoesisBlueprintEditorToolbar::FillNoesisBlueprintEditorModesToolbar(FToolBarBuilder& ToolbarBuilder)
{
	TSharedPtr<FNoesisBlueprintEditor> BlueprintEditorPtr = BlueprintEditor.Pin();

	UBlueprint* BlueprintObj = BlueprintEditorPtr->GetBlueprintObj();

	if (!BlueprintObj ||
		(!FBlueprintEditorUtils::IsLevelScriptBlueprint(BlueprintObj)
			&& !FBlueprintEditorUtils::IsInterfaceBlueprint(BlueprintObj)
			&& !BlueprintObj->bIsNewlyCreated)
		)
	{
		TAttribute<FName> GetActiveMode(BlueprintEditorPtr.ToSharedRef(), &FBlueprintEditor::GetCurrentMode);
		FOnModeChangeRequested SetActiveMode = FOnModeChangeRequested::CreateSP(BlueprintEditorPtr.ToSharedRef(), &FBlueprintEditor::SetCurrentMode);

		// Left side padding
		BlueprintEditorPtr->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));

		BlueprintEditorPtr->AddToolbarWidget(
			SNew(SModeWidget, FNoesisBlueprintApplicationModes::GetLocalizedMode(FNoesisBlueprintApplicationModes::PreviewMode), FNoesisBlueprintApplicationModes::PreviewMode)
			.OnGetActiveMode(GetActiveMode)
			.OnSetActiveMode(SetActiveMode)
#if UE_VERSION_OLDER_THAN(5, 1, 0)
			.IconImage(FEditorStyle::GetBrush("UMGEditor.SwitchToDesigner"))
#else
			.IconImage(FAppStyle::GetBrush("UMGEditor.SwitchToDesigner"))
#endif
#if UE_VERSION_OLDER_THAN(5, 0, 0)
			.SmallIconImage(FEditorStyle::GetBrush("UMGEditor.SwitchToDesigner.Small"))
#endif
			.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("PreviewMode")))
		);

		BlueprintEditorPtr->AddToolbarWidget(SNew(SBlueprintModeSeparator));

		BlueprintEditorPtr->AddToolbarWidget(
			SNew(SModeWidget, FNoesisBlueprintApplicationModes::GetLocalizedMode(FNoesisBlueprintApplicationModes::GraphMode), FNoesisBlueprintApplicationModes::GraphMode)
			.OnGetActiveMode(GetActiveMode)
			.OnSetActiveMode(SetActiveMode)
			.CanBeSelected(BlueprintEditorPtr.Get(), &FBlueprintEditor::IsEditingSingleBlueprint)
			.ToolTipText(LOCTEXT("GraphModeButtonTooltip", "Switch to Graph Editing Mode"))
#if UE_VERSION_OLDER_THAN(5, 1, 0)
			.IconImage(FEditorStyle::GetBrush("FullBlueprintEditor.SwitchToScriptingMode"))
#else
			.IconImage(FAppStyle::GetBrush("FullBlueprintEditor.SwitchToScriptingMode"))
#endif
#if UE_VERSION_OLDER_THAN(5, 0, 0)
			.SmallIconImage(FEditorStyle::GetBrush("FullBlueprintEditor.SwitchToScriptingMode.Small"))
#endif
			.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("GraphMode")))
		);

		// Right side padding
		BlueprintEditorPtr->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));
	}
}

void FNoesisBlueprintEditorToolbar::AddNoesisControls(UToolMenu* InMenu)
{
	FToolMenuSection& Section = InMenu->AddSection("Preview");
	Section.InsertPosition = FToolMenuInsert("Asset", EToolMenuInsertType::After);

	Section.AddDynamicEntry("PreviewCommands", FNewToolMenuSectionDelegate::CreateLambda([](FToolMenuSection& InSection)
	{
		UBlueprintEditorToolMenuContext* Context = InSection.FindContext<UBlueprintEditorToolMenuContext>();
		if (Context && Context->GetBlueprintObj())
		{
			const FNoesisBlueprintEditorCommands& Commands = FNoesisBlueprintEditorCommands::Get();
			InSection.AddEntry(FToolMenuEntry::InitToolBarButton(Commands.RestartPreview));
		}
	}));
}

#undef LOCTEXT_NAMESPACE
