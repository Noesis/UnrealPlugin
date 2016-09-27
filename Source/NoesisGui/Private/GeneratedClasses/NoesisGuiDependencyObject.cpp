////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDependencyObject::UNoesisGuiDependencyObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDependencyObject::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(InNoesisComponent);
	check(NoesisDependencyObject);

}

	void UNoesisGuiDependencyObject::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	if (!NoesisDependencyObject)
		return;

}

