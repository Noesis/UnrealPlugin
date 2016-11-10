////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGridViewColumnHeader.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridViewColumnHeader::UNoesisGridViewColumnHeader(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGridViewColumnHeader::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(InNoesisComponent);
	check(NoesisGridViewColumnHeader);
}

class UNoesisGridViewColumn* UNoesisGridViewColumnHeader::GetColumn()
{
	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumnHeader);
	return CastChecked<UNoesisGridViewColumn>(Instance->FindUnrealComponentForNoesisComponent(NoesisGridViewColumnHeader->GetColumn()));
}

ENoesisGridViewColumnHeaderRole UNoesisGridViewColumnHeader::GetRole()
{
	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumnHeader);
	return (ENoesisGridViewColumnHeaderRole)NoesisGridViewColumnHeader->GetRole();
}

void UNoesisGridViewColumnHeader::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumnHeader)


}

void UNoesisGridViewColumnHeader::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumnHeader)


}

