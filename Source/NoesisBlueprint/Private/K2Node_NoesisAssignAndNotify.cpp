////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "K2Node_NoesisAssignAndNotify.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

// BlueprintGraph includes
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintFieldNodeSpawner.h"
#include "K2Node_CallFunction.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_Self.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"

// EditorStyle includes
#if UE_VERSION_OLDER_THAN(5, 1, 0)
#include "Classes/EditorStyleSettings.h"
#else
#include "Settings/EditorStyleSettings.h"
#endif

// Engine includes
#include "ObjectEditorUtils.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetTextLibrary.h"
#include "Engine/BlueprintGeneratedClass.h"

// KismetCompiler includes
#include "KismetCompiler.h"

// NoesisRuntime includes
#include "NoesisFunctionLibrary.h"

// UnrealEd includes
#include "EditorCategoryUtils.h"
#include "Editor/EditorEngine.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

static FText GetBaseTooltip(FName VarName)
{
	FFormatNamedArguments Args;
	Args.Add(TEXT("VarName"), FText::FromName(VarName));

	return FText::Format(LOCTEXT("SetVariableTooltip", "Set the value of variable {VarName}"), Args);

}

static bool PropertyHasLocalRepNotify(FProperty const* VariableProperty)
{
	if (VariableProperty != nullptr)
	{
		// We check that the variable is 'defined in a blueprint' so as to avoid 
		// natively defined RepNotifies being called unintentionally. Most(all?) 
		// native rep notifies are intended to be client only. We are moving 
		// away from this paradigm in blueprints. So for now this is somewhat of 
		// a hold over to avoid nasty bugs where a K2 set node is calling a 
		// native function that the designer has no idea what it is doing.
		UBlueprintGeneratedClass* VariableSourceClass = Cast<UBlueprintGeneratedClass>(VariableProperty->GetOwnerClass());
		bool const bIsBlueprintProperty = (VariableSourceClass != nullptr);

		if (bIsBlueprintProperty && (VariableProperty->RepNotifyFunc != NAME_None))
		{
			// Find function (ok if its defined in native class)
			UFunction* Function = VariableSourceClass->FindFunctionByName(VariableProperty->RepNotifyFunc);

			// If valid repnotify func
			if ((Function != nullptr) && (Function->NumParms == 0) && (Function->GetReturnProperty() == nullptr))
			{
				return true;
			}
		}
	}
	return false;
}

static FText GetPropertyTooltip(FProperty const* VariableProperty)
{
	FText TextFormat;
	FFormatNamedArguments Args;

	bool const bHasLocalRepNotify = PropertyHasLocalRepNotify(VariableProperty);

	FName VarName = NAME_None;
	if (VariableProperty != nullptr)
	{
		if (bHasLocalRepNotify)
		{
			Args.Add(TEXT("ReplicationNotifyName"), FText::FromName(VariableProperty->RepNotifyFunc));
			TextFormat = LOCTEXT("SetVariableWithRepNotify_Tooltip", "Set the value of variable {VarName} and call {ReplicationNotifyName}");
		}

		VarName = VariableProperty->GetFName();

		UClass* SourceClass = VariableProperty->GetOwnerClass();
		// discover if the variable property is a non blueprint user variable
		bool const bIsNativeVariable = (SourceClass != nullptr) && (SourceClass->ClassGeneratedBy == nullptr);
		FName const TooltipMetaKey(TEXT("tooltip"));

		FText SubTooltip;
		if (bIsNativeVariable)
		{
			FText const PropertyTooltip = VariableProperty->GetToolTipText();
			if (!PropertyTooltip.IsEmpty())
			{
				// See if the native property has a tooltip
				SubTooltip = PropertyTooltip;
				FString TooltipName = FString::Printf(TEXT("%s.%s"), *VarName.ToString(), *TooltipMetaKey.ToString());
				FText::FindText(*VariableProperty->GetFullGroupName(true), *TooltipName, SubTooltip);
			}
		}
		else if (SourceClass)
		{
			if (UBlueprint* VarBlueprint = Cast<UBlueprint>(SourceClass->ClassGeneratedBy))
			{
				FString UserTooltipData;
				if (FBlueprintEditorUtils::GetBlueprintVariableMetaData(VarBlueprint, VarName, VariableProperty->GetOwnerStruct(), TooltipMetaKey, UserTooltipData))
				{
					SubTooltip = FText::FromString(UserTooltipData);
				}
			}
		}

		if (!SubTooltip.IsEmpty())
		{
			Args.Add(TEXT("PropertyTooltip"), SubTooltip);
			if (bHasLocalRepNotify)
			{
				TextFormat = LOCTEXT("SetVariablePropertyWithRepNotify_Tooltip", "Set the value of variable {VarName} and call {ReplicationNotifyName}\n{PropertyTooltip}");
			}
			else
			{
				TextFormat = LOCTEXT("SetVariableProperty_Tooltip", "Set the value of variable {VarName}\n{PropertyTooltip}");
			}
		}
	}

	if (TextFormat.IsEmpty())
	{
		return GetBaseTooltip(VarName);
	}
	else
	{
		Args.Add(TEXT("VarName"), FText::FromName(VarName));
		return FText::Format(TextFormat, Args);
	}
}

static UBlueprintFieldNodeSpawner* CreateSpawnerFromMemberOrParam(TSubclassOf<UK2Node> Class, FProperty const* VarProperty)
{
	check(VarProperty != nullptr);

	//--------------------------------------
	// Constructing the Spawner
	//--------------------------------------

	UBlueprintFieldNodeSpawner* NodeSpawner = UBlueprintFieldNodeSpawner::Create(Class, VarProperty);

	//--------------------------------------
	// Default UI Signature
	//--------------------------------------

	FBlueprintActionUiSpec& MenuSignature = NodeSpawner->DefaultMenuSignature;
	FString const VarSubCategory = FObjectEditorUtils::GetCategory(VarProperty);
	MenuSignature.Category = FEditorCategoryUtils::BuildCategoryString(FCommonEditorCategory::Variables, FText::FromString(VarSubCategory));

	bool bShowFriendlyNames = GetDefault<UEditorStyleSettings>()->bShowFriendlyNames;
	FText const VarName = bShowFriendlyNames ? FText::FromString(UEditorEngine::GetFriendlyName(VarProperty)) : FText::FromName(VarProperty->GetFName());
	// @TODO: NodeClass could be modified post Create()
	MenuSignature.MenuName = FText::Format(LOCTEXT("UK2Node_NoesisAssignAndNotifyTitle", "Set {0} w/ NotifyChanged"), VarName);
	MenuSignature.Tooltip = GetPropertyTooltip(VarProperty);

	// add at least one character, so that PrimeDefaultUiSpec() doesn't 
	// attempt to query the template node
	//
	// @TODO: maybe UPROPERTY() fields should have keyword metadata like functions
	if (MenuSignature.Keywords.IsEmpty())
	{
		// want to set it to something so we won't end up back in this condition
		MenuSignature.Keywords = FText::FromString(TEXT(" "));
	}
	FEdGraphPinType VarType;
	UEdGraphSchema_K2 const* K2Schema = GetDefault<UEdGraphSchema_K2>();
	K2Schema->ConvertPropertyToPinType(VarProperty, VarType);
	MenuSignature.Icon = UK2Node_Variable::GetVarIconFromPinType(VarType, MenuSignature.IconTint);

	//--------------------------------------
	// Post-Spawn Setup
	//--------------------------------------

	auto MemberVarSetupLambda = [](UEdGraphNode* NewNode, FFieldVariant InField)
	{
		if (FProperty const* Property = CastField<FProperty>(InField.ToField()))
		{
			UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForNodeChecked(NewNode);
			UClass* OwnerClass = Property->GetOwnerClass();

			// We need to use a generated class instead of a skeleton class for IsChildOf, so if the OwnerClass has a Blueprint, grab the GeneratedClass
			const bool bOwnerClassIsSelfContext = (Blueprint->SkeletonGeneratedClass->GetAuthoritativeClass() == OwnerClass) || Blueprint->SkeletonGeneratedClass->IsChildOf(OwnerClass);
			const bool bIsFunctionVariable = Property->GetOwner<UFunction>() != nullptr;

			UK2Node_NoesisAssignAndNotify* VarNode = CastChecked<UK2Node_NoesisAssignAndNotify>(NewNode);
			VarNode->SetFromProperty(Property, bOwnerClassIsSelfContext && !bIsFunctionVariable, OwnerClass);
		}
	};
	NodeSpawner->SetNodeFieldDelegate = UBlueprintFieldNodeSpawner::FSetNodeFieldDelegate::CreateStatic(MemberVarSetupLambda);

	return NodeSpawner;
}

UK2Node_NoesisAssignAndNotify::UK2Node_NoesisAssignAndNotify(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UK2Node_NoesisAssignAndNotify::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, FName(), nullptr, UEdGraphSchema_K2::PN_Execute);
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, FName(), nullptr, UEdGraphSchema_K2::PN_Then);

	if (GetVarName() != NAME_None)
	{
		if (CreatePinForVariable(EGPD_Input))
		{
			CreatePinForSelf();
		}

		if (CreatePinForVariable(EGPD_Output, GetVariableOutputPinName()))
		{
			CreateOutputPinTooltip();
		}
	}

	Super::AllocateDefaultPins();
}

FName UK2Node_NoesisAssignAndNotify::GetVariableOutputPinName() const
{
	return TEXT("Output_Get");
}

void UK2Node_NoesisAssignAndNotify::CreateOutputPinTooltip()
{
	UEdGraphPin* Pin = FindPin(GetVariableOutputPinName());
	check(Pin);
	Pin->PinToolTip = NSLOCTEXT("K2Node", "SetPinOutputTooltip", "Retrieves the value of the variable, can use instead of a separate Get node").ToString();
}

FText UK2Node_NoesisAssignAndNotify::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	FFormatNamedArguments FormatArgs;
	FormatArgs.Add(TEXT("VarName"), FText::FromName(GetVarName()));
	if (TitleType == ENodeTitleType::FullTitle)
	{
		return FText::Format(LOCTEXT("UK2Node_NoesisAssignAndNotifyTitleFull", "Set {VarName}\nw/ NotifyChanged"), FormatArgs);
	}
	else
	{
		return FText::Format(LOCTEXT("UK2Node_NoesisAssignAndNotifyTitle", "Set {VarName} w/ NotifyChanged"), FormatArgs);
	}
}

FText UK2Node_NoesisAssignAndNotify::GetTooltipText() const
{
	FFormatNamedArguments FormatArgs;
	FormatArgs.Add(TEXT("VarName"), FText::FromName(GetVarName()));
	FormatArgs.Add(TEXT("ClassName"), FText::FromName(GetVariableSourceClass()->GetFName()));
	return FText::Format(LOCTEXT("SetVariableTooltip", "Set the value of variable {VarName} with NotifyChanged (class is {ClassName})"), FormatArgs);
}

void UK2Node_NoesisAssignAndNotify::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	const UBlueprint* Blueprint = Cast<UBlueprint>(ActionRegistrar.GetActionKeyFilter());
	if (Blueprint && Blueprint->SkeletonGeneratedClass && ActionRegistrar.IsOpenForRegistration(Blueprint->SkeletonGeneratedClass))
	{
		// If the SuperClass is a Blueprint we don't want to include its properties, or they will appear duplicated.
		// But if the SuperClass is a native class we want to add those.
		UClass* SuperClass = Blueprint->SkeletonGeneratedClass->GetSuperClass();
		bool bIsSuperBlueprint = SuperClass->ClassGeneratedBy && SuperClass->ClassGeneratedBy->IsA<UBlueprint>();
		EFieldIteratorFlags::SuperClassFlags IteratorFlags = bIsSuperBlueprint ? EFieldIteratorFlags::ExcludeSuper : EFieldIteratorFlags::IncludeSuper;
		for (TFieldIterator<FProperty> PropertyIt(Blueprint->SkeletonGeneratedClass, IteratorFlags); PropertyIt; ++PropertyIt)
		{
			FProperty* Property = *PropertyIt;

			bool const bIsAccessible = Property->HasAllPropertyFlags(CPF_BlueprintVisible);
			bool const bIsReadOnly = Property->HasAllPropertyFlags(CPF_BlueprintReadOnly);
			bool IsPropertyBlueprintVisible = !Property->HasAnyPropertyFlags(CPF_Parm) && bIsAccessible && !bIsReadOnly;

			if (IsPropertyBlueprintVisible)
			{
				UBlueprintNodeSpawner* SetterSpawner = CreateSpawnerFromMemberOrParam(UK2Node_NoesisAssignAndNotify::StaticClass(), Property);
				ActionRegistrar.AddBlueprintAction(Blueprint->SkeletonGeneratedClass, SetterSpawner);
			}
		}
	}
}

bool UK2Node_NoesisAssignAndNotify::IsActionFilteredOut(const FBlueprintActionFilter& Filter)
{
	bool FilteredOut = false;
	if (Filter.Context.Pins.Num())
	{
		for (auto Pin : Filter.Context.Pins)
		{
			if (Pin->Direction == EGPD_Input)
			{
				FilteredOut = true;
			}
		}
	}
	else
	{
		for (auto Blueprint : Filter.Context.Blueprints)
		{
			UClass* BlueprintClass = Blueprint->GeneratedClass;
			UClass* VariableSourceClass = GetVariableSourceClass();
			if (!BlueprintClass->IsChildOf(VariableSourceClass))
			{
				FilteredOut = true;
			}
		}
	}

	return FilteredOut;
}

void UK2Node_NoesisAssignAndNotify::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	if (CompilerContext.bIsFullCompile)
	{
		FProperty* VariableProperty = GetPropertyForVariable();

		if (VariableProperty)
		{
			UFunction* Setter = nullptr;
			const FString& SetterFunctionName = VariableProperty->GetMetaData(FBlueprintMetadata::MD_PropertySetFunction);
			if (!SetterFunctionName.IsEmpty())
			{
				UClass* OwnerClass = VariableProperty->GetOwnerClass();
				Setter = OwnerClass->FindFunctionByName(*SetterFunctionName);
			}

			const UEdGraphSchema_K2* K2Schema = CompilerContext.GetSchema();

			// Our node's pins
			UEdGraphPin* ExecPin = GetExecPin();
			UEdGraphPin* ThenPin = FindPin(K2Schema->PN_Then);
			UEdGraphPin* SelfPin = K2Schema->FindSelfPin(*this, EGPD_Input);
			UEdGraphPin* VariableSetPin = FindPin(GetVarNameString());
			UEdGraphPin* VariableGetPin = FindPin(GetVariableOutputPinName());

			// CallFunction node
			UK2Node_CallFunction* CallFunctionNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
			CallFunctionNode->FunctionReference.SetExternalMember(TEXT("NoesisSetWithNotify"), UNoesisFunctionLibrary::StaticClass());
			CallFunctionNode->AllocateDefaultPins();
			UEdGraphPin* CallFunctionNodeExecPin = CallFunctionNode->GetExecPin();
			UEdGraphPin* CallFunctionNodeThenPin = CallFunctionNode->FindPin(K2Schema->PN_Then);
			UEdGraphPin* CallFunctionNodeSelfPin = K2Schema->FindSelfPin(*CallFunctionNode, EGPD_Input);
			CallFunctionNodeSelfPin->DefaultObject = UNoesisFunctionLibrary::StaticClass()->GetDefaultObject();
			UEdGraphPin* CallFunctionNodePropertyPin = CallFunctionNode->FindPin(TEXT("Property"));
			UEdGraphPin* CallFunctionNodeValuePin = CallFunctionNode->FindPin(TEXT("Value"));
			UEdGraphPin* CallFunctionNodeSetterPin = CallFunctionNode->FindPin(TEXT("Setter"));
			CallFunctionNodeSetterPin->DefaultObject = Setter;

			// VariableGet node
			UK2Node_VariableGet* VariableGetNode = CompilerContext.SpawnIntermediateNode<UK2Node_VariableGet>(this, SourceGraph);
			VariableGetNode->VariableReference = VariableReference;
			VariableGetNode->AllocateDefaultPins();
			UEdGraphPin* VariableGetNodeSelfPin = K2Schema->FindSelfPin(*VariableGetNode, EGPD_Input);
			UEdGraphPin* VariableGetNodeVariablePin = VariableGetNode->FindPin(GetVarNameString());

			// Connect the Get and Call Function nodes
			VariableGetNodeVariablePin->MakeLinkTo(CallFunctionNodePropertyPin);

			// Input pin types
			K2Schema->ConvertPropertyToPinType(VariableProperty, CallFunctionNodePropertyPin->PinType);
			K2Schema->ConvertPropertyToPinType(VariableProperty, CallFunctionNodeValuePin->PinType);

			// Execution routing
			CompilerContext.MovePinLinksToIntermediate(*ExecPin, *CallFunctionNodeExecPin);
			CompilerContext.MovePinLinksToIntermediate(*ThenPin, *CallFunctionNodeThenPin);

			// Input and output routing
			CompilerContext.MovePinLinksToIntermediate(*SelfPin, *VariableGetNodeSelfPin);
			CompilerContext.MovePinLinksToIntermediate(*VariableGetPin, *VariableGetNodeVariablePin);
			CompilerContext.MovePinLinksToIntermediate(*VariableSetPin, *CallFunctionNodeValuePin);

			BreakAllNodeLinks();
		}
	}
}

#undef LOCTEXT_NAMESPACE
