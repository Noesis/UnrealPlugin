////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTabControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisTabControl::UNoesisTabControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTabControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(InNoesisComponent);
	check(NoesisTabControl);
}

class UNoesisDataTemplate* UNoesisTabControl::GetContentTemplate()
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisTabControl->GetContentTemplate()));
}

void UNoesisTabControl::SetContentTemplate(class UNoesisDataTemplate* InContentTemplate)
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	NoesisTabControl->SetContentTemplate(NsDynamicCast<DataTemplate*>(InContentTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisTabControl::GetContentTemplateSelector()
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisTabControl->GetContentTemplateSelector()));
}

void UNoesisTabControl::SetContentTemplateSelector(class UNoesisDataTemplateSelector* InContentTemplateSelector)
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	NoesisTabControl->SetContentTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InContentTemplateSelector->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisTabControl::GetSelectedContent()
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisTabControl->GetSelectedContent()));
}

class UNoesisDataTemplate* UNoesisTabControl::GetSelectedContentTemplate()
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisTabControl->GetSelectedContentTemplate()));
}

class UNoesisDataTemplateSelector* UNoesisTabControl::GetSelectedContentTemplateSelector()
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisTabControl->GetSelectedContentTemplateSelector()));
}

ENoesisDock UNoesisTabControl::GetTabStripPlacement()
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	return (ENoesisDock)NoesisTabControl->GetTabStripPlacement();
}

void UNoesisTabControl::SetTabStripPlacement(ENoesisDock InTabStripPlacement)
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl);
	NoesisTabControl->SetTabStripPlacement((Noesis::Gui::Dock)InTabStripPlacement);
}

void UNoesisTabControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl)


}

void UNoesisTabControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	check(NoesisTabControl)


}

