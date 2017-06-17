////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDecorator.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDecorator::UNoesisDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Decorator::StaticGetClassType();
}

void UNoesisDecorator::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Decorator* NoesisDecorator = NsDynamicCast<Noesis::Gui::Decorator*>(InNoesisComponent);
	check(NoesisDecorator);
}

class UNoesisUIElement* UNoesisDecorator::GetChild()
{
	Noesis::Gui::Decorator* NoesisDecorator = NsDynamicCast<Noesis::Gui::Decorator*>(NoesisComponent.GetPtr());
	check(NoesisDecorator);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisDecorator->GetChild(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisDecorator::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Decorator* NoesisDecorator = NsDynamicCast<Noesis::Gui::Decorator*>(NoesisComponent.GetPtr());
	check(NoesisDecorator);


}

void UNoesisDecorator::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Decorator* NoesisDecorator = NsDynamicCast<Noesis::Gui::Decorator*>(NoesisComponent.GetPtr());
	check(NoesisDecorator);


}

