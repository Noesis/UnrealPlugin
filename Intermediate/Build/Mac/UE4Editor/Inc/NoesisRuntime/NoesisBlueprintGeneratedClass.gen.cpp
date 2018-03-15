// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisBlueprintGeneratedClass.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisBlueprintGeneratedClass() {}
// Cross Module References
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisBlueprintGeneratedClass_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisBlueprintGeneratedClass();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintGeneratedClass();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisXaml_NoRegister();
// End Cross Module References
	void UNoesisBlueprintGeneratedClass::StaticRegisterNativesUNoesisBlueprintGeneratedClass()
	{
	}
	UClass* Z_Construct_UClass_UNoesisBlueprintGeneratedClass_NoRegister()
	{
		return UNoesisBlueprintGeneratedClass::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisBlueprintGeneratedClass()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintGeneratedClass,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisBlueprintGeneratedClass.h" },
				{ "ModuleRelativePath", "Classes/NoesisBlueprintGeneratedClass.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TessellationQuality_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisBlueprintGeneratedClass.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_TessellationQuality = { UE4CodeGen_Private::EPropertyClass::Enum, "TessellationQuality", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UNoesisBlueprintGeneratedClass, TessellationQuality), Z_Construct_UEnum_NoesisRuntime_ENoesisTessellationQuality, METADATA_PARAMS(NewProp_TessellationQuality_MetaData, ARRAY_COUNT(NewProp_TessellationQuality_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_TessellationQuality_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnablePPAA_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisBlueprintGeneratedClass.h" },
			};
#endif
			auto NewProp_EnablePPAA_SetBit = [](void* Obj){ ((UNoesisBlueprintGeneratedClass*)Obj)->EnablePPAA = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnablePPAA = { UE4CodeGen_Private::EPropertyClass::Bool, "EnablePPAA", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UNoesisBlueprintGeneratedClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_EnablePPAA_SetBit)>::SetBit, METADATA_PARAMS(NewProp_EnablePPAA_MetaData, ARRAY_COUNT(NewProp_EnablePPAA_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseXaml_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisBlueprintGeneratedClass.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BaseXaml = { UE4CodeGen_Private::EPropertyClass::Object, "BaseXaml", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UNoesisBlueprintGeneratedClass, BaseXaml), Z_Construct_UClass_UNoesisXaml_NoRegister, METADATA_PARAMS(NewProp_BaseXaml_MetaData, ARRAY_COUNT(NewProp_BaseXaml_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TessellationQuality,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TessellationQuality_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_EnablePPAA,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseXaml,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisBlueprintGeneratedClass>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisBlueprintGeneratedClass::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(UNoesisBlueprintGeneratedClass, 363418058);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisBlueprintGeneratedClass(Z_Construct_UClass_UNoesisBlueprintGeneratedClass, &UNoesisBlueprintGeneratedClass::StaticClass, TEXT("/Script/NoesisRuntime"), TEXT("UNoesisBlueprintGeneratedClass"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisBlueprintGeneratedClass);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
