////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisSizeKeyFrameCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisSizeKeyFrameCollection::UNoesisSizeKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>::StaticGetClassType();
}

void UNoesisSizeKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>* NoesisSizeKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>*>(InNoesisComponent);
	check(NoesisSizeKeyFrameCollection);
}

void UNoesisSizeKeyFrameCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>* NoesisSizeKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>*>(NoesisComponent.GetPtr());
	check(NoesisSizeKeyFrameCollection);


}

void UNoesisSizeKeyFrameCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>* NoesisSizeKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>>*>(NoesisComponent.GetPtr());
	check(NoesisSizeKeyFrameCollection);


}

