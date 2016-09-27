////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLabel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLabel::UNoesisGuiLabel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLabel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Label* NoesisLabel = NsDynamicCast<Noesis::Gui::Label*>(InNoesisComponent);
	check(NoesisLabel);

}

	void UNoesisGuiLabel::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Label* NoesisLabel = NsDynamicCast<Noesis::Gui::Label*>(NoesisComponent.GetPtr());
	if (!NoesisLabel)
		return;

}

