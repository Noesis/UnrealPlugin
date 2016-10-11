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

float UNoesisGuiTextureSource::GetDpiX()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	return (float)NoesisTextureSource->GetDpiX();
}

float UNoesisGuiTextureSource::GetDpiY()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	return (float)NoesisTextureSource->GetDpiY();
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

FString UNoesisGuiTextureSource::GetSource()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	return NsStringToFString(NoesisTextureSource->GetSource());
}

void UNoesisGuiTextureSource::SetSource(FString InSource)
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	check(NoesisTextureSource);
	NoesisTextureSource->SetSource(StringCast<NsChar>(*InSource).Get());
}

	void UNoesisGuiTextureSource::BeginDestroy()
{
	Noesis::Gui::TextureSource* NoesisTextureSource = NsDynamicCast<Noesis::Gui::TextureSource*>(NoesisComponent.GetPtr());
	if (!NoesisTextureSource)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

