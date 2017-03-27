////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisResourceKeyType.h"

using namespace Noesis;
using namespace Gui;

UNoesisResourceKeyType::UNoesisResourceKeyType(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ResourceKeyType::StaticGetClassType();
}

void UNoesisResourceKeyType::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ResourceKeyType* NoesisResourceKeyType = NsDynamicCast<Noesis::Gui::ResourceKeyType*>(InNoesisComponent);
	check(NoesisResourceKeyType);
}

void UNoesisResourceKeyType::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ResourceKeyType* NoesisResourceKeyType = NsDynamicCast<Noesis::Gui::ResourceKeyType*>(NoesisComponent.GetPtr());
	check(NoesisResourceKeyType);


}

void UNoesisResourceKeyType::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ResourceKeyType* NoesisResourceKeyType = NsDynamicCast<Noesis::Gui::ResourceKeyType*>(NoesisComponent.GetPtr());
	check(NoesisResourceKeyType);


}

