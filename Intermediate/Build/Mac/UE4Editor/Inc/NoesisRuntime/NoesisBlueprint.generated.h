// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NOESISRUNTIME_NoesisBlueprint_generated_h
#error "NoesisBlueprint.generated.h already included, missing '#pragma once' in NoesisBlueprint.h"
#endif
#define NOESISRUNTIME_NoesisBlueprint_generated_h

#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_RPC_WRAPPERS
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNoesisBlueprint(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisBlueprint(); \
public: \
	DECLARE_CLASS(UNoesisBlueprint, UBlueprint, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisBlueprint) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUNoesisBlueprint(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisBlueprint(); \
public: \
	DECLARE_CLASS(UNoesisBlueprint, UBlueprint, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisBlueprint) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisBlueprint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisBlueprint) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisBlueprint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisBlueprint); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisBlueprint(UNoesisBlueprint&&); \
	NO_API UNoesisBlueprint(const UNoesisBlueprint&); \
public:


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisBlueprint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisBlueprint(UNoesisBlueprint&&); \
	NO_API UNoesisBlueprint(const UNoesisBlueprint&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisBlueprint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisBlueprint); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisBlueprint)


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_19_PROLOG
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_RPC_WRAPPERS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_INCLASS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h_22_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class NoesisBlueprint."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisBlueprint_h


#define FOREACH_ENUM_ENOESISTESSELLATIONQUALITY(op) \
	op(ENoesisTessellationQuality::Low) \
	op(ENoesisTessellationQuality::Medium) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
