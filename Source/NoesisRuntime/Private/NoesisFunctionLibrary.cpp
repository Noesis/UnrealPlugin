////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisFunctionLibrary.h"

// Core includes
#include "UObject/PropertyPortFlags.h"

// Engine includes
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetArrayLibrary.h"

// NoesisRuntime includes
#include "NoesisTypeClass.h"
#include "NoesisBaseComponent.h"
#include "NoesisXaml.h"

UNoesisFunctionLibrary::UNoesisFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisFunctionLibrary::NotifyChanged(UObject* Owner, FName PropertyName)
{
	NoesisNotifyPropertyChanged(Owner, PropertyName);
}

void UNoesisFunctionLibrary::NotifyChanges(UObject* Owner, FName PropertyNames)
{
	TArray<FString> Names;
	PropertyNames.ToString().ParseIntoArray(Names, TEXT(","));

	for (auto& Name : Names)
		NoesisNotifyArrayPropertyChanged(Owner, FName(*Name));
}

void UNoesisFunctionLibrary::NotifyArrayChanged(UObject* Owner, FName PropertyName)
{
	NoesisNotifyArrayPropertyChanged(Owner, PropertyName);
}

void UNoesisFunctionLibrary::TrySetDataContext(UObject* Element, UObject* DataContext)
{
	UNoesisBaseComponent* BaseComponent = Cast<UNoesisBaseComponent>(Element);
	if (BaseComponent)
	{
		Noesis::FrameworkElement* NoesisElement = Noesis::DynamicCast<Noesis::FrameworkElement*>(BaseComponent->NoesisComponent.GetPtr());

		if (NoesisElement)
		{
			Noesis::Ptr<Noesis::BaseComponent> NoesisDataContext = NoesisCreateComponentForUObject(DataContext);
			NoesisElement->SetDataContext(NoesisDataContext);
		}
	}
}

UObject*UNoesisFunctionLibrary::LoadXaml(class UNoesisXaml* Xaml)
{
	return NoesisCreateUObjectForComponent(Xaml->LoadXaml().GetPtr());
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisStruct_NotEqual)
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

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Add)
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
	NoesisNotifyArrayPropertyPostAdd(ArrayAddr);
	P_NATIVE_END;
	InnerProp->DestroyValue(StorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_AddUnique)
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
	FScriptArrayHelper ArrayHelper = FScriptArrayHelper::CreateHelperFormInnerProperty(InnerProp, ArrayAddr);
	int32 ArrayNum = ArrayHelper.Num();
	*(int32*)RESULT_PARAM = UKismetArrayLibrary::GenericArray_AddUnique(ArrayAddr, ArrayProperty, NewItemPtr);
	if (ArrayHelper.Num() != ArrayNum)
	{
		NoesisNotifyArrayPropertyPostAdd(ArrayAddr);
	}
	P_NATIVE_END;
	InnerProp->DestroyValue(StorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Shuffle)
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
	NoesisNotifyArrayPropertyPostChanged(ArrayAddr);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Append)
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
	NoesisNotifyArrayPropertyPreAppend(TargetArrayAddr);
	UKismetArrayLibrary::GenericArray_Append(TargetArrayAddr, TargetArrayProperty, SourceArrayAddr, SourceArrayProperty);
	NoesisNotifyArrayPropertyPostAppend(TargetArrayAddr);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Insert)
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
	FScriptArrayHelper ArrayHelper = FScriptArrayHelper::CreateHelperFormInnerProperty(InnerProp, ArrayAddr);
	int32 ArrayNum = ArrayHelper.Num();
	if (ArrayHelper.IsValidIndex(Index))
	{
		NoesisNotifyArrayPropertyPostInsert(ArrayAddr, Index);
	}
	P_NATIVE_END;
	InnerProp->DestroyValue(StorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Remove)
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
	NoesisNotifyArrayPropertyPreRemove(ArrayAddr, Index);
	UKismetArrayLibrary::GenericArray_Remove(ArrayAddr, ArrayProperty, Index);
	NoesisNotifyArrayPropertyPostRemove(ArrayAddr, Index);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_RemoveItem)
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
			NoesisNotifyArrayPropertyPreRemove(ArrayAddr, IndexToRemove);
			UKismetArrayLibrary::GenericArray_Remove(ArrayAddr, ArrayProperty, IndexToRemove);
			*(bool*)RESULT_PARAM = true; //removed
			NoesisNotifyArrayPropertyPostRemove(ArrayAddr, IndexToRemove);

			// See if there is another in the array
			IndexToRemove = UKismetArrayLibrary::GenericArray_Find(ArrayAddr, ArrayProperty, ItemPtr);
		}
	}
	P_NATIVE_END;
	InnerProp->DestroyValue(StorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Clear)
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
	NoesisNotifyArrayPropertyPostClear(ArrayAddr);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Resize)
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
	const UProperty* InnerProp = ArrayProperty->Inner;
	FScriptArrayHelper ArrayHelper = FScriptArrayHelper::CreateHelperFormInnerProperty(InnerProp, ArrayAddr);
	int32 ArrayNum = ArrayHelper.Num();
	for (int32 Index = ArrayNum; Index-- > Size;)
	{
		NoesisNotifyArrayPropertyPreRemove(ArrayAddr, Index);
		UKismetArrayLibrary::GenericArray_Remove(ArrayAddr, ArrayProperty, Index);
		NoesisNotifyArrayPropertyPostRemove(ArrayAddr, Index);
	}
	if (Size > ArrayNum)
	{
		NoesisNotifyArrayPropertyPreAppend(ArrayAddr);
		UKismetArrayLibrary::GenericArray_Resize(ArrayAddr, ArrayProperty, Size);
		NoesisNotifyArrayPropertyPostAppend(ArrayAddr);
	}
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Set)
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
	FScriptArrayHelper ArrayHelper = FScriptArrayHelper::CreateHelperFormInnerProperty(InnerProp, ArrayAddr);
	int32 ArrayNum = ArrayHelper.Num();
	if (bSizeToFit && Index >= ArrayNum)
	{
		NoesisNotifyArrayPropertyPreAppend(ArrayAddr);
		UKismetArrayLibrary::GenericArray_Resize(ArrayAddr, ArrayProperty, Index + 1);
		NoesisNotifyArrayPropertyPostAppend(ArrayAddr);
		ArrayNum = Index + 1;
	}
	if (bSizeToFit || Index < ArrayNum)
	{
		NoesisNotifyArrayPropertyPreSet(ArrayAddr, Index);
		UKismetArrayLibrary::GenericArray_Set(ArrayAddr, ArrayProperty, Index, NewItemPtr, bSizeToFit);
		NoesisNotifyArrayPropertyPostSet(ArrayAddr, Index);
	}
	P_NATIVE_END;
	InnerProp->DestroyValue(StorageSpace);
}
