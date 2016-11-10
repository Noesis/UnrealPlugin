////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGridViewColumn.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridViewColumn::UNoesisGridViewColumn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGridViewColumn::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(InNoesisComponent);
	check(NoesisGridViewColumn);
}

float UNoesisGridViewColumn::GetActualWidth()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return (float)NoesisGridViewColumn->GetActualWidth();
}

void UNoesisGridViewColumn::SetActualWidth(float InActualWidth)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetActualWidth(InActualWidth);
}

class UNoesisDataTemplate* UNoesisGridViewColumn::GetCellTemplate()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetCellTemplate()));
}

void UNoesisGridViewColumn::SetCellTemplate(class UNoesisDataTemplate* InCellTemplate)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetCellTemplate(NsDynamicCast<DataTemplate*>(InCellTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisGridViewColumn::GetCellTemplateSelector()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetCellTemplateSelector()));
}

void UNoesisGridViewColumn::SetCellTemplateSelector(class UNoesisDataTemplateSelector* InCellTemplateSelector)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetCellTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InCellTemplateSelector->NoesisComponent.GetPtr()));
}

class UNoesisBaseBindingExpression* UNoesisGridViewColumn::GetDisplayMemberBinding()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisBaseBindingExpression>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetDisplayMemberBinding()));
}

void UNoesisGridViewColumn::SetDisplayMemberBinding(class UNoesisBaseBindingExpression* InDisplayMemberBinding)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetDisplayMemberBinding(NsDynamicCast<BaseBindingExpression*>(InDisplayMemberBinding->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisGridViewColumn::GetHeader()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetHeader()));
}

void UNoesisGridViewColumn::SetHeader(class UNoesisBaseComponent* InHeader)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetHeader(NsDynamicCast<Core::BaseComponent*>(InHeader->NoesisComponent.GetPtr()));
}

class UNoesisStyle* UNoesisGridViewColumn::GetHeaderContainerStyle()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisStyle>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetHeaderContainerStyle()));
}

void UNoesisGridViewColumn::SetHeaderContainerStyle(class UNoesisStyle* InHeaderContainerStyle)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetHeaderContainerStyle(NsDynamicCast<Style*>(InHeaderContainerStyle->NoesisComponent.GetPtr()));
}

FString UNoesisGridViewColumn::GetHeaderStringFormat()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return NsStringToFString(NoesisGridViewColumn->GetHeaderStringFormat());
}

void UNoesisGridViewColumn::SetHeaderStringFormat(FString InHeaderStringFormat)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetHeaderStringFormat(StringCast<NsChar>(*InHeaderStringFormat).Get());
}

class UNoesisDataTemplate* UNoesisGridViewColumn::GetHeaderTemplate()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisDataTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetHeaderTemplate()));
}

void UNoesisGridViewColumn::SetHeaderTemplate(class UNoesisDataTemplate* InHeaderTemplate)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetHeaderTemplate(NsDynamicCast<DataTemplate*>(InHeaderTemplate->NoesisComponent.GetPtr()));
}

class UNoesisDataTemplateSelector* UNoesisGridViewColumn::GetHeaderTemplateSelector()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisDataTemplateSelector>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetHeaderTemplateSelector()));
}

void UNoesisGridViewColumn::SetHeaderTemplateSelector(class UNoesisDataTemplateSelector* InHeaderTemplateSelector)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetHeaderTemplateSelector(NsDynamicCast<DataTemplateSelector*>(InHeaderTemplateSelector->NoesisComponent.GetPtr()));
}

float UNoesisGridViewColumn::GetWidth()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return (float)NoesisGridViewColumn->GetWidth();
}

void UNoesisGridViewColumn::SetWidth(float InWidth)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetWidth(InWidth);
}

void UNoesisGridViewColumn::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn)


}

void UNoesisGridViewColumn::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn)


}

