////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

// Generated header include
#include "NoesisEditorUserSettings.generated.h"

UCLASS(Config = EditorPerProjectUserSettings, DefaultConfig)
class NOESISEDITOR_API UNoesisEditorUserSettings : public UObject
{
	GENERATED_UCLASS_BODY()

	/** The directory that is the root of absolute URIs in XAML files for the project. */
	UPROPERTY(EditAnywhere, Config, Category = "Editor Settings", DisplayName = "Project URI Root")
	FDirectoryPath ProjectURIRoot;

	FString GetProjectURIRoot() const;
};
