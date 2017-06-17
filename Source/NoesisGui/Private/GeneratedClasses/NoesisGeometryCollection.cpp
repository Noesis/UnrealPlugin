////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisGeometryCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisGeometryCollection::UNoesisGeometryCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Geometry>::StaticGetClassType();
}

void UNoesisGeometryCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Geometry>* NoesisGeometryCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Geometry>*>(InNoesisComponent);
	check(NoesisGeometryCollection);
}

void UNoesisGeometryCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Geometry>* NoesisGeometryCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Geometry>*>(NoesisComponent.GetPtr());
	check(NoesisGeometryCollection);


}

void UNoesisGeometryCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Geometry>* NoesisGeometryCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Geometry>*>(NoesisComponent.GetPtr());
	check(NoesisGeometryCollection);


}

