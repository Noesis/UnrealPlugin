////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisEasingThicknessKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingThicknessKeyFrame::UNoesisEasingThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>::StaticGetClassType();
}

void UNoesisEasingThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>* NoesisEasingThicknessKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisEasingThicknessKeyFrame);
}

void UNoesisEasingThicknessKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>* NoesisEasingThicknessKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisEasingThicknessKeyFrame);


}

void UNoesisEasingThicknessKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>* NoesisEasingThicknessKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisEasingThicknessKeyFrame);


}

