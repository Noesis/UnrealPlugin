////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintCompilerContext.h"

// UnrealEd includes
#include "Kismet2/KismetReinstanceUtilities.h"

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

void FNoesisBlueprintCompilerContext::CleanAndSanitizeClass(UBlueprintGeneratedClass* ClassToClean, UObject*& InOutOldCDO)
{
	Super::CleanAndSanitizeClass(ClassToClean, InOutOldCDO);
}

void FNoesisBlueprintCompilerContext::EnsureProperGeneratedClass(UClass*& TargetUClass)
{
	if (TargetUClass && !((UObject*)TargetUClass)->IsA(UNoesisBlueprintGeneratedClass::StaticClass()))
	{
		FKismetCompilerUtilities::ConsignToOblivion(TargetUClass, Blueprint->bIsRegeneratingOnLoad);
		TargetUClass = NULL;
	}
}

void FNoesisBlueprintCompilerContext::CreateClassVariablesFromBlueprint()
{
	Super::CreateClassVariablesFromBlueprint();
}

void FNoesisBlueprintCompilerContext::CreateFunctionList()
{
	Super::CreateFunctionList();
}

void FNoesisBlueprintCompilerContext::FinishCompilingClass(UClass* Class)
{
	Super::FinishCompilingClass(Class);

	UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
	UNoesisBlueprintGeneratedClass* NoesisBlueprintGeneratedClass = CastChecked<UNoesisBlueprintGeneratedClass>(Class);
	NoesisBlueprintGeneratedClass->BaseXaml = NoesisBlueprint->BaseXaml;
	NoesisBlueprintGeneratedClass->EnablePPAA = NoesisBlueprint->EnablePPAA;
	NoesisBlueprintGeneratedClass->TessellationQuality = NoesisBlueprint->TessellationQuality;
}

bool FNoesisBlueprintCompilerContext::ValidateGeneratedClass(UBlueprintGeneratedClass* Class)
{
	return Super::ValidateGeneratedClass(Class);
}
