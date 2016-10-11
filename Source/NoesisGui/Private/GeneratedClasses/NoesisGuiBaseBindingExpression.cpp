////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseBindingExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseBindingExpression::UNoesisGuiBaseBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseBindingExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(InNoesisComponent);
	check(NoesisBaseBindingExpression);

}

class UNoesisGuiBaseBinding* UNoesisGuiBaseBindingExpression::GetBinding()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisGuiBaseBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBindingExpression->GetBinding()));
}

	void UNoesisGuiBaseBindingExpression::BeginDestroy()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	if (!NoesisBaseBindingExpression)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

