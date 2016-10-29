////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPropertyPath.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPropertyPath::UNoesisGuiPropertyPath(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPropertyPath::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(InNoesisComponent);
	check(NoesisPropertyPath);
}

FString UNoesisGuiPropertyPath::GetPath()
{
	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath);
	return NsStringToFString(NoesisPropertyPath->GetPath());
}

void UNoesisGuiPropertyPath::SetPath(FString InPath)
{
	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath);
	NoesisPropertyPath->SetPath(StringCast<NsChar>(*InPath).Get());
}

void UNoesisGuiPropertyPath::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath)


}

void UNoesisGuiPropertyPath::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath)


}

