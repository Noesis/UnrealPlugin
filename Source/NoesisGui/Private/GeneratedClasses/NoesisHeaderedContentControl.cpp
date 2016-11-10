////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisHeaderedContentControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisHeaderedContentControl::UNoesisHeaderedContentControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisHeaderedContentControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(InNoesisComponent);
	check(NoesisHeaderedContentControl);
}

bool UNoesisHeaderedContentControl::GetHasHeader()
{
	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl);
	return NoesisHeaderedContentControl->GetHasHeader();
}

class UNoesisBaseComponent* UNoesisHeaderedContentControl::GetHeader()
{
	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisHeaderedContentControl->GetHeader()));
}

void UNoesisHeaderedContentControl::SetHeader(class UNoesisBaseComponent* InHeader)
{
	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl);
	NoesisHeaderedContentControl->SetHeader(NsDynamicCast<Core::BaseComponent*>(InHeader->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplate* UNoesisHeaderedContentControl::GetHeaderTemplate()
{
	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisHeaderedContentControl->GetHeaderTemplate()));
}

void UNoesisHeaderedContentControl::SetHeaderTemplate(class UNoesisDataTemplate* InHeaderTemplate)
{
	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl);
	NoesisHeaderedContentControl->SetHeaderTemplate(NsDynamicCast<DataTemplate*>(InHeaderTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisHeaderedContentControl::GetHeaderTemplateSelector()
{
	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisHeaderedContentControl->GetHeaderTemplateSelector()));
}

void UNoesisHeaderedContentControl::SetHeaderTemplateSelector(class UNoesisDataTemplateSelector* InHeaderTemplateSelector)
{
	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl);
	NoesisHeaderedContentControl->SetHeaderTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InHeaderTemplateSelector->NoesisComponent.GetPtr()));
}

void UNoesisHeaderedContentControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl)


}

void UNoesisHeaderedContentControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	check(NoesisHeaderedContentControl)


}

