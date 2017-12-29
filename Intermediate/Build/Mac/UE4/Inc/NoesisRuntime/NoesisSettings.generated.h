// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NOESISRUNTIME_NoesisSettings_generated_h
#error "NoesisSettings.generated.h already included, missing '#pragma once' in NoesisSettings.h"
#endif
#define NOESISRUNTIME_NoesisSettings_generated_h

#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_RPC_WRAPPERS
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_RPC_WRAPPERS_NO_PURE_DECLS
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNoesisSettings(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisSettings(); \
public: \
	DECLARE_CLASS(UNoesisSettings, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisSettings) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_INCLASS \
private: \
	static void StaticRegisterNativesUNoesisSettings(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisSettings(); \
public: \
	DECLARE_CLASS(UNoesisSettings, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisSettings) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisSettings(UNoesisSettings&&); \
	NO_API UNoesisSettings(const UNoesisSettings&); \
public:


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisSettings(UNoesisSettings&&); \
	NO_API UNoesisSettings(const UNoesisSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisSettings)


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_37_PROLOG
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_RPC_WRAPPERS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_INCLASS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h_40_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class NoesisSettings."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisSettings_h


#define FOREACH_ENUM_ENOESISLOGGINGSETTINGS(op) \
	op(ENoesisLoggingSettings::Quiet) \
	op(ENoesisLoggingSettings::Normal) 
#define FOREACH_ENUM_ENOESISGLYPHCACHEDIMENSIONS(op) \
	op(ENoesisGlyphCacheDimensions::x256) \
	op(ENoesisGlyphCacheDimensions::x512) \
	op(ENoesisGlyphCacheDimensions::x1024) \
	op(ENoesisGlyphCacheDimensions::x2048) 
#define FOREACH_ENUM_ENOESISOFFSCREENSAMPLECOUNT(op) \
	op(ENoesisOffscreenSampleCount::One) \
	op(ENoesisOffscreenSampleCount::Two) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
