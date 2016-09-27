////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGridViewColumn.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGridViewColumn::UNoesisGuiGridViewColumn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGridViewColumn::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(InNoesisComponent);
	check(NoesisGridViewColumn);

}

float UNoesisGuiGridViewColumn::GetActualWidth()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return (float)NoesisGridViewColumn->GetActualWidth();
}

void UNoesisGuiGridViewColumn::SetActualWidth(float InActualWidth)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetActualWidth(InActualWidth);
}

class UNoesisGuiBaseBindingExpression* UNoesisGuiGridViewColumn::GetDisplayMemberBinding()
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	return CastChecked<UNoesisGuiBaseBindingExpression>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumn->GetDisplayMemberBinding()));
}

void UNoesisGuiGridViewColumn::SetDisplayMemberBinding(class UNoesisGuiBaseBindingExpression* InDisplayMemberBinding)
{
	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumn);
	NoesisGridViewColumn->SetDisplayMemberBinding(NsDynamicCast<BaseBindingExpression*>(InDisplayMemberBinding->NoesisComponent.GetPtr()));
}

	void UNoesisGuiGridViewColumn::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::GridViewColumn* NoesisGridViewColumn = NsDynamicCast<Noesis::Gui::GridViewColumn*>(NoesisComponent.GetPtr());
	if (!NoesisGridViewColumn)
		return;

}

