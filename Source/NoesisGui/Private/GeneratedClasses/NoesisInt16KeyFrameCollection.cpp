////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisInt16KeyFrameCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisInt16KeyFrameCollection::UNoesisInt16KeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>::StaticGetClassType();
}

void UNoesisInt16KeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>* NoesisInt16KeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>*>(InNoesisComponent);
	check(NoesisInt16KeyFrameCollection);
}

void UNoesisInt16KeyFrameCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>* NoesisInt16KeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>*>(NoesisComponent.GetPtr());
	check(NoesisInt16KeyFrameCollection);


}

void UNoesisInt16KeyFrameCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>* NoesisInt16KeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<NsInt16>>*>(NoesisComponent.GetPtr());
	check(NoesisInt16KeyFrameCollection);


}

