////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetArrayLibrary.h"

// NoesisRuntime includes
#include "NoesisTypeClass.h"

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

	DECLARE_FUNCTION(execNoesisStruct_NotEqual)
	{
		Stack.StepCompiledIn<UStructProperty>(NULL);
		UStructProperty* AProperty = CastChecked<UStructProperty>(Stack.MostRecentProperty);
		void* AAddress = Stack.MostRecentPropertyAddress;

		Stack.StepCompiledIn<UStructProperty>(NULL);
		UStructProperty* BProperty = CastChecked<UStructProperty>(Stack.MostRecentProperty);
		void* BAddress = Stack.MostRecentPropertyAddress;

		check(AProperty->Struct == BProperty->Struct);

		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)RESULT_PARAM = !AProperty->Struct->CompareScriptStruct(AAddress, BAddress, PPF_None);
		P_NATIVE_END;
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (DisplayName = "Add w/ NotifyArrayChanged", CompactNodeTitle = "ADD\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category = "Noesis|Array")
	static int32 NoesisArray_Add(const TArray<int32>& TargetArray, const int32& NewItem);

	DECLARE_FUNCTION(execNoesisArray_Add)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		// Since NewItem isn't really an int, step the stack manually
		const UProperty* InnerProp = ArrayProperty->Inner;
		const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
		void* StorageSpace = FMemory_Alloca(PropertySize);
		InnerProp->InitializeValue(StorageSpace);

		Stack.MostRecentPropertyAddress = NULL;
		Stack.StepCompiledIn<UProperty>(StorageSpace);
		void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)RESULT_PARAM = UKismetArrayLibrary::GenericArray_Add(ArrayAddr, ArrayProperty, NewItemPtr);
		P_NATIVE_END;
		InnerProp->DestroyValue(StorageSpace);

		NoesisNotifyArrayPropertyAdd(ArrayAddr);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (DisplayName = "Add Unique w/ NotifyArrayChanged", CompactNodeTitle = "ADDUNIQUE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category = "Noesis|Array")
		static int32 NoesisArray_AddUnique(const TArray<int32>& TargetArray, const int32& NewItem);

	DECLARE_FUNCTION(execNoesisArray_AddUnique)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		// Since NewItem isn't really an int, step the stack manually
		const UProperty* InnerProp = ArrayProperty->Inner;
		const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
		void* StorageSpace = FMemory_Alloca(PropertySize);
		InnerProp->InitializeValue(StorageSpace);

		Stack.MostRecentPropertyAddress = NULL;
		Stack.StepCompiledIn<UProperty>(StorageSpace);
		void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

		FScriptArrayHelper ArrayHelper = FScriptArrayHelper::CreateHelperFormInnerProperty(InnerProp, ArrayAddr);
		int32 ArrayNum = ArrayHelper.Num();

		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)RESULT_PARAM = UKismetArrayLibrary::GenericArray_AddUnique(ArrayAddr, ArrayProperty, NewItemPtr);
		P_NATIVE_END;
		InnerProp->DestroyValue(StorageSpace);

		if (ArrayHelper.Num() != ArrayNum)
		{
			NoesisNotifyArrayPropertyAdd(ArrayAddr);
		}
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Shuffle w/ NotifyArrayChanged", CompactNodeTitle = "SHUFFLE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Shuffle(const TArray<int32>& TargetArray);

	DECLARE_FUNCTION(execNoesisArray_Shuffle)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		P_FINISH;
		P_NATIVE_BEGIN;
		UKismetArrayLibrary::GenericArray_Shuffle(ArrayAddr, ArrayProperty);
		P_NATIVE_END;

		NoesisNotifyArrayPropertyChanged(ArrayAddr);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Append Array w/ NotifyArrayChanged", CompactNodeTitle = "APPEND\nw/ NotifyArrayChanged", ArrayParm = "TargetArray,SourceArray", ArrayTypeDependentParams = "SourceArray"), Category="Noesis|Array")
	static void NoesisArray_Append(const TArray<int32>& TargetArray, const TArray<int32>& SourceArray);

	DECLARE_FUNCTION(execNoesisArray_Append)
	{
		// Retrieve the target array
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* TargetArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* TargetArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!TargetArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}
		// Retrieve the source array
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* SourceArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* SourceArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!SourceArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		P_FINISH;
		P_NATIVE_BEGIN;
		UKismetArrayLibrary::GenericArray_Append(TargetArrayAddr, TargetArrayProperty, SourceArrayAddr, SourceArrayProperty);
		P_NATIVE_END;

		FScriptArrayHelper SourceArrayHelper(SourceArrayProperty, SourceArrayAddr);
		int32 NumItems = SourceArrayHelper.Num();
		NoesisNotifyArrayPropertyAppend(TargetArrayAddr, NumItems);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Insert w/ NotifyArrayChanged", CompactNodeTitle = "INSERT\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "NewItem", AutoCreateRefTerm = "NewItem"), Category="Noesis|Array")
	static void NoesisArray_Insert(const TArray<int32>& TargetArray, const int32& NewItem, int32 Index);

	DECLARE_FUNCTION(execNoesisArray_Insert)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		// Since NewItem isn't really an int, step the stack manually
		const UProperty* InnerProp = ArrayProperty->Inner;
		const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
		void* StorageSpace = FMemory_Alloca(PropertySize);
		InnerProp->InitializeValue(StorageSpace);

		Stack.MostRecentPropertyAddress = NULL;
		Stack.StepCompiledIn<UProperty>(StorageSpace);
		void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

		P_GET_PROPERTY(UIntProperty, Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		UKismetArrayLibrary::GenericArray_Insert(ArrayAddr, ArrayProperty, NewItemPtr, Index);
		P_NATIVE_END;
		InnerProp->DestroyValue(StorageSpace);

		NoesisNotifyArrayPropertyInsert(ArrayAddr, Index);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Remove Index w/ NotifyArrayChanged", CompactNodeTitle = "REMOVE INDEX\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Remove(const TArray<int32>& TargetArray, int32 IndexToRemove);

	DECLARE_FUNCTION(execNoesisArray_Remove)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		P_GET_PROPERTY(UIntProperty, Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		UKismetArrayLibrary::GenericArray_Remove(ArrayAddr, ArrayProperty, Index);
		P_NATIVE_END;

		NoesisNotifyArrayPropertyRemove(ArrayAddr, Index);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Remove Item w/ NotifyArrayChanged", CompactNodeTitle = "REMOVE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "Item", AutoCreateRefTerm = "Item"), Category="Noesis|Array")
	static bool NoesisArray_RemoveItem(const TArray<int32>& TargetArray, const int32 &Item);

	DECLARE_FUNCTION(execNoesisArray_RemoveItem)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}
		// Since Item isn't really an int, step the stack manually
		const UProperty* InnerProp = ArrayProperty->Inner;
		const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
		void* StorageSpace = FMemory_Alloca(PropertySize);
		InnerProp->InitializeValue(StorageSpace);

		Stack.MostRecentPropertyAddress = NULL;
		Stack.StepCompiledIn<UProperty>(StorageSpace);
		void* ItemPtr = StorageSpace;

		P_FINISH;

		// Bools need to be processed internally by the property so that C++ bool value is properly set.
		const UBoolProperty* BoolProperty = Cast<const UBoolProperty>(InnerProp);
		if (BoolProperty)
		{
			ensure((BoolProperty->ElementSize * BoolProperty->ArrayDim) == sizeof(uint8));
			BoolProperty->SetPropertyValue(ItemPtr, 0 != *(reinterpret_cast<uint8*>(ItemPtr)));
		}
		P_NATIVE_BEGIN;
		*(bool*)RESULT_PARAM = false;

		if (ArrayAddr)
		{
			int32 IndexToRemove = UKismetArrayLibrary::GenericArray_Find(ArrayAddr, ArrayProperty, ItemPtr);
			while (IndexToRemove != INDEX_NONE)
			{
				UKismetArrayLibrary::GenericArray_Remove(ArrayAddr, ArrayProperty, IndexToRemove);
				*(bool*)RESULT_PARAM = true; //removed
				NoesisNotifyArrayPropertyRemove(ArrayAddr, IndexToRemove);

												 // See if there is another in the array
				IndexToRemove = UKismetArrayLibrary::GenericArray_Find(ArrayAddr, ArrayProperty, ItemPtr);
			}
		}

		P_NATIVE_END;

		InnerProp->DestroyValue(StorageSpace);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Clear w/ NotifyArrayChanged", CompactNodeTitle = "CLEAR\nw/ NotifyArrayChanged", Keywords = "empty", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Clear(const TArray<int32>& TargetArray);

	DECLARE_FUNCTION(execNoesisArray_Clear)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}
		P_FINISH;
		P_NATIVE_BEGIN;
		UKismetArrayLibrary::GenericArray_Clear(ArrayAddr, ArrayProperty);
		P_NATIVE_END;

		NoesisNotifyArrayPropertyClear(ArrayAddr);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Resize w/ NotifyArrayChanged", CompactNodeTitle = "RESIZE\nw/ NotifyArrayChanged", ArrayParm = "TargetArray"), Category="Noesis|Array")
	static void NoesisArray_Resize(const TArray<int32>& TargetArray, int32 Size);

	DECLARE_FUNCTION(execNoesisArray_Resize)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}
		P_GET_PROPERTY(UIntProperty, Size);
		P_FINISH;
		P_NATIVE_BEGIN;
		UKismetArrayLibrary::GenericArray_Resize(ArrayAddr, ArrayProperty, Size);
		P_NATIVE_END;

		NoesisNotifyArrayPropertyResize(ArrayAddr);
	}

	UFUNCTION(BlueprintCallable, CustomThunk, meta=(DisplayName = "Set Array Elem w/ NotifyArrayChanged", CompactNodeTitle = "Set Array Elem\nw/ NotifyArrayChanged", ArrayParm = "TargetArray", ArrayTypeDependentParams = "Item", AutoCreateRefTerm = "Item"), Category="Noesis|Array")
	static void NoesisArray_Set(const TArray<int32>& TargetArray, int32 Index, const int32& Item, bool bSizeToFit);

	DECLARE_FUNCTION(execNoesisArray_Set)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}
		P_GET_PROPERTY(UIntProperty, Index);

		// Since NewItem isn't really an int, step the stack manually
		const UProperty* InnerProp = ArrayProperty->Inner;
		const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
		void* StorageSpace = FMemory_Alloca(PropertySize);
		InnerProp->InitializeValue(StorageSpace);

		Stack.MostRecentPropertyAddress = NULL;
		Stack.StepCompiledIn<UProperty>(StorageSpace);
		void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

		P_GET_UBOOL(bSizeToFit);

		P_FINISH;

		P_NATIVE_BEGIN;
		UKismetArrayLibrary::GenericArray_Set(ArrayAddr, ArrayProperty, Index, NewItemPtr, bSizeToFit);
		P_NATIVE_END;
		InnerProp->DestroyValue(StorageSpace);

		NoesisNotifyArrayPropertySet(ArrayAddr, Index);
	}
};
