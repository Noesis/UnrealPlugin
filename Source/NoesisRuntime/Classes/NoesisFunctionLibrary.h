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

// NoesisRuntime includes
#include "NoesisTypeClass.h"

// Generated header include
#include "NoesisFunctionLibrary.generated.h"

UCLASS(meta = (CustomThunkTemplates = "FNoesisFunctionLibraryCustomThunkTemplates"))
class NOESISRUNTIME_API UNoesisFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void NotifyChanged(UObject* Owner, FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void NotifyArrayChanged(UObject* Owner, FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void NotifyMapChanged(UObject* Owner, FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void NotifyCanExecuteFunctionChanged(UObject* Owner, FName FunctionName);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static void TrySetDataContext(UObject* Element, UObject* DataContext);

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI", meta = (HidePin = "Target"))
	static UObject* LoadXaml(class UNoesisXaml* Xaml);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (BlueprintInternalUseOnly = "true", CustomStructureParam = "Property,Value"), Category = "Noesis")
	static void NoesisSetWithNotify(const int32& Property, const int32& Value, UFunction* Setter);

	DECLARE_FUNCTION(execNoesisSetWithNotify);

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (BlueprintInternalUseOnly = "true", CustomStructureParam = "A,B"), Category = "Noesis|Struct")
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

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Add w/ NotifyMapChanged", CompactNodeTitle = "ADD\nw/ NotifyMapChanged", MapParam = "TargetMap", MapKeyParam = "Key", MapValueParam = "Value", AutoCreateRefTerm = "Key, Value"), Category = "Utilities|Map")
	static void NoesisMap_Add(const TMap<int32, int32>& TargetMap, const int32& Key, const int32& Value);

	DECLARE_FUNCTION(execNoesisMap_Add);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Remove w/ NotifyMapChanged", CompactNodeTitle = "REMOVE\nw/ NotifyMapChanged", MapParam = "TargetMap", MapKeyParam = "Key",  AutoCreateRefTerm = "Key"), Category = "Utilities|Map")
	static bool NoesisMap_Remove(const TMap<int32, int32>& TargetMap, const int32& Key);

	DECLARE_FUNCTION(execNoesisMap_Remove);

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Clear w/ NotifyMapChanged", CompactNodeTitle = "CLEAR\nw/ NotifyMapChanged", MapParam = "TargetMap" ), Category = "Utilities|Map")
	static void NoesisMap_Clear(const TMap<int32, int32>& TargetMap);

	DECLARE_FUNCTION(execNoesisMap_Clear);
};

struct FNoesisFunctionLibraryCustomThunkTemplates
{
private:
	static void ExecutionMessage(const TCHAR* Message, ELogVerbosity::Type Verbosity)
	{
		FFrame::KismetExecutionMessage(Message, Verbosity);
	}

	template<typename T>
	static int32 LastIndexForLog(const TArray<T>& TargetArray)
	{
		const int32 ArraySize = TargetArray.Num();
		return (ArraySize > 0) ? (ArraySize - 1) : 0;
	}

public:
	//Replacements for CustomThunk functions from UNoesisFunctionLibrary

	template<typename T>
	static bool NoesisStruct_NotEqual(const T& A, const T& B)
	{
		return A != B;
	}

	template<typename T, typename U>
	static int32 NoesisArray_Add(TArray<T>& TargetArray, const U& NewItem)
	{
		int32 Result = TargetArray.Add(NewItem);
		NoesisNotifyArrayPropertyPostAdd(&TargetArray);
		return Result;
	}

	template<typename T, typename U>
	static int32 NoesisArray_AddUnique(TArray<T>& TargetArray, const U& NewItem)
	{
		int32 ArrayNum = TargetArray.Num();
		int32 Result = TargetArray.AddUnique(NewItem);
		if (TargetArray.Num() != ArrayNum)
		{
			NoesisNotifyArrayPropertyPostAdd(&TargetArray);
		}
		return Result;
	}

	static int32 NoesisArray_AddUnique(TArray<FText>& TargetArray, const FText& NewItem)
	{
		auto TextIdenticalImplementation = [&](const FText& Element) -> bool
		{
			return FTextProperty::Identical_Implementation(Element, NewItem, 0);
		};
		int32 Index = TargetArray.IndexOfByPredicate(TextIdenticalImplementation);
		if (Index != INDEX_NONE)
		{
			return Index;
		}
		int32 Result = TargetArray.Add(NewItem);
		NoesisNotifyArrayPropertyPostAdd(&TargetArray);
		return Result;
	}

	template<typename T>
	static void NoesisArray_Shuffle(TArray<T>& TargetArray)
	{
		int32 LastIndex = TargetArray.Num() - 1;
		for (int32 i = 0; i < LastIndex; ++i)
		{
			int32 Index = FMath::RandRange(i, LastIndex);
			if (i != Index)
			{
				TargetArray.Swap(i, Index);
			}
		}
		NoesisNotifyArrayPropertyPostChanged(&TargetArray);
	}

	template<typename T, typename U>
	static void NoesisArray_Append(TArray<T>& TargetArray, const TArray<U>& SourceArray)
	{
		NoesisNotifyArrayPropertyPreAppend(&TargetArray);
		TargetArray.Append(SourceArray);
		NoesisNotifyArrayPropertyPostAppend(&TargetArray);
	}

	template<typename T, typename U>
	static void NoesisArray_Insert(TArray<T>& TargetArray, const U& NewItem, int32 Index)
	{
		if ((Index >= 0) && (Index <= TargetArray.Num()))
		{
			TargetArray.Insert(NewItem, Index);
			NoesisNotifyArrayPropertyPostInsert(&TargetArray, Index);
		}
		else
		{
			ExecutionMessage(*FString::Printf(TEXT("Attempted to insert an item into array out of bounds [%d/%d]!"), Index, LastIndexForLog(TargetArray)), ELogVerbosity::Warning);
		}
	}

	template<typename T>
	static void NoesisArray_Remove(TArray<T>& TargetArray, int32 IndexToRemove)
	{
		if (TargetArray.IsValidIndex(IndexToRemove))
		{
			NoesisNotifyArrayPropertyPreRemove(&TargetArray, IndexToRemove);
			TargetArray.RemoveAt(IndexToRemove);
			NoesisNotifyArrayPropertyPostRemove(&TargetArray, IndexToRemove);
		}
		else
		{
			ExecutionMessage(*FString::Printf(TEXT("Attempted to remove an item from an invalid index from array [%d/%d]!"), IndexToRemove, LastIndexForLog(TargetArray)), ELogVerbosity::Warning);
		}
	}

	template<typename T, typename U>
	static bool NoesisArray_RemoveItem(TArray<T>& TargetArray, const U& Item)
	{
		bool Result = false;
		int32 IndexToRemove = TargetArray.Find(Item);
		while (IndexToRemove != INDEX_NONE)
		{
			NoesisNotifyArrayPropertyPreRemove(&TargetArray, IndexToRemove);
			TargetArray.RemoveAt(IndexToRemove);
			Result = true; //removed
			NoesisNotifyArrayPropertyPostRemove(&TargetArray, IndexToRemove);

			// See if there is another in the array
			IndexToRemove = TargetArray.Find(Item);
		}
		return Result;
	}

	static bool NoesisArray_RemoveItem(TArray<FText>& TargetArray, const FText& Item)
	{
		bool Result = false;
		auto TextIdenticalImplementation = [&](const FText& Element) -> bool
		{
			return FTextProperty::Identical_Implementation(Element, Item, 0);
		};
		int32 IndexToRemove = TargetArray.IndexOfByPredicate(TextIdenticalImplementation);
		while (IndexToRemove != INDEX_NONE)
		{
			NoesisNotifyArrayPropertyPreRemove(&TargetArray, IndexToRemove);
			TargetArray.RemoveAt(IndexToRemove);
			Result = true; //removed
			NoesisNotifyArrayPropertyPostRemove(&TargetArray, IndexToRemove);

			// See if there is another in the array
			IndexToRemove = TargetArray.IndexOfByPredicate(TextIdenticalImplementation);
		}
		return Result;
	}

	template<typename T>
	static void NoesisArray_Clear(TArray<T>& TargetArray)
	{
		TargetArray.Empty();
		NoesisNotifyArrayPropertyPostClear(&TargetArray);
	}

	template<typename T>
	static void NoesisArray_Resize(TArray<T>& TargetArray, int32 Size)
	{
		if (Size >= 0)
		{
			int32 ArrayNum = TargetArray.Num();
			for (int32 Index = ArrayNum; Index-- > Size;)
			{
				NoesisNotifyArrayPropertyPreRemove(&TargetArray, Index);
				TargetArray.RemoveAt(Index);
				NoesisNotifyArrayPropertyPostRemove(&TargetArray, Index);
			}
			if (Size > ArrayNum)
			{
				NoesisNotifyArrayPropertyPreAppend(&TargetArray);
				TargetArray.SetNum(Size);
				NoesisNotifyArrayPropertyPostAppend(&TargetArray);
			}
		}
		else
		{
			ExecutionMessage(*FString::Printf(TEXT("Attempted to resize an array using negative size: Size = %d!"), Size), ELogVerbosity::Warning);
		}
	}

	template<typename T, typename U>
	static void NoesisArray_Set(TArray<T>& TargetArray, int32 Index, const U& Item, bool bSizeToFit)
	{
		if (!TargetArray.IsValidIndex(Index) && bSizeToFit && (Index >= 0))
		{
			NoesisArray_Resize(TargetArray, Index + 1);
		}

		if (TargetArray.IsValidIndex(Index))
		{
			TargetArray[Index] = Item;
			NoesisNotifyArrayPropertyPostSet(&TargetArray, Index);
		}
		else
		{
			ExecutionMessage(*FString::Printf(TEXT("Attempted to set an invalid index on array [%d/%d]!"), Index, LastIndexForLog(TargetArray)), ELogVerbosity::Warning);
		}
	}

	template<typename T, typename U, typename V, typename W>
	static void NoesisMap_Add(TMap<T, U>& TargetMap, const V& Key, const W& Value)
	{
		TargetMap.Add(Key, Value);
	}

	template<typename T, typename U, typename W>
	static void NoesisMap_Add(TMap<T, U>& TargetMap, const FString& Key, const W& Value)
	{
		TargetMap.Add(Key, Value);
		NoesisNotifyMapPropertyPostAdd(&TargetMap, Key);
	}

	template<typename T, typename U, typename V>
	static bool NoesisMap_Remove(TMap<T, U>& TargetMap, const V& Key)
	{
		return TargetMap.Remove(Key) > 0;
	}

	template<typename T, typename U>
	static bool NoesisMap_Remove(TMap<T, U>& TargetMap, const FString& Key)
	{
		NoesisNotifyMapPropertyPreRemove(&TargetMap, Key);
		bool Result = TargetMap.Remove(Key) > 0;
		NoesisNotifyMapPropertyPostRemove(&TargetMap, Key);
		return Result;
	}

	template<typename T, typename U>
	static void NoesisMap_Clear(TMap<T, U>& TargetMap)
	{
		TargetMap.Empty();
		NoesisNotifyMapPropertyPostChanged(&TargetMap);
	}

	/*template<typename T>
	static void NoesisArray_Swap(const TArray<T>& TargetArray, int32 FirstIndex, int32 SecondIndex)
	{
		const_cast<TArray<T>*>(&TargetArray)->Swap(FirstIndex, SecondIndex);
	}

	template<typename T>
	static int32 NoesisArray_AddUnique_Struct(const TArray<T>& TargetArray, const T& NewItem)
	{
		int32 Index = Array_Find_Struct<T>(TargetArray, NewItem);
		if (Index != INDEX_NONE)
		{
			return Index;
		}
		return const_cast<TArray<T>*>(&TargetArray)->Add(NewItem);
	}

	static int32 NoesisArray_AddUnique_FText(const TArray<FText>& TargetArray, const FText& NewItem)
	{
		int32 Index = Array_Find_FText(TargetArray, NewItem);
		if (Index != INDEX_NONE)
		{
			return Index;
		}
		return const_cast<TArray<FText>*>(&TargetArray)->Add(NewItem);
	}

	template<typename T>
	static bool NoesisArray_RemoveItem_Struct(const TArray<T>& TargetArray, const T& Item)
	{
		TargetArray.CheckAddress(&Item);

		auto ScriptStruct = T::StaticStruct();
		return const_cast<TArray<T>*>(&TargetArray)->RemoveAll([&](const T& Element) -> bool
			{
				return ScriptStruct->CompareScriptStruct(&Element, &Item, 0);
			}) != 0;
	}

	static bool NoesisArray_RemoveItem_FText(const TArray<FText>& TargetArray, const FText& Item)
	{
		TargetArray.CheckAddress(&Item);

		return const_cast<TArray<FText>*>(&TargetArray)->RemoveAll([&](const FText& Element) -> bool
			{
				return FTextProperty::Identical_Implementation(Element, Item, 0);
			}) != 0;
	}

	template<typename T>
	static void NoesisArray_Reverse(const TArray<T>& TargetArray)
	{
		Algo::Reverse(*const_cast<TArray<T>*>(&TargetArray));
	}*/
};
