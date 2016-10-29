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

void UNoesisGuiIEasingFunction::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(NoesisInterface.GetPtr());
	check(NoesisIEasingFunction)


}

void UNoesisGuiIEasingFunction::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IEasingFunction* NoesisIEasingFunction = NsDynamicCast<Noesis::Gui::IEasingFunction*>(NoesisInterface.GetPtr());
	check(NoesisIEasingFunction)


}

