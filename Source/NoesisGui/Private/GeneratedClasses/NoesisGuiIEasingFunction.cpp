////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIEasingFunction.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIEasingFunction::UNoesisGuiIEasingFunction(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIEasingFunction::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(InNoesisInterface);
	check(NoesisIEasingFunction);

}

float UNoesisGuiIEasingFunction::Ease(float InNormalizedTime)
{
	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(NoesisInterface.GetPtr());
	check(NoesisIEasingFunction);
	NsFloat32 NoesisInNormalizedTime = InNormalizedTime;
	return (float)NoesisIEasingFunction->Ease(NoesisInNormalizedTime);
}

	void UNoesisGuiIEasingFunction::BeginDestroy()
{
	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(NoesisInterface.GetPtr());
	if (!NoesisIEasingFunction)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

