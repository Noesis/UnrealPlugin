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
#include "NoesisBaseComponent.generated.h"

UCLASS(Blueprintable, BlueprintType)
class NOESISRUNTIME_API UNoesisBaseComponent : public UObject
{
	GENERATED_UCLASS_BODY()

	Noesis::Ptr<Noesis::BaseComponent> NoesisComponent;
};
