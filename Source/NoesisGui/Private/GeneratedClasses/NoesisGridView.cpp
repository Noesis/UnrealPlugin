////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGridView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridView::UNoesisGridView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGridView::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(InNoesisComponent);
	check(NoesisGridView);
}

bool UNoesisGridView::GetAllowsColumnReorder()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return NoesisGridView->GetAllowsColumnReorder();
}

void UNoesisGridView::SetAllowsColumnReorder(bool InAllowsColumnReorder)
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	NoesisGridView->SetAllowsColumnReorder(InAllowsColumnReorder);
}

class UNoesisStyle* UNoesisGridView::GetColumnHeaderContainerStyle()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return CastChecked<UNoesisStyle>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridView->GetColumnHeaderContainerStyle()));
}

void UNoesisGridView::SetColumnHeaderContainerStyle(class UNoesisStyle* InColumnHeaderContainerStyle)
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	NoesisGridView->SetColumnHeaderContainerStyle(NsDynamicCast<Style*>(InColumnHeaderContainerStyle->NoesisComponent.GetPtr()));
}

class UNoesisContextMenu* UNoesisGridView::GetColumnHeaderContextMenu()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return CastChecked<UNoesisContextMenu>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridView->GetColumnHeaderContextMenu()));
}

void UNoesisGridView::SetColumnHeaderContextMenu(class UNoesisContextMenu* InColumnHeaderContextMenu)
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	NoesisGridView->SetColumnHeaderContextMenu(NsDynamicCast<ContextMenu*>(InColumnHeaderContextMenu->NoesisComponent.GetPtr()));
}

FString UNoesisGridView::GetColumnHeaderStringFormat()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return NsStringToFString(NoesisGridView->GetColumnHeaderStringFormat());
}

void UNoesisGridView::SetColumnHeaderStringFormat(FString InColumnHeaderStringFormat)
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	NoesisGridView->SetColumnHeaderStringFormat(StringCast<NsChar>(*InColumnHeaderStringFormat).Get());
}

class UNoesisDataTemplate* UNoesisGridView::GetColumnHeaderTemplate()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridView->GetColumnHeaderTemplate()));
}

void UNoesisGridView::SetColumnHeaderTemplate(class UNoesisDataTemplate* InColumnHeaderTemplate)
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	NoesisGridView->SetColumnHeaderTemplate(NsDynamicCast<DataTemplate*>(InColumnHeaderTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisGridView::GetColumnHeaderTemplateSelector()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridView->GetColumnHeaderTemplateSelector()));
}

void UNoesisGridView::SetColumnHeaderTemplateSelector(class UNoesisDataTemplateSelector* InColumnHeaderTemplateSelector)
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	NoesisGridView->SetColumnHeaderTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InColumnHeaderTemplateSelector->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisGridView::GetColumnHeaderToolTip()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridView->GetColumnHeaderToolTip()));
}

void UNoesisGridView::SetColumnHeaderToolTip(class UNoesisBaseComponent* InColumnHeaderToolTip)
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	NoesisGridView->SetColumnHeaderToolTip(NsDynamicCast<Core::BaseComponent*>(InColumnHeaderToolTip->NoesisComponent.GetPtr()));
}

class UNoesisGridViewColumnCollection* UNoesisGridView::GetColumns()
{
	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);
	return CastChecked<UNoesisGridViewColumnCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridView->GetColumns()));
}

void UNoesisGridView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView)


}

void UNoesisGridView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView)


}

