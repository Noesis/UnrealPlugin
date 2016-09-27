////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTextBlock.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTextBlock::UNoesisGuiTextBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTextBlock::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(InNoesisComponent);
	check(NoesisTextBlock);

}

class UNoesisGuiInlineCollection* UNoesisGuiTextBlock::GetInlines()
{
	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	check(NoesisTextBlock);
	return CastChecked<UNoesisGuiInlineCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisTextBlock->GetInlines()));
}

	void UNoesisGuiTextBlock::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TextBlock* NoesisTextBlock = NsDynamicCast<Noesis::Gui::TextBlock*>(NoesisComponent.GetPtr());
	if (!NoesisTextBlock)
		return;

}

