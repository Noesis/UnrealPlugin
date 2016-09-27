////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisGuiBlueprintCompiler.h"

// NoesisGui includes
#include "NoesisGuiBlueprint.h"

// NoesisGuiEditor includes
#include "NoesisGuiBlueprintCompilerContext.h"

bool FNoesisGuiBlueprintCompiler::CanCompile(const UBlueprint* Blueprint)
{
	return Blueprint->IsA(UNoesisGuiBlueprint::StaticClass());
}

void FNoesisGuiBlueprintCompiler::PreCompile(UBlueprint* Blueprint)
{
}

void FNoesisGuiBlueprintCompiler::Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompilerOptions, FCompilerResultsLog& Results, TArray<UObject*>* ObjLoaded)
{
	UNoesisGuiBlueprint* NoesisGuiBlueprint = CastChecked<UNoesisGuiBlueprint>(Blueprint);
	FNoesisGuiBlueprintCompilerContext Compiler(NoesisGuiBlueprint, Results, CompilerOptions, ObjLoaded);
	Compiler.Compile();
	check(Compiler.NewClass);
}

void FNoesisGuiBlueprintCompiler::PostCompile(UBlueprint* Blueprint)
{
}
