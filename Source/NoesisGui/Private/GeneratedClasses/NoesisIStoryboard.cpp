////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisIStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisIStoryboard::UNoesisIStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IStoryboard::StaticGetClassType();
}

void UNoesisIStoryboard::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(InNoesisInterface);
	check(NoesisIStoryboard);
}

void UNoesisIStoryboard::Begin()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Begin();
}

bool UNoesisIStoryboard::IsPaused()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->IsPaused();
}

bool UNoesisIStoryboard::IsPlaying()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->IsPlaying();
}

void UNoesisIStoryboard::Pause()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Pause();
}

void UNoesisIStoryboard::Remove()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Remove();
}

void UNoesisIStoryboard::Resume()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Resume();
}

void UNoesisIStoryboard::Stop()
{
	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);
	return NoesisIStoryboard->Stop();
}

void UNoesisIStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);


}

void UNoesisIStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IStoryboard* NoesisIStoryboard = NsDynamicCast<Noesis::Gui::IStoryboard*>(NoesisInterface.GetPtr());
	check(NoesisIStoryboard);


}

