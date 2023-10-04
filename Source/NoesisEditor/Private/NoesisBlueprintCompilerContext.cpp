////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintCompilerContext.h"

// UnrealEd includes
#include "Kismet2/KismetReinstanceUtilities.h"

// NoesisRuntime includes
#include "NoesisBlueprint.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisInstance.h"

FNoesisBlueprintCompilerContext::FNoesisBlueprintCompilerContext(UNoesisBlueprint* NoesisBlueprint, FCompilerResultsLog& Results, const FKismetCompilerOptions& CompilerOptions)
	: Super(NoesisBlueprint, Results, CompilerOptions)
{
}

FNoesisBlueprintCompilerContext::~FNoesisBlueprintCompilerContext()
{
}

void FNoesisBlueprintCompilerContext::SpawnNewClass(const FString& NewClassName)
{
	UNoesisBlueprintGeneratedClass* NoesisBlueprintGeneratedClass = FindObject<UNoesisBlueprintGeneratedClass>(Blueprint->GetOutermost(), *NewClassName);

	if (NoesisBlueprintGeneratedClass == NULL)
	{
		NoesisBlueprintGeneratedClass = NewObject<UNoesisBlueprintGeneratedClass>(Blueprint->GetOutermost(), FName(*NewClassName), RF_Public | RF_Transactional);
	}
	else
	{
		FBlueprintCompileReinstancer::Create(NoesisBlueprintGeneratedClass);
	}

	NewClass = NoesisBlueprintGeneratedClass;
}

void FNoesisBlueprintCompilerContext::EnsureProperGeneratedClass(UClass*& TargetUClass)
{
	if (TargetUClass && !((UObject*)TargetUClass)->IsA(UNoesisBlueprintGeneratedClass::StaticClass()))
	{
		FKismetCompilerUtilities::ConsignToOblivion(TargetUClass, Blueprint->bIsRegeneratingOnLoad);
		TargetUClass = NULL;
	}
}

void FNoesisBlueprintCompilerContext::CopyTermDefaultsToDefaultObject(UObject* DefaultObject)
{
	UNoesisInstance* DefaultInstance = Cast<UNoesisInstance>(DefaultObject);

	if (DefaultInstance != nullptr)
	{
		UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
		DefaultInstance->BaseXaml = NoesisBlueprint->BaseXaml;
		DefaultInstance->EnablePPAA = NoesisBlueprint->EnablePPAA;
		DefaultInstance->TessellationQuality = NoesisBlueprint->TessellationQuality;
		DefaultInstance->EnableKeyboard = NoesisBlueprint->EnableKeyboard;
		DefaultInstance->EnableMouse = NoesisBlueprint->EnableMouse;
		DefaultInstance->EmulateTouch = NoesisBlueprint->EmulateTouch;
		DefaultInstance->EnableTouch = NoesisBlueprint->EnableTouch;
		DefaultInstance->EnableActions = NoesisBlueprint->EnableActions;
		DefaultInstance->PixelDepthBias = NoesisBlueprint->PixelDepthBias;
	}
}
