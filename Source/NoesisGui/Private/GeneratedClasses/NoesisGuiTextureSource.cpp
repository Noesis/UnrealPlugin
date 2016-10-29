////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTextureSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTextureSource::UNoesisGuiTextureSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTextureSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(InNoesisComponent);
	check(NoesisTextureSource);
}

int32 UNoesisGuiTextureSource::GetPixelHeight()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	return NoesisTextureSource->GetPixelHeight();
}

int32 UNoesisGuiTextureSource::GetPixelWidth()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	return NoesisTextureSource->GetPixelWidth();
}

void UNoesisGuiTextureSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource)


}

void UNoesisGuiTextureSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource)


}

