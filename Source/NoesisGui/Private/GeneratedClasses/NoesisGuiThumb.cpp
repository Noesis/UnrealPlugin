////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiThumb.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiThumb::UNoesisGuiThumb(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiThumb::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(InNoesisComponent);
	check(NoesisThumb);

}

	void UNoesisGuiThumb::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	if (!NoesisThumb)
		return;

}

