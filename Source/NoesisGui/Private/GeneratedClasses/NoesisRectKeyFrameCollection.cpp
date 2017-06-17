////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisRectKeyFrameCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisRectKeyFrameCollection::UNoesisRectKeyFrameCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>>::StaticGetClassType();
}

void UNoesisRectKeyFrameCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>>* NoesisRectKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>>*>(InNoesisComponent);
	check(NoesisRectKeyFrameCollection);
}

void UNoesisRectKeyFrameCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>>* NoesisRectKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrameCollection);


}

void UNoesisRectKeyFrameCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>>* NoesisRectKeyFrameCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrameCollection);


}

