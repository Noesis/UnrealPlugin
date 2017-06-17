////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisGridViewColumnHeader.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridViewColumnHeader::UNoesisGridViewColumnHeader(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::GridViewColumnHeader::StaticGetClassType();
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
	return CastChecked<UNoesisGridViewColumn>(CreateClassFor(NoesisGridViewColumnHeader->GetColumn(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisGridViewColumnHeader);


}

void UNoesisGridViewColumnHeader::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GridViewColumnHeader* NoesisGridViewColumnHeader = NsDynamicCast<Noesis::Gui::GridViewColumnHeader*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumnHeader);


}

