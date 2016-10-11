////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiColorKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiColorKeyFrameCollection::UNoesisGuiColorKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiColorKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>>* NoesisColorKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>>*>(InNoesisComponent);
	check(NoesisColorKeyFrameCollection);

}

	void UNoesisGuiColorKeyFrameCollection::BeginDestroy()
{
	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>>* NoesisColorKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>>*>(NoesisComponent.GetPtr());
	if (!NoesisColorKeyFrameCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

