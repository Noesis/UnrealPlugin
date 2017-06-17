////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisCreateInterface.h"
#include "NoesisGeneratedClasses.h"

UClass* GetInterfaceFor(const Noesis::Core::Interface* Interface)
{
	const Noesis::Core::TypeClass* InterfaceClass = Interface->GetClassType();
	UClass* Class = UNoesisInterface::StaticClass();

	TArray<UClass*> NoesisInterfaceClasses;
	GetDerivedClasses(Class, NoesisInterfaceClasses, true);
	for (auto NoesisInterfaceClass : NoesisInterfaceClasses)
	{
		UNoesisInterface* CDO = NoesisInterfaceClass->GetDefaultObject<UNoesisInterface>();
		if (InterfaceClass == CDO->NoesisInterfaceTypeClass || InterfaceClass->IsDescendantOf(CDO->NoesisInterfaceTypeClass))
		{
			if (NoesisInterfaceClass->IsChildOf(Class))
			{
				Class = NoesisInterfaceClass;
			}
		}
	}

	return Class;
}

UNoesisInterface* CreateInterfaceFor(const Noesis::Core::Interface* Interface, UObject* Outer)
{
	if (!Interface)
	{
		return nullptr;
	}

	UClass* Class = GetInterfaceFor(Interface);

	for (FObjectIterator ObjectIterator(Class); ObjectIterator; ++ObjectIterator)
	{
		UNoesisInterface* NoesisInterface = (UNoesisInterface*)*ObjectIterator;
		if (NoesisInterface->NoesisInterface.GetPtr() == Interface)
		{
			return NoesisInterface;
		}
	}

	UNoesisInterface* NoesisInterface = NewObject<UNoesisInterface>(Outer ? Outer : GetTransientPackage(), Class);
	NoesisInterface->SetNoesisInterface((Noesis::Core::Interface*)Interface);
	NoesisInterface->BindEvents();

	return NoesisInterface;
}
