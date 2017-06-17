////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisEasingRectKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingRectKeyFrame::UNoesisEasingRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>::StaticGetClassType();
}

void UNoesisEasingRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>* NoesisEasingRectKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisEasingRectKeyFrame);
}

void UNoesisEasingRectKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>* NoesisEasingRectKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisEasingRectKeyFrame);


}

void UNoesisEasingRectKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>* NoesisEasingRectKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisEasingRectKeyFrame);


}

