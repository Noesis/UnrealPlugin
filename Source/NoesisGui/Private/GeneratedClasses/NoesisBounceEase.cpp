////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBounceEase.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBounceEase::UNoesisBounceEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BounceEase::StaticGetClassType();
}

void UNoesisBounceEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(InNoesisComponent);
	check(NoesisBounceEase);
}

int32 UNoesisBounceEase::GetBounces()
{
	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase);
	return NoesisBounceEase->GetBounces();
}

void UNoesisBounceEase::SetBounces(int32 InBounces)
{
	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase);
	NoesisBounceEase->SetBounces(InBounces);
}

float UNoesisBounceEase::GetBounciness()
{
	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase);
	return (float)NoesisBounceEase->GetBounciness();
}

void UNoesisBounceEase::SetBounciness(float InBounciness)
{
	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase);
	NoesisBounceEase->SetBounciness(InBounciness);
}

void UNoesisBounceEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase);


}

void UNoesisBounceEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BounceEase* NoesisBounceEase = NsDynamicCast<Noesis::Gui::BounceEase*>(NoesisComponent.GetPtr());
	check(NoesisBounceEase);


}

