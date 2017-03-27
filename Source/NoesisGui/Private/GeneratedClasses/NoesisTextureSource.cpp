////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisTextureSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisTextureSource::UNoesisTextureSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TextureSource::StaticGetClassType();
}

void UNoesisTextureSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(InNoesisComponent);
	check(NoesisTextureSource);
}

int32 UNoesisTextureSource::GetPixelHeight()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	return NoesisTextureSource->GetPixelHeight();
}

int32 UNoesisTextureSource::GetPixelWidth()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	return NoesisTextureSource->GetPixelWidth();
}

void UNoesisTextureSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);


}

void UNoesisTextureSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);


}

