////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisINameScope.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisINameScope::UNoesisINameScope(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::INameScope::StaticGetClassType();
}

void UNoesisINameScope::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(InNoesisInterface);
	check(NoesisINameScope);
}

class UNoesisBaseComponent* UNoesisINameScope::FindName(FString InName)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisINameScope->FindName(NoesisInName), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisINameScope::RegisterName(FString InName, class UNoesisBaseComponent* InObject)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	Core::BaseComponent* NoesisInObject = NsDynamicCast<Core::BaseComponent*>(InObject->NoesisComponent.GetPtr());
	return NoesisINameScope->RegisterName(NoesisInName, NoesisInObject);
}

void UNoesisINameScope::UnregisterName(FString InName)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return NoesisINameScope->UnregisterName(NoesisInName);
}

void UNoesisINameScope::UpdateName(FString InName, class UNoesisBaseComponent* InObject)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	Core::BaseComponent* NoesisInObject = NsDynamicCast<Core::BaseComponent*>(InObject->NoesisComponent.GetPtr());
	return NoesisINameScope->UpdateName(NoesisInName, NoesisInObject);
}

void UNoesisINameScope::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);


}

void UNoesisINameScope::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);


}

