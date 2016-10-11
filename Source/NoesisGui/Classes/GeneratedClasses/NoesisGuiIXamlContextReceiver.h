////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIXamlContextReceiver.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIXamlContextReceiver : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

