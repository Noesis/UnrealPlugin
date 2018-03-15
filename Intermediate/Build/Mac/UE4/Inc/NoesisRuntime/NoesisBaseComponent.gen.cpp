// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisBaseComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisBaseComponent() {}
// Cross Module References
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisBaseComponent_NoRegister();
	NOESISRUNTIME_API UClass* Z_Construct_UClass_UNoesisBaseComponent();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
// End Cross Module References
	void UNoesisBaseComponent::StaticRegisterNativesUNoesisBaseComponent()
	{
	}
	UClass* Z_Construct_UClass_UNoesisBaseComponent_NoRegister()
	{
		return UNoesisBaseComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisBaseComponent()
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
				{ "BlueprintType", "true" },
				{ "IncludePath", "NoesisBaseComponent.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/NoesisBaseComponent.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisBaseComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisBaseComponent::StaticClass,
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
	IMPLEMENT_CLASS(UNoesisBaseComponent, 1887067503);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisBaseComponent(Z_Construct_UClass_UNoesisBaseComponent, &UNoesisBaseComponent::StaticClass, TEXT("/Script/NoesisRuntime"), TEXT("UNoesisBaseComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisBaseComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
