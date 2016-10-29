////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiBlueprintGeneratedClass.h"

// NoesisGui includes
#include "NoesisGuiBaseComponent.h"

UNoesisGuiBlueprintGeneratedClass::UNoesisGuiBlueprintGeneratedClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBlueprintGeneratedClass::InitComponents(class UNoesisGuiInstance* NoesisGuiInstance)
{
	check(NoesisGuiInstance->Xaml);
	TArray<Noesis::FrameworkElement*> Elements;
	CollectElements(NoesisGuiInstance->Xaml.GetPtr(), Elements);
	check(Elements.Num() == NoesisGuiInstance->BaseXaml->Components.Num());
	int32 ElementIndex = 0;
	Components.Empty();
	Components.Reserve(NoesisGuiInstance->BaseXaml->Components.Num());
	for (auto Component : NoesisGuiInstance->BaseXaml->Components)
	{
		UNoesisGuiBaseComponent* DuplicatedComponent = DuplicateObject<UNoesisGuiBaseComponent>(Component, NoesisGuiInstance);

		Noesis::FrameworkElement* Element = Elements[ElementIndex++];
		check(Element);
		NoesisGuiInstance->SetComponentFor(Element, DuplicatedComponent);

		if (DuplicatedComponent->ElementName != NAME_None)
		{
			UObjectPropertyBase* Property = FindField<UObjectPropertyBase>(this, DuplicatedComponent->ElementName);
			if (Property)
			{
				Property->SetObjectPropertyValue_InContainer(NoesisGuiInstance, DuplicatedComponent);
				check(Property->GetObjectPropertyValue_InContainer(NoesisGuiInstance) == DuplicatedComponent);
			}
		}

		Components.Add(DuplicatedComponent);
	}
}

void UNoesisGuiBlueprintGeneratedClass::BindEvents()
{
	for (auto Component : Components)
	{
		Component->BindEvents();
	}
}
