////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Engine includes
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// Generated header include
#include "NoesisFunctionLibrary.generated.h"

UCLASS()
class NOESISRUNTIME_API UNoesisFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void NotifyChanged(UObject* Owner, FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void NotifyArrayChanged(UObject* Owner, FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void TrySetDataContext(UObject* Element, UObject* DataContext);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static UObject* LoadXaml(class UNoesisXaml* Xaml);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (BlueprintInternalUseOnly = "true", CustomStructureParam = "A, B"), Category = "Noesis|Struct")
	static bool NoesisStruct_NotEqual(const FGenericStruct& A, const FGenericStruct& B);

	DECLARE_FUNCTION(execNoesisStruct_NotEqual);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (DisplayName = "Add w/ NotifyArrayChanged", CompactNodeTitle = "ADD\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category = "Noesis|Array")
	static int32 NoesisArray_Add(const TArray<int32>& TargetArray, const int32& NewItem);

	DECLARE_FUNCTION(execNoesisArray_Add);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (DisplayName = "Add Unique w/ NotifyArrayChanged", CompactNodeTitle = "ADDUNIQUE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category = "Noesis|Array")
	static int32 NoesisArray_AddUnique(const TArray<int32>& TargetArray, const int32& NewItem);

	DECLARE_FUNCTION(execNoesisArray_AddUnique);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Shuffle w/ NotifyArrayChanged", CompactNodeTitle = "SHUFFLE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Shuffle(const TArray<int32>& TargetArray);

	DECLARE_FUNCTION(execNoesisArray_Shuffle);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Append Array w/ NotifyArrayChanged", CompactNodeTitle = "APPEND\nw/ NotifyArrayChanged", ArrayParm = "TargetArray,SourceArray", ArrayTypeDependentParams = "SourceArray"), Category="Noesis|Array")
	static void NoesisArray_Append(const TArray<int32>& TargetArray, const TArray<int32>& SourceArray);

	DECLARE_FUNCTION(execNoesisArray_Append);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Insert w/ NotifyArrayChanged", CompactNodeTitle = "INSERT\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category="Noesis|Array")
	static void NoesisArray_Insert(const TArray<int32>& TargetArray, const int32& NewItem, int32 Index);

	DECLARE_FUNCTION(execNoesisArray_Insert);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Remove Index w/ NotifyArrayChanged", CompactNodeTitle = "REMOVE INDEX\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Remove(const TArray<int32>& TargetArray, int32 IndexToRemove);

	DECLARE_FUNCTION(execNoesisArray_Remove);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Remove Item w/ NotifyArrayChanged", CompactNodeTitle = "REMOVE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "Item", AutoCreateRefTerm = "Item"), Category="Noesis|Array")
	static bool NoesisArray_RemoveItem(const TArray<int32>& TargetArray, const int32 &Item);

	DECLARE_FUNCTION(execNoesisArray_RemoveItem);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Clear w/ NotifyArrayChanged", CompactNodeTitle = "CLEAR\nw/ NotifyArrayChanged", Keywords = "empty", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Clear(const TArray<int32>& TargetArray);

	DECLARE_FUNCTION(execNoesisArray_Clear);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Resize w/ NotifyArrayChanged", CompactNodeTitle = "RESIZE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Resize(const TArray<int32>& TargetArray, int32 Size);

	DECLARE_FUNCTION(execNoesisArray_Resize);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Set Array Elem w/ NotifyArrayChanged", CompactNodeTitle = "Set Array Elem\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "Item", AutoCreateRefTerm = "Item"), Category="Noesis|Array")
	static void NoesisArray_Set(const TArray<int32>& TargetArray, int32 Index, const int32& Item, bool bSizeToFit);

	DECLARE_FUNCTION(execNoesisArray_Set);
};
