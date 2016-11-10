////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisBrush::UNoesisBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(InNoesisComponent);
	check(NoesisBrush);
}

float UNoesisBrush::GetOpacity()
{
	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush);
	return (float)NoesisBrush->GetOpacity();
}

void UNoesisBrush::SetOpacity(float InOpacity)
{
	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush);
	NoesisBrush->SetOpacity(InOpacity);
}

class UNoesisTransform* UNoesisBrush::GetRelativeTransform()
{
	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush);
	return CastChecked<UNoesisTransform>(Instance->FindUnrealComponentForNoesisComponent(NoesisBrush->GetRelativeTransform()));
}

void UNoesisBrush::SetRelativeTransform(class UNoesisTransform* InRelativeTransform)
{
	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush);
	NoesisBrush->SetRelativeTransform(NsDynamicCast<Transform*>(InRelativeTransform->NoesisComponent.GetPtr()));
}

class UNoesisTransform* UNoesisBrush::GetTransform()
{
	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush);
	return CastChecked<UNoesisTransform>(Instance->FindUnrealComponentForNoesisComponent(NoesisBrush->GetTransform()));
}

void UNoesisBrush::SetTransform(class UNoesisTransform* InTransform)
{
	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush);
	NoesisBrush->SetTransform(NsDynamicCast<Transform*>(InTransform->NoesisComponent.GetPtr()));
}

bool UNoesisBrush::IsTransparent()
{
	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush);
	return NoesisBrush->IsTransparent();
}

void UNoesisBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush)


}

void UNoesisBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	check(NoesisBrush)


}

