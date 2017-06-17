////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisStringKeyFrameCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisStringKeyFrameCollection::UNoesisStringKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>::StaticGetClassType();
}

void UNoesisStringKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>* NoesisStringKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>*>(InNoesisComponent);
	check(NoesisStringKeyFrameCollection);
}

void UNoesisStringKeyFrameCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>* NoesisStringKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>*>(NoesisComponent.GetPtr());
	check(NoesisStringKeyFrameCollection);


}

void UNoesisStringKeyFrameCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>* NoesisStringKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsString>>*>(NoesisComponent.GetPtr());
	check(NoesisStringKeyFrameCollection);


}

