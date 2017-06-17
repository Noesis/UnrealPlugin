////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisGridView.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridView::UNoesisGridView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::GridView::StaticGetClassType();
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
	return CastChecked<UNoesisStyle>(CreateClassFor(NoesisGridView->GetColumnHeaderContainerStyle(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisContextMenu>(CreateClassFor(NoesisGridView->GetColumnHeaderContextMenu(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisDataTemplate>(CreateClassFor(NoesisGridView->GetColumnHeaderTemplate(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisDataTemplateSelector>(CreateClassFor(NoesisGridView->GetColumnHeaderTemplateSelector(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisGridView->GetColumnHeaderToolTip(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisGridViewColumnCollection>(CreateClassFor(NoesisGridView->GetColumns(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisGridView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);


}

void UNoesisGridView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridView* NoesisGridView = NsDynamicCast<Noesis::Gui::GridView*>(NoesisComponent.GetPtr());
	check(NoesisGridView);


}

