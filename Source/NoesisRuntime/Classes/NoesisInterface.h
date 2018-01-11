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
#include "NoesisInterface.generated.h"

UCLASS()
class NOESISRUNTIME_API UNoesisInterface : public UObject
{
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Interface* NoesisInterface);

	const Noesis::TypeClass* NoesisInterfaceTypeClass;
	Noesis::Ptr<Noesis::Interface> NoesisInterface;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface

	virtual void BindEvents();
	virtual void UnbindEvents();
};
