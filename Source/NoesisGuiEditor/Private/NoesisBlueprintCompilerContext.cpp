////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintCompilerContext.h"

// UnrealEd includes
#include "KismetReinstanceUtilities.h"

// NoesisGui includes
#include "NoesisBlueprint.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisCreateClass.h"

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

	UNoesisBlueprint* NoesisBlueprint = Cast<UNoesisBlueprint>(Blueprint);
	if (!NoesisBlueprint || !NoesisBlueprint->BaseXaml)
		return;

	NoesisBlueprint->BaseXaml->PreloadDependencies();

	Noesis::Ptr<Noesis::Core::BaseComponent> Xaml = Noesis::GUI::LoadXaml<Noesis::Core::BaseComponent>(StringCast<NsChar>(*(FString::FromInt(NoesisBlueprint->BaseXaml->GetUniqueID()) / NoesisBlueprint->BaseXaml->GetName() + TEXT(".xaml"))).Get());
	Noesis::Ptr<Noesis::FrameworkElement> FrameworkElement = NsDynamicCast<Noesis::Ptr<Noesis::FrameworkElement>>(Xaml);
	if (FrameworkElement)
	{
		TArray<Noesis::FrameworkElement*> Elements;
		CollectElements(FrameworkElement.GetPtr(), Elements);

		for (auto Element : Elements)
		{
			FName ElementName = NsStringToFName(Element->GetName());
			if (ElementName != NAME_None)
			{
				UClass* ComponentClass = GetClassFor(Element);
				FEdGraphPinType PinType(Schema->PC_Object, TEXT(""), ComponentClass, false, false, false, false, FEdGraphTerminalType());
				UProperty* Property = CreateVariable(ElementName, PinType);
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
