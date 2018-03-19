// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/K2Node_NoesisAssignAndNotify.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeK2Node_NoesisAssignAndNotify() {}
// Cross Module References
	NOESISEDITOR_API UClass* Z_Construct_UClass_UK2Node_NoesisAssignAndNotify_NoRegister();
	NOESISEDITOR_API UClass* Z_Construct_UClass_UK2Node_NoesisAssignAndNotify();
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node_Variable();
	UPackage* Z_Construct_UPackage__Script_NoesisEditor();
// End Cross Module References
	void UK2Node_NoesisAssignAndNotify::StaticRegisterNativesUK2Node_NoesisAssignAndNotify()
	{
	}
	UClass* Z_Construct_UClass_UK2Node_NoesisAssignAndNotify_NoRegister()
	{
		return UK2Node_NoesisAssignAndNotify::StaticClass();
	}
	UClass* Z_Construct_UClass_UK2Node_NoesisAssignAndNotify()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UK2Node_Variable,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisEditor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "K2Node_NoesisAssignAndNotify.h" },
				{ "ModuleRelativePath", "Classes/K2Node_NoesisAssignAndNotify.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UK2Node_NoesisAssignAndNotify>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UK2Node_NoesisAssignAndNotify::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00080080u,
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
	IMPLEMENT_CLASS(UK2Node_NoesisAssignAndNotify, 589162200);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UK2Node_NoesisAssignAndNotify(Z_Construct_UClass_UK2Node_NoesisAssignAndNotify, &UK2Node_NoesisAssignAndNotify::StaticClass, TEXT("/Script/NoesisEditor"), TEXT("UK2Node_NoesisAssignAndNotify"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UK2Node_NoesisAssignAndNotify);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
