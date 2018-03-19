// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisSettings() {}
// Cross Module References
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisLoggingSettings();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisGlyphCacheDimensions();
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisOffscreenSampleCount();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisSettings_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
// End Cross Module References
	static UEnum* ENoesisLoggingSettings_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_NoesisRuntime_ENoesisLoggingSettings, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("ENoesisLoggingSettings"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ENoesisLoggingSettings(ENoesisLoggingSettings_StaticEnum, TEXT("/Script/NoesisRuntime"), TEXT("ENoesisLoggingSettings"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_NoesisRuntime_ENoesisLoggingSettings_CRC() { return 3063919398U; }
	UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisLoggingSettings()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ENoesisLoggingSettings"), 0, Get_Z_Construct_UEnum_NoesisRuntime_ENoesisLoggingSettings_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ENoesisLoggingSettings::Quiet", (int64)ENoesisLoggingSettings::Quiet },
				{ "ENoesisLoggingSettings::Normal", (int64)ENoesisLoggingSettings::Normal },
				{ "ENoesisLoggingSettings::Bindings", (int64)ENoesisLoggingSettings::Bindings },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_NoesisRuntime,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ENoesisLoggingSettings",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ENoesisLoggingSettings",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ENoesisGlyphCacheDimensions_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_NoesisRuntime_ENoesisGlyphCacheDimensions, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("ENoesisGlyphCacheDimensions"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ENoesisGlyphCacheDimensions(ENoesisGlyphCacheDimensions_StaticEnum, TEXT("/Script/NoesisRuntime"), TEXT("ENoesisGlyphCacheDimensions"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_NoesisRuntime_ENoesisGlyphCacheDimensions_CRC() { return 2873697901U; }
	UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisGlyphCacheDimensions()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ENoesisGlyphCacheDimensions"), 0, Get_Z_Construct_UEnum_NoesisRuntime_ENoesisGlyphCacheDimensions_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ENoesisGlyphCacheDimensions::x256", (int64)ENoesisGlyphCacheDimensions::x256 },
				{ "ENoesisGlyphCacheDimensions::x512", (int64)ENoesisGlyphCacheDimensions::x512 },
				{ "ENoesisGlyphCacheDimensions::x1024", (int64)ENoesisGlyphCacheDimensions::x1024 },
				{ "ENoesisGlyphCacheDimensions::x2048", (int64)ENoesisGlyphCacheDimensions::x2048 },
				{ "ENoesisGlyphCacheDimensions::x4096", (int64)ENoesisGlyphCacheDimensions::x4096 },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "x1024.DisplayName", "1024x1024" },
				{ "x2048.DisplayName", "2048x2048" },
				{ "x256.DisplayName", "256x256" },
				{ "x4096.DisplayName", "4096x4096" },
				{ "x512.DisplayName", "512x512" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_NoesisRuntime,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ENoesisGlyphCacheDimensions",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ENoesisGlyphCacheDimensions",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ENoesisOffscreenSampleCount_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_NoesisRuntime_ENoesisOffscreenSampleCount, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("ENoesisOffscreenSampleCount"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ENoesisOffscreenSampleCount(ENoesisOffscreenSampleCount_StaticEnum, TEXT("/Script/NoesisRuntime"), TEXT("ENoesisOffscreenSampleCount"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_NoesisRuntime_ENoesisOffscreenSampleCount_CRC() { return 992018784U; }
	UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisOffscreenSampleCount()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ENoesisOffscreenSampleCount"), 0, Get_Z_Construct_UEnum_NoesisRuntime_ENoesisOffscreenSampleCount_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ENoesisOffscreenSampleCount::One", (int64)ENoesisOffscreenSampleCount::One },
				{ "ENoesisOffscreenSampleCount::Two", (int64)ENoesisOffscreenSampleCount::Two },
				{ "ENoesisOffscreenSampleCount::Four", (int64)ENoesisOffscreenSampleCount::Four },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Four.DisplayName", "4x" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "One.DisplayName", "1x" },
				{ "Two.DisplayName", "2x" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_NoesisRuntime,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ENoesisOffscreenSampleCount",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ENoesisOffscreenSampleCount",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UNoesisSettings::StaticRegisterNativesUNoesisSettings()
	{
	}
	UClass* Z_Construct_UClass_UNoesisSettings_NoRegister()
	{
		return UNoesisSettings::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisSettings()
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
				{ "IncludePath", "NoesisSettings.h" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RestoreUITexturePNGPremultipliedAlpha_MetaData[] = {
				{ "Category", "Editor Settings" },
				{ "DisplayName", "Fix for premultiplied alpha UI textures" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Restores the color of UI PNG texture texels with an alpha value of zero." },
			};
#endif
			auto NewProp_RestoreUITexturePNGPremultipliedAlpha_SetBit = [](void* Obj){ ((UNoesisSettings*)Obj)->RestoreUITexturePNGPremultipliedAlpha = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_RestoreUITexturePNGPremultipliedAlpha = { UE4CodeGen_Private::EPropertyClass::Bool, "RestoreUITexturePNGPremultipliedAlpha", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UNoesisSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_RestoreUITexturePNGPremultipliedAlpha_SetBit)>::SetBit, METADATA_PARAMS(NewProp_RestoreUITexturePNGPremultipliedAlpha_MetaData, ARRAY_COUNT(NewProp_RestoreUITexturePNGPremultipliedAlpha_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LogVerbosity_MetaData[] = {
				{ "Category", "Editor Settings" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Maximum number of offscreen textures (0 = unlimited)." },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_LogVerbosity = { UE4CodeGen_Private::EPropertyClass::Enum, "LogVerbosity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, LogVerbosity), Z_Construct_UEnum_NoesisRuntime_ENoesisLoggingSettings, METADATA_PARAMS(NewProp_LogVerbosity_MetaData, ARRAY_COUNT(NewProp_LogVerbosity_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_LogVerbosity_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OffscreenMaxSurfaces_MetaData[] = {
				{ "Category", "Offscreen" },
				{ "ClampMin", "0" },
				{ "ConfigRestartRequired", "TRUE" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Maximum number of offscreen textures (0 = unlimited)." },
				{ "UIMin", "0" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_OffscreenMaxSurfaces = { UE4CodeGen_Private::EPropertyClass::Int, "OffscreenMaxSurfaces", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, OffscreenMaxSurfaces), METADATA_PARAMS(NewProp_OffscreenMaxSurfaces_MetaData, ARRAY_COUNT(NewProp_OffscreenMaxSurfaces_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OffscreenInitSurfaces_MetaData[] = {
				{ "Category", "Offscreen" },
				{ "ClampMin", "0" },
				{ "ConfigRestartRequired", "TRUE" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Number of offscreen textures created at startup." },
				{ "UIMin", "0" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_OffscreenInitSurfaces = { UE4CodeGen_Private::EPropertyClass::Int, "OffscreenInitSurfaces", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, OffscreenInitSurfaces), METADATA_PARAMS(NewProp_OffscreenInitSurfaces_MetaData, ARRAY_COUNT(NewProp_OffscreenInitSurfaces_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OffscreenTextureSampleCount_MetaData[] = {
				{ "Category", "Offscreen" },
				{ "ConfigRestartRequired", "TRUE" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Multisampling of offscreen textures." },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OffscreenTextureSampleCount = { UE4CodeGen_Private::EPropertyClass::Enum, "OffscreenTextureSampleCount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, OffscreenTextureSampleCount), Z_Construct_UEnum_NoesisRuntime_ENoesisOffscreenSampleCount, METADATA_PARAMS(NewProp_OffscreenTextureSampleCount_MetaData, ARRAY_COUNT(NewProp_OffscreenTextureSampleCount_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_OffscreenTextureSampleCount_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OffscreenTextureHeight_MetaData[] = {
				{ "Category", "Offscreen" },
				{ "ClampMin", "0" },
				{ "ConfigRestartRequired", "TRUE" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Height of offscreen textures (0 = automatic)." },
				{ "UIMin", "0" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_OffscreenTextureHeight = { UE4CodeGen_Private::EPropertyClass::Int, "OffscreenTextureHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, OffscreenTextureHeight), METADATA_PARAMS(NewProp_OffscreenTextureHeight_MetaData, ARRAY_COUNT(NewProp_OffscreenTextureHeight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OffscreenTextureWidth_MetaData[] = {
				{ "Category", "Offscreen" },
				{ "ClampMin", "0" },
				{ "ConfigRestartRequired", "TRUE" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Width of offscreen textures (0 = automatic)." },
				{ "UIMin", "0" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_OffscreenTextureWidth = { UE4CodeGen_Private::EPropertyClass::Int, "OffscreenTextureWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, OffscreenTextureWidth), METADATA_PARAMS(NewProp_OffscreenTextureWidth_MetaData, ARRAY_COUNT(NewProp_OffscreenTextureWidth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GlyphMeshThreshold_MetaData[] = {
				{ "Category", "Text Rendering" },
				{ "ClampMax", "256" },
				{ "ClampMin", "32" },
				{ "ConfigRestartRequired", "TRUE" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Glyphs with size above this are rendered using triangles." },
				{ "UIMax", "256" },
				{ "UIMin", "32" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_GlyphMeshThreshold = { UE4CodeGen_Private::EPropertyClass::Int, "GlyphMeshThreshold", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, GlyphMeshThreshold), METADATA_PARAMS(NewProp_GlyphMeshThreshold_MetaData, ARRAY_COUNT(NewProp_GlyphMeshThreshold_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GlyphTextureSize_MetaData[] = {
				{ "Category", "Text Rendering" },
				{ "ConfigRestartRequired", "TRUE" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Dimensions of texture used to cache glyphs." },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_GlyphTextureSize = { UE4CodeGen_Private::EPropertyClass::Enum, "GlyphTextureSize", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, GlyphTextureSize), Z_Construct_UEnum_NoesisRuntime_ENoesisGlyphCacheDimensions, METADATA_PARAMS(NewProp_GlyphTextureSize_MetaData, ARRAY_COUNT(NewProp_GlyphTextureSize_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_GlyphTextureSize_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ApplicationResources_MetaData[] = {
				{ "AllowedClasses", "NoesisXaml" },
				{ "Category", "Noesis Settings" },
				{ "ModuleRelativePath", "Classes/NoesisSettings.h" },
				{ "ToolTip", "Sets a collection of application-scope resources, such as styles and brushes. Provides a simple way to support a consistent theme across your application" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ApplicationResources = { UE4CodeGen_Private::EPropertyClass::Struct, "ApplicationResources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisSettings, ApplicationResources), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(NewProp_ApplicationResources_MetaData, ARRAY_COUNT(NewProp_ApplicationResources_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RestoreUITexturePNGPremultipliedAlpha,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LogVerbosity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LogVerbosity_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OffscreenMaxSurfaces,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OffscreenInitSurfaces,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OffscreenTextureSampleCount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OffscreenTextureSampleCount_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OffscreenTextureHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OffscreenTextureWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GlyphMeshThreshold,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GlyphTextureSize,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GlyphTextureSize_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ApplicationResources,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisSettings>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisSettings::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100086u,
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
	IMPLEMENT_CLASS(UNoesisSettings, 3541941688);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisSettings(Z_Construct_UClass_UNoesisSettings, &UNoesisSettings::StaticClass, TEXT("/Script/NoesisRuntime"), TEXT("UNoesisSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
