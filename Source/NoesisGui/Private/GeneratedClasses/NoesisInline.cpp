////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisInline.h"

using namespace Noesis;
using namespace Gui;

UNoesisInline::UNoesisInline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisInline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(InNoesisComponent);
	check(NoesisInline);
}

class UNoesisInline* UNoesisInline::GetNextInline()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisInline>(Instance->FindUnrealComponentForNoesisComponent(NoesisInline->GetNextInline()));
}

class UNoesisInline* UNoesisInline::GetPreviousInline()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisInline>(Instance->FindUnrealComponentForNoesisComponent(NoesisInline->GetPreviousInline()));
}

class UNoesisInlineCollection* UNoesisInline::GetSiblingInlines()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisInlineCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisInline->GetSiblingInlines()));
}

void UNoesisInline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline)


}

void UNoesisInline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline)


}

