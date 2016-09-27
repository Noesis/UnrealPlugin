////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisGuiBlueprintCompiler.h"

// UnrealEd includes
#include "KismetReinstanceUtilities.h"

// NoesisGui includes
#include "NoesisGuiBlueprint.h"
#include "NoesisGuiBlueprintGeneratedClass.h"
#include "GeneratedClasses/NoesisGuiButton.h"

FNoesisGuiBlueprintCompilerContext::FNoesisGuiBlueprintCompilerContext(UNoesisGuiBlueprint* NoesisGuiBlueprint, FCompilerResultsLog& Results, const FKismetCompilerOptions& CompilerOptions, TArray<UObject*>* ObjLoaded)
	: Super(NoesisGuiBlueprint, Results, CompilerOptions, ObjLoaded)
{
}

FNoesisGuiBlueprintCompilerContext::~FNoesisGuiBlueprintCompilerContext()
{
}

void FNoesisGuiBlueprintCompilerContext::SpawnNewClass(const FString& NewClassName)
{
	UNoesisGuiBlueprintGeneratedClass* NoesisGuiBlueprintGeneratedClass = FindObject<UNoesisGuiBlueprintGeneratedClass>(Blueprint->GetOutermost(), *NewClassName);

	if (NoesisGuiBlueprintGeneratedClass == NULL)
	{
		NoesisGuiBlueprintGeneratedClass = NewObject<UNoesisGuiBlueprintGeneratedClass>(Blueprint->GetOutermost(), FName(*NewClassName), RF_Public | RF_Transactional);
	}
	else
	{
		FBlueprintCompileReinstancer::Create(NoesisGuiBlueprintGeneratedClass);
	}

	NewClass = NoesisGuiBlueprintGeneratedClass;
}

void FNoesisGuiBlueprintCompilerContext::CleanAndSanitizeClass(UBlueprintGeneratedClass* ClassToClean, UObject*& OldCDO)
{
	Super::CleanAndSanitizeClass(ClassToClean, OldCDO);
}

void FNoesisGuiBlueprintCompilerContext::EnsureProperGeneratedClass(UClass*& TargetUClass)
{
	if (TargetUClass && !((UObject*)TargetUClass)->IsA(UNoesisGuiBlueprintGeneratedClass::StaticClass()))
	{
		FKismetCompilerUtilities::ConsignToOblivion(TargetUClass, Blueprint->bIsRegeneratingOnLoad);
		TargetUClass = NULL;
	}
}

void FNoesisGuiBlueprintCompilerContext::CreateClassVariablesFromBlueprint()
{
	Super::CreateClassVariablesFromBlueprint();

	UNoesisGuiBlueprint* NoesisGuiBlueprint = Cast<UNoesisGuiBlueprint>(Blueprint);
	if (!NoesisGuiBlueprint || !NoesisGuiBlueprint->BaseXaml)
		return;

	auto Linker = NoesisGuiBlueprint->BaseXaml->GetLinker();
	if (Linker)
	{
		Linker->Preload(NoesisGuiBlueprint->BaseXaml);
	}

	for (auto Component : NoesisGuiBlueprint->BaseXaml->Components)
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

void FNoesisGuiBlueprintCompilerContext::CreateFunctionList()
{
	Super::CreateFunctionList();
}

void FNoesisGuiBlueprintCompilerContext::FinishCompilingClass(UClass* Class)
{
	Super::FinishCompilingClass(Class);

	UNoesisGuiBlueprint* NoesisGuiBlueprint = CastChecked<UNoesisGuiBlueprint>(Blueprint);
	UNoesisGuiBlueprintGeneratedClass* NoesisGuiBlueprintGeneratedClass = CastChecked<UNoesisGuiBlueprintGeneratedClass>(Class);
	NoesisGuiBlueprintGeneratedClass->BaseXaml = NoesisGuiBlueprint->BaseXaml;
}

bool FNoesisGuiBlueprintCompilerContext::ValidateGeneratedClass(UBlueprintGeneratedClass* Class)
{
	return Super::ValidateGeneratedClass(Class);
}
