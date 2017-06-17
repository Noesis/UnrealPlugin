////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisCreateClass.h"
#include "NoesisGeneratedClasses.h"

UClass* GetClassFor(const Noesis::Core::BaseComponent* BaseComponent)
{
	const Noesis::Core::TypeClass* BaseComponentClass = BaseComponent->GetClassType();
	UClass* Class = UNoesisBaseComponent::StaticClass();

	TArray<UClass*> NoesisComponentClasses;
	GetDerivedClasses(Class, NoesisComponentClasses, true);
	for (auto NoesisComponentClass : NoesisComponentClasses)
	{
		UNoesisBaseComponent* CDO = NoesisComponentClass->GetDefaultObject<UNoesisBaseComponent>();
		if (BaseComponentClass == CDO->NoesisComponentTypeClass || BaseComponentClass->IsDescendantOf(CDO->NoesisComponentTypeClass))
		{
			if (NoesisComponentClass->IsChildOf(Class))
			{
				Class = NoesisComponentClass;
			}
		}
	}

	return Class;
}

UNoesisBaseComponent* CreateClassFor(const Noesis::Core::BaseComponent* BaseComponent, UObject* Outer)
{
	if (!BaseComponent)
	{
		return nullptr;
	}

	UClass* Class = GetClassFor(BaseComponent);

	for (FObjectIterator ObjectIterator(Class); ObjectIterator; ++ObjectIterator)
	{
		UNoesisBaseComponent* NoesisBaseComponent = (UNoesisBaseComponent*)*ObjectIterator;
		if (NoesisBaseComponent->NoesisComponent.GetPtr() == BaseComponent)
		{
			return NoesisBaseComponent;
		}
	}

	UNoesisBaseComponent* NoesisBaseComponent = NewObject<UNoesisBaseComponent>(Outer ? Outer : GetTransientPackage(), Class);
	NoesisBaseComponent->SetNoesisComponent((Noesis::Core::BaseComponent*)BaseComponent);
	NoesisBaseComponent->BindEvents();

	return NoesisBaseComponent;
}
