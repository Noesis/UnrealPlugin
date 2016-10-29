////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiExpression::UNoesisGuiExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Expression* NoesisExpression = NsDynamicCast<Noesis::Gui::Expression*>(InNoesisComponent);
	check(NoesisExpression);
}

void UNoesisGuiExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Expression* NoesisExpression = NsDynamicCast<Noesis::Gui::Expression*>(NoesisComponent.GetPtr());
	check(NoesisExpression)


}

void UNoesisGuiExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Expression* NoesisExpression = NsDynamicCast<Noesis::Gui::Expression*>(NoesisComponent.GetPtr());
	check(NoesisExpression)


}

