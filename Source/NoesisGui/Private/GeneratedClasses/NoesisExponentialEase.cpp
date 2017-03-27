////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisExponentialEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisExponentialEase::UNoesisExponentialEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ExponentialEase::StaticGetClassType();
}

void UNoesisExponentialEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(InNoesisComponent);
	check(NoesisExponentialEase);
}

float UNoesisExponentialEase::GetExponent()
{
	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(NoesisComponent.GetPtr());
	check(NoesisExponentialEase);
	return (float)NoesisExponentialEase->GetExponent();
}

void UNoesisExponentialEase::SetExponent(float InExponent)
{
	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(NoesisComponent.GetPtr());
	check(NoesisExponentialEase);
	NoesisExponentialEase->SetExponent(InExponent);
}

void UNoesisExponentialEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(NoesisComponent.GetPtr());
	check(NoesisExponentialEase);


}

void UNoesisExponentialEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(NoesisComponent.GetPtr());
	check(NoesisExponentialEase);


}

