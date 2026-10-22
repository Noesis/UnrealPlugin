////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if WITH_EDITOR

// RHI includes
#include "RHI.h"

// Engine includes
#include "Engine/World.h"

// Slate includes
#include "Widgets/SCompoundWidget.h"

#include "NoesisSDK.h"

class SNoesisStudioWindow : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SNoesisStudioWindow) {}
		SLATE_ATTRIBUTE(FString, ProjectPath)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	TSharedPtr<class SBox> ViewBox;
	class UNoesisStudioInstance* StudioInstance;
	TWeakPtr<SWidget> ViewSlateWidget;
	FString ProjectPath;
};


#endif
