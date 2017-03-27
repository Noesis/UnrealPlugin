////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisObjectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisObjectKeyFrame::UNoesisObjectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>::StaticGetClassType();
}

void UNoesisObjectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(InNoesisComponent);
	check(NoesisObjectKeyFrame);
}

FNoesisKeyTime UNoesisObjectKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisObjectKeyFrame);
	return FNoesisKeyTime(NoesisObjectKeyFrame->GetKeyTime());
}

void UNoesisObjectKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisObjectKeyFrame);
	NoesisObjectKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisObjectKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisObjectKeyFrame);


}

void UNoesisObjectKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisObjectKeyFrame);


}

