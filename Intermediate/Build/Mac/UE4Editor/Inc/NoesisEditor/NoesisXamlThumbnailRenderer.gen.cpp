// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/NoesisXamlThumbnailRenderer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoesisXamlThumbnailRenderer() {}
// Cross Module References
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisXamlThumbnailRenderer_NoRegister();
	NOESISEDITOR_API UClass* Z_Construct_UClass_UNoesisXamlThumbnailRenderer();
	UNREALED_API UClass* Z_Construct_UClass_UDefaultSizedThumbnailRenderer();
	UPackage* Z_Construct_UPackage__Script_NoesisEditor();
// End Cross Module References
	void UNoesisXamlThumbnailRenderer::StaticRegisterNativesUNoesisXamlThumbnailRenderer()
	{
	}
	UClass* Z_Construct_UClass_UNoesisXamlThumbnailRenderer_NoRegister()
	{
		return UNoesisXamlThumbnailRenderer::StaticClass();
	}
	UClass* Z_Construct_UClass_UNoesisXamlThumbnailRenderer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UDefaultSizedThumbnailRenderer,
				(UObject* (*)())Z_Construct_UPackage__Script_NoesisEditor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "NoesisXamlThumbnailRenderer.h" },
				{ "ModuleRelativePath", "Classes/NoesisXamlThumbnailRenderer.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UNoesisXamlThumbnailRenderer>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UNoesisXamlThumbnailRenderer::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00080084u,
				nullptr, 0,
				nullptr, 0,
				"Editor",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNoesisXamlThumbnailRenderer, 1041867563);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNoesisXamlThumbnailRenderer(Z_Construct_UClass_UNoesisXamlThumbnailRenderer, &UNoesisXamlThumbnailRenderer::StaticClass, TEXT("/Script/NoesisEditor"), TEXT("UNoesisXamlThumbnailRenderer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNoesisXamlThumbnailRenderer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
