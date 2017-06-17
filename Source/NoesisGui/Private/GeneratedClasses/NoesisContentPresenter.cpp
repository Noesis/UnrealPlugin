////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisContentPresenter.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisContentPresenter::UNoesisContentPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ContentPresenter::StaticGetClassType();
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
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisContentPresenter->GetContent(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisDataTemplate>(CreateClassFor(NoesisContentPresenter->GetContentTemplate(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisDataTemplateSelector>(CreateClassFor(NoesisContentPresenter->GetContentTemplateSelector(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisContentPresenter);


}

void UNoesisContentPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ContentPresenter* NoesisContentPresenter = NsDynamicCast<Noesis::Gui::ContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisContentPresenter);


}

