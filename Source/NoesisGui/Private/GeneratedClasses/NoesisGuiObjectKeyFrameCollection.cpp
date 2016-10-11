////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiObjectKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiObjectKeyFrameCollection::UNoesisGuiObjectKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiObjectKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent> >>* NoesisObjectKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent> >>*>(InNoesisComponent);
	check(NoesisObjectKeyFrameCollection);

}

	void UNoesisGuiObjectKeyFrameCollection::BeginDestroy()
{
	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent> >>* NoesisObjectKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent> >>*>(NoesisComponent.GetPtr());
	if (!NoesisObjectKeyFrameCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

