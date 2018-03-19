// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisBlueprintFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisBlueprintFactory() {}
// Cross Module References
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisBlueprintFactory_NoRegister();
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisBlueprintFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_NoesisEditor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisInstance_NoRegister();
// End Cross Module References
	void UNoesisBlueprintFactory::StaticRegisterNativesUNoesisBlueprintFactory()
	{
	}
	UClass* Z_Construct_UClass_UNoesisBlueprintFactory_NoRegister()
	{
		return UNoesisBlueprintFactory::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisBlueprintFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UFactory,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisEditor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisBlueprintFactory.h" },
				{ "ModuleRelativePath", "Classes/NoesisBlueprintFactory.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentClass_MetaData[] = {
				{ "AllowAbstract", "" },
				{ "Category", "NoesisBlueprintFactory" },
				{ "ModuleRelativePath", "Classes/NoesisBlueprintFactory.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ParentClass = { UE4CodeGen_Private::EPropertyClass::Class, "ParentClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000001, 1, nullptr, STRUCT_OFFSET(UNoesisBlueprintFactory, ParentClass), Z_Construct_UClass_UNoesisInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ParentClass_MetaData, ARRAY_COUNT(NewProp_ParentClass_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ParentClass,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisBlueprintFactory>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisBlueprintFactory::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
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
	IMPLEMENT_CLASS(UNoesisBlueprintFactory, 29023673);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisBlueprintFactory(Z_Construct_UClass_UNoesisBlueprintFactory, &UNoesisBlueprintFactory::StaticClass, TEXT("/Script/NoesisEditor"), TEXT("UNoesisBlueprintFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisBlueprintFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
