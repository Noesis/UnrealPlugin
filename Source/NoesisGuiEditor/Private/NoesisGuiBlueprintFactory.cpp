////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisGuiXamlFactory.h"

// NoesisGuiEditor includes
#include "NoesisGuiEditorModule.h"

#define LOCTEXT_NAMESPACE "UNoesisGuiBlueprintFactory"

UNoesisGuiBlueprintFactory::UNoesisGuiBlueprintFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	SupportedClass = UNoesisGuiBlueprint::StaticClass();
	ParentClass = UNoesisGuiInstance::StaticClass();
}

UObject* UNoesisGuiBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if ((ParentClass == NULL) || !FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass) || !ParentClass->IsChildOf(UNoesisGuiInstance::StaticClass()))
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != NULL) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateNoesisGuiBlueprint", "Cannot create a NoesisGui Blueprint based on the class '{ClassName}'."), Args));
		return NULL;
	}
	else
	{
		return CastChecked<UNoesisGuiBlueprint>(FKismetEditorUtilities::CreateBlueprint(ParentClass, Parent, Name, BPTYPE_Normal, UNoesisGuiBlueprint::StaticClass(), UNoesisGuiBlueprintGeneratedClass::StaticClass(), "UNoesisGuiBlueprintFactory"));
	}
}