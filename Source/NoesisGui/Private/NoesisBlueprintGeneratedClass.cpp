////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintGeneratedClass.h"

// NoesisGui includes
#include "NoesisBaseComponent.h"
#include "NoesisCreateClass.h"

UNoesisBlueprintGeneratedClass::UNoesisBlueprintGeneratedClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBlueprintGeneratedClass::InitComponents(class UNoesisInstance* NoesisInstance)
{
	check(NoesisInstance->Xaml);
	TArray<Noesis::FrameworkElement*> Elements;
	CollectElements(NoesisInstance->Xaml.GetPtr(), Elements);
	Components.Empty();
	Components.Reserve(Elements.Num());
	for (auto Element : Elements)
	{
		check(Element);
		const NsChar* ElementName = Element->GetName();
		UNoesisBaseComponent* NoesisGuiComponent = CreateClassFor(Element, NoesisInstance);
		NoesisGuiComponent->ElementName = ElementName ? NsStringToFName(ElementName) : NAME_None;

		if (NoesisGuiComponent->ElementName != NAME_None)
		{
			UObjectPropertyBase* Property = FindField<UObjectPropertyBase>(this, NoesisGuiComponent->ElementName);
			if (Property)
			{
				Property->SetObjectPropertyValue_InContainer(NoesisInstance, NoesisGuiComponent);
				check(Property->GetObjectPropertyValue_InContainer(NoesisInstance) == NoesisGuiComponent);
			}
		}

		Components.Add(NoesisGuiComponent);
	}
}
