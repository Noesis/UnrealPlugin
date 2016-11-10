////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisHeaderedItemsControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisHeaderedItemsControl::UNoesisHeaderedItemsControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisHeaderedItemsControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(InNoesisComponent);
	check(NoesisHeaderedItemsControl);
}

bool UNoesisHeaderedItemsControl::GetHasHeader()
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	return NoesisHeaderedItemsControl->GetHasHeader();
}

class UNoesisBaseComponent* UNoesisHeaderedItemsControl::GetHeader()
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisHeaderedItemsControl->GetHeader()));
}

void UNoesisHeaderedItemsControl::SetHeader(class UNoesisBaseComponent* InHeader)
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	NoesisHeaderedItemsControl->SetHeader(NsDynamicCast<Core::BaseComponent*>(InHeader->NoesisComponent.GetPtr()));
}

FString UNoesisHeaderedItemsControl::GetHeaderStringFormat()
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	return NsStringToFString(NoesisHeaderedItemsControl->GetHeaderStringFormat());
}

void UNoesisHeaderedItemsControl::SetHeaderStringFormat(FString InHeaderStringFormat)
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	NoesisHeaderedItemsControl->SetHeaderStringFormat(StringCast<NsChar>(*InHeaderStringFormat).Get());
}

class UNoesisDataTemplate* UNoesisHeaderedItemsControl::GetHeaderTemplate()
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisHeaderedItemsControl->GetHeaderTemplate()));
}

void UNoesisHeaderedItemsControl::SetHeaderTemplate(class UNoesisDataTemplate* InHeaderTemplate)
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	NoesisHeaderedItemsControl->SetHeaderTemplate(NsDynamicCast<DataTemplate*>(InHeaderTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisHeaderedItemsControl::GetHeaderTemplateSelector()
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisHeaderedItemsControl->GetHeaderTemplateSelector()));
}

void UNoesisHeaderedItemsControl::SetHeaderTemplateSelector(class UNoesisDataTemplateSelector* InHeaderTemplateSelector)
{
	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl);
	NoesisHeaderedItemsControl->SetHeaderTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InHeaderTemplateSelector->NoesisComponent.GetPtr()));
}

void UNoesisHeaderedItemsControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl)


}

void UNoesisHeaderedItemsControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::HeaderedItemsControl* NoesisHeaderedItemsControl = NsDynamicCast<Noesis::Gui::HeaderedItemsControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedItemsControl)


}

