////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

NOESISRUNTIME_API Noesis::TypeClass* NoesisCreateTypeClassForUClass(class UClass*);
NOESISRUNTIME_API Noesis::TypeClass* NoesisCreateTypeClassForUStruct(class UScriptStruct*);
NOESISRUNTIME_API Noesis::TypeEnum* NoesisCreateTypeEnumForUEnum(class UEnum*);
NOESISRUNTIME_API void NoesisDestroyTypeClassForBlueprint(class UBlueprint*);
NOESISRUNTIME_API void NoesisDestroyAllTypes();
NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUStruct(class UScriptStruct*, void*);
NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUObject(class UObject*);
NOESISRUNTIME_API class UObject* NoesisCreateUObjectForComponent(Noesis::BaseComponent*);
NOESISRUNTIME_API void NoesisCopyUStructFromComponent(class UScriptStruct*, Noesis::BaseComponent*, void*);

template<class StructType>
Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUStruct(StructType* Struct)
{
	return NoesisCreateComponentForUStruct(StructType::StaticStruct(), Struct);
}

template<class StructType>
StructType NoesisGetUStructFromComponent(Noesis::BaseComponent* Component)
{
	StructType Result;
	NoesisCopyUStructFromComponent(StructType::StaticStruct(), Component, &Result);
	return Result;
}


NOESISRUNTIME_API void NoesisNotifyPropertyChanged(class UObject*, FName);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyChanged(class UObject*, FName);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyAdd(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyChanged(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyAppend(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyInsert(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyRemove(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyClear(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyResize(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertySet(void*, int32);
NOESISRUNTIME_API void NoesisGarbageCollected();
void NoesisReflectionRegistryCallback(NsSymbol TypeId, Noesis::ReflectionRegistry* Registry);
void NoesisRegisterTypes();
