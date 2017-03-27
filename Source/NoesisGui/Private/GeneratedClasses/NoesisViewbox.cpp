////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisViewbox.h"

using namespace Noesis;
using namespace Gui;

UNoesisViewbox::UNoesisViewbox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Viewbox::StaticGetClassType();
}

void UNoesisViewbox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(InNoesisComponent);
	check(NoesisViewbox);
}

class UNoesisUIElement* UNoesisViewbox::GetChild()
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisViewbox->GetChild(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisViewbox::SetChild(class UNoesisUIElement* InChild)
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	NoesisViewbox->SetChild(NsDynamicCast<UIElement*>(InChild->NoesisComponent.GetPtr()));
}

ENoesisStretch UNoesisViewbox::GetStretch()
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	return (ENoesisStretch)NoesisViewbox->GetStretch();
}

void UNoesisViewbox::SetStretch(ENoesisStretch InStretch)
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	NoesisViewbox->SetStretch((Noesis::Gui::Stretch)InStretch);
}

ENoesisStretchDirection UNoesisViewbox::GetStretchDirection()
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	return (ENoesisStretchDirection)NoesisViewbox->GetStretchDirection();
}

void UNoesisViewbox::SetStretchDirection(ENoesisStretchDirection InStretchDirection)
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	NoesisViewbox->SetStretchDirection((Noesis::Gui::StretchDirection)InStretchDirection);
}

void UNoesisViewbox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);


}

void UNoesisViewbox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);


}

