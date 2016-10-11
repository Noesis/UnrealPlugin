////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseExpression::UNoesisGuiBaseExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseExpression* NoesisBaseExpression = NsDynamicCast<Noesis::Gui::BaseExpression*>(InNoesisComponent);
	check(NoesisBaseExpression);

}

	void UNoesisGuiBaseExpression::BeginDestroy()
{
	Noesis::Gui::BaseExpression* NoesisBaseExpression = NsDynamicCast<Noesis::Gui::BaseExpression*>(NoesisComponent.GetPtr());
	if (!NoesisBaseExpression)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

