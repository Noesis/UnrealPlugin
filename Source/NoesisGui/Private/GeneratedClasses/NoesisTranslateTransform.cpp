////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTranslateTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisTranslateTransform::UNoesisTranslateTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTranslateTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(InNoesisComponent);
	check(NoesisTranslateTransform);
}

float UNoesisTranslateTransform::GetX()
{
	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(NoesisComponent.GetPtr());
	check(NoesisTranslateTransform);
	return (float)NoesisTranslateTransform->GetX();
}

void UNoesisTranslateTransform::SetX(float InX)
{
	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(NoesisComponent.GetPtr());
	check(NoesisTranslateTransform);
	NoesisTranslateTransform->SetX(InX);
}

float UNoesisTranslateTransform::GetY()
{
	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(NoesisComponent.GetPtr());
	check(NoesisTranslateTransform);
	return (float)NoesisTranslateTransform->GetY();
}

void UNoesisTranslateTransform::SetY(float InY)
{
	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(NoesisComponent.GetPtr());
	check(NoesisTranslateTransform);
	NoesisTranslateTransform->SetY(InY);
}

void UNoesisTranslateTransform::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(NoesisComponent.GetPtr());
	check(NoesisTranslateTransform)


}

void UNoesisTranslateTransform::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(NoesisComponent.GetPtr());
	check(NoesisTranslateTransform)


}

