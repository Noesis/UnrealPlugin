////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisPropertyPath.h"

using namespace Noesis;
using namespace Gui;

UNoesisPropertyPath::UNoesisPropertyPath(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::PropertyPath::StaticGetClassType();
}

void UNoesisPropertyPath::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(InNoesisComponent);
	check(NoesisPropertyPath);
}

FString UNoesisPropertyPath::GetPath()
{
	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath);
	return NsStringToFString(NoesisPropertyPath->GetPath());
}

void UNoesisPropertyPath::SetPath(FString InPath)
{
	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath);
	NoesisPropertyPath->SetPath(StringCast<NsChar>(*InPath).Get());
}

void UNoesisPropertyPath::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath);


}

void UNoesisPropertyPath::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PropertyPath* NoesisPropertyPath = NsDynamicCast<Noesis::Gui::PropertyPath*>(NoesisComponent.GetPtr());
	check(NoesisPropertyPath);


}

