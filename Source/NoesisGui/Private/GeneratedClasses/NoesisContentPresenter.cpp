////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisContentPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisContentPresenter::UNoesisContentPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisContentPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(InNoesisComponent);
	check(NoesisContentPresenter);
}

class UNoesisBaseComponent* UNoesisContentPresenter::GetContent()
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisContentPresenter->GetContent()));
}

void UNoesisContentPresenter::SetContent(class UNoesisBaseComponent* InContent)
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	NoesisContentPresenter->SetContent(NsDynamicCast<Core::BaseComponent*>(InContent->NoesisComponent.GetPtr()));
}

FString UNoesisContentPresenter::GetContentSource()
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	return NsStringToFString(NoesisContentPresenter->GetContentSource());
}

void UNoesisContentPresenter::SetContentSource(FString InContentSource)
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	NoesisContentPresenter->SetContentSource(StringCast<NsChar>(*InContentSource).Get());
}

class UNoesisDataTemplate* UNoesisContentPresenter::GetContentTemplate()
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisContentPresenter->GetContentTemplate()));
}

void UNoesisContentPresenter::SetContentTemplate(class UNoesisDataTemplate* InContentTemplate)
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	NoesisContentPresenter->SetContentTemplate(NsDynamicCast<DataTemplate*>(InContentTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisContentPresenter::GetContentTemplateSelector()
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisContentPresenter->GetContentTemplateSelector()));
}

void UNoesisContentPresenter::SetContentTemplateSelector(class UNoesisDataTemplateSelector* InContentTemplateSelector)
{
	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);
	NoesisContentPresenter->SetContentTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InContentTemplateSelector->NoesisComponent.GetPtr()));
}

void UNoesisContentPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter)


}

void UNoesisContentPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter)


}

