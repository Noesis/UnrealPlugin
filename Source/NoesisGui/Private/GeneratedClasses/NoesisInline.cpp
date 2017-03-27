////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisInline.h"

using namespace Noesis;
using namespace Gui;

UNoesisInline::UNoesisInline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Inline::StaticGetClassType();
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
	return CastChecked<UNoesisInline>(CreateClassFor(NoesisInline->GetNextInline(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisInline* UNoesisInline::GetPreviousInline()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisInline>(CreateClassFor(NoesisInline->GetPreviousInline(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisInlineCollection* UNoesisInline::GetSiblingInlines()
{
	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);
	return CastChecked<UNoesisInlineCollection>(CreateClassFor(NoesisInline->GetSiblingInlines(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisInline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);


}

void UNoesisInline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Inline* NoesisInline = NsDynamicCast<Noesis::Gui::Inline*>(NoesisComponent.GetPtr());
	check(NoesisInline);


}

