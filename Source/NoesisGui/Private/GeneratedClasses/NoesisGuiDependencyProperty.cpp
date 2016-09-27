////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDependencyProperty.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDependencyProperty::UNoesisGuiDependencyProperty(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDependencyProperty::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(InNoesisComponent);
	check(NoesisDependencyProperty);

}

int32 UNoesisGuiDependencyProperty::GetSize()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	return (int32)NoesisDependencyProperty->GetSize();
}

	void UNoesisGuiDependencyProperty::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	if (!NoesisDependencyProperty)
		return;

}

