////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVirtualizationCacheLength.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVirtualizationCacheLength::UNoesisGuiVirtualizationCacheLength(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVirtualizationCacheLength::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(InNoesisComponent);
	check(NoesisVirtualizationCacheLength);

}

float UNoesisGuiVirtualizationCacheLength::GetCacheAfterViewport()
{
	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizationCacheLength);
	return (float)NoesisVirtualizationCacheLength->GetCacheAfterViewport();
}

float UNoesisGuiVirtualizationCacheLength::GetCacheBeforeViewport()
{
	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizationCacheLength);
	return (float)NoesisVirtualizationCacheLength->GetCacheBeforeViewport();
}

	void UNoesisGuiVirtualizationCacheLength::BeginDestroy()
{
	Noesis::Gui::VirtualizationCacheLength* NoesisVirtualizationCacheLength = NsDynamicCast<Noesis::Gui::VirtualizationCacheLength*>(NoesisComponent.GetPtr());
	if (!NoesisVirtualizationCacheLength)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

