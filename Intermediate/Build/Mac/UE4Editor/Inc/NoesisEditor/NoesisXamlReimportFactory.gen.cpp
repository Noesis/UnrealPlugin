// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisXamlReimportFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisXamlReimportFactory() {}
// Cross Module References
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisXamlReimportFactory_NoRegister();
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisXamlReimportFactory();
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisXamlFactory();
	UPackage* Z_Construct_UPackage__Script_NoesisEditor();
// End Cross Module References
	void UNoesisXamlReimportFactory::StaticRegisterNativesUNoesisXamlReimportFactory()
	{
	}
	UClass* Z_Construct_UClass_UNoesisXamlReimportFactory_NoRegister()
	{
		return UNoesisXamlReimportFactory::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisXamlReimportFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UNoesisXamlFactory,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisEditor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisXamlReimportFactory.h" },
				{ "ModuleRelativePath", "Classes/NoesisXamlReimportFactory.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisXamlReimportFactory>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisXamlReimportFactory::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(UNoesisXamlReimportFactory, 349670743);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisXamlReimportFactory(Z_Construct_UClass_UNoesisXamlReimportFactory, &UNoesisXamlReimportFactory::StaticClass, TEXT("/Script/NoesisEditor"), TEXT("UNoesisXamlReimportFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisXamlReimportFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
