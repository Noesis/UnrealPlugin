////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisPage.h"

using namespace Noesis;
using namespace Gui;

UNoesisPage::UNoesisPage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Page::StaticGetClassType();
}

void UNoesisPage::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(InNoesisComponent);
	check(NoesisPage);
}

FString UNoesisPage::GetTitle()
{
	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(NoesisComponent.GetPtr());
	check(NoesisPage);
	return NsStringToFString(NoesisPage->GetTitle());
}

void UNoesisPage::SetTitle(FString InTitle)
{
	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(NoesisComponent.GetPtr());
	check(NoesisPage);
	NoesisPage->SetTitle(StringCast<NsChar>(*InTitle).Get());
}

void UNoesisPage::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(NoesisComponent.GetPtr());
	check(NoesisPage);


}

void UNoesisPage::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Page* NoesisPage = NsDynamicCast<Noesis::Gui::Page*>(NoesisComponent.GetPtr());
	check(NoesisPage);


}

