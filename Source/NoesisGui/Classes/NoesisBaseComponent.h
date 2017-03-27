////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Generated header include
#include "NoesisBaseComponent.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBaseComponent : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NoesisGui")
	FName ElementName;

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent);

	const Noesis::Core::TypeClass* NoesisComponentTypeClass;
	Noesis::Ptr<Noesis::Core::BaseComponent> NoesisComponent;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface

	virtual void BindEvents();
	virtual void UnbindEvents();
};
