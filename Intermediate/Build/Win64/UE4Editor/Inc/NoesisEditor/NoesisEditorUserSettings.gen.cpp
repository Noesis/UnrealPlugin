// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisEditorUserSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisEditorUserSettings() {}
// Cross Module References
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisEditorUserSettings_NoRegister();
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisEditorUserSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_NoesisEditor();
// End Cross Module References
	void UNoesisEditorUserSettings::StaticRegisterNativesUNoesisEditorUserSettings()
	{
	}
	UClass* Z_Construct_UClass_UNoesisEditorUserSettings_NoRegister()
	{
		return UNoesisEditorUserSettings::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisEditorUserSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisEditor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisEditorUserSettings.h" },
				{ "ModuleRelativePath", "Classes/NoesisEditorUserSettings.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectURIRoot_MetaData[] = {
				{ "Category", "Editor Settings" },
				{ "DisplayName", "Project URI Root" },
				{ "ModuleRelativePath", "Classes/NoesisEditorUserSettings.h" },
				{ "ToolTip", "The directory that is the root of absolute URIs in XAML files for the project." },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_ProjectURIRoot = { UE4CodeGen_Private::EPropertyClass::Str, "ProjectURIRoot", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000004001, 1, nullptr, STRUCT_OFFSET(UNoesisEditorUserSettings, ProjectURIRoot), METADATA_PARAMS(NewProp_ProjectURIRoot_MetaData, ARRAY_COUNT(NewProp_ProjectURIRoot_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectURIRoot,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisEditorUserSettings>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisEditorUserSettings::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100086u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				"EditorPerProjectUserSettings",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNoesisEditorUserSettings, 628969668);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisEditorUserSettings(Z_Construct_UClass_UNoesisEditorUserSettings, &UNoesisEditorUserSettings::StaticClass, TEXT("/Script/NoesisEditor"), TEXT("UNoesisEditorUserSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisEditorUserSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
