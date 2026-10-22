////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#if WITH_EDITOR

// UnrealEd includes
#include "NoesisStudioWindow.h"

// UtilityShaders includes
#include "ClearQuad.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
void SNoesisStudioWindow::Construct(const FArguments& InArgs)
{
	StudioInstance = nullptr;
	ProjectPath = InArgs._ProjectPath.Get();

	ChildSlot
		[
			SNew(SBorder)
				.Padding(FMargin(0))
				[
					SAssignNew(ViewBox, SBox)
				]
		];
}

#endif
