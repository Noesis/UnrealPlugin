// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisStructs.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisStructs() {}
// Cross Module References
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisGeneratorPosition();
	UPackage* Z_Construct_UPackage__Script_NoesisRuntime();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisManipulationVelocities();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisPoint();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisManipulationDelta();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisTimeSpan();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisKeyTime();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisGridLength();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisRepeatBehavior();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisDuration();
	NOESISRUNTIME_API UEnum* Z_Construct_UEnum_NoesisRuntime_ENoesisDurationType();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisPointi();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisRecti();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisSizei();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisColor();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisThickness();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisCornerRadius();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisRect();
	NOESISRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FNoesisSize();
// End Cross Module References
class UScriptStruct* FNoesisGeneratorPosition::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisGeneratorPosition_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisGeneratorPosition, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisGeneratorPosition"), sizeof(FNoesisGeneratorPosition), Get_Z_Construct_UScriptStruct_FNoesisGeneratorPosition_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisGeneratorPosition(FNoesisGeneratorPosition::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisGeneratorPosition"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisGeneratorPosition
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisGeneratorPosition()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisGeneratorPosition")),new UScriptStruct::TCppStructOps<FNoesisGeneratorPosition>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisGeneratorPosition;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisGeneratorPosition()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisGeneratorPosition_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisGeneratorPosition"), sizeof(FNoesisGeneratorPosition), Get_Z_Construct_UScriptStruct_FNoesisGeneratorPosition_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisGeneratorPosition>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Offset = { UE4CodeGen_Private::EPropertyClass::Int, "Offset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisGeneratorPosition, Offset), METADATA_PARAMS(NewProp_Offset_MetaData, ARRAY_COUNT(NewProp_Offset_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Index_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisGeneratorPosition, Index), METADATA_PARAMS(NewProp_Index_MetaData, ARRAY_COUNT(NewProp_Index_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Offset,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Index,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisGeneratorPosition",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisGeneratorPosition),
				alignof(FNoesisGeneratorPosition),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisGeneratorPosition_CRC() { return 1093225648U; }
class UScriptStruct* FNoesisInertiaTranslationBehavior::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisInertiaTranslationBehavior"), sizeof(FNoesisInertiaTranslationBehavior), Get_Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisInertiaTranslationBehavior(FNoesisInertiaTranslationBehavior::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisInertiaTranslationBehavior"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaTranslationBehavior
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaTranslationBehavior()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisInertiaTranslationBehavior")),new UScriptStruct::TCppStructOps<FNoesisInertiaTranslationBehavior>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaTranslationBehavior;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisInertiaTranslationBehavior"), sizeof(FNoesisInertiaTranslationBehavior), Get_Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisInertiaTranslationBehavior>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DesiredDeceleration_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DesiredDeceleration = { UE4CodeGen_Private::EPropertyClass::Float, "DesiredDeceleration", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisInertiaTranslationBehavior, DesiredDeceleration), METADATA_PARAMS(NewProp_DesiredDeceleration_MetaData, ARRAY_COUNT(NewProp_DesiredDeceleration_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DesiredDeceleration,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisInertiaTranslationBehavior",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisInertiaTranslationBehavior),
				alignof(FNoesisInertiaTranslationBehavior),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaTranslationBehavior_CRC() { return 355457380U; }
class UScriptStruct* FNoesisInertiaRotationBehavior::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisInertiaRotationBehavior"), sizeof(FNoesisInertiaRotationBehavior), Get_Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisInertiaRotationBehavior(FNoesisInertiaRotationBehavior::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisInertiaRotationBehavior"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaRotationBehavior
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaRotationBehavior()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisInertiaRotationBehavior")),new UScriptStruct::TCppStructOps<FNoesisInertiaRotationBehavior>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaRotationBehavior;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisInertiaRotationBehavior"), sizeof(FNoesisInertiaRotationBehavior), Get_Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisInertiaRotationBehavior>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DesiredDeceleration_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DesiredDeceleration = { UE4CodeGen_Private::EPropertyClass::Float, "DesiredDeceleration", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisInertiaRotationBehavior, DesiredDeceleration), METADATA_PARAMS(NewProp_DesiredDeceleration_MetaData, ARRAY_COUNT(NewProp_DesiredDeceleration_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DesiredDeceleration,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisInertiaRotationBehavior",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisInertiaRotationBehavior),
				alignof(FNoesisInertiaRotationBehavior),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaRotationBehavior_CRC() { return 920141515U; }
class UScriptStruct* FNoesisInertiaExpansionBehavior::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisInertiaExpansionBehavior"), sizeof(FNoesisInertiaExpansionBehavior), Get_Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisInertiaExpansionBehavior(FNoesisInertiaExpansionBehavior::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisInertiaExpansionBehavior"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaExpansionBehavior
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaExpansionBehavior()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisInertiaExpansionBehavior")),new UScriptStruct::TCppStructOps<FNoesisInertiaExpansionBehavior>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisInertiaExpansionBehavior;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisInertiaExpansionBehavior"), sizeof(FNoesisInertiaExpansionBehavior), Get_Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisInertiaExpansionBehavior>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DesiredDeceleration_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DesiredDeceleration = { UE4CodeGen_Private::EPropertyClass::Float, "DesiredDeceleration", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisInertiaExpansionBehavior, DesiredDeceleration), METADATA_PARAMS(NewProp_DesiredDeceleration_MetaData, ARRAY_COUNT(NewProp_DesiredDeceleration_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DesiredDeceleration,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisInertiaExpansionBehavior",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisInertiaExpansionBehavior),
				alignof(FNoesisInertiaExpansionBehavior),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisInertiaExpansionBehavior_CRC() { return 2509272002U; }
class UScriptStruct* FNoesisManipulationVelocities::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisManipulationVelocities_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisManipulationVelocities, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisManipulationVelocities"), sizeof(FNoesisManipulationVelocities), Get_Z_Construct_UScriptStruct_FNoesisManipulationVelocities_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisManipulationVelocities(FNoesisManipulationVelocities::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisManipulationVelocities"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisManipulationVelocities
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisManipulationVelocities()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisManipulationVelocities")),new UScriptStruct::TCppStructOps<FNoesisManipulationVelocities>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisManipulationVelocities;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisManipulationVelocities()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisManipulationVelocities_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisManipulationVelocities"), sizeof(FNoesisManipulationVelocities), Get_Z_Construct_UScriptStruct_FNoesisManipulationVelocities_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisManipulationVelocities>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LinearVelocity_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_LinearVelocity = { UE4CodeGen_Private::EPropertyClass::Struct, "LinearVelocity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisManipulationVelocities, LinearVelocity), Z_Construct_UScriptStruct_FNoesisPoint, METADATA_PARAMS(NewProp_LinearVelocity_MetaData, ARRAY_COUNT(NewProp_LinearVelocity_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExpansionVelocity_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ExpansionVelocity = { UE4CodeGen_Private::EPropertyClass::Struct, "ExpansionVelocity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisManipulationVelocities, ExpansionVelocity), Z_Construct_UScriptStruct_FNoesisPoint, METADATA_PARAMS(NewProp_ExpansionVelocity_MetaData, ARRAY_COUNT(NewProp_ExpansionVelocity_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AngularVelocity_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AngularVelocity = { UE4CodeGen_Private::EPropertyClass::Float, "AngularVelocity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisManipulationVelocities, AngularVelocity), METADATA_PARAMS(NewProp_AngularVelocity_MetaData, ARRAY_COUNT(NewProp_AngularVelocity_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LinearVelocity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ExpansionVelocity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AngularVelocity,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisManipulationVelocities",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisManipulationVelocities),
				alignof(FNoesisManipulationVelocities),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisManipulationVelocities_CRC() { return 1519009124U; }
class UScriptStruct* FNoesisManipulationDelta::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisManipulationDelta_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisManipulationDelta, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisManipulationDelta"), sizeof(FNoesisManipulationDelta), Get_Z_Construct_UScriptStruct_FNoesisManipulationDelta_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisManipulationDelta(FNoesisManipulationDelta::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisManipulationDelta"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisManipulationDelta
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisManipulationDelta()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisManipulationDelta")),new UScriptStruct::TCppStructOps<FNoesisManipulationDelta>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisManipulationDelta;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisManipulationDelta()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisManipulationDelta_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisManipulationDelta"), sizeof(FNoesisManipulationDelta), Get_Z_Construct_UScriptStruct_FNoesisManipulationDelta_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisManipulationDelta>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Translation_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Translation = { UE4CodeGen_Private::EPropertyClass::Struct, "Translation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisManipulationDelta, Translation), Z_Construct_UScriptStruct_FNoesisPoint, METADATA_PARAMS(NewProp_Translation_MetaData, ARRAY_COUNT(NewProp_Translation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Scale = { UE4CodeGen_Private::EPropertyClass::Float, "Scale", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisManipulationDelta, Scale), METADATA_PARAMS(NewProp_Scale_MetaData, ARRAY_COUNT(NewProp_Scale_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Rotation = { UE4CodeGen_Private::EPropertyClass::Float, "Rotation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisManipulationDelta, Rotation), METADATA_PARAMS(NewProp_Rotation_MetaData, ARRAY_COUNT(NewProp_Rotation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Expansion_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Expansion = { UE4CodeGen_Private::EPropertyClass::Struct, "Expansion", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisManipulationDelta, Expansion), Z_Construct_UScriptStruct_FNoesisPoint, METADATA_PARAMS(NewProp_Expansion_MetaData, ARRAY_COUNT(NewProp_Expansion_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Translation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Scale,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Rotation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Expansion,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisManipulationDelta",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisManipulationDelta),
				alignof(FNoesisManipulationDelta),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisManipulationDelta_CRC() { return 777136832U; }
class UScriptStruct* FNoesisTimeSpan::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisTimeSpan_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisTimeSpan, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisTimeSpan"), sizeof(FNoesisTimeSpan), Get_Z_Construct_UScriptStruct_FNoesisTimeSpan_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisTimeSpan(FNoesisTimeSpan::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisTimeSpan"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisTimeSpan
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisTimeSpan()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisTimeSpan")),new UScriptStruct::TCppStructOps<FNoesisTimeSpan>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisTimeSpan;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisTimeSpan()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisTimeSpan_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisTimeSpan"), sizeof(FNoesisTimeSpan), Get_Z_Construct_UScriptStruct_FNoesisTimeSpan_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisTimeSpan>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Milliseconds_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Milliseconds = { UE4CodeGen_Private::EPropertyClass::Int, "Milliseconds", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisTimeSpan, Milliseconds), METADATA_PARAMS(NewProp_Milliseconds_MetaData, ARRAY_COUNT(NewProp_Milliseconds_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seconds_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Seconds = { UE4CodeGen_Private::EPropertyClass::Int, "Seconds", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisTimeSpan, Seconds), METADATA_PARAMS(NewProp_Seconds_MetaData, ARRAY_COUNT(NewProp_Seconds_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Minutes_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Minutes = { UE4CodeGen_Private::EPropertyClass::Int, "Minutes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisTimeSpan, Minutes), METADATA_PARAMS(NewProp_Minutes_MetaData, ARRAY_COUNT(NewProp_Minutes_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hours_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Hours = { UE4CodeGen_Private::EPropertyClass::Int, "Hours", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisTimeSpan, Hours), METADATA_PARAMS(NewProp_Hours_MetaData, ARRAY_COUNT(NewProp_Hours_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Days_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Days = { UE4CodeGen_Private::EPropertyClass::Int, "Days", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisTimeSpan, Days), METADATA_PARAMS(NewProp_Days_MetaData, ARRAY_COUNT(NewProp_Days_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Milliseconds,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Seconds,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Minutes,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Hours,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Days,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisTimeSpan",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisTimeSpan),
				alignof(FNoesisTimeSpan),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisTimeSpan_CRC() { return 458218489U; }
class UScriptStruct* FNoesisKeyTime::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisKeyTime_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisKeyTime, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisKeyTime"), sizeof(FNoesisKeyTime), Get_Z_Construct_UScriptStruct_FNoesisKeyTime_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisKeyTime(FNoesisKeyTime::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisKeyTime"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisKeyTime
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisKeyTime()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisKeyTime")),new UScriptStruct::TCppStructOps<FNoesisKeyTime>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisKeyTime;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisKeyTime()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisKeyTime_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisKeyTime"), sizeof(FNoesisKeyTime), Get_Z_Construct_UScriptStruct_FNoesisKeyTime_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisKeyTime>(); };
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisKeyTime",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisKeyTime),
				alignof(FNoesisKeyTime),
				nullptr, 0,
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisKeyTime_CRC() { return 131334903U; }
class UScriptStruct* FNoesisGridLength::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisGridLength_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisGridLength, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisGridLength"), sizeof(FNoesisGridLength), Get_Z_Construct_UScriptStruct_FNoesisGridLength_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisGridLength(FNoesisGridLength::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisGridLength"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisGridLength
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisGridLength()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisGridLength")),new UScriptStruct::TCppStructOps<FNoesisGridLength>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisGridLength;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisGridLength()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisGridLength_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisGridLength"), sizeof(FNoesisGridLength), Get_Z_Construct_UScriptStruct_FNoesisGridLength_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisGridLength>(); };
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisGridLength",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisGridLength),
				alignof(FNoesisGridLength),
				nullptr, 0,
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisGridLength_CRC() { return 3407437188U; }
class UScriptStruct* FNoesisRepeatBehavior::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisRepeatBehavior_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisRepeatBehavior, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisRepeatBehavior"), sizeof(FNoesisRepeatBehavior), Get_Z_Construct_UScriptStruct_FNoesisRepeatBehavior_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisRepeatBehavior(FNoesisRepeatBehavior::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisRepeatBehavior"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRepeatBehavior
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRepeatBehavior()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisRepeatBehavior")),new UScriptStruct::TCppStructOps<FNoesisRepeatBehavior>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRepeatBehavior;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisRepeatBehavior()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisRepeatBehavior_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisRepeatBehavior"), sizeof(FNoesisRepeatBehavior), Get_Z_Construct_UScriptStruct_FNoesisRepeatBehavior_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisRepeatBehavior>(); };
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisRepeatBehavior",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisRepeatBehavior),
				alignof(FNoesisRepeatBehavior),
				nullptr, 0,
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisRepeatBehavior_CRC() { return 2463229682U; }
class UScriptStruct* FNoesisDuration::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisDuration_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisDuration, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisDuration"), sizeof(FNoesisDuration), Get_Z_Construct_UScriptStruct_FNoesisDuration_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisDuration(FNoesisDuration::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisDuration"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisDuration
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisDuration()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisDuration")),new UScriptStruct::TCppStructOps<FNoesisDuration>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisDuration;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisDuration()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisDuration_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisDuration"), sizeof(FNoesisDuration), Get_Z_Construct_UScriptStruct_FNoesisDuration_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisDuration>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Milliseconds_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Milliseconds = { UE4CodeGen_Private::EPropertyClass::Int, "Milliseconds", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisDuration, Milliseconds), METADATA_PARAMS(NewProp_Milliseconds_MetaData, ARRAY_COUNT(NewProp_Milliseconds_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DurationType_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DurationType = { UE4CodeGen_Private::EPropertyClass::Enum, "DurationType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisDuration, DurationType), Z_Construct_UEnum_NoesisRuntime_ENoesisDurationType, METADATA_PARAMS(NewProp_DurationType_MetaData, ARRAY_COUNT(NewProp_DurationType_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_DurationType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Milliseconds,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DurationType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DurationType_Underlying,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisDuration",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisDuration),
				alignof(FNoesisDuration),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisDuration_CRC() { return 1741596611U; }
class UScriptStruct* FNoesisPointi::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisPointi_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisPointi, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisPointi"), sizeof(FNoesisPointi), Get_Z_Construct_UScriptStruct_FNoesisPointi_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisPointi(FNoesisPointi::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisPointi"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisPointi
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisPointi()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisPointi")),new UScriptStruct::TCppStructOps<FNoesisPointi>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisPointi;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisPointi()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisPointi_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisPointi"), sizeof(FNoesisPointi), Get_Z_Construct_UScriptStruct_FNoesisPointi_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisPointi>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Int, "Y", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisPointi, Y), METADATA_PARAMS(NewProp_Y_MetaData, ARRAY_COUNT(NewProp_Y_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_X = { UE4CodeGen_Private::EPropertyClass::Int, "X", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisPointi, X), METADATA_PARAMS(NewProp_X_MetaData, ARRAY_COUNT(NewProp_X_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Y,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_X,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisPointi",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisPointi),
				alignof(FNoesisPointi),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisPointi_CRC() { return 92459743U; }
class UScriptStruct* FNoesisRecti::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisRecti_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisRecti, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisRecti"), sizeof(FNoesisRecti), Get_Z_Construct_UScriptStruct_FNoesisRecti_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisRecti(FNoesisRecti::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisRecti"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRecti
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRecti()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisRecti")),new UScriptStruct::TCppStructOps<FNoesisRecti>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRecti;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisRecti()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisRecti_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisRecti"), sizeof(FNoesisRecti), Get_Z_Construct_UScriptStruct_FNoesisRecti_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisRecti>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Height = { UE4CodeGen_Private::EPropertyClass::Int, "Height", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRecti, Height), METADATA_PARAMS(NewProp_Height_MetaData, ARRAY_COUNT(NewProp_Height_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Width = { UE4CodeGen_Private::EPropertyClass::Int, "Width", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRecti, Width), METADATA_PARAMS(NewProp_Width_MetaData, ARRAY_COUNT(NewProp_Width_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Int, "Y", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRecti, Y), METADATA_PARAMS(NewProp_Y_MetaData, ARRAY_COUNT(NewProp_Y_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_X = { UE4CodeGen_Private::EPropertyClass::Int, "X", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRecti, X), METADATA_PARAMS(NewProp_X_MetaData, ARRAY_COUNT(NewProp_X_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Height,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Width,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Y,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_X,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisRecti",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisRecti),
				alignof(FNoesisRecti),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisRecti_CRC() { return 383316389U; }
class UScriptStruct* FNoesisSizei::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisSizei_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisSizei, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisSizei"), sizeof(FNoesisSizei), Get_Z_Construct_UScriptStruct_FNoesisSizei_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisSizei(FNoesisSizei::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisSizei"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisSizei
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisSizei()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisSizei")),new UScriptStruct::TCppStructOps<FNoesisSizei>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisSizei;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisSizei()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisSizei_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisSizei"), sizeof(FNoesisSizei), Get_Z_Construct_UScriptStruct_FNoesisSizei_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisSizei>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Height = { UE4CodeGen_Private::EPropertyClass::Int, "Height", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisSizei, Height), METADATA_PARAMS(NewProp_Height_MetaData, ARRAY_COUNT(NewProp_Height_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Width = { UE4CodeGen_Private::EPropertyClass::Int, "Width", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisSizei, Width), METADATA_PARAMS(NewProp_Width_MetaData, ARRAY_COUNT(NewProp_Width_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Height,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Width,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisSizei",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisSizei),
				alignof(FNoesisSizei),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisSizei_CRC() { return 444348669U; }
class UScriptStruct* FNoesisColor::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisColor_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisColor, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisColor"), sizeof(FNoesisColor), Get_Z_Construct_UScriptStruct_FNoesisColor_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisColor(FNoesisColor::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisColor"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisColor
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisColor()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisColor")),new UScriptStruct::TCppStructOps<FNoesisColor>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisColor;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisColor()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisColor_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisColor"), sizeof(FNoesisColor), Get_Z_Construct_UScriptStruct_FNoesisColor_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisColor>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Alpha_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Alpha = { UE4CodeGen_Private::EPropertyClass::Float, "Alpha", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisColor, Alpha), METADATA_PARAMS(NewProp_Alpha_MetaData, ARRAY_COUNT(NewProp_Alpha_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Blue_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Blue = { UE4CodeGen_Private::EPropertyClass::Float, "Blue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisColor, Blue), METADATA_PARAMS(NewProp_Blue_MetaData, ARRAY_COUNT(NewProp_Blue_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Green_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Green = { UE4CodeGen_Private::EPropertyClass::Float, "Green", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisColor, Green), METADATA_PARAMS(NewProp_Green_MetaData, ARRAY_COUNT(NewProp_Green_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Red_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Red = { UE4CodeGen_Private::EPropertyClass::Float, "Red", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisColor, Red), METADATA_PARAMS(NewProp_Red_MetaData, ARRAY_COUNT(NewProp_Red_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Alpha,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Blue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Green,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Red,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisColor",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisColor),
				alignof(FNoesisColor),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisColor_CRC() { return 1402948709U; }
class UScriptStruct* FNoesisThickness::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisThickness_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisThickness, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisThickness"), sizeof(FNoesisThickness), Get_Z_Construct_UScriptStruct_FNoesisThickness_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisThickness(FNoesisThickness::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisThickness"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisThickness
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisThickness()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisThickness")),new UScriptStruct::TCppStructOps<FNoesisThickness>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisThickness;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisThickness()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisThickness_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisThickness"), sizeof(FNoesisThickness), Get_Z_Construct_UScriptStruct_FNoesisThickness_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisThickness>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bottom_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Bottom = { UE4CodeGen_Private::EPropertyClass::Float, "Bottom", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisThickness, Bottom), METADATA_PARAMS(NewProp_Bottom_MetaData, ARRAY_COUNT(NewProp_Bottom_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Right = { UE4CodeGen_Private::EPropertyClass::Float, "Right", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisThickness, Right), METADATA_PARAMS(NewProp_Right_MetaData, ARRAY_COUNT(NewProp_Right_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Top_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Top = { UE4CodeGen_Private::EPropertyClass::Float, "Top", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisThickness, Top), METADATA_PARAMS(NewProp_Top_MetaData, ARRAY_COUNT(NewProp_Top_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Left = { UE4CodeGen_Private::EPropertyClass::Float, "Left", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisThickness, Left), METADATA_PARAMS(NewProp_Left_MetaData, ARRAY_COUNT(NewProp_Left_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Bottom,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Right,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Top,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Left,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisThickness",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisThickness),
				alignof(FNoesisThickness),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisThickness_CRC() { return 3984303138U; }
class UScriptStruct* FNoesisCornerRadius::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisCornerRadius_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisCornerRadius, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisCornerRadius"), sizeof(FNoesisCornerRadius), Get_Z_Construct_UScriptStruct_FNoesisCornerRadius_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisCornerRadius(FNoesisCornerRadius::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisCornerRadius"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisCornerRadius
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisCornerRadius()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisCornerRadius")),new UScriptStruct::TCppStructOps<FNoesisCornerRadius>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisCornerRadius;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisCornerRadius()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisCornerRadius_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisCornerRadius"), sizeof(FNoesisCornerRadius), Get_Z_Construct_UScriptStruct_FNoesisCornerRadius_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisCornerRadius>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BottomLeft_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BottomLeft = { UE4CodeGen_Private::EPropertyClass::Float, "BottomLeft", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisCornerRadius, BottomLeft), METADATA_PARAMS(NewProp_BottomLeft_MetaData, ARRAY_COUNT(NewProp_BottomLeft_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BottomRight_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BottomRight = { UE4CodeGen_Private::EPropertyClass::Float, "BottomRight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisCornerRadius, BottomRight), METADATA_PARAMS(NewProp_BottomRight_MetaData, ARRAY_COUNT(NewProp_BottomRight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TopRight_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TopRight = { UE4CodeGen_Private::EPropertyClass::Float, "TopRight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisCornerRadius, TopRight), METADATA_PARAMS(NewProp_TopRight_MetaData, ARRAY_COUNT(NewProp_TopRight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TopLeft_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TopLeft = { UE4CodeGen_Private::EPropertyClass::Float, "TopLeft", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisCornerRadius, TopLeft), METADATA_PARAMS(NewProp_TopLeft_MetaData, ARRAY_COUNT(NewProp_TopLeft_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BottomLeft,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BottomRight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TopRight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TopLeft,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisCornerRadius",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisCornerRadius),
				alignof(FNoesisCornerRadius),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisCornerRadius_CRC() { return 3296541311U; }
class UScriptStruct* FNoesisPoint::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisPoint_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisPoint, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisPoint"), sizeof(FNoesisPoint), Get_Z_Construct_UScriptStruct_FNoesisPoint_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisPoint(FNoesisPoint::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisPoint"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisPoint
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisPoint()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisPoint")),new UScriptStruct::TCppStructOps<FNoesisPoint>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisPoint;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisPoint()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisPoint_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisPoint"), sizeof(FNoesisPoint), Get_Z_Construct_UScriptStruct_FNoesisPoint_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisPoint>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisPoint, Y), METADATA_PARAMS(NewProp_Y_MetaData, ARRAY_COUNT(NewProp_Y_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisPoint, X), METADATA_PARAMS(NewProp_X_MetaData, ARRAY_COUNT(NewProp_X_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Y,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_X,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisPoint",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisPoint),
				alignof(FNoesisPoint),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisPoint_CRC() { return 1467205788U; }
class UScriptStruct* FNoesisRect::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisRect_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisRect, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisRect"), sizeof(FNoesisRect), Get_Z_Construct_UScriptStruct_FNoesisRect_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisRect(FNoesisRect::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisRect"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRect
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRect()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisRect")),new UScriptStruct::TCppStructOps<FNoesisRect>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisRect;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisRect()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisRect_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisRect"), sizeof(FNoesisRect), Get_Z_Construct_UScriptStruct_FNoesisRect_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisRect>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Height = { UE4CodeGen_Private::EPropertyClass::Float, "Height", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRect, Height), METADATA_PARAMS(NewProp_Height_MetaData, ARRAY_COUNT(NewProp_Height_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Width = { UE4CodeGen_Private::EPropertyClass::Float, "Width", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRect, Width), METADATA_PARAMS(NewProp_Width_MetaData, ARRAY_COUNT(NewProp_Width_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y = { UE4CodeGen_Private::EPropertyClass::Float, "Y", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRect, Y), METADATA_PARAMS(NewProp_Y_MetaData, ARRAY_COUNT(NewProp_Y_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X = { UE4CodeGen_Private::EPropertyClass::Float, "X", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisRect, X), METADATA_PARAMS(NewProp_X_MetaData, ARRAY_COUNT(NewProp_X_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Height,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Width,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Y,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_X,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisRect",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisRect),
				alignof(FNoesisRect),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisRect_CRC() { return 1986541263U; }
class UScriptStruct* FNoesisSize::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern NOESISRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FNoesisSize_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FNoesisSize, Z_Construct_UPackage__Script_NoesisRuntime(), TEXT("NoesisSize"), sizeof(FNoesisSize), Get_Z_Construct_UScriptStruct_FNoesisSize_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FNoesisSize(FNoesisSize::StaticStruct, TEXT("/Script/NoesisRuntime"), TEXT("NoesisSize"), false, nullptr, nullptr);
static struct FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisSize
{
	FScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisSize()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("NoesisSize")),new UScriptStruct::TCppStructOps<FNoesisSize>);
	}
} ScriptStruct_NoesisRuntime_StaticRegisterNativesFNoesisSize;
	UScriptStruct* Z_Construct_UScriptStruct_FNoesisSize()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FNoesisSize_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_NoesisRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("NoesisSize"), sizeof(FNoesisSize), Get_Z_Construct_UScriptStruct_FNoesisSize_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNoesisSize>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Height = { UE4CodeGen_Private::EPropertyClass::Float, "Height", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisSize, Height), METADATA_PARAMS(NewProp_Height_MetaData, ARRAY_COUNT(NewProp_Height_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[] = {
				{ "Category", "NoesisGUI" },
				{ "ModuleRelativePath", "Classes/NoesisStructs.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Width = { UE4CodeGen_Private::EPropertyClass::Float, "Width", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(FNoesisSize, Width), METADATA_PARAMS(NewProp_Width_MetaData, ARRAY_COUNT(NewProp_Width_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Height,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Width,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisRuntime,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"NoesisSize",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FNoesisSize),
				alignof(FNoesisSize),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FNoesisSize_CRC() { return 3828233280U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
