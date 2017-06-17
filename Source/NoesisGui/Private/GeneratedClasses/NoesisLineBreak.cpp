////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisLineBreak.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisLineBreak::UNoesisLineBreak(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LineBreak::StaticGetClassType();
}

void UNoesisLineBreak::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LineBreak* NoesisLineBreak = NsDynamicCast<Noesis::Gui::LineBreak*>(InNoesisComponent);
	check(NoesisLineBreak);
}

void UNoesisLineBreak::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LineBreak* NoesisLineBreak = NsDynamicCast<Noesis::Gui::LineBreak*>(NoesisComponent.GetPtr());
	check(NoesisLineBreak);


}

void UNoesisLineBreak::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LineBreak* NoesisLineBreak = NsDynamicCast<Noesis::Gui::LineBreak*>(NoesisComponent.GetPtr());
	check(NoesisLineBreak);


}

