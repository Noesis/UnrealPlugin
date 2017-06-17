////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisKeyGesture.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisKeyGesture::UNoesisKeyGesture(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyGesture::StaticGetClassType();
}

void UNoesisKeyGesture::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(InNoesisComponent);
	check(NoesisKeyGesture);
}

FString UNoesisKeyGesture::GetDisplayString()
{
	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);
	return NsStringToFString(NoesisKeyGesture->GetDisplayString().c_str());
}

int32 UNoesisKeyGesture::GetKey()
{
	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);
	return NoesisKeyGesture->GetKey();
}

int32 UNoesisKeyGesture::GetModifiers()
{
	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);
	return NoesisKeyGesture->GetModifiers();
}

void UNoesisKeyGesture::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);


}

void UNoesisKeyGesture::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyGesture* NoesisKeyGesture = NsDynamicCast<Noesis::Gui::KeyGesture*>(NoesisComponent.GetPtr());
	check(NoesisKeyGesture);


}

