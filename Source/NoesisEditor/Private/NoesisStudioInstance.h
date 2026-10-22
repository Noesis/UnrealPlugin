////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// NoesisRuntime includes
#include "NoesisInstance.h"
#include "SNoesisStudioWidget.h"

// Generated header include
#include "NoesisStudioInstance.generated.h"

UCLASS(Blueprintable)
class UNoesisStudioInstance : public UNoesisInstance
{
	GENERATED_UCLASS_BODY()
	// End of UUserWidget interface

	void InitInstance() override;
	void Update() override;

	void SetOptions(StudioOptions& InOptions);

	void SaveAllChanges();
	void DiscardAllChanges();

private:
	StudioOptions Options;
};
