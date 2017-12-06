////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisFunctionLibrary.h"

// NoesisRuntime includes
#include "NoesisTypeClass.h"

UNoesisFunctionLibrary::UNoesisFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisFunctionLibrary::NotifyChanged(UObject* Owner, FName PropertyName)
{
	NoesisNotifyPropertyChanged(Owner, PropertyName);
}

void UNoesisFunctionLibrary::NotifyArrayChanged(UObject* Owner, FName PropertyName)
{
	NoesisNotifyArrayPropertyChanged(Owner, PropertyName);
}
