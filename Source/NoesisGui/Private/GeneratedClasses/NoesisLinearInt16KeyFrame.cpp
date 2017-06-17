////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisLinearInt16KeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisLinearInt16KeyFrame::UNoesisLinearInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LinearKeyFrame<NsInt16>::StaticGetClassType();
}

void UNoesisLinearInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<NsInt16>* NoesisLinearInt16KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisLinearInt16KeyFrame);
}

void UNoesisLinearInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<NsInt16>* NoesisLinearInt16KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisLinearInt16KeyFrame);


}

void UNoesisLinearInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<NsInt16>* NoesisLinearInt16KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisLinearInt16KeyFrame);


}

