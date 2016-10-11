////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTranslateTransform.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTranslateTransform::UNoesisGuiTranslateTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTranslateTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(InNoesisComponent);
	check(NoesisTranslateTransform);

}

	void UNoesisGuiTranslateTransform::BeginDestroy()
{
	Noesis::Gui::TranslateTransform* NoesisTranslateTransform = NsDynamicCast<Noesis::Gui::TranslateTransform*>(NoesisComponent.GetPtr());
	if (!NoesisTranslateTransform)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

