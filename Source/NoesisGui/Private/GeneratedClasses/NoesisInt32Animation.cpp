////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisInt32Animation.h"

using namespace Noesis;
using namespace Gui;

UNoesisInt32Animation::UNoesisInt32Animation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Animation<NsInt32>::StaticGetClassType();
}

void UNoesisInt32Animation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animation<NsInt32>* NoesisInt32Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt32>*>(InNoesisComponent);
	check(NoesisInt32Animation);
}

void UNoesisInt32Animation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animation<NsInt32>* NoesisInt32Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32Animation);


}

void UNoesisInt32Animation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animation<NsInt32>* NoesisInt32Animation = NsDynamicCast<Noesis::Gui::Animation<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32Animation);


}

