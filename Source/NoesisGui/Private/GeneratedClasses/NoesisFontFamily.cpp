////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisFontFamily.h"

using namespace Noesis;
using namespace Gui;

UNoesisFontFamily::UNoesisFontFamily(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisFontFamily::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::FontFamily* NoesisFontFamily = NsDynamicCast<Noesis::Gui::FontFamily*>(InNoesisComponent);
	check(NoesisFontFamily);
}

FString UNoesisFontFamily::GetBaseUri()
{
	Noesis::Gui::FontFamily* NoesisFontFamily = NsDynamicCast<Noesis::Gui::FontFamily*>(NoesisComponent.GetPtr());
	check(NoesisFontFamily);
	return NsStringToFString(NoesisFontFamily->GetBaseUri());
}

FString UNoesisFontFamily::GetName()
{
	Noesis::Gui::FontFamily* NoesisFontFamily = NsDynamicCast<Noesis::Gui::FontFamily*>(NoesisComponent.GetPtr());
	check(NoesisFontFamily);
	return NsStringToFString(NoesisFontFamily->GetName());
}

FString UNoesisFontFamily::GetSource()
{
	Noesis::Gui::FontFamily* NoesisFontFamily = NsDynamicCast<Noesis::Gui::FontFamily*>(NoesisComponent.GetPtr());
	check(NoesisFontFamily);
	return NsStringToFString(NoesisFontFamily->GetSource());
}

void UNoesisFontFamily::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::FontFamily* NoesisFontFamily = NsDynamicCast<Noesis::Gui::FontFamily*>(NoesisComponent.GetPtr());
	check(NoesisFontFamily)


}

void UNoesisFontFamily::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::FontFamily* NoesisFontFamily = NsDynamicCast<Noesis::Gui::FontFamily*>(NoesisComponent.GetPtr());
	check(NoesisFontFamily)


}

