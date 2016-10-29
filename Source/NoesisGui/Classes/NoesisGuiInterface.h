////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// CoreUObject includes
#include "UObject/UObject.h"

// Generated header include
#include "NoesisGuiInterface.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiInterface : public UObject
{
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface);

	Noesis::Ptr<Noesis::Interface> NoesisInterface;

	class UNoesisGuiInstance* Instance;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface

	virtual void BindEvents();
	virtual void UnbindEvents();
};
