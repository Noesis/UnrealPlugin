////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

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

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (BlueprintInternalUseOnly = "true", CustomStructureParam = "A, B"), Category = "Noesis|Struct")
	static bool NoesisStruct_NotEqual(const FGenericStruct& A, const FGenericStruct& B);

	void execNoesisStruct_NotEqual(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (DisplayName = "Add w/ NotifyArrayChanged", CompactNodeTitle = "ADD\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category = "Noesis|Array")
	static int32 NoesisArray_Add(const TArray<int32>& TargetArray, const int32& NewItem);

	void execNoesisArray_Add(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (DisplayName = "Add Unique w/ NotifyArrayChanged", CompactNodeTitle = "ADDUNIQUE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category = "Noesis|Array")
		static int32 NoesisArray_AddUnique(const TArray<int32>& TargetArray, const int32& NewItem);

	void execNoesisArray_AddUnique(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Shuffle w/ NotifyArrayChanged", CompactNodeTitle = "SHUFFLE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Shuffle(const TArray<int32>& TargetArray);

	void execNoesisArray_Shuffle(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Append Array w/ NotifyArrayChanged", CompactNodeTitle = "APPEND\nw/ NotifyArrayChanged", ArrayParm = "TargetArray,SourceArray", ArrayTypeDependentParams = "SourceArray"), Category="Noesis|Array")
	static void NoesisArray_Append(const TArray<int32>& TargetArray, const TArray<int32>& SourceArray);

	void execNoesisArray_Append(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Insert w/ NotifyArrayChanged", CompactNodeTitle = "INSERT\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category="Noesis|Array")
	static void NoesisArray_Insert(const TArray<int32>& TargetArray, const int32& NewItem, int32 Index);

	void execNoesisArray_Insert(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Remove Index w/ NotifyArrayChanged", CompactNodeTitle = "REMOVE INDEX\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Remove(const TArray<int32>& TargetArray, int32 IndexToRemove);

	void execNoesisArray_Remove(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Remove Item w/ NotifyArrayChanged", CompactNodeTitle = "REMOVE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "Item", AutoCreateRefTerm = "Item"), Category="Noesis|Array")
	static bool NoesisArray_RemoveItem(const TArray<int32>& TargetArray, const int32 &Item);

	void execNoesisArray_RemoveItem(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Clear w/ NotifyArrayChanged", CompactNodeTitle = "CLEAR\nw/ NotifyArrayChanged", Keywords = "empty", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Clear(const TArray<int32>& TargetArray);

	void execNoesisArray_Clear(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Resize w/ NotifyArrayChanged", CompactNodeTitle = "RESIZE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Resize(const TArray<int32>& TargetArray, int32 Size);

	void execNoesisArray_Resize(FFrame& Stack, RESULT_DECL);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Set Array Elem w/ NotifyArrayChanged", CompactNodeTitle = "Set Array Elem\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "Item", AutoCreateRefTerm = "Item"), Category="Noesis|Array")
	static void NoesisArray_Set(const TArray<int32>& TargetArray, int32 Index, const int32& Item, bool bSizeToFit);

	void execNoesisArray_Set(FFrame& Stack, RESULT_DECL);
};
