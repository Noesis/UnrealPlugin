////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPointKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPointKeyFrameCollection::UNoesisGuiPointKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPointKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>>* NoesisPointKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>>*>(InNoesisComponent);
	check(NoesisPointKeyFrameCollection);

}

	void UNoesisGuiPointKeyFrameCollection::BeginDestroy()
{
	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>>* NoesisPointKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>>*>(NoesisComponent.GetPtr());
	if (!NoesisPointKeyFrameCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

