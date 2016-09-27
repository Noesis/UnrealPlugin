////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBulletDecorator.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBulletDecorator::UNoesisGuiBulletDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBulletDecorator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(InNoesisComponent);
	check(NoesisBulletDecorator);

}

class UNoesisGuiUIElement* UNoesisGuiBulletDecorator::GetBullet()
{
	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator);
	return CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisBulletDecorator->GetBullet()));
}

void UNoesisGuiBulletDecorator::SetBullet(class UNoesisGuiUIElement* InBullet)
{
	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	check(NoesisBulletDecorator);
	NoesisBulletDecorator->SetBullet(NsDynamicCast<UIElement*>(InBullet->NoesisComponent.GetPtr()));
}

	void UNoesisGuiBulletDecorator::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::BulletDecorator* NoesisBulletDecorator = NsDynamicCast<Noesis::Gui::BulletDecorator*>(NoesisComponent.GetPtr());
	if (!NoesisBulletDecorator)
		return;

}

