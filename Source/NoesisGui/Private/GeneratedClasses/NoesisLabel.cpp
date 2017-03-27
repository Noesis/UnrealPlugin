////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisLabel.h"

using namespace Noesis;
using namespace Gui;

UNoesisLabel::UNoesisLabel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Label::StaticGetClassType();
}

void UNoesisLabel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Label* NoesisLabel = NsDynamicCast<Noesis::Gui::Label*>(InNoesisComponent);
	check(NoesisLabel);
}

void UNoesisLabel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Label* NoesisLabel = NsDynamicCast<Noesis::Gui::Label*>(NoesisComponent.GetPtr());
	check(NoesisLabel);


}

void UNoesisLabel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Label* NoesisLabel = NsDynamicCast<Noesis::Gui::Label*>(NoesisComponent.GetPtr());
	check(NoesisLabel);


}

