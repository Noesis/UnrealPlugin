////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

struct FNoesisBlueprintApplicationModes
{
	static const FName PreviewMode;
	static const FName GraphMode;

	static FText GetLocalizedMode(const FName InMode);

private:
	FNoesisBlueprintApplicationModes() {}
};
