////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIStoryboard::UNoesisGuiIStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIStoryboard::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(InNoesisInterface);
	check(NoesisIStoryboard);

}

void UNoesisGuiIStoryboard::Begin()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Begin();
}

bool UNoesisGuiIStoryboard::IsPaused()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->IsPaused();
}

bool UNoesisGuiIStoryboard::IsPlaying()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->IsPlaying();
}

void UNoesisGuiIStoryboard::Pause()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Pause();
}

void UNoesisGuiIStoryboard::Remove()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Remove();
}

void UNoesisGuiIStoryboard::Resume()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Resume();
}

void UNoesisGuiIStoryboard::Stop()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Stop();
}

	void UNoesisGuiIStoryboard::BeginDestroy()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	if (!NoesisIStoryboard)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

