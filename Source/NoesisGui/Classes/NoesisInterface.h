////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Generated header include
#include "NoesisInterface.generated.h"

UCLASS()
class NOESISGUI_API UNoesisInterface : public UObject
{
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface);

	const Noesis::Core::TypeClass* NoesisInterfaceTypeClass;
	Noesis::Ptr<Noesis::Interface> NoesisInterface;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface

	virtual void BindEvents();
	virtual void UnbindEvents();
};
