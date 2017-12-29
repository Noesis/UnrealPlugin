// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisXamlFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisXamlFactory() {}
// Cross Module References
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisXamlFactory_NoRegister();
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisXamlFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_NoesisEditor();
// End Cross Module References
	void UNoesisXamlFactory::StaticRegisterNativesUNoesisXamlFactory()
	{
	}
	UClass* Z_Construct_UClass_UNoesisXamlFactory_NoRegister()
	{
		return UNoesisXamlFactory::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisXamlFactory()
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
				{ "IncludePath", "NoesisXamlFactory.h" },
				{ "ModuleRelativePath", "Classes/NoesisXamlFactory.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisXamlFactory>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisXamlFactory::StaticClass,
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
	IMPLEMENT_CLASS(UNoesisXamlFactory, 330800866);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisXamlFactory(Z_Construct_UClass_UNoesisXamlFactory, &UNoesisXamlFactory::StaticClass, TEXT("/Script/NoesisEditor"), TEXT("UNoesisXamlFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisXamlFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
