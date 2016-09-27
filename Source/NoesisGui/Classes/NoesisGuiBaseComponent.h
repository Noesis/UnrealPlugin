////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// CoreUObject includes
#include "UObject/UObject.h"

// Generated header include
#include "NoesisGuiBaseComponent.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBaseComponent : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(Category = NoesisGui, BlueprintReadOnly)
	FName ElementName;

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent);

	Noesis::Ptr<Noesis::Core::BaseComponent> NoesisComponent;

	class UNoesisGuiInstance* Instance;
};
