////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInt16KeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInt16KeyFrameCollection::UNoesisGuiInt16KeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInt16KeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>* NoesisInt16KeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>*>(InNoesisComponent);
	check(NoesisInt16KeyFrameCollection);

}

	void UNoesisGuiInt16KeyFrameCollection::BeginDestroy()
{
	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>* NoesisInt16KeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>*>(NoesisComponent.GetPtr());
	if (!NoesisInt16KeyFrameCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

