////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiINameScope.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiINameScope::UNoesisGuiINameScope(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiINameScope::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(InNoesisInterface);
	check(NoesisINameScope);

}

class UNoesisGuiBaseComponent* UNoesisGuiINameScope::FindName(FString InName)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisINameScope->FindName(NoesisInName)));
}

void UNoesisGuiINameScope::RegisterName(FString InName, class UNoesisGuiBaseComponent* InObject)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	Core::BaseComponent* NoesisInObject = NsDynamicCast<Core::BaseComponent*>(InObject->NoesisComponent.GetPtr());
	return NoesisINameScope->RegisterName(NoesisInName, NoesisInObject);
}

void UNoesisGuiINameScope::UnregisterName(FString InName)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return NoesisINameScope->UnregisterName(NoesisInName);
}

void UNoesisGuiINameScope::UpdateName(FString InName, class UNoesisGuiBaseComponent* InObject)
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	check(NoesisINameScope);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	Core::BaseComponent* NoesisInObject = NsDynamicCast<Core::BaseComponent*>(InObject->NoesisComponent.GetPtr());
	return NoesisINameScope->UpdateName(NoesisInName, NoesisInObject);
}

	void UNoesisGuiINameScope::BeginDestroy()
{
	Noesis::Gui::INameScope* NoesisINameScope = NsDynamicCast<Noesis::Gui::INameScope*>(NoesisInterface.GetPtr());
	if (!NoesisINameScope)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

