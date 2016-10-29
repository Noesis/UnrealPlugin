////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDoubleKeyFrameCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDoubleKeyFrameCollection::UNoesisGuiDoubleKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDoubleKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>* NoesisDoubleKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>*>(InNoesisComponent);
	check(NoesisDoubleKeyFrameCollection);
}

void UNoesisGuiDoubleKeyFrameCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>* NoesisDoubleKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrameCollection)


}

void UNoesisGuiDoubleKeyFrameCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>* NoesisDoubleKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsFloat32>>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrameCollection)


}

