////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStringKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStringKeyFrameCollection::UNoesisGuiStringKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStringKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>* NoesisStringKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>*>(InNoesisComponent);
	check(NoesisStringKeyFrameCollection);

}

	void UNoesisGuiStringKeyFrameCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>* NoesisStringKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>*>(NoesisComponent.GetPtr());
	if (!NoesisStringKeyFrameCollection)
		return;

}

