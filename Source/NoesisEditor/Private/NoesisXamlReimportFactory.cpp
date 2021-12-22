////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlReimportFactory.h"

// Core includes
#include "HAL/FileManager.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"

// NoesisRuntime includes
#include "NoesisXaml.h"

UNoesisXamlReimportFactory::UNoesisXamlReimportFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = false;
	bEditAfterNew = false;
}

bool UNoesisXamlReimportFactory::CanReimport(UObject* Obj, TArray<FString>& OutFilenames)
{
	UNoesisXaml* NoesisXaml = Cast<UNoesisXaml>(Obj);
	if (NoesisXaml && NoesisXaml->AssetImportData)
	{
		NoesisXaml->AssetImportData->ExtractFilenames(OutFilenames);
		return true;
	}
	return false;
}

void UNoesisXamlReimportFactory::SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths)
{
	UNoesisXaml* NoesisXaml = Cast<UNoesisXaml>(Obj);
	if (NoesisXaml && ensure(NewReimportPaths.Num() == 1))
	{
		NoesisXaml->AssetImportData->UpdateFilenameOnly(NewReimportPaths[0]);
	}
}

EReimportResult::Type UNoesisXamlReimportFactory::Reimport(UObject* Obj)
{
	UNoesisXaml* NoesisXaml = Cast<UNoesisXaml>(Obj);
	if (!NoesisXaml)
	{
		return EReimportResult::Failed;
	}

	// Make sure file is valid and exists
	const FString Filename = NoesisXaml->AssetImportData->GetFirstFilename();
	if (!Filename.Len() || IFileManager::Get().FileSize(*Filename) == INDEX_NONE)
	{
		return EReimportResult::Failed;
	}

	// Run the import again
	EReimportResult::Type Result = EReimportResult::Failed;
	bool OutCanceled = false;

	if (ImportObject(NoesisXaml->GetClass(), NoesisXaml->GetOuter(), *NoesisXaml->GetName(), RF_Public | RF_Standalone, Filename, nullptr, OutCanceled) != nullptr)
	{
		NoesisXaml->AssetImportData->Update(Filename);

		// Try to find the outer package so we can dirty it up
		if (NoesisXaml->GetOuter())
		{
			NoesisXaml->GetOuter()->MarkPackageDirty();
		}
		else
		{
			NoesisXaml->MarkPackageDirty();
		}
		Result = EReimportResult::Succeeded;
	}
	else
	{
		// If the NoesisXaml factory returns null on a reimport, it means the XAML wasn't reimported directly or
		// its contents haven't changed.
		// We return Cancelled instead of Failed so that we don't get a pop up on the editor.
		Result = EReimportResult::Cancelled;
	}

	return Result;
}

int32 UNoesisXamlReimportFactory::GetPriority() const
{
	return ImportPriority;
}
