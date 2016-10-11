////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIControlLibrary.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIControlLibrary::UNoesisGuiIControlLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIControlLibrary::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IControlLibrary* NoesisIControlLibrary = NsDynamicCast<Noesis::Gui::IControlLibrary*>(InNoesisInterface);
	check(NoesisIControlLibrary);

}

FString UNoesisGuiIControlLibrary::GetResourceFile(FString InThemeName)
{
	Noesis::Gui::IControlLibrary* NoesisIControlLibrary = NsDynamicCast<Noesis::Gui::IControlLibrary*>(NoesisInterface.GetPtr());
	check(NoesisIControlLibrary);
	const NsChar* NoesisInThemeName = StringCast<NsChar>(*InThemeName).Get();
	return NsStringToFString(NoesisIControlLibrary->GetResourceFile(NoesisInThemeName));
}

	void UNoesisGuiIControlLibrary::BeginDestroy()
{
	Noesis::Gui::IControlLibrary* NoesisIControlLibrary = NsDynamicCast<Noesis::Gui::IControlLibrary*>(NoesisInterface.GetPtr());
	if (!NoesisIControlLibrary)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

