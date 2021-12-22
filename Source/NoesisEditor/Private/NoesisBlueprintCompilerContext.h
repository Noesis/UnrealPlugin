////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// KismetCompiler includes
#include "KismetCompiler.h"

class FNoesisBlueprintCompilerContext : public FKismetCompilerContext
{
protected:

	typedef FKismetCompilerContext Super;

public:
	FNoesisBlueprintCompilerContext(class UNoesisBlueprint* SourceSketch, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions);
	virtual ~FNoesisBlueprintCompilerContext();

	// FKismetCompilerContext interface
	virtual void SpawnNewClass(const FString& NewClassName) override;
	virtual void EnsureProperGeneratedClass(UClass*& TargetClass) override;
	virtual void CopyTermDefaultsToDefaultObject(UObject* DefaultObject) override;
	// End of FKismetCompilerContext interface
};
