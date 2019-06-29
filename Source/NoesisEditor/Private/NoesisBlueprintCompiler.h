////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "KismetCompilerModule.h"

class FNoesisBlueprintCompiler : public IBlueprintCompiler
{
	// IBlueprintCompiler interface
	virtual bool CanCompile(const UBlueprint* Blueprint) override;
#if ENGINE_MINOR_VERSION <= 21
	virtual void PreCompile(UBlueprint* Blueprint) override;
	virtual void Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompilerOptions, FCompilerResultsLog& Results, TArray<UObject*>* ObjLoaded) override;
	virtual void PostCompile(UBlueprint* Blueprint) override;
#else
	virtual void PreCompile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompileOptions) override;
	virtual void Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompileOptions, FCompilerResultsLog& Results) override;
	virtual void PostCompile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompileOptions) override;
#endif
	// End of IBlueprintCompiler interface

public:
	virtual ~FNoesisBlueprintCompiler() {}
};
