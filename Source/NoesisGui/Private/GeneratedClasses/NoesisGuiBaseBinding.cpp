////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseBinding::UNoesisGuiBaseBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseBinding* NoesisBaseBinding = NsDynamicCast<Noesis::Gui::BaseBinding*>(InNoesisComponent);
	check(NoesisBaseBinding);

}

class UNoesisGuiBaseComponent* UNoesisGuiBaseBinding::GetFallbackValue()
{
	Noesis::Gui::BaseBinding* NoesisBaseBinding = NsDynamicCast<Noesis::Gui::BaseBinding*>(NoesisComponent.GetPtr());
	check(NoesisBaseBinding);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBinding->GetFallbackValue()));
}

void UNoesisGuiBaseBinding::SetFallbackValue(class UNoesisGuiBaseComponent* InFallbackValue)
{
	Noesis::Gui::BaseBinding* NoesisBaseBinding = NsDynamicCast<Noesis::Gui::BaseBinding*>(NoesisComponent.GetPtr());
	check(NoesisBaseBinding);
	NoesisBaseBinding->SetFallbackValue(NsDynamicCast<Core::BaseComponent*>(InFallbackValue->NoesisComponent.GetPtr()));
}

FString UNoesisGuiBaseBinding::GetStringFormat()
{
	Noesis::Gui::BaseBinding* NoesisBaseBinding = NsDynamicCast<Noesis::Gui::BaseBinding*>(NoesisComponent.GetPtr());
	check(NoesisBaseBinding);
	return NsStringToFString(NoesisBaseBinding->GetStringFormat());
}

void UNoesisGuiBaseBinding::SetStringFormat(FString InStringFormat)
{
	Noesis::Gui::BaseBinding* NoesisBaseBinding = NsDynamicCast<Noesis::Gui::BaseBinding*>(NoesisComponent.GetPtr());
	check(NoesisBaseBinding);
	NoesisBaseBinding->SetStringFormat(StringCast<NsChar>(*InStringFormat).Get());
}

	void UNoesisGuiBaseBinding::BeginDestroy()
{
	Noesis::Gui::BaseBinding* NoesisBaseBinding = NsDynamicCast<Noesis::Gui::BaseBinding*>(NoesisComponent.GetPtr());
	if (!NoesisBaseBinding)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

