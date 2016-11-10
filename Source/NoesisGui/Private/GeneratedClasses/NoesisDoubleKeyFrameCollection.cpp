////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDoubleKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisDoubleKeyFrameCollection::UNoesisDoubleKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDoubleKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>* NoesisDoubleKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>*>(InNoesisComponent);
	check(NoesisDoubleKeyFrameCollection);
}

void UNoesisDoubleKeyFrameCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>* NoesisDoubleKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrameCollection)


}

void UNoesisDoubleKeyFrameCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>* NoesisDoubleKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrameCollection)


}

