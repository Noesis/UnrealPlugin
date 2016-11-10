////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGridViewHeaderRowPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridViewHeaderRowPresenter::UNoesisGridViewHeaderRowPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGridViewHeaderRowPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(InNoesisComponent);
	check(NoesisGridViewHeaderRowPresenter);
}

bool UNoesisGridViewHeaderRowPresenter::GetAllowsColumnReorder()
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	return NoesisGridViewHeaderRowPresenter->GetAllowsColumnReorder();
}

void UNoesisGridViewHeaderRowPresenter::SetAllowsColumnReorder(bool InAllowsColumnReorder)
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	NoesisGridViewHeaderRowPresenter->SetAllowsColumnReorder(InAllowsColumnReorder);
}

class UNoesisStyle* UNoesisGridViewHeaderRowPresenter::GetColumnHeaderContainerStyle()
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	return CastChecked<UNoesisStyle>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewHeaderRowPresenter->GetColumnHeaderContainerStyle()));
}

void UNoesisGridViewHeaderRowPresenter::SetColumnHeaderContainerStyle(class UNoesisStyle* InColumnHeaderContainerStyle)
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	NoesisGridViewHeaderRowPresenter->SetColumnHeaderContainerStyle(NsDynamicCast<Style*>(InColumnHeaderContainerStyle->NoesisComponent.GetPtr()));
}

class UNoesisContextMenu* UNoesisGridViewHeaderRowPresenter::GetColumnHeaderContextMenu()
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	return CastChecked<UNoesisContextMenu>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewHeaderRowPresenter->GetColumnHeaderContextMenu()));
}

void UNoesisGridViewHeaderRowPresenter::SetColumnHeaderContextMenu(class UNoesisContextMenu* InColumnHeaderContextMenu)
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	NoesisGridViewHeaderRowPresenter->SetColumnHeaderContextMenu(NsDynamicCast<ContextMenu*>(InColumnHeaderContextMenu->NoesisComponent.GetPtr()));
}

FString UNoesisGridViewHeaderRowPresenter::GetColumnHeaderStringFormat()
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	return NsStringToFString(NoesisGridViewHeaderRowPresenter->GetColumnHeaderStringFormat());
}

void UNoesisGridViewHeaderRowPresenter::SetColumnHeaderStringFormat(FString InColumnHeaderStringFormat)
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	NoesisGridViewHeaderRowPresenter->SetColumnHeaderStringFormat(StringCast<NsChar>(*InColumnHeaderStringFormat).Get());
}

class UNoesisDataTemplate* UNoesisGridViewHeaderRowPresenter::GetColumnHeaderTemplate()
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewHeaderRowPresenter->GetColumnHeaderTemplate()));
}

void UNoesisGridViewHeaderRowPresenter::SetColumnHeaderTemplate(class UNoesisDataTemplate* InColumnHeaderTemplate)
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	NoesisGridViewHeaderRowPresenter->SetColumnHeaderTemplate(NsDynamicCast<DataTemplate*>(InColumnHeaderTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisGridViewHeaderRowPresenter::GetColumnHeaderTemplateSelector()
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewHeaderRowPresenter->GetColumnHeaderTemplateSelector()));
}

void UNoesisGridViewHeaderRowPresenter::SetColumnHeaderTemplateSelector(class UNoesisDataTemplateSelector* InColumnHeaderTemplateSelector)
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	NoesisGridViewHeaderRowPresenter->SetColumnHeaderTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InColumnHeaderTemplateSelector->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisGridViewHeaderRowPresenter::GetColumnHeaderToolTip()
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewHeaderRowPresenter->GetColumnHeaderToolTip()));
}

void UNoesisGridViewHeaderRowPresenter::SetColumnHeaderToolTip(class UNoesisBaseComponent* InColumnHeaderToolTip)
{
	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter);
	NoesisGridViewHeaderRowPresenter->SetColumnHeaderToolTip(NsDynamicCast<Core::BaseComponent*>(InColumnHeaderToolTip->NoesisComponent.GetPtr()));
}

void UNoesisGridViewHeaderRowPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter)


}

void UNoesisGridViewHeaderRowPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridViewHeaderRowPresenter* NoesisGridViewHeaderRowPresenter = NsDynamicCast<Noesis::Gui::GridViewHeaderRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisGridViewHeaderRowPresenter)


}

