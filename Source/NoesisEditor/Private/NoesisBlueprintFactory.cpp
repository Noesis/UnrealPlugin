////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintFactory.h"

// Core includes
#include "Misc/MessageDialog.h"

// NoesisEditor includes
#include "NoesisEditorModule.h"

// NoesisRuntime includes
#include "NoesisBlueprint.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisInstance.h"

// UnrealEd includes
#include "Kismet2/KismetEditorUtilities.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

UNoesisBlueprintFactory::UNoesisBlueprintFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	SupportedClass = UNoesisBlueprint::StaticClass();
	ParentClass = UNoesisInstance::StaticClass();
}

UObject* UNoesisBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if ((ParentClass == NULL) || !FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass) || !ParentClass->IsChildOf(UNoesisInstance::StaticClass()))
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != NULL) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateNoesisBlueprint", "Cannot create a NoesisGUI View based on the class '{ClassName}'."), Args));
		return NULL;
	}
	else
	{
		return CastChecked<UNoesisBlueprint>(FKismetEditorUtilities::CreateBlueprint(ParentClass, Parent, Name, BPTYPE_Normal, UNoesisBlueprint::StaticClass(), UNoesisBlueprintGeneratedClass::StaticClass(), "UNoesisBlueprintFactory"));
	}
}

#undef LOCTEXT_NAMESPACE
