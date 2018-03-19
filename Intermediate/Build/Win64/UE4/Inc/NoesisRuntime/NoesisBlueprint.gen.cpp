// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisBlueprint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisBlueprint() {}
// Cross Module References
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisBlueprint_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisBlueprint();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprint();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisXaml_NoRegister();
// End Cross Module References
	static UEnum* ENoesisTessellationQuality_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("ENoesisTessellationQuality"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ENoesisTessellationQuality(ENoesisTessellationQuality_StaticEnum, TEXT("/Script/NoesisRuntime"), TEXT("ENoesisTessellationQuality"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality_CRC() { return 1855823201U; }
	UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ENoesisTessellationQuality"), 0, Get_Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ENoesisTessellationQuality::Low", (int64)ENoesisTessellationQuality::Low },
				{ "ENoesisTessellationQuality::Medium", (int64)ENoesisTessellationQuality::Medium },
				{ "ENoesisTessellationQuality::High", (int64)ENoesisTessellationQuality::High },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/NoesisBlueprint.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_NoesisRuntime,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ENoesisTessellationQuality",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ENoesisTessellationQuality",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UNoesisBlueprint::StaticRegisterNativesUNoesisBlueprint()
	{
	}
	UClass* Z_Construct_UClass_UNoesisBlueprint_NoRegister()
	{
		return UNoesisBlueprint::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisBlueprint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprint,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisBlueprint.h" },
				{ "ModuleRelativePath", "Classes/NoesisBlueprint.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TessellationQuality_MetaData[] = {
				{ "Category", "Noesis View" },
				{ "ModuleRelativePath", "Classes/NoesisBlueprint.h" },
				{ "ToolTip", "Specifies tessellation quality." },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_TessellationQuality = { UE4CodeGen_Private::EPropertyClass::Enum, "TessellationQuality", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UNoesisBlueprint, TessellationQuality), Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality, METADATA_PARAMS(NewProp_TessellationQuality_MetaData, ARRAY_COUNT(NewProp_TessellationQuality_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_TessellationQuality_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnablePPAA_MetaData[] = {
				{ "Category", "Noesis View" },
				{ "ModuleRelativePath", "Classes/NoesisBlueprint.h" },
				{ "ToolTip", "Per-Primitive Antialiasing extrudes the contours of the geometry and smooths them. Useful when GPU MSAA is not enabled." },
			};
#endif
			auto NewProp_EnablePPAA_SetBit = [](void* Obj){ ((UNoesisBlueprint*)Obj)->EnablePPAA = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnablePPAA = { UE4CodeGen_Private::EPropertyClass::Bool, "EnablePPAA", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UNoesisBlueprint), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_EnablePPAA_SetBit)>::SetBit, METADATA_PARAMS(NewProp_EnablePPAA_MetaData, ARRAY_COUNT(NewProp_EnablePPAA_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseXaml_MetaData[] = {
				{ "Category", "Noesis View" },
				{ "DisplayName", "XAML" },
				{ "ModuleRelativePath", "Classes/NoesisBlueprint.h" },
				{ "ToolTip", "Xaml file that defines the user interface." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BaseXaml = { UE4CodeGen_Private::EPropertyClass::Object, "BaseXaml", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UNoesisBlueprint, BaseXaml), Z_Construct_UClass_UNoesisXaml_NoRegister, METADATA_PARAMS(NewProp_BaseXaml_MetaData, ARRAY_COUNT(NewProp_BaseXaml_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TessellationQuality,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TessellationQuality_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_EnablePPAA,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseXaml,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisBlueprint>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisBlueprint::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900084u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				"Engine",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNoesisBlueprint, 558837155);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisBlueprint(Z_Construct_UClass_UNoesisBlueprint, &UNoesisBlueprint::StaticClass, TEXT("/Script/NoesisRuntime"), TEXT("UNoesisBlueprint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisBlueprint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
