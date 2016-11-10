////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisBlueprintCompiler.h"

// UnrealEd includes
#include "KismetReinstanceUtilities.h"

// NoesisGui includes
#include "NoesisBlueprint.h"
#include "NoesisBlueprintGeneratedClass.h"

FNoesisBlueprintCompilerContext::FNoesisBlueprintCompilerContext(UNoesisBlueprint* NoesisBlueprint, FCompilerResultsLog& Results, const FKismetCompilerOptions& CompilerOptions, TArray<UObject*>* ObjLoaded)
	: Super(NoesisBlueprint, Results, CompilerOptions, ObjLoaded)
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

void FNoesisBlueprintCompilerContext::CleanAndSanitizeClass(UBlueprintGeneratedClass* ClassToClean, UObject*& OldCDO)
{
	Super::CleanAndSanitizeClass(ClassToClean, OldCDO);
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

	UNoesisBlueprint* NoesisBlueprint = Cast<UNoesisBlueprint>(Blueprint);
	if (!NoesisBlueprint || !NoesisBlueprint->BaseXaml)
		return;

	auto Linker = NoesisBlueprint->BaseXaml->GetLinker();
	if (Linker)
	{
		Linker->Preload(NoesisBlueprint->BaseXaml);
	}

	for (auto Component : NoesisBlueprint->BaseXaml->Components)
	{
		auto ComponentLinker = Component->GetLinker();
		if (ComponentLinker)
		{
			ComponentLinker->Preload(Component);
		}
		if (Component->ElementName != NAME_None)
		{
			FEdGraphPinType PinType(Schema->PC_Object, TEXT(""), Component->GetClass(), false, false);
			UProperty* Property = CreateVariable(Component->ElementName, PinType);
			if (Property != nullptr)
			{
				Property->SetMetaData(TEXT("Category"), *Blueprint->GetName());

				Property->SetPropertyFlags(CPF_BlueprintVisible);
				Property->SetPropertyFlags(CPF_Transient);
				Property->SetPropertyFlags(CPF_RepSkip);
			}
		}
	}
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
}

bool FNoesisBlueprintCompilerContext::ValidateGeneratedClass(UBlueprintGeneratedClass* Class)
{
	return Super::ValidateGeneratedClass(Class);
}
