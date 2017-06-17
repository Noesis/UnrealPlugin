////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBackEase.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBackEase::UNoesisBackEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BackEase::StaticGetClassType();
}

void UNoesisBackEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BackEase* NoesisBackEase = NsDynamicCast<Noesis::Gui::BackEase*>(InNoesisComponent);
	check(NoesisBackEase);
}

float UNoesisBackEase::GetAmplitude()
{
	Noesis::Gui::BackEase* NoesisBackEase = NsDynamicCast<Noesis::Gui::BackEase*>(NoesisComponent.GetPtr());
	check(NoesisBackEase);
	return (float)NoesisBackEase->GetAmplitude();
}

void UNoesisBackEase::SetAmplitude(float InAmplitude)
{
	Noesis::Gui::BackEase* NoesisBackEase = NsDynamicCast<Noesis::Gui::BackEase*>(NoesisComponent.GetPtr());
	check(NoesisBackEase);
	NoesisBackEase->SetAmplitude(InAmplitude);
}

void UNoesisBackEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BackEase* NoesisBackEase = NsDynamicCast<Noesis::Gui::BackEase*>(NoesisComponent.GetPtr());
	check(NoesisBackEase);


}

void UNoesisBackEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BackEase* NoesisBackEase = NsDynamicCast<Noesis::Gui::BackEase*>(NoesisComponent.GetPtr());
	check(NoesisBackEase);


}

