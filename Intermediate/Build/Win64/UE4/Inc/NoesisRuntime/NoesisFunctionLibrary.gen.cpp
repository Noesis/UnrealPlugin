// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisFunctionLibrary() {}
// Cross Module References
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisFunctionLibrary_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_LoadXaml();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisXaml_NoRegister();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Add();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_AddUnique();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Append();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Clear();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Insert();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Remove();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_RemoveItem();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Resize();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Set();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Shuffle();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisStruct_NotEqual();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FGenericStruct();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NotifyArrayChanged();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NotifyChanged();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_TrySetDataContext();
// End Cross Module References
	void UNoesisFunctionLibrary::StaticRegisterNativesUNoesisFunctionLibrary()
	{
		UClass* Class = UNoesisFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadXaml", (Native)&UNoesisFunctionLibrary::execLoadXaml },
			{ "NoesisArray_Add", (Native)&UNoesisFunctionLibrary::execNoesisArray_Add },
			{ "NoesisArray_AddUnique", (Native)&UNoesisFunctionLibrary::execNoesisArray_AddUnique },
			{ "NoesisArray_Append", (Native)&UNoesisFunctionLibrary::execNoesisArray_Append },
			{ "NoesisArray_Clear", (Native)&UNoesisFunctionLibrary::execNoesisArray_Clear },
			{ "NoesisArray_Insert", (Native)&UNoesisFunctionLibrary::execNoesisArray_Insert },
			{ "NoesisArray_Remove", (Native)&UNoesisFunctionLibrary::execNoesisArray_Remove },
			{ "NoesisArray_RemoveItem", (Native)&UNoesisFunctionLibrary::execNoesisArray_RemoveItem },
			{ "NoesisArray_Resize", (Native)&UNoesisFunctionLibrary::execNoesisArray_Resize },
			{ "NoesisArray_Set", (Native)&UNoesisFunctionLibrary::execNoesisArray_Set },
			{ "NoesisArray_Shuffle", (Native)&UNoesisFunctionLibrary::execNoesisArray_Shuffle },
			{ "NoesisStruct_NotEqual", (Native)&UNoesisFunctionLibrary::execNoesisStruct_NotEqual },
			{ "NotifyArrayChanged", (Native)&UNoesisFunctionLibrary::execNotifyArrayChanged },
			{ "NotifyChanged", (Native)&UNoesisFunctionLibrary::execNotifyChanged },
			{ "TrySetDataContext", (Native)&UNoesisFunctionLibrary::execTrySetDataContext },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_LoadXaml()
	{
		struct NoesisFunctionLibrary_eventLoadXaml_Parms
		{
			UNoesisXaml* Xaml;
			UObject* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventLoadXaml_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Xaml = { UE4CodeGen_Private::EPropertyClass::Object, "Xaml", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventLoadXaml_Parms, Xaml), Z_Construct_UClass_UNoesisXaml_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Xaml,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "HidePin", "Target" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "LoadXaml", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(NoesisFunctionLibrary_eventLoadXaml_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Add()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Add_Parms
		{
			TArray<int32> TargetArray;
			int32 NewItem;
			int32 ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Add_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewItem_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_NewItem = { UE4CodeGen_Private::EPropertyClass::Int, "NewItem", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Add_Parms, NewItem), METADATA_PARAMS(NewProp_NewItem_MetaData, ARRAY_COUNT(NewProp_NewItem_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Add_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewItem,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "ArrayTypeDependentParams", "NewItem" },
				{ "AutoCreateRefTerm", "NewItem" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "ADD\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Add w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Add", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Add_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_AddUnique()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_AddUnique_Parms
		{
			TArray<int32> TargetArray;
			int32 NewItem;
			int32 ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_AddUnique_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewItem_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_NewItem = { UE4CodeGen_Private::EPropertyClass::Int, "NewItem", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_AddUnique_Parms, NewItem), METADATA_PARAMS(NewProp_NewItem_MetaData, ARRAY_COUNT(NewProp_NewItem_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_AddUnique_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewItem,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "ArrayTypeDependentParams", "NewItem" },
				{ "AutoCreateRefTerm", "NewItem" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "ADDUNIQUE\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Add Unique w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_AddUnique", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_AddUnique_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Append()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Append_Parms
		{
			TArray<int32> TargetArray;
			TArray<int32> SourceArray;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SourceArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SourceArray = { UE4CodeGen_Private::EPropertyClass::Array, "SourceArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Append_Parms, SourceArray), METADATA_PARAMS(NewProp_SourceArray_MetaData, ARRAY_COUNT(NewProp_SourceArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_SourceArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "SourceArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Append_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SourceArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SourceArray_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray,SourceArray" },
				{ "ArrayTypeDependentParams", "SourceArray" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "APPEND\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Append Array w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Append", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Append_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Clear()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Clear_Parms
		{
			TArray<int32> TargetArray;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Clear_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "CLEAR\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Clear w/ NotifyArrayChanged" },
				{ "Keywords", "empty" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Clear", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Clear_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Insert()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Insert_Parms
		{
			TArray<int32> TargetArray;
			int32 NewItem;
			int32 Index;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Insert_Parms, Index), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewItem_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_NewItem = { UE4CodeGen_Private::EPropertyClass::Int, "NewItem", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Insert_Parms, NewItem), METADATA_PARAMS(NewProp_NewItem_MetaData, ARRAY_COUNT(NewProp_NewItem_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Insert_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Index,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewItem,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "ArrayTypeDependentParams", "NewItem" },
				{ "AutoCreateRefTerm", "NewItem" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "INSERT\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Insert w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Insert", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Insert_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Remove()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Remove_Parms
		{
			TArray<int32> TargetArray;
			int32 IndexToRemove;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_IndexToRemove = { UE4CodeGen_Private::EPropertyClass::Int, "IndexToRemove", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Remove_Parms, IndexToRemove), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Remove_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IndexToRemove,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "REMOVE INDEX\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Remove Index w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Remove", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Remove_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_RemoveItem()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_RemoveItem_Parms
		{
			TArray<int32> TargetArray;
			int32 Item;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((NoesisFunctionLibrary_eventNoesisArray_RemoveItem_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(NoesisFunctionLibrary_eventNoesisArray_RemoveItem_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Item_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Item = { UE4CodeGen_Private::EPropertyClass::Int, "Item", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_RemoveItem_Parms, Item), METADATA_PARAMS(NewProp_Item_MetaData, ARRAY_COUNT(NewProp_Item_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_RemoveItem_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Item,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "ArrayTypeDependentParams", "Item" },
				{ "AutoCreateRefTerm", "Item" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "REMOVE\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Remove Item w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_RemoveItem", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_RemoveItem_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Resize()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Resize_Parms
		{
			TArray<int32> TargetArray;
			int32 Size;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Size = { UE4CodeGen_Private::EPropertyClass::Int, "Size", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Resize_Parms, Size), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Resize_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Size,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "RESIZE\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Resize w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Resize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Resize_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Set()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Set_Parms
		{
			TArray<int32> TargetArray;
			int32 Index;
			int32 Item;
			bool bSizeToFit;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_bSizeToFit_SetBit = [](void* Obj){ ((NoesisFunctionLibrary_eventNoesisArray_Set_Parms*)Obj)->bSizeToFit = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSizeToFit = { UE4CodeGen_Private::EPropertyClass::Bool, "bSizeToFit", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(NoesisFunctionLibrary_eventNoesisArray_Set_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bSizeToFit_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Item_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Item = { UE4CodeGen_Private::EPropertyClass::Int, "Item", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Set_Parms, Item), METADATA_PARAMS(NewProp_Item_MetaData, ARRAY_COUNT(NewProp_Item_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Set_Parms, Index), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Set_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bSizeToFit,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Item,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Index,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "ArrayTypeDependentParams", "Item" },
				{ "AutoCreateRefTerm", "Item" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "Set Array Elem\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Set Array Elem w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Set", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Set_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Shuffle()
	{
		struct NoesisFunctionLibrary_eventNoesisArray_Shuffle_Parms
		{
			TArray<int32> TargetArray;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetArray_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetArray = { UE4CodeGen_Private::EPropertyClass::Array, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisArray_Shuffle_Parms, TargetArray), METADATA_PARAMS(NewProp_TargetArray_MetaData, ARRAY_COUNT(NewProp_TargetArray_MetaData)) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetArray_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "TargetArray", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetArray_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ArrayParm", "TargetArray" },
				{ "Category", "Noesis|Array" },
				{ "CompactNodeTitle", "SHUFFLE\nw/ NotifyArrayChanged" },
				{ "CustomThunk", "true" },
				{ "DisplayName", "Shuffle w/ NotifyArrayChanged" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisArray_Shuffle", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisArray_Shuffle_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisStruct_NotEqual()
	{
		struct NoesisFunctionLibrary_eventNoesisStruct_NotEqual_Parms
		{
			FGenericStruct A;
			FGenericStruct B;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((NoesisFunctionLibrary_eventNoesisStruct_NotEqual_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(NoesisFunctionLibrary_eventNoesisStruct_NotEqual_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_B = { UE4CodeGen_Private::EPropertyClass::Struct, "B", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisStruct_NotEqual_Parms, B), Z_Construct_UScriptStruct_FGenericStruct, METADATA_PARAMS(NewProp_B_MetaData, ARRAY_COUNT(NewProp_B_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_A = { UE4CodeGen_Private::EPropertyClass::Struct, "A", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNoesisStruct_NotEqual_Parms, A), Z_Construct_UScriptStruct_FGenericStruct, METADATA_PARAMS(NewProp_A_MetaData, ARRAY_COUNT(NewProp_A_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_B,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_A,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "BlueprintInternalUseOnly", "true" },
				{ "Category", "Noesis|Struct" },
				{ "CustomStructureParam", "A, B" },
				{ "CustomThunk", "true" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NoesisStruct_NotEqual", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(NoesisFunctionLibrary_eventNoesisStruct_NotEqual_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NotifyArrayChanged()
	{
		struct NoesisFunctionLibrary_eventNotifyArrayChanged_Parms
		{
			UObject* Owner;
			FName PropertyName;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_PropertyName = { UE4CodeGen_Private::EPropertyClass::Name, "PropertyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNotifyArrayChanged_Parms, PropertyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Owner = { UE4CodeGen_Private::EPropertyClass::Object, "Owner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNotifyArrayChanged_Parms, Owner), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PropertyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Owner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "HidePin", "Target" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NotifyArrayChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(NoesisFunctionLibrary_eventNotifyArrayChanged_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_NotifyChanged()
	{
		struct NoesisFunctionLibrary_eventNotifyChanged_Parms
		{
			UObject* Owner;
			FName PropertyName;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_PropertyName = { UE4CodeGen_Private::EPropertyClass::Name, "PropertyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNotifyChanged_Parms, PropertyName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Owner = { UE4CodeGen_Private::EPropertyClass::Object, "Owner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventNotifyChanged_Parms, Owner), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PropertyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Owner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "HidePin", "Target" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "NotifyChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(NoesisFunctionLibrary_eventNotifyChanged_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisFunctionLibrary_TrySetDataContext()
	{
		struct NoesisFunctionLibrary_eventTrySetDataContext_Parms
		{
			UObject* Element;
			UObject* DataContext;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DataContext = { UE4CodeGen_Private::EPropertyClass::Object, "DataContext", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventTrySetDataContext_Parms, DataContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Element = { UE4CodeGen_Private::EPropertyClass::Object, "Element", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisFunctionLibrary_eventTrySetDataContext_Parms, Element), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DataContext,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Element,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "HidePin", "Target" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisFunctionLibrary, "TrySetDataContext", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(NoesisFunctionLibrary_eventTrySetDataContext_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UNoesisFunctionLibrary_NoRegister()
	{
		return UNoesisFunctionLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_LoadXaml, "LoadXaml" }, // 674550273
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Add, "NoesisArray_Add" }, // 407442035
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_AddUnique, "NoesisArray_AddUnique" }, // 4001971059
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Append, "NoesisArray_Append" }, // 1760319785
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Clear, "NoesisArray_Clear" }, // 1089296183
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Insert, "NoesisArray_Insert" }, // 3370623536
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Remove, "NoesisArray_Remove" }, // 3755354130
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_RemoveItem, "NoesisArray_RemoveItem" }, // 1886032738
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Resize, "NoesisArray_Resize" }, // 3360885037
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Set, "NoesisArray_Set" }, // 2965290964
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisArray_Shuffle, "NoesisArray_Shuffle" }, // 2541319244
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NoesisStruct_NotEqual, "NoesisStruct_NotEqual" }, // 2198068011
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NotifyArrayChanged, "NotifyArrayChanged" }, // 585300534
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_NotifyChanged, "NotifyChanged" }, // 3950502718
				{ &Z_Construct_UFunction_UNoesisFunctionLibrary_TrySetDataContext, "TrySetDataContext" }, // 4084366279
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisFunctionLibrary.h" },
				{ "ModuleRelativePath", "Classes/NoesisFunctionLibrary.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisFunctionLibrary>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisFunctionLibrary::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNoesisFunctionLibrary, 500026234);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisFunctionLibrary(Z_Construct_UClass_UNoesisFunctionLibrary, &UNoesisFunctionLibrary::StaticClass, TEXT("/Script/NoesisRuntime"), TEXT("UNoesisFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
