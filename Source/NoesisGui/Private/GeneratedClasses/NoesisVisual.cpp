////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisVisual.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisual::UNoesisVisual(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisVisual::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(InNoesisComponent);
	check(NoesisVisual);
}

UNoesisIView* UNoesisVisual::GetView()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return CastChecked<UNoesisIView>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisVisual->GetView()));
}

void UNoesisVisual::ConnectToView(class UNoesisIView* InView)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	IView* NoesisInView = NsDynamicCast<IView*>(InView->NoesisInterface.GetPtr());
	return NoesisVisual->ConnectToView(NoesisInView);
}

void UNoesisVisual::DisableDebugFlags()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->DisableDebugFlags();
}

class UNoesisVisual* UNoesisVisual::FindCommonVisualAncestor(const class UNoesisVisual* InVisual)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Visual* NoesisInVisual = NsDynamicCast<const Visual*>(InVisual->NoesisComponent.GetPtr());
	return CastChecked<UNoesisVisual>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisual->FindCommonVisualAncestor(NoesisInVisual)));
}

int32 UNoesisVisual::GetRenderTreeId()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return (int32)NoesisVisual->GetRenderTreeId();
}

bool UNoesisVisual::IsAncestorOf(const class UNoesisVisual* InVisual)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Visual* NoesisInVisual = NsDynamicCast<const Visual*>(InVisual->NoesisComponent.GetPtr());
	return NoesisVisual->IsAncestorOf(NoesisInVisual);
}

bool UNoesisVisual::IsConnectedToView()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->IsConnectedToView();
}

bool UNoesisVisual::IsDescendantOf(const class UNoesisVisual* InVisual)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Visual* NoesisInVisual = NsDynamicCast<const Visual*>(InVisual->NoesisComponent.GetPtr());
	return NoesisVisual->IsDescendantOf(NoesisInVisual);
}

bool UNoesisVisual::IsInRenderTree()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->IsInRenderTree();
}

bool UNoesisVisual::IsInvalidated()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->IsInvalidated();
}

FNoesisDrawingPoint UNoesisVisual::PointFromScreen(FNoesisDrawingPoint InPoint)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return FNoesisDrawingPoint(NoesisVisual->PointFromScreen(NoesisInPoint));
}

FNoesisDrawingPoint UNoesisVisual::PointToScreen(FNoesisDrawingPoint InPoint)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return FNoesisDrawingPoint(NoesisVisual->PointToScreen(NoesisInPoint));
}

void UNoesisVisual::SetVisualBrushFlag()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->SetVisualBrushFlag();
}

void UNoesisVisual::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual)


}

void UNoesisVisual::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual)


}

