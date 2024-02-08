////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Helper functions for Property change notifications
////////////////////////////////////////////////////////////////////////////////////////////////////

/// Notifies that the specified property value has changed
//@{
NOESISRUNTIME_API void NoesisNotifyPropertyChanged(class UObject* Object, FName PropertyName);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyChanged(class UObject* Object, FName ArrayPropertyName);
NOESISRUNTIME_API void NoesisNotifyMapPropertyChanged(UObject* Owner, FName MapPropertyName);
//@}

/// Raises the *CanExecuteChanged* event for the Command stored in the specified property
//@{
NOESISRUNTIME_API void NoesisNotifyCanExecuteFunctionChanged(class UObject* Object, FName CommandName);
NOESISRUNTIME_API void NoesisNotifyCanExecuteFunctionChanged(class UObject* Object, class UFunction* CommandExecuteFunction);
//@}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Helper functions for TArray change notifications
////////////////////////////////////////////////////////////////////////////////////////////////////

/// Notifies that a new item was added to the end of the array
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostAdd(void* Array);

/// Notifies that a range of items is going to be added to the end of the array
//@{
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPreAppend(void* Array);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostAppend(void* Array);
//@}

/// Notifies that a new item was inserted in the specified index of the array
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostInsert(void* Array, int32 InsertIndex);

/// Notifies that an item is going to be removed from the specified index of the array
//@{
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPreRemove(void* Array, int32 RemoveIndex);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostRemove(void* Array, int32 RemoveIndex);
//@}

/// Notifies that an item is going to be set in the specified index of the array
//@{
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPreSet(void* Array, int32 ModifiedIndex);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostSet(void* Array, int32 ModifiedIndex);
//@}

/// Notifies that the array was reset (its contents changed completely)
//@{
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostReset(void* Array);
UE_DEPRECATED(3.1.5, "This function is deprecated. Use NoesisNotifyArrayPropertyPostReset instead.")
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostClear(void* Array);
UE_DEPRECATED(3.1.5, "This function is deprecated. Use NoesisNotifyArrayPropertyPostReset instead.")
NOESISRUNTIME_API void NoesisNotifyArrayPropertyPostChanged(void* Array);
//@}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Helper functions for TMap change notifications
////////////////////////////////////////////////////////////////////////////////////////////////////

/// Notifies that a new item was added to the map
NOESISRUNTIME_API void NoesisNotifyMapPropertyPostAdd(void* Map, const FString& Key);

/// Notifies that an item is going to be removed from the map
NOESISRUNTIME_API void NoesisNotifyMapPropertyPreRemove(void* Map, const FString& Key);
/// Notifies that an item was removed from the map
NOESISRUNTIME_API void NoesisNotifyMapPropertyPostRemove(void* Map, const FString& Key);

/// Notifies that a Map was reset (its contents changed completely)
//@{
NOESISRUNTIME_API void NoesisNotifyMapPropertyPostReset(void* Map);
UE_DEPRECATED(3.1.5, "This function is deprecated. Use NoesisNotifyMapPropertyPostReset instead.")
NOESISRUNTIME_API void NoesisNotifyMapPropertyPostChanged(void* Map);
//@}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Conversion between Unreal objects and Noesis wrappers
////////////////////////////////////////////////////////////////////////////////////////////////////

/// UObject -> Noesis::BaseComponent
NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUObject(class UObject* Object);

/// UStruct -> Noesis::BaseComponent (struct is boxed/copied)
NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUStruct(class UScriptStruct* StructType, void* StructSrc);
template<class StructType> Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUStruct(StructType* Struct)
{
	return NoesisCreateComponentForUStruct(StructType::StaticStruct(), Struct);
}

/// UEnum -> Noesis::BaseComponent (enum is boxed/copied)
NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUEnum(class UEnum* EnumType, int64 EnumValue);

/// Noesis::BaseComponent -> UObject
NOESISRUNTIME_API class UObject* NoesisCreateUObjectForComponent(Noesis::BaseComponent* Wrapper);

/// Noesis::BaseComponent (boxed struct) -> UStruct
NOESISRUNTIME_API void NoesisCopyUStructFromComponent(class UScriptStruct* StructType, Noesis::BaseComponent* Boxed, void* StructDst);
template<class StructType> StructType NoesisGetUStructFromComponent(Noesis::BaseComponent* Component)
{
	StructType Result;
	NoesisCopyUStructFromComponent(StructType::StaticStruct(), Component, &Result);
	return Result;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Plugin editor functions. For internal use only
////////////////////////////////////////////////////////////////////////////////////////////////////

NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisFindComponentForUObject(UObject* Object);
NOESISRUNTIME_API UObject* NoesisFindUObjectForComponent(Noesis::BaseComponent* Component);

NOESISRUNTIME_API Noesis::TypeClass* NoesisCreateTypeClassForUClass(class UClass*);
NOESISRUNTIME_API Noesis::TypeClass* NoesisCreateTypeClassForUStruct(class UScriptStruct*);
NOESISRUNTIME_API Noesis::TypeEnum* NoesisCreateTypeEnumForUEnum(class UEnum*);

#if WITH_EDITOR
NOESISRUNTIME_API void NoesisDestroyTypeClassForBlueprint(class UBlueprint*);
NOESISRUNTIME_API void NoesisDestroyTypeClassForStruct(class UUserDefinedStruct*);
NOESISRUNTIME_API void NoesisDestroyTypeClassForEnum(class UEnum*);
NOESISRUNTIME_API void NoesisDestroyTypeClassForMaterial(class UMaterialInterface*);
NOESISRUNTIME_API void NoesisAssetRenamed(UObject* Object, FString OldPath);
#endif
