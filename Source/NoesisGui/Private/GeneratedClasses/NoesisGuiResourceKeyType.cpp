////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiResourceKeyType.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiResourceKeyType::UNoesisGuiResourceKeyType(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiResourceKeyType::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ResourceKeyType* NoesisResourceKeyType = NsDynamicCast<Noesis::Gui::ResourceKeyType*>(InNoesisComponent);
	check(NoesisResourceKeyType);

}

	void UNoesisGuiResourceKeyType::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ResourceKeyType* NoesisResourceKeyType = NsDynamicCast<Noesis::Gui::ResourceKeyType*>(NoesisComponent.GetPtr());
	if (!NoesisResourceKeyType)
		return;

}

