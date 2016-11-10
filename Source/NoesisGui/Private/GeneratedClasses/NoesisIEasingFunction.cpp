////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisIEasingFunction.h"

using namespace Noesis;
using namespace Gui;

UNoesisIEasingFunction::UNoesisIEasingFunction(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisIEasingFunction::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(InNoesisInterface);
	check(NoesisIEasingFunction);
}

float UNoesisIEasingFunction::Ease(float InNormalizedTime)
{
	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(NoesisInterface.GetPtr());
	check(NoesisIEasingFunction);
	NsFloat32 NoesisInNormalizedTime = InNormalizedTime;
	return (float)NoesisIEasingFunction->Ease(NoesisInNormalizedTime);
}

void UNoesisIEasingFunction::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(NoesisInterface.GetPtr());
	check(NoesisIEasingFunction)


}

void UNoesisIEasingFunction::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(NoesisInterface.GetPtr());
	check(NoesisIEasingFunction)


}

