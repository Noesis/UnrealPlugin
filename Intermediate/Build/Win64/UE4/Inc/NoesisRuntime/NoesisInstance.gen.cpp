// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisInstance() {}
// Cross Module References
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_NoesisInstanceRenderFlags();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisInstance_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisInstance();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisInstance_EventInitInstance();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisInstance_ExecuteConsoleCommand();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisInstance_FindName();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisInstance_FindResource();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisInstance_GetTimeSeconds();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisInstance_InitInstance();
	NOESISRUNTIME_API UFunction* Z_Construct_UFunction_UNoesisInstance_SetDataContext();
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisXaml_NoRegister();
// End Cross Module References
	static UEnum* NoesisInstanceRenderFlags_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_NoesisRuntime_NoesisInstanceRenderFlags, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisInstanceRenderFlags"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_NoesisInstanceRenderFlags(NoesisInstanceRenderFlags_StaticEnum, TEXT("/Script/NoesisRuntime"), TEXT("NoesisInstanceRenderFlags"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_NoesisRuntime_NoesisInstanceRenderFlags_CRC() { return 3771446757U; }
	UEnum* Z_Construct_UEnum_NoesisRuntime_NoesisInstanceRenderFlags()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("NoesisInstanceRenderFlags"), 0, Get_Z_Construct_UEnum_NoesisRuntime_NoesisInstanceRenderFlags_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "NoesisInstanceRenderFlags::Normal", (int64)NoesisInstanceRenderFlags::Normal },
				{ "NoesisInstanceRenderFlags::Wireframe", (int64)NoesisInstanceRenderFlags::Wireframe },
				{ "NoesisInstanceRenderFlags::ColorBatches", (int64)NoesisInstanceRenderFlags::ColorBatches },
				{ "NoesisInstanceRenderFlags::Overdraw", (int64)NoesisInstanceRenderFlags::Overdraw },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_NoesisRuntime,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"NoesisInstanceRenderFlags",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"NoesisInstanceRenderFlags",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static FName NAME_UNoesisInstance_EventInitInstance = FName(TEXT("EventInitInstance"));
	void UNoesisInstance::EventInitInstance()
	{
		ProcessEvent(FindFunctionChecked(NAME_UNoesisInstance_EventInitInstance),NULL);
	}
	void UNoesisInstance::StaticRegisterNativesUNoesisInstance()
	{
		UClass* Class = UNoesisInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ExecuteConsoleCommand", (Native)&UNoesisInstance::execExecuteConsoleCommand },
			{ "FindName", (Native)&UNoesisInstance::execFindName },
			{ "FindResource", (Native)&UNoesisInstance::execFindResource },
			{ "GetTimeSeconds", (Native)&UNoesisInstance::execGetTimeSeconds },
			{ "InitInstance", (Native)&UNoesisInstance::execInitInstance },
			{ "SetDataContext", (Native)&UNoesisInstance::execSetDataContext },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UNoesisInstance_EventInitInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisInstance, "EventInitInstance", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisInstance_ExecuteConsoleCommand()
	{
		struct NoesisInstance_eventExecuteConsoleCommand_Parms
		{
			FString Command;
			APlayerController* SpecificPlayer;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpecificPlayer = { UE4CodeGen_Private::EPropertyClass::Object, "SpecificPlayer", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventExecuteConsoleCommand_Parms, SpecificPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Command = { UE4CodeGen_Private::EPropertyClass::Str, "Command", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventExecuteConsoleCommand_Parms, Command), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpecificPlayer,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Command,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisInstance, "ExecuteConsoleCommand", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NoesisInstance_eventExecuteConsoleCommand_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisInstance_FindName()
	{
		struct NoesisInstance_eventFindName_Parms
		{
			FString Name;
			UObject* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventFindName_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Str, "Name", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventFindName_Parms, Name), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Name,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisInstance, "FindName", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NoesisInstance_eventFindName_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisInstance_FindResource()
	{
		struct NoesisInstance_eventFindResource_Parms
		{
			FString Name;
			UObject* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventFindResource_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Str, "Name", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventFindResource_Parms, Name), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Name,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisInstance, "FindResource", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NoesisInstance_eventFindResource_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisInstance_GetTimeSeconds()
	{
		struct NoesisInstance_eventGetTimeSeconds_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventGetTimeSeconds_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisInstance, "GetTimeSeconds", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(NoesisInstance_eventGetTimeSeconds_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisInstance_InitInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisInstance, "InitInstance", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UNoesisInstance_SetDataContext()
	{
		struct NoesisInstance_eventSetDataContext_Parms
		{
			UObject* DataContext;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DataContext = { UE4CodeGen_Private::EPropertyClass::Object, "DataContext", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(NoesisInstance_eventSetDataContext_Parms, DataContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DataContext,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoesisInstance, "SetDataContext", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(NoesisInstance_eventSetDataContext_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UNoesisInstance_NoRegister()
	{
		return UNoesisInstance::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UUserWidget,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UNoesisInstance_EventInitInstance, "EventInitInstance" }, // 1351826312
				{ &Z_Construct_UFunction_UNoesisInstance_ExecuteConsoleCommand, "ExecuteConsoleCommand" }, // 2594842535
				{ &Z_Construct_UFunction_UNoesisInstance_FindName, "FindName" }, // 2154634107
				{ &Z_Construct_UFunction_UNoesisInstance_FindResource, "FindResource" }, // 3334442950
				{ &Z_Construct_UFunction_UNoesisInstance_GetTimeSeconds, "GetTimeSeconds" }, // 438339246
				{ &Z_Construct_UFunction_UNoesisInstance_InitInstance, "InitInstance" }, // 3632403251
				{ &Z_Construct_UFunction_UNoesisInstance_SetDataContext, "SetDataContext" }, // 1833838904
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "NoesisInstance.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RenderFlags_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_RenderFlags = { UE4CodeGen_Private::EPropertyClass::Enum, "RenderFlags", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000004, 1, nullptr, STRUCT_OFFSET(UNoesisInstance, RenderFlags), Z_Construct_UEnum_NoesisRuntime_NoesisInstanceRenderFlags, METADATA_PARAMS(NewProp_RenderFlags_MetaData, ARRAY_COUNT(NewProp_RenderFlags_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_RenderFlags_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TessellationQuality_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_TessellationQuality = { UE4CodeGen_Private::EPropertyClass::Enum, "TessellationQuality", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000004, 1, nullptr, STRUCT_OFFSET(UNoesisInstance, TessellationQuality), Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality, METADATA_PARAMS(NewProp_TessellationQuality_MetaData, ARRAY_COUNT(NewProp_TessellationQuality_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_TessellationQuality_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnablePPAA_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			auto NewProp_EnablePPAA_SetBit = [](void* Obj){ ((UNoesisInstance*)Obj)->EnablePPAA = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnablePPAA = { UE4CodeGen_Private::EPropertyClass::Bool, "EnablePPAA", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000004, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UNoesisInstance), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_EnablePPAA_SetBit)>::SetBit, METADATA_PARAMS(NewProp_EnablePPAA_MetaData, ARRAY_COUNT(NewProp_EnablePPAA_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseXaml_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BaseXaml = { UE4CodeGen_Private::EPropertyClass::Object, "BaseXaml", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UNoesisInstance, BaseXaml), Z_Construct_UClass_UNoesisXaml_NoRegister, METADATA_PARAMS(NewProp_BaseXaml_MetaData, ARRAY_COUNT(NewProp_BaseXaml_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RenderFlags,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RenderFlags_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TessellationQuality,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TessellationQuality_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_EnablePPAA,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseXaml,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisInstance>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisInstance::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B01080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNoesisInstance, 1010432552);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisInstance(Z_Construct_UClass_UNoesisInstance, &UNoesisInstance::StaticClass, TEXT("/Script/NoesisRuntime"), TEXT("UNoesisInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
