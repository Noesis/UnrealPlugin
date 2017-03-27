////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSeparator.h"

using namespace Noesis;
using namespace Gui;

UNoesisSeparator::UNoesisSeparator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Separator::StaticGetClassType();
}

void UNoesisSeparator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Separator* NoesisSeparator = NsDynamicCast<Noesis::Gui::Separator*>(InNoesisComponent);
	check(NoesisSeparator);
}

void UNoesisSeparator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Separator* NoesisSeparator = NsDynamicCast<Noesis::Gui::Separator*>(NoesisComponent.GetPtr());
	check(NoesisSeparator);


}

void UNoesisSeparator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Separator* NoesisSeparator = NsDynamicCast<Noesis::Gui::Separator*>(NoesisComponent.GetPtr());
	check(NoesisSeparator);


}

