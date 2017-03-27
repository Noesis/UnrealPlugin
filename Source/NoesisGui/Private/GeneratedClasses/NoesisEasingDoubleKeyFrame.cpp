////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisEasingDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingDoubleKeyFrame::UNoesisEasingDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::EasingKeyFrame<NsFloat32>::StaticGetClassType();
}

void UNoesisEasingDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<NsFloat32>* NoesisEasingDoubleKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisEasingDoubleKeyFrame);
}

void UNoesisEasingDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<NsFloat32>* NoesisEasingDoubleKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingDoubleKeyFrame);


}

void UNoesisEasingDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<NsFloat32>* NoesisEasingDoubleKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingDoubleKeyFrame);


}

