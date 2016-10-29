////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCollectionViewSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCollectionViewSource::UNoesisGuiCollectionViewSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCollectionViewSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(InNoesisComponent);
	check(NoesisCollectionViewSource);
}

void UNoesisGuiCollectionViewSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource)


}

void UNoesisGuiCollectionViewSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource)


}

