////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisInt16KeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisInt16KeyFrame::UNoesisInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyFrame<NsInt16>::StaticGetClassType();
}

void UNoesisInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsInt16>* NoesisInt16KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisInt16KeyFrame);
}

FNoesisKeyTime UNoesisInt16KeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<NsInt16>* NoesisInt16KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16KeyFrame);
	return FNoesisKeyTime(NoesisInt16KeyFrame->GetKeyTime());
}

void UNoesisInt16KeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<NsInt16>* NoesisInt16KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16KeyFrame);
	NoesisInt16KeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<NsInt16>* NoesisInt16KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16KeyFrame);


}

void UNoesisInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<NsInt16>* NoesisInt16KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16KeyFrame);


}

