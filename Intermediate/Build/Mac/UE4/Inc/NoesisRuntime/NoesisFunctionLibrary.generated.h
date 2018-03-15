// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UNoesisXaml;
class UObject;
struct FGenericStruct;
#ifdef NOESISRUNTIME_NoesisFunctionLibrary_generated_h
#error "NoesisFunctionLibrary.generated.h already included, missing '#pragma once' in NoesisFunctionLibrary.h"
#endif
#define NOESISRUNTIME_NoesisFunctionLibrary_generated_h

#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLoadXaml) \
	{ \
		P_GET_OBJECT(UNoesisXaml,Z_Param_Xaml); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UNoesisFunctionLibrary::LoadXaml(Z_Param_Xaml); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrySetDataContext) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Element); \
		P_GET_OBJECT(UObject,Z_Param_DataContext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UNoesisFunctionLibrary::TrySetDataContext(Z_Param_Element,Z_Param_DataContext); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNotifyArrayChanged) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Owner); \
		P_GET_PROPERTY(UNameProperty,Z_Param_PropertyName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UNoesisFunctionLibrary::NotifyArrayChanged(Z_Param_Owner,Z_Param_PropertyName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNotifyChanged) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Owner); \
		P_GET_PROPERTY(UNameProperty,Z_Param_PropertyName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UNoesisFunctionLibrary::NotifyChanged(Z_Param_Owner,Z_Param_PropertyName); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadXaml) \
	{ \
		P_GET_OBJECT(UNoesisXaml,Z_Param_Xaml); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=UNoesisFunctionLibrary::LoadXaml(Z_Param_Xaml); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrySetDataContext) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Element); \
		P_GET_OBJECT(UObject,Z_Param_DataContext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UNoesisFunctionLibrary::TrySetDataContext(Z_Param_Element,Z_Param_DataContext); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNotifyArrayChanged) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Owner); \
		P_GET_PROPERTY(UNameProperty,Z_Param_PropertyName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UNoesisFunctionLibrary::NotifyArrayChanged(Z_Param_Owner,Z_Param_PropertyName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNotifyChanged) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Owner); \
		P_GET_PROPERTY(UNameProperty,Z_Param_PropertyName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UNoesisFunctionLibrary::NotifyChanged(Z_Param_Owner,Z_Param_PropertyName); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNoesisFunctionLibrary(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisFunctionLibrary(); \
public: \
	DECLARE_CLASS(UNoesisFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisFunctionLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUNoesisFunctionLibrary(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisFunctionLibrary(); \
public: \
	DECLARE_CLASS(UNoesisFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisFunctionLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisFunctionLibrary(UNoesisFunctionLibrary&&); \
	NO_API UNoesisFunctionLibrary(const UNoesisFunctionLibrary&); \
public:


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisFunctionLibrary(UNoesisFunctionLibrary&&); \
	NO_API UNoesisFunctionLibrary(const UNoesisFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisFunctionLibrary)


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_18_PROLOG
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_RPC_WRAPPERS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_INCLASS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h_21_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class NoesisFunctionLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
