////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiViewbox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiViewbox::UNoesisGuiViewbox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiViewbox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(InNoesisComponent);
	check(NoesisViewbox);

}

class UNoesisGuiUIElement* UNoesisGuiViewbox::GetChild()
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	return CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisViewbox->GetChild()));
}

void UNoesisGuiViewbox::SetChild(class UNoesisGuiUIElement* InChild)
{
	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	check(NoesisViewbox);
	NoesisViewbox->SetChild(NsDynamicCast<UIElement*>(InChild->NoesisComponent.GetPtr()));
}

	void UNoesisGuiViewbox::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Viewbox* NoesisViewbox = NsDynamicCast<Noesis::Gui::Viewbox*>(NoesisComponent.GetPtr());
	if (!NoesisViewbox)
		return;

}

