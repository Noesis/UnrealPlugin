////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisCombinedGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisCombinedGeometry::UNoesisCombinedGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisCombinedGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(InNoesisComponent);
	check(NoesisCombinedGeometry);
}

class UNoesisGeometry* UNoesisCombinedGeometry::GetGeometry1()
{
	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry);
	return CastChecked<UNoesisGeometry>(Instance->FindUnrealComponentForNoesisComponent(NoesisCombinedGeometry->GetGeometry1()));
}

void UNoesisCombinedGeometry::SetGeometry1(class UNoesisGeometry* InGeometry1)
{
	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry);
	NoesisCombinedGeometry->SetGeometry1(NsDynamicCast<Geometry*>(InGeometry1->NoesisComponent.GetPtr()));
}

class UNoesisGeometry* UNoesisCombinedGeometry::GetGeometry2()
{
	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry);
	return CastChecked<UNoesisGeometry>(Instance->FindUnrealComponentForNoesisComponent(NoesisCombinedGeometry->GetGeometry2()));
}

void UNoesisCombinedGeometry::SetGeometry2(class UNoesisGeometry* InGeometry2)
{
	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry);
	NoesisCombinedGeometry->SetGeometry2(NsDynamicCast<Geometry*>(InGeometry2->NoesisComponent.GetPtr()));
}

ENoesisGeometryCombineMode UNoesisCombinedGeometry::GetGeometryCombineMode()
{
	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry);
	return (ENoesisGeometryCombineMode)NoesisCombinedGeometry->GetGeometryCombineMode();
}

void UNoesisCombinedGeometry::SetGeometryCombineMode(ENoesisGeometryCombineMode InGeometryCombineMode)
{
	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry);
	NoesisCombinedGeometry->SetGeometryCombineMode((Noesis::Gui::GeometryCombineMode)InGeometryCombineMode);
}

void UNoesisCombinedGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry)


}

void UNoesisCombinedGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CombinedGeometry* NoesisCombinedGeometry = NsDynamicCast<Noesis::Gui::CombinedGeometry*>(NoesisComponent.GetPtr());
	check(NoesisCombinedGeometry)


}

