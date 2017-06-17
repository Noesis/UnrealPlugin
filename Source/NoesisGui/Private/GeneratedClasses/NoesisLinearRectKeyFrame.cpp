////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisLinearRectKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisLinearRectKeyFrame::UNoesisLinearRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>::StaticGetClassType();
}

void UNoesisLinearRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>* NoesisLinearRectKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisLinearRectKeyFrame);
}

void UNoesisLinearRectKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>* NoesisLinearRectKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisLinearRectKeyFrame);


}

void UNoesisLinearRectKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>* NoesisLinearRectKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisLinearRectKeyFrame);


}

