////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisVirtualizationCacheLength.h"

using namespace Noesis;
using namespace Gui;

UNoesisVirtualizationCacheLength::UNoesisVirtualizationCacheLength(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::VirtualizationCacheLength::StaticGetClassType();
}

void UNoesisVirtualizationCacheLength::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(InNoesisComponent);
	check(NoesisVirtualizationCacheLength);
}

float UNoesisVirtualizationCacheLength::GetCacheAfterViewport()
{
	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizationCacheLength);
	return (float)NoesisVirtualizationCacheLength->GetCacheAfterViewport();
}

float UNoesisVirtualizationCacheLength::GetCacheBeforeViewport()
{
	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizationCacheLength);
	return (float)NoesisVirtualizationCacheLength->GetCacheBeforeViewport();
}

void UNoesisVirtualizationCacheLength::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizationCacheLength);


}

void UNoesisVirtualizationCacheLength::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizationCacheLength);


}

