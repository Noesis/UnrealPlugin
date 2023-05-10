////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRiveReimportFactory.h"

// Core includes
#include "HAL/FileManager.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"

// NoesisRuntime includes
#include "NoesisRive.h"

UNoesisRiveReimportFactory::UNoesisRiveReimportFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = false;
	bEditAfterNew = false;
}

bool UNoesisRiveReimportFactory::CanReimport(UObject* Obj, TArray<FString>& OutFilenames)
{
	UNoesisRive* Rive = Cast<UNoesisRive>(Obj);
	if (Rive != nullptr && Rive->AssetImportData != nullptr)
	{
		Rive->AssetImportData->ExtractFilenames(OutFilenames);
		return true;
	}
	return false;
}

void UNoesisRiveReimportFactory::SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths)
{
	UNoesisRive* Rive = Cast<UNoesisRive>(Obj);
	if (Rive != nullptr && ensure(NewReimportPaths.Num() == 1))
	{
		Rive->AssetImportData->UpdateFilenameOnly(NewReimportPaths[0]);
	}
}

EReimportResult::Type UNoesisRiveReimportFactory::Reimport(UObject* Obj)
{
	UNoesisRive* Rive = Cast<UNoesisRive>(Obj);
	if (Rive == nullptr)
	{
		return EReimportResult::Failed;
	}

	// Make sure file is valid and exists
	const FString Filename = Rive->AssetImportData->GetFirstFilename();
	if (!Filename.Len() || IFileManager::Get().FileSize(*Filename) == INDEX_NONE)
	{
		return EReimportResult::Failed;
	}

	// Run the import again
	EReimportResult::Type Result = EReimportResult::Failed;
	bool OutCanceled = false;

	if (ImportObject(Rive->GetClass(), Rive->GetOuter(), *Rive->GetName(), RF_Public | RF_Standalone, Filename, nullptr, OutCanceled) != nullptr)
	{
		Rive->AssetImportData->Update(Filename);

		// Try to find the outer package so we can dirty it up
		if (Rive->GetOuter() != nullptr)
		{
			Rive->GetOuter()->MarkPackageDirty();
		}
		else
		{
			Rive->MarkPackageDirty();
		}
		Result = EReimportResult::Succeeded;
	}
	else
	{
		Result = EReimportResult::Cancelled;
	}

	return Result;
}

int32 UNoesisRiveReimportFactory::GetPriority() const
{
	return ImportPriority;
}
