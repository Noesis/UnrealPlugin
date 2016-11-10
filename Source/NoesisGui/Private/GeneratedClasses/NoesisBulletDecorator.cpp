////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBulletDecorator.h"

using namespace Noesis;
using namespace Gui;

UNoesisBulletDecorator::UNoesisBulletDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBulletDecorator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(InNoesisComponent);
	check(NoesisBulletDecorator);
}

class UNoesisBrush* UNoesisBulletDecorator::GetBackground()
{
	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisBulletDecorator->GetBackground()));
}

void UNoesisBulletDecorator::SetBackground(class UNoesisBrush* InBackground)
{
	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator);
	NoesisBulletDecorator->SetBackground(NsDynamicCast<Brush*>(InBackground->NoesisComponent.GetPtr()));
}

class UNoesisUIElement* UNoesisBulletDecorator::GetBullet()
{
	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator);
	return CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisBulletDecorator->GetBullet()));
}

void UNoesisBulletDecorator::SetBullet(class UNoesisUIElement* InBullet)
{
	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator);
	NoesisBulletDecorator->SetBullet(NsDynamicCast<UIElement*>(InBullet->NoesisComponent.GetPtr()));
}

void UNoesisBulletDecorator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator)


}

void UNoesisBulletDecorator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator)


}

