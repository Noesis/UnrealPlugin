////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisLinearDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisLinearDoubleKeyFrame::UNoesisLinearDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LinearKeyFrame<NsFloat32>::StaticGetClassType();
}

void UNoesisLinearDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<NsFloat32>* NoesisLinearDoubleKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisLinearDoubleKeyFrame);
}

void UNoesisLinearDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<NsFloat32>* NoesisLinearDoubleKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisLinearDoubleKeyFrame);


}

void UNoesisLinearDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<NsFloat32>* NoesisLinearDoubleKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisLinearDoubleKeyFrame);


}

