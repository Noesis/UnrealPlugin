////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisInt16Animation.h"

using namespace Noesis;
using namespace Gui;

UNoesisInt16Animation::UNoesisInt16Animation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Animation<NsInt16>::StaticGetClassType();
}

void UNoesisInt16Animation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<NsInt16>* NoesisInt16Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt16>*>(InNoesisComponent);
	check(NoesisInt16Animation);
}

void UNoesisInt16Animation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<NsInt16>* NoesisInt16Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16Animation);


}

void UNoesisInt16Animation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<NsInt16>* NoesisInt16Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16Animation);


}

