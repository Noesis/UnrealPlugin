////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPage.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPage::UNoesisGuiPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPage::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(InNoesisComponent);
	check(NoesisPage);

}

FString UNoesisGuiPage::GetTitle()
{
	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(NoesisComponent.GetPtr());
	check(NoesisPage);
	return NsStringToFString(NoesisPage->GetTitle());
}

void UNoesisGuiPage::SetTitle(FString InTitle)
{
	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(NoesisComponent.GetPtr());
	check(NoesisPage);
	NoesisPage->SetTitle(StringCast<NsChar>(*InTitle).Get());
}

	void UNoesisGuiPage::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(NoesisComponent.GetPtr());
	if (!NoesisPage)
		return;

}

