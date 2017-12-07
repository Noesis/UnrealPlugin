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

void UNoesisFunctionLibrary::execNoesisStruct_NotEqual(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Add(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_AddUnique(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Shuffle(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Append(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Insert(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Remove(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_RemoveItem(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Clear(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Resize(FFrame& Stack, RESULT_DECL)
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

void UNoesisFunctionLibrary::execNoesisArray_Set(FFrame& Stack, RESULT_DECL)
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
