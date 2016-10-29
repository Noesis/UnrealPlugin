////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiKeyGesture.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiKeyGesture::UNoesisGuiKeyGesture(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiKeyGesture::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(InNoesisComponent);
	check(NoesisKeyGesture);
}

FString UNoesisGuiKeyGesture::GetDisplayString()
{
	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);
	return NsStringToFString(NoesisKeyGesture->GetDisplayString().c_str());
}

int32 UNoesisGuiKeyGesture::GetKey()
{
	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);
	return NoesisKeyGesture->GetKey();
}

int32 UNoesisGuiKeyGesture::GetModifiers()
{
	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);
	return NoesisKeyGesture->GetModifiers();
}

void UNoesisGuiKeyGesture::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture)


}

void UNoesisGuiKeyGesture::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture)


}

