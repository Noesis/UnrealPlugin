////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisFunctionLibrary.h"

// Core includes
#include "Misc/EngineVersionComparison.h"
#include "UObject/PropertyPortFlags.h"
#include "Net/Core/PushModel/PushModel.h"

// Engine includes
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/BlueprintMapLibrary.h"

// NoesisRuntime includes
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

void UNoesisFunctionLibrary::NotifyArrayChanged(UObject* Owner, FName PropertyName)
{
	if (!IsValid(Owner))
		return;

	UClass* OwnerClass = Owner->GetClass();
	FProperty* ArrayProperty = OwnerClass->FindPropertyByName(PropertyName);
	if (ArrayProperty != nullptr)
	{
		void* ArrayPointer = ArrayProperty->template ContainerPtrToValuePtr<void>(Owner);
		NoesisNotifyArrayPropertyPostReset(ArrayPointer);
	}
}

void UNoesisFunctionLibrary::NotifyMapChanged(UObject* Owner, FName PropertyName)
{
	if (!IsValid(Owner))
		return;

	UClass* OwnerClass = Owner->GetClass();
	FProperty* MapProperty = OwnerClass->FindPropertyByName(PropertyName);
	if (MapProperty != nullptr)
	{
		void* MapPointer = MapProperty->template ContainerPtrToValuePtr<void>(Owner);
		NoesisNotifyMapPropertyPostReset(MapPointer);
	}
}

void UNoesisFunctionLibrary::NotifyCanExecuteFunctionChanged(UObject* Owner, FName FunctionName)
{
	NoesisNotifyCanExecuteFunctionChanged(Owner, FunctionName);
}

void UNoesisFunctionLibrary::TrySetDataContext(UObject* Element, UObject* DataContext)
{
	UNoesisBaseComponent* BaseComponent = Cast<UNoesisBaseComponent>(Element);
	if (BaseComponent)
	{
		// OK to demote Ptr to *. The reference is kept by the UNoesisBaseComponent.
		Noesis::FrameworkElement* NoesisElement = Noesis::DynamicPtrCast<Noesis::FrameworkElement>(BaseComponent->NoesisComponent);

		if (NoesisElement)
		{
			Noesis::Ptr<Noesis::BaseComponent> NoesisDataContext = NoesisCreateComponentForUObject(DataContext);
			NoesisElement->SetDataContext(NoesisDataContext);
		}
	}
}

UObject* UNoesisFunctionLibrary::LoadXaml(class UNoesisXaml* Xaml)
{
	if (Xaml != nullptr)
	{
		return NoesisCreateUObjectForComponent(Xaml->LoadXaml());
	}
	return nullptr;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisSetWithNotify)
{
	// Step to get the property
	Stack.MostRecentProperty = nullptr;
	Stack.MostRecentPropertyAddress = nullptr;
	Stack.StepCompiledIn<FProperty>(nullptr);

	FProperty* Property = Stack.MostRecentProperty;
	void* PropertyAddress = Stack.MostRecentPropertyAddress;

#if UE_VERSION_OLDER_THAN(5, 1, 0)
	UObject* Object = (UObject*)(Stack.MostRecentPropertyAddress - Property->GetOffset_ForInternal());
#else
	UObject* Object = (UObject*)Stack.MostRecentPropertyContainer;
#endif

	// Sanity checks
	check(Object != nullptr);
	check(Property != nullptr);
	check(PropertyAddress != nullptr);
	check(Property->ContainerPtrToValuePtr<void>(Object) == PropertyAddress);

	// Allocate and initialize the return value
	const int32 PropertySize = Property->GetSize();
	void* StorageSpace = FMemory_Alloca(PropertySize);
	Property->InitializeValue(StorageSpace);

	// Step to get the value
	Stack.MostRecentProperty = nullptr;
	Stack.MostRecentPropertyAddress = nullptr;
	Stack.StepCompiledIn<FProperty>(StorageSpace);
	FProperty* ValueProperty = Stack.MostRecentProperty;
	void* ValueAddress = Stack.MostRecentPropertyAddress;

	// More sanity checks
	check(ValueProperty == nullptr || ValueProperty->IsA(Property->GetClass()));
	check(ValueAddress == nullptr || Property->Identical(StorageSpace, ValueAddress));

	// Step to get the setter
	Stack.MostRecentProperty = nullptr;
	Stack.MostRecentPropertyAddress = nullptr;
	UFunction* Setter = nullptr;
	Stack.StepCompiledIn<FProperty>(&Setter);

	P_FINISH;
	P_NATIVE_BEGIN;
	if (!Property->Identical(PropertyAddress, StorageSpace, PPF_None))
	{
		if (Setter == nullptr)
		{
			Property->CopyCompleteValue(PropertyAddress, StorageSpace);
		}
		else
		{
			check(PropertySize == Setter->GetStructureSize());
			Object->ProcessEvent(Setter, StorageSpace);
		}
		if (Property->IsA<FArrayProperty>())
		{
			NoesisNotifyArrayPropertyPostReset(PropertyAddress);
		}
		else if (Property->IsA<FMapProperty>())
		{
			NoesisNotifyMapPropertyPostReset(PropertyAddress);
		}
		else
		{
			NoesisNotifyPropertyChanged(Object, Property->GetFName());
		}
	}
	P_NATIVE_END;

	Property->DestroyValue(StorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisStruct_NotEqual)
{
	Stack.StepCompiledIn<FStructProperty>(NULL);
	FStructProperty* AProperty = CastField<FStructProperty>(Stack.MostRecentProperty);
	void* AAddress = Stack.MostRecentPropertyAddress;

	Stack.StepCompiledIn<FStructProperty>(NULL);
	FStructProperty* BProperty = CastField<FStructProperty>(Stack.MostRecentProperty);
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
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	// Since NewItem isn't really an int, step the stack manually
	const FProperty* InnerProp = ArrayProperty->Inner;
	const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
	void* StorageSpace = FMemory_Alloca(PropertySize);
	InnerProp->InitializeValue(StorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(StorageSpace);
	void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
	*(int32*)RESULT_PARAM = UKismetArrayLibrary::GenericArray_Add(ArrayAddr, ArrayProperty, NewItemPtr);
	NoesisNotifyArrayPropertyPostAdd(ArrayAddr);
	P_NATIVE_END;
	InnerProp->DestroyValue(StorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_AddUnique)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	// Since NewItem isn't really an int, step the stack manually
	const FProperty* InnerProp = ArrayProperty->Inner;
	const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
	void* StorageSpace = FMemory_Alloca(PropertySize);
	InnerProp->InitializeValue(StorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(StorageSpace);
	void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
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
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
	UKismetArrayLibrary::GenericArray_Shuffle(ArrayAddr, ArrayProperty);
	NoesisNotifyArrayPropertyPostReset(ArrayAddr);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Append)
{
	// Retrieve the target array
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* TargetArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* TargetArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!TargetArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}
	// Retrieve the source array
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* SourceArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* SourceArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!SourceArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, TargetArrayProperty);
	NoesisNotifyArrayPropertyPreAppend(TargetArrayAddr);
	UKismetArrayLibrary::GenericArray_Append(TargetArrayAddr, TargetArrayProperty, SourceArrayAddr, SourceArrayProperty);
	NoesisNotifyArrayPropertyPostAppend(TargetArrayAddr);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Insert)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	// Since NewItem isn't really an int, step the stack manually
	const FProperty* InnerProp = ArrayProperty->Inner;
	const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
	void* StorageSpace = FMemory_Alloca(PropertySize);
	InnerProp->InitializeValue(StorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(StorageSpace);
	void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

	P_GET_PROPERTY(FIntProperty, Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
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
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	P_GET_PROPERTY(FIntProperty, Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
	NoesisNotifyArrayPropertyPreRemove(ArrayAddr, Index);
	UKismetArrayLibrary::GenericArray_Remove(ArrayAddr, ArrayProperty, Index);
	NoesisNotifyArrayPropertyPostRemove(ArrayAddr, Index);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_RemoveItem)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}
	// Since Item isn't really an int, step the stack manually
	const FProperty* InnerProp = ArrayProperty->Inner;
	const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
	void* StorageSpace = FMemory_Alloca(PropertySize);
	InnerProp->InitializeValue(StorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(StorageSpace);
	void* ItemPtr = StorageSpace;

	P_FINISH;
	// Bools need to be processed internally by the property so that C++ bool value is properly set.
	const FBoolProperty* BoolProperty = CastField<const FBoolProperty>(InnerProp);
	if (BoolProperty)
	{
		ensure((BoolProperty->ElementSize * BoolProperty->ArrayDim) == sizeof(uint8));
		BoolProperty->SetPropertyValue(ItemPtr, 0 != *(reinterpret_cast<uint8*>(ItemPtr)));
	}
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
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
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}
	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
	UKismetArrayLibrary::GenericArray_Clear(ArrayAddr, ArrayProperty);
	NoesisNotifyArrayPropertyPostReset(ArrayAddr);
	P_NATIVE_END;
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisArray_Resize)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	P_GET_PROPERTY(FIntProperty, Size);

	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
	const FProperty* InnerProp = ArrayProperty->Inner;
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
	Stack.StepCompiledIn<FArrayProperty>(NULL);
	void* ArrayAddr = Stack.MostRecentPropertyAddress;
	FArrayProperty* ArrayProperty = CastField<FArrayProperty>(Stack.MostRecentProperty);
	if (!ArrayProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}
	P_GET_PROPERTY(FIntProperty, Index);

	// Since NewItem isn't really an int, step the stack manually
	const FProperty* InnerProp = ArrayProperty->Inner;
	const int32 PropertySize = InnerProp->ElementSize * InnerProp->ArrayDim;
	void* StorageSpace = FMemory_Alloca(PropertySize);
	InnerProp->InitializeValue(StorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(StorageSpace);
	void* NewItemPtr = (Stack.MostRecentPropertyAddress != NULL && Stack.MostRecentProperty->GetClass() == InnerProp->GetClass()) ? Stack.MostRecentPropertyAddress : StorageSpace;

	P_GET_UBOOL(bSizeToFit);
	P_FINISH;
	P_NATIVE_BEGIN;
	MARK_PROPERTY_DIRTY(Stack.Object, ArrayProperty);
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

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisMap_Add)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FMapProperty>(NULL);
	void* MapAddr = Stack.MostRecentPropertyAddress;
	FMapProperty* MapProperty = CastField<FMapProperty>(Stack.MostRecentProperty);
	if (!MapProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	// Since Key and Value aren't really an int, step the stack manually
	const FProperty* CurrKeyProp = MapProperty->KeyProp;
	const int32 KeyPropertySize = CurrKeyProp->ElementSize * CurrKeyProp->ArrayDim;
	void* KeyStorageSpace = FMemory_Alloca(KeyPropertySize);
	CurrKeyProp->InitializeValue(KeyStorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(KeyStorageSpace);

	const FProperty* CurrValueProp = MapProperty->ValueProp;
	const int32 ValuePropertySize = CurrValueProp->ElementSize * CurrValueProp->ArrayDim;
	void* ValueStorageSpace = FMemory_Alloca(ValuePropertySize);
	CurrValueProp->InitializeValue(ValueStorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(ValueStorageSpace);

	P_FINISH;

	P_NATIVE_BEGIN;
	UBlueprintMapLibrary::GenericMap_Add(MapAddr, MapProperty, KeyStorageSpace, ValueStorageSpace);
	if (CurrKeyProp->IsA<FStrProperty>())
	{
		FString* KeyPtr = (FString*)KeyStorageSpace;
		NoesisNotifyMapPropertyPostAdd(MapAddr, *KeyPtr);
	}
	P_NATIVE_END;

	CurrValueProp->DestroyValue(ValueStorageSpace);
	CurrKeyProp->DestroyValue(KeyStorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisMap_Remove)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FMapProperty>(NULL);
	void* MapAddr = Stack.MostRecentPropertyAddress;
	FMapProperty* MapProperty = CastField<FMapProperty>(Stack.MostRecentProperty);
	if (!MapProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	// Since Key and Value aren't really an int, step the stack manually
	const FProperty* CurrKeyProp = MapProperty->KeyProp;
	const int32 KeyPropertySize = CurrKeyProp->ElementSize * CurrKeyProp->ArrayDim;
	void* KeyStorageSpace = FMemory_Alloca(KeyPropertySize);
	CurrKeyProp->InitializeValue(KeyStorageSpace);

	Stack.MostRecentPropertyAddress = NULL;
	Stack.StepCompiledIn<FProperty>(KeyStorageSpace);

	P_FINISH;
	P_NATIVE_BEGIN;
	if (CurrKeyProp->IsA<FStrProperty>())
	{
		FString* KeyPtr = (FString*)KeyStorageSpace;
		NoesisNotifyMapPropertyPreRemove(MapAddr, *KeyPtr);
	}
	*(bool*)RESULT_PARAM = UBlueprintMapLibrary::GenericMap_Remove(MapAddr, MapProperty, KeyStorageSpace);
	if (CurrKeyProp->IsA<FStrProperty>())
	{
		FString* KeyPtr = (FString*)KeyStorageSpace;
		NoesisNotifyMapPropertyPostRemove(MapAddr, *KeyPtr);
	}
	P_NATIVE_END;

	CurrKeyProp->DestroyValue(KeyStorageSpace);
}

DEFINE_FUNCTION(UNoesisFunctionLibrary::execNoesisMap_Clear)
{
	Stack.MostRecentProperty = nullptr;
	Stack.StepCompiledIn<FMapProperty>(NULL);
	void* MapAddr = Stack.MostRecentPropertyAddress;
	FMapProperty* MapProperty = CastField<FMapProperty>(Stack.MostRecentProperty);
	if (!MapProperty)
	{
		Stack.bArrayContextFailed = true;
		return;
	}

	P_FINISH;
	P_NATIVE_BEGIN;
	UBlueprintMapLibrary::GenericMap_Clear(MapAddr, MapProperty);
	const FProperty* CurrKeyProp = MapProperty->KeyProp;
	if (CurrKeyProp->IsA<FStrProperty>())
	{
		NoesisNotifyMapPropertyPostReset(MapAddr);
	}
	P_NATIVE_END
}
