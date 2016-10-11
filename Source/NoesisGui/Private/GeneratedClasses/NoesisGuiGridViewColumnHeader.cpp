////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGridViewColumnHeader.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGridViewColumnHeader::UNoesisGuiGridViewColumnHeader(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGridViewColumnHeader::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(InNoesisComponent);
	check(NoesisGridViewColumnHeader);

}

	void UNoesisGuiGridViewColumnHeader::BeginDestroy()
{
	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(NoesisComponent.GetPtr());
	if (!NoesisGridViewColumnHeader)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

