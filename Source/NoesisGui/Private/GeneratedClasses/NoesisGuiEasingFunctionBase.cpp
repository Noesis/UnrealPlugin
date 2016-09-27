////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingFunctionBase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingFunctionBase::UNoesisGuiEasingFunctionBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingFunctionBase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingFunctionBase* NoesisEasingFunctionBase = NsDynamicCast<Noesis::Gui::EasingFunctionBase*>(InNoesisComponent);
	check(NoesisEasingFunctionBase);

}

	void UNoesisGuiEasingFunctionBase::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::EasingFunctionBase* NoesisEasingFunctionBase = NsDynamicCast<Noesis::Gui::EasingFunctionBase*>(NoesisComponent.GetPtr());
	if (!NoesisEasingFunctionBase)
		return;

}

