////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRiveFactory.h"

// Core includes
#include "CoreMinimal.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"

// NoesisRuntime includes
#include "NoesisRive.h"

UNoesisRiveFactory::UNoesisRiveFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = true;
	bEditAfterNew = true;
	SupportedClass = UNoesisRive::StaticClass();
	Formats.Add(TEXT("riv;Rive"));
}

UObject* UNoesisRiveFactory::FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name,
	EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd,
	FFeedbackContext* Warn)
{
	UNoesisRive* Rive = NewObject<UNoesisRive>(Parent, Class, Name, Flags);
	Rive->Content.Insert(Buffer, (int32)(BufferEnd - Buffer), 0);
	Rive->AssetImportData->Update(GetCurrentFilename());

	return Rive;
}
