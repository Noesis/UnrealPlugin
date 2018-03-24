////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisEditorUserSettings.h"

// Core includes
#include "Misc/Paths.h"

UNoesisEditorUserSettings::UNoesisEditorUserSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FString UNoesisEditorUserSettings::GetProjectURIRoot() const
{
	if (FPaths::DirectoryExists(ProjectURIRoot))
	{
		FString Path = ProjectURIRoot;
		FPaths::RemoveDuplicateSlashes(Path);
		FPaths::NormalizeDirectoryName(Path);
		FPaths::CollapseRelativeDirectories(Path);

		return Path.EndsWith(TEXT("/")) ? Path : Path + TEXT("/");
	}
	return FPaths::ProjectContentDir();
}
