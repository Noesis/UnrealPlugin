////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisEasingFunctionBase.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingFunctionBase::UNoesisEasingFunctionBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::EasingFunctionBase::StaticGetClassType();
}

void UNoesisEasingFunctionBase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingFunctionBase* NoesisEasingFunctionBase = NsDynamicCast<Noesis::Gui::EasingFunctionBase*>(InNoesisComponent);
	check(NoesisEasingFunctionBase);
}

ENoesisEasingMode UNoesisEasingFunctionBase::GetEasingMode()
{
	Noesis::Gui::EasingFunctionBase* NoesisEasingFunctionBase = NsDynamicCast<Noesis::Gui::EasingFunctionBase*>(NoesisComponent.GetPtr());
	check(NoesisEasingFunctionBase);
	return (ENoesisEasingMode)NoesisEasingFunctionBase->GetEasingMode();
}

void UNoesisEasingFunctionBase::SetEasingMode(ENoesisEasingMode InEasingMode)
{
	Noesis::Gui::EasingFunctionBase* NoesisEasingFunctionBase = NsDynamicCast<Noesis::Gui::EasingFunctionBase*>(NoesisComponent.GetPtr());
	check(NoesisEasingFunctionBase);
	NoesisEasingFunctionBase->SetEasingMode((Noesis::Gui::EasingMode)InEasingMode);
}

void UNoesisEasingFunctionBase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingFunctionBase* NoesisEasingFunctionBase = NsDynamicCast<Noesis::Gui::EasingFunctionBase*>(NoesisComponent.GetPtr());
	check(NoesisEasingFunctionBase);


}

void UNoesisEasingFunctionBase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingFunctionBase* NoesisEasingFunctionBase = NsDynamicCast<Noesis::Gui::EasingFunctionBase*>(NoesisComponent.GetPtr());
	check(NoesisEasingFunctionBase);


}

