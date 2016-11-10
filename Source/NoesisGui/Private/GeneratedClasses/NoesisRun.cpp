////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRun.h"

using namespace Noesis;
using namespace Gui;

UNoesisRun::UNoesisRun(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRun::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(InNoesisComponent);
	check(NoesisRun);
}

FString UNoesisRun::GetText()
{
	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(NoesisComponent.GetPtr());
	check(NoesisRun);
	return NsStringToFString(NoesisRun->GetText());
}

void UNoesisRun::SetText(FString InText)
{
	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(NoesisComponent.GetPtr());
	check(NoesisRun);
	NoesisRun->SetText(StringCast<NsChar>(*InText).Get());
}

void UNoesisRun::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(NoesisComponent.GetPtr());
	check(NoesisRun)


}

void UNoesisRun::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Run* NoesisRun = NsDynamicCast<Noesis::Gui::Run*>(NoesisComponent.GetPtr());
	check(NoesisRun)


}

