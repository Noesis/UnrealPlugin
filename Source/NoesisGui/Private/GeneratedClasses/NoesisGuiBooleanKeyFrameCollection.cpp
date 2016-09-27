////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBooleanKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBooleanKeyFrameCollection::UNoesisGuiBooleanKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBooleanKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsBool>>* NoesisBooleanKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsBool>>*>(InNoesisComponent);
	check(NoesisBooleanKeyFrameCollection);

}

	void UNoesisGuiBooleanKeyFrameCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsBool>>* NoesisBooleanKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsBool>>*>(NoesisComponent.GetPtr());
	if (!NoesisBooleanKeyFrameCollection)
		return;

}

