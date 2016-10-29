////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisual.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisual::UNoesisGuiVisual(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisual::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(InNoesisComponent);
	check(NoesisVisual);
}

UNoesisGuiIView* UNoesisGuiVisual::GetView()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return CastChecked<UNoesisGuiIView>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisVisual->GetView()));
}

void UNoesisGuiVisual::ConnectToView(class UNoesisGuiIView* InView)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	IView* NoesisInView = NsDynamicCast<IView*>(InView->NoesisInterface.GetPtr());
	return NoesisVisual->ConnectToView(NoesisInView);
}

void UNoesisGuiVisual::DisableDebugFlags()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->DisableDebugFlags();
}

class UNoesisGuiVisual* UNoesisGuiVisual::FindCommonVisualAncestor(const class UNoesisGuiVisual* InVisual)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Visual* NoesisInVisual = NsDynamicCast<const Visual*>(InVisual->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiVisual>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisual->FindCommonVisualAncestor(NoesisInVisual)));
}

int32 UNoesisGuiVisual::GetRenderTreeId()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return (int32)NoesisVisual->GetRenderTreeId();
}

bool UNoesisGuiVisual::IsAncestorOf(const class UNoesisGuiVisual* InVisual)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Visual* NoesisInVisual = NsDynamicCast<const Visual*>(InVisual->NoesisComponent.GetPtr());
	return NoesisVisual->IsAncestorOf(NoesisInVisual);
}

bool UNoesisGuiVisual::IsConnectedToView()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->IsConnectedToView();
}

bool UNoesisGuiVisual::IsDescendantOf(const class UNoesisGuiVisual* InVisual)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Visual* NoesisInVisual = NsDynamicCast<const Visual*>(InVisual->NoesisComponent.GetPtr());
	return NoesisVisual->IsDescendantOf(NoesisInVisual);
}

bool UNoesisGuiVisual::IsInRenderTree()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->IsInRenderTree();
}

bool UNoesisGuiVisual::IsInvalidated()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->IsInvalidated();
}

FNoesisGuiDrawingPoint UNoesisGuiVisual::PointFromScreen(FNoesisGuiDrawingPoint InPoint)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return FNoesisGuiDrawingPoint(NoesisVisual->PointFromScreen(NoesisInPoint));
}

FNoesisGuiDrawingPoint UNoesisGuiVisual::PointToScreen(FNoesisGuiDrawingPoint InPoint)
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return FNoesisGuiDrawingPoint(NoesisVisual->PointToScreen(NoesisInPoint));
}

void UNoesisGuiVisual::SetVisualBrushFlag()
{
	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual);
	return NoesisVisual->SetVisualBrushFlag();
}

void UNoesisGuiVisual::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual)


}

void UNoesisGuiVisual::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	check(NoesisVisual)


}

