////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintCompiler.h"

// NoesisEditor includes
#include "NoesisBlueprintCompilerContext.h"

bool FNoesisBlueprintCompiler::CanCompile(const UBlueprint* Blueprint)
{
	return Blueprint->IsA(UNoesisBlueprint::StaticClass());
}

#if ENGINE_MINOR_VERSION <= 21
void FNoesisBlueprintCompiler::PreCompile(UBlueprint* Blueprint) { }

void FNoesisBlueprintCompiler::Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompilerOptions, FCompilerResultsLog& Results, TArray<UObject*>* ObjLoaded)
{
	UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
	FNoesisBlueprintCompilerContext Compiler(NoesisBlueprint, Results, CompilerOptions, ObjLoaded);
	Compiler.Compile();
	check(Compiler.NewClass);
}

void FNoesisBlueprintCompiler::PostCompile(UBlueprint* Blueprint) { }
#else
void FNoesisBlueprintCompiler::PreCompile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompilerOptions) { }

void FNoesisBlueprintCompiler::Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompilerOptions, FCompilerResultsLog& Results)
{
	UNoesisBlueprint* NoesisBlueprint = CastChecked<UNoesisBlueprint>(Blueprint);
	FNoesisBlueprintCompilerContext Compiler(NoesisBlueprint, Results, CompilerOptions);
	Compiler.Compile();
	check(Compiler.NewClass);
}

void FNoesisBlueprintCompiler::PostCompile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompileOptions) { }
#endif
