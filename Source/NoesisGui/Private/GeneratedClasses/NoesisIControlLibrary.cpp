////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisIControlLibrary.h"

using namespace Noesis;
using namespace Gui;

UNoesisIControlLibrary::UNoesisIControlLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisIControlLibrary::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IControlLibrary* NoesisIControlLibrary = NsDynamicCast<Noesis::Gui::IControlLibrary*>(InNoesisInterface);
	check(NoesisIControlLibrary);
}

FString UNoesisIControlLibrary::GetResourceFile(FString InThemeName)
{
	Noesis::Gui::IControlLibrary* NoesisIControlLibrary = NsDynamicCast<Noesis::Gui::IControlLibrary*>(NoesisInterface.GetPtr());
	check(NoesisIControlLibrary);
	const NsChar* NoesisInThemeName = StringCast<NsChar>(*InThemeName).Get();
	return NsStringToFString(NoesisIControlLibrary->GetResourceFile(NoesisInThemeName));
}

void UNoesisIControlLibrary::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IControlLibrary* NoesisIControlLibrary = NsDynamicCast<Noesis::Gui::IControlLibrary*>(NoesisInterface.GetPtr());
	check(NoesisIControlLibrary)


}

void UNoesisIControlLibrary::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IControlLibrary* NoesisIControlLibrary = NsDynamicCast<Noesis::Gui::IControlLibrary*>(NoesisInterface.GetPtr());
	check(NoesisIControlLibrary)


}

