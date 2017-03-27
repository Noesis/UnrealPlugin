////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisBulletDecorator.h"

using namespace Noesis;
using namespace Gui;

UNoesisBulletDecorator::UNoesisBulletDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BulletDecorator::StaticGetClassType();
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
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisBulletDecorator->GetBackground(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisBulletDecorator->GetBullet(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisBulletDecorator);


}

void UNoesisBulletDecorator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator);


}

