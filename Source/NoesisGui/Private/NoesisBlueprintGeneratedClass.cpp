////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisBlueprintGeneratedClass.h"

// NoesisGui includes
#include "NoesisBaseComponent.h"

UNoesisBlueprintGeneratedClass::UNoesisBlueprintGeneratedClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBlueprintGeneratedClass::InitComponents(class UNoesisInstance* NoesisInstance)
{
	check(NoesisInstance->Xaml);
	TArray<Noesis::FrameworkElement*> Elements;
	CollectElements(NoesisInstance->Xaml.GetPtr(), Elements);
	check(Elements.Num() == NoesisInstance->BaseXaml->Components.Num());
	int32 ElementIndex = 0;
	Components.Empty();
	Components.Reserve(NoesisInstance->BaseXaml->Components.Num());
	for (auto Component : NoesisInstance->BaseXaml->Components)
	{
		UNoesisBaseComponent* DuplicatedComponent = DuplicateObject<UNoesisBaseComponent>(Component, NoesisInstance);

		Noesis::FrameworkElement* Element = Elements[ElementIndex++];
		check(Element);
		NoesisInstance->SetComponentFor(Element, DuplicatedComponent);

		if (DuplicatedComponent->ElementName != NAME_None)
		{
			UObjectPropertyBase* Property = FindField<UObjectPropertyBase>(this, DuplicatedComponent->ElementName);
			if (Property)
			{
				Property->SetObjectPropertyValue_InContainer(NoesisInstance, DuplicatedComponent);
				check(Property->GetObjectPropertyValue_InContainer(NoesisInstance) == DuplicatedComponent);
			}
		}

		Components.Add(DuplicatedComponent);
	}
}

void UNoesisBlueprintGeneratedClass::BindEvents()
{
	for (auto Component : Components)
	{
		Component->BindEvents();
	}
}
