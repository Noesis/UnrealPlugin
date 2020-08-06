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
#if WITH_EDITOR
NOESISRUNTIME_API void NoesisDestroyTypeClassForBlueprint(const class UBlueprint*);
NOESISRUNTIME_API void NoesisDestroyTypeClassForStruct(const class UStruct*);
NOESISRUNTIME_API void NoesisDestroyTypeClassForEnum(const class UEnum*);
NOESISRUNTIME_API void NoesisDestroyTypeClass(FString Path);
NOESISRUNTIME_API void NoesisDestroyTypeClass();
#endif
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
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostAdd(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostChanged(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPreAppend(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostAppend(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostInsert(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPreRemove(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostRemove(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostClear(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPreSet(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostSet(void*, int32);
NOESISRUNTIME_API void NoesisGarbageCollected();
void NoesisReflectionRegistryCallback(Noesis::Symbol TypeId);
void NoesisRegisterTypes();
