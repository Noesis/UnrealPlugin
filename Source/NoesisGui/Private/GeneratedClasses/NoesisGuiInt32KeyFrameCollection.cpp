////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInt32KeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInt32KeyFrameCollection::UNoesisGuiInt32KeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInt32KeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt32>>* NoesisInt32KeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt32>>*>(InNoesisComponent);
	check(NoesisInt32KeyFrameCollection);

}

	void UNoesisGuiInt32KeyFrameCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt32>>* NoesisInt32KeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt32>>*>(NoesisComponent.GetPtr());
	if (!NoesisInt32KeyFrameCollection)
		return;

}

