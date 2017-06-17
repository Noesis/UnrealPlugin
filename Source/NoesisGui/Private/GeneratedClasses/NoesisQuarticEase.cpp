////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisQuarticEase.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisQuarticEase::UNoesisQuarticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::QuarticEase::StaticGetClassType();
}

void UNoesisQuarticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::QuarticEase* NoesisQuarticEase = NsDynamicCast<Noesis::Gui::QuarticEase*>(InNoesisComponent);
	check(NoesisQuarticEase);
}

void UNoesisQuarticEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::QuarticEase* NoesisQuarticEase = NsDynamicCast<Noesis::Gui::QuarticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuarticEase);


}

void UNoesisQuarticEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::QuarticEase* NoesisQuarticEase = NsDynamicCast<Noesis::Gui::QuarticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuarticEase);


}

