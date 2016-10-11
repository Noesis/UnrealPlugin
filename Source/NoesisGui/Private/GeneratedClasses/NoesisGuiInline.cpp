////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInline.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInline::UNoesisGuiInline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(InNoesisComponent);
	check(NoesisInline);

}

class UNoesisGuiInline* UNoesisGuiInline::GetNextInline()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisGuiInline>(Instance->FindUnrealComponentForNoesisComponent(NoesisInline->GetNextInline()));
}

class UNoesisGuiInline* UNoesisGuiInline::GetPreviousInline()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisGuiInline>(Instance->FindUnrealComponentForNoesisComponent(NoesisInline->GetPreviousInline()));
}

class UNoesisGuiInlineCollection* UNoesisGuiInline::GetSiblingInlines()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisGuiInlineCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisInline->GetSiblingInlines()));
}

	void UNoesisGuiInline::BeginDestroy()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	if (!NoesisInline)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

