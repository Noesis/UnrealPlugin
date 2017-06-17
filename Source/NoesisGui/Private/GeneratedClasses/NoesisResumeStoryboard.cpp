////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisResumeStoryboard.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisResumeStoryboard::UNoesisResumeStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ResumeStoryboard::StaticGetClassType();
}

void UNoesisResumeStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ResumeStoryboard* NoesisResumeStoryboard = NsDynamicCast<Noesis::Gui::ResumeStoryboard*>(InNoesisComponent);
	check(NoesisResumeStoryboard);
}

void UNoesisResumeStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ResumeStoryboard* NoesisResumeStoryboard = NsDynamicCast<Noesis::Gui::ResumeStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisResumeStoryboard);


}

void UNoesisResumeStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ResumeStoryboard* NoesisResumeStoryboard = NsDynamicCast<Noesis::Gui::ResumeStoryboard*>(NoesisComponent.GetPtr());
	check(NoesisResumeStoryboard);


}

