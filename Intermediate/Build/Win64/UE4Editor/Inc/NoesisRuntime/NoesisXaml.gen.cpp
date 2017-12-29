// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisXaml.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisXaml() {}
// Cross Module References
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisXaml_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisXaml();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAssetImportData_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UFont_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	void UNoesisXaml::StaticRegisterNativesUNoesisXaml()
	{
	}
	UClass* Z_Construct_UClass_UNoesisXaml_NoRegister()
	{
		return UNoesisXaml::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisXaml()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisXaml.h" },
				{ "ModuleRelativePath", "Classes/NoesisXaml.h" },
			};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ThumbnailRenderInstance_MetaData[] = {
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Classes/NoesisXaml.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ThumbnailRenderInstance = { UE4CodeGen_Private::EPropertyClass::Object, "ThumbnailRenderInstance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000800080008, 1, nullptr, STRUCT_OFFSET(UNoesisXaml, ThumbnailRenderInstance), Z_Construct_UClass_UNoesisInstance_NoRegister, METADATA_PARAMS(NewProp_ThumbnailRenderInstance_MetaData, ARRAY_COUNT(NewProp_ThumbnailRenderInstance_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetImportData_MetaData[] = {
				{ "Category", "ImportSettings" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Classes/NoesisXaml.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AssetImportData = { UE4CodeGen_Private::EPropertyClass::Object, "AssetImportData", RF_Public|RF_Transient|RF_MarkAsNative, 0x00120008000a0009, 1, nullptr, STRUCT_OFFSET(UNoesisXaml, AssetImportData), Z_Construct_UClass_UAssetImportData_NoRegister, METADATA_PARAMS(NewProp_AssetImportData_MetaData, ARRAY_COUNT(NewProp_AssetImportData_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Fonts_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisXaml.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Fonts = { UE4CodeGen_Private::EPropertyClass::Array, "Fonts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UNoesisXaml, Fonts), METADATA_PARAMS(NewProp_Fonts_MetaData, ARRAY_COUNT(NewProp_Fonts_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Fonts_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Fonts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UFont_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Textures_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisXaml.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Textures = { UE4CodeGen_Private::EPropertyClass::Array, "Textures", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UNoesisXaml, Textures), METADATA_PARAMS(NewProp_Textures_MetaData, ARRAY_COUNT(NewProp_Textures_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Textures_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Textures", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Xamls_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisXaml.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Xamls = { UE4CodeGen_Private::EPropertyClass::Array, "Xamls", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UNoesisXaml, Xamls), METADATA_PARAMS(NewProp_Xamls_MetaData, ARRAY_COUNT(NewProp_Xamls_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Xamls_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Xamls", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UNoesisXaml_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_XamlText_MetaData[] = {
				{ "ModuleRelativePath", "Classes/NoesisXaml.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_XamlText = { UE4CodeGen_Private::EPropertyClass::Array, "XamlText", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(UNoesisXaml, XamlText), METADATA_PARAMS(NewProp_XamlText_MetaData, ARRAY_COUNT(NewProp_XamlText_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_XamlText_Inner = { UE4CodeGen_Private::EPropertyClass::Byte, "XamlText", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
#if WITH_EDITORONLY_DATA
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ThumbnailRenderInstance,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AssetImportData,
#endif // WITH_EDITORONLY_DATA
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Fonts,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Fonts_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Textures,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Textures_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Xamls,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Xamls_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_XamlText,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_XamlText_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisXaml>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisXaml::StaticClass,
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
	IMPLEMENT_CLASS(UNoesisXaml, 3122360877);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisXaml(Z_Construct_UClass_UNoesisXaml, &UNoesisXaml::StaticClass, TEXT("/Script/NoesisRuntime"), TEXT("UNoesisXaml"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisXaml);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
