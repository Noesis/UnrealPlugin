////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSizeKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSizeKeyFrameCollection::UNoesisGuiSizeKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSizeKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>* NoesisSizeKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>*>(InNoesisComponent);
	check(NoesisSizeKeyFrameCollection);

}

	void UNoesisGuiSizeKeyFrameCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>* NoesisSizeKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>*>(NoesisComponent.GetPtr());
	if (!NoesisSizeKeyFrameCollection)
		return;

}

