////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "K2Node_NoesisAssignAndNotify.h"

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
	if (Blueprint && ActionRegistrar.IsOpenForRegistration(Blueprint))
	{
		for (TFieldIterator<FProperty> PropertyIt(Blueprint->SkeletonGeneratedClass, EFieldIteratorFlags::ExcludeSuper); PropertyIt; ++PropertyIt)
		{
			FProperty* Property = *PropertyIt;

			bool const bIsAccessible = Property->HasAllPropertyFlags(CPF_BlueprintVisible);
			bool const bIsReadOnly = Property->HasAllPropertyFlags(CPF_BlueprintReadOnly);
			bool IsPropertyBlueprintVisible = !Property->HasAnyPropertyFlags(CPF_Parm) && bIsAccessible && !bIsReadOnly;

			if (IsPropertyBlueprintVisible)
			{
				UBlueprintNodeSpawner* SetterSpawner = CreateSpawnerFromMemberOrParam(UK2Node_NoesisAssignAndNotify::StaticClass(), Property);
				ActionRegistrar.AddBlueprintAction(Blueprint, SetterSpawner);
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
			if (BlueprintClass != VariableSourceClass)
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
			const UEdGraphSchema_K2* K2Schema = CompilerContext.GetSchema();

			// Our node's pins
			UEdGraphPin* ExecPin = GetExecPin();
			UEdGraphPin* ThenPin = FindPin(K2Schema->PN_Then);
			UEdGraphPin* SelfPin = K2Schema->FindSelfPin(*this, EGPD_Input);
			UEdGraphPin* VariableSetPin = FindPin(GetVarNameString());
			UEdGraphPin* VariableGetPin = FindPin(GetVariableOutputPinName());

			// Set node
			UK2Node_VariableSet* SetNode = CompilerContext.SpawnIntermediateNode<UK2Node_VariableSet>(this, SourceGraph);
			SetNode->VariableReference = VariableReference;
			SetNode->AllocateDefaultPins();
			UEdGraphPin* SetNodeExecPin = SetNode->GetExecPin();
			UEdGraphPin* SetNodeThenPin = SetNode->FindPin(K2Schema->PN_Then);
			UEdGraphPin* SetNodeSelfPin = K2Schema->FindSelfPin(*SetNode, EGPD_Input);
			UEdGraphPin* SetNodeVariableSetPin = SetNode->FindPin(GetVarNameString());
			UEdGraphPin* SetNodeVariableGetPin = SetNode->FindPin(GetVariableOutputPinName());

			// Notify node
			UK2Node_CallFunction* NotifyNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
			if (VariableProperty->IsA<FArrayProperty>())
			{
				NotifyNode->FunctionReference.SetExternalMember(TEXT("NotifyArrayChanged"), UNoesisFunctionLibrary::StaticClass());
			}
			else
			{
				NotifyNode->FunctionReference.SetExternalMember(TEXT("NotifyChanged"), UNoesisFunctionLibrary::StaticClass());
			}
			NotifyNode->AllocateDefaultPins();
			UEdGraphPin* NotifyNodeExecPin = NotifyNode->GetExecPin();
			UEdGraphPin* NotifyNodeThenPin = NotifyNode->FindPin(K2Schema->PN_Then);
			UEdGraphPin* NotifyNodeSelfPin = K2Schema->FindSelfPin(*NotifyNode, EGPD_Input);
			NotifyNodeSelfPin->DefaultObject = UNoesisFunctionLibrary::StaticClass()->GetDefaultObject();
			UEdGraphPin* NotifyNodeOwnerPin = NotifyNode->FindPin(TEXT("Owner"));
			UEdGraphPin* NotifyNodePropertyNamePin = NotifyNode->FindPin(TEXT("PropertyName"));

			// Compare node
			UK2Node_CallFunction* CompareNode = nullptr;
			UEdGraphPin* CompareNodeExecPin = nullptr;
			UEdGraphPin* CompareNodeThenPin = nullptr;
			UEdGraphPin* CompareNodeFirstInputPin = nullptr;
			UEdGraphPin* CompareNodeSecondInputPin = nullptr;
			UEdGraphPin* CompareNodeReturnValuePin = nullptr;
			if (VariableProperty->IsA<FIntProperty>())
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NotEqual_IntInt"), UKismetMathLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UKismetMathLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));
			}
			else if (VariableProperty->IsA<FFloatProperty>())
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NotEqual_FloatFloat"), UKismetMathLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UKismetMathLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));
			}
			else if (VariableProperty->IsA<FBoolProperty>())
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NotEqual_BoolBool"), UKismetMathLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UKismetMathLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));
			}
			else if (VariableProperty->IsA<FStrProperty>())
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NotEqual_StrStr"), UKismetStringLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UKismetStringLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));
			}
			else if (VariableProperty->IsA<FTextProperty>())
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NotEqual_TextText"), UKismetTextLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UKismetStringLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));
			}
			else if (VariableProperty->IsA<FObjectProperty>())
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NotEqual_ObjectObject"), UKismetMathLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UKismetMathLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));
			}
			else if (FStructProperty* StructProperty = CastField<FStructProperty>(VariableProperty))
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NoesisStruct_NotEqual"), UNoesisFunctionLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UNoesisFunctionLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));

				CompareNodeFirstInputPin->PinType = VariableSetPin->PinType;
				CompareNodeSecondInputPin->PinType = VariableSetPin->PinType;
			}
			else if (FByteProperty* ByteProperty = CastField<FByteProperty>(VariableProperty))
			{
				CompareNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				CompareNode->FunctionReference.SetExternalMember(TEXT("NotEqual_ByteByte"), UKismetMathLibrary::StaticClass());
				CompareNode->AllocateDefaultPins();
				CompareNodeExecPin = CompareNode->GetExecPin();
				CompareNodeThenPin = CompareNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* CompareNodeSelfPin = K2Schema->FindSelfPin(*CompareNode, EGPD_Input);
				CompareNodeSelfPin->DefaultObject = UKismetMathLibrary::StaticClass()->GetDefaultObject();
				CompareNodeFirstInputPin = CompareNode->FindPin(TEXT("A"));
				CompareNodeSecondInputPin = CompareNode->FindPin(TEXT("B"));
				CompareNodeReturnValuePin = CompareNode->FindPin(TEXT("ReturnValue"));

				if (ByteProperty->Enum)
				{
					CompareNodeFirstInputPin->PinType = VariableSetPin->PinType;
					CompareNodeSecondInputPin->PinType = VariableSetPin->PinType;
				}
			}
			else if (FArrayProperty* ArrayProperty = CastField<FArrayProperty>(VariableProperty))
			{

			}

			if (CompareNode)
			{
				// Get node
				UK2Node_VariableGet* GetNode = CompilerContext.SpawnIntermediateNode<UK2Node_VariableGet>(this, SourceGraph);
				GetNode->VariableReference = VariableReference;
				GetNode->AllocateDefaultPins();
				UEdGraphPin* GetNodeExecPin = GetNode->GetExecPin();
				UEdGraphPin* GetNodeThenPin = GetNode->FindPin(K2Schema->PN_Then);
				UEdGraphPin* GetNodeSelfPin = K2Schema->FindSelfPin(*GetNode, EGPD_Input);
				UEdGraphPin* GetNodeVariableGetPin = GetNode->FindPin(GetVarNameString());

				// Branch node
				UK2Node_IfThenElse* BranchNode = CompilerContext.SpawnIntermediateNode<UK2Node_IfThenElse>(this, SourceGraph);
				BranchNode->AllocateDefaultPins();
				UEdGraphPin* BranchNodeExecPin = BranchNode->GetExecPin();
				UEdGraphPin* BranchNodeThenPin = BranchNode->GetThenPin();
				UEdGraphPin* BranchNodeElsePin = BranchNode->GetElsePin();
				UEdGraphPin* BranchNodeConditionPin = BranchNode->GetConditionPin();

				// Execution routing
				if (GetNodeExecPin)
				{
					CompilerContext.MovePinLinksToIntermediate(*ExecPin, *GetNodeExecPin);
					if (CompareNodeExecPin)
					{
						GetNodeThenPin->MakeLinkTo(CompareNodeExecPin);
						CompareNodeThenPin->MakeLinkTo(BranchNodeExecPin);
					}
					else
					{
						GetNodeThenPin->MakeLinkTo(BranchNodeExecPin);
					}
				}
				else if (CompareNodeExecPin)
				{
					CompilerContext.MovePinLinksToIntermediate(*ExecPin, *CompareNodeExecPin);
					CompareNodeThenPin->MakeLinkTo(BranchNodeExecPin);
				}
				else
				{
					CompilerContext.MovePinLinksToIntermediate(*ExecPin, *BranchNodeExecPin);
				}
				BranchNodeThenPin->MakeLinkTo(SetNodeExecPin);
				CompilerContext.CopyPinLinksToIntermediate(*ThenPin, *BranchNodeElsePin);
				SetNodeThenPin->MakeLinkTo(NotifyNodeExecPin);
				CompilerContext.CopyPinLinksToIntermediate(*ThenPin, *NotifyNodeThenPin);

				// Data routing
				CompilerContext.CopyPinLinksToIntermediate(*VariableSetPin, *CompareNodeFirstInputPin);
				GetNodeVariableGetPin->MakeLinkTo(CompareNodeSecondInputPin);
				CompareNodeReturnValuePin->MakeLinkTo(BranchNodeConditionPin);
				CompilerContext.CopyPinLinksToIntermediate(*VariableSetPin, *SetNodeVariableSetPin);
				CompilerContext.MovePinLinksToIntermediate(*VariableGetPin, *SetNodeVariableGetPin);
				NotifyNodePropertyNamePin->DefaultValue = GetVarNameString();

				// Self assignment
				CompilerContext.CopyPinLinksToIntermediate(*SelfPin, *GetNodeSelfPin);
				CompilerContext.CopyPinLinksToIntermediate(*SelfPin, *SetNodeSelfPin);
				if (SelfPin->LinkedTo.Num())
				{
					CompilerContext.CopyPinLinksToIntermediate(*SelfPin, *NotifyNodeOwnerPin);
				}
				else
				{
					// Self node
					UK2Node_Self* SelfNode = CompilerContext.SpawnIntermediateNode<UK2Node_Self>(this, SourceGraph);
					SelfNode->AllocateDefaultPins();
					UEdGraphPin* SelfNodeSelfPin = K2Schema->FindSelfPin(*SelfNode, EGPD_Output);
					SelfNodeSelfPin->MakeLinkTo(NotifyNodeOwnerPin);
				}
			}
			else
			{
				// Execution routing
				CompilerContext.MovePinLinksToIntermediate(*ExecPin, *SetNodeExecPin);
				SetNodeThenPin->MakeLinkTo(NotifyNodeExecPin);
				CompilerContext.CopyPinLinksToIntermediate(*ThenPin, *NotifyNodeThenPin);

				// Data routing
				CompilerContext.CopyPinLinksToIntermediate(*VariableSetPin, *SetNodeVariableSetPin);
				CompilerContext.MovePinLinksToIntermediate(*VariableGetPin, *SetNodeVariableGetPin);
				NotifyNodePropertyNamePin->DefaultValue = GetVarNameString();

				// Self assignment
				CompilerContext.CopyPinLinksToIntermediate(*SelfPin, *SetNodeSelfPin);
				if (SelfPin->LinkedTo.Num())
				{
					CompilerContext.CopyPinLinksToIntermediate(*SelfPin, *NotifyNodeOwnerPin);
				}
				else
				{
					// Self node
					UK2Node_Self* SelfNode = CompilerContext.SpawnIntermediateNode<UK2Node_Self>(this, SourceGraph);
					SelfNode->AllocateDefaultPins();
					UEdGraphPin* SelfNodeSelfPin = K2Schema->FindSelfPin(*SelfNode, EGPD_Output);
					SelfNodeSelfPin->MakeLinkTo(NotifyNodeOwnerPin);
				}
			}

			BreakAllNodeLinks();
		}
	}
}

#undef LOCTEXT_NAMESPACE
