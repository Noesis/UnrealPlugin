////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisInt32KeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisInt32KeyFrame::UNoesisInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyFrame<NsInt32>::StaticGetClassType();
}

void UNoesisInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsInt32>* NoesisInt32KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisInt32KeyFrame);
}

FNoesisKeyTime UNoesisInt32KeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<NsInt32>* NoesisInt32KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32KeyFrame);
	return FNoesisKeyTime(NoesisInt32KeyFrame->GetKeyTime());
}

void UNoesisInt32KeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<NsInt32>* NoesisInt32KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32KeyFrame);
	NoesisInt32KeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisInt32KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<NsInt32>* NoesisInt32KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32KeyFrame);


}

void UNoesisInt32KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<NsInt32>* NoesisInt32KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32KeyFrame);


}

