// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
class UObject;
#ifdef NOESISRUNTIME_NoesisInstance_generated_h
#error "NoesisInstance.generated.h already included, missing '#pragma once' in NoesisInstance.h"
#endif
#define NOESISRUNTIME_NoesisInstance_generated_h

#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execExecuteConsoleCommand) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Command); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExecuteConsoleCommand(Z_Param_Command,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTimeSeconds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetTimeSeconds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindResource) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=P_THIS->FindResource(Z_Param_Name); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=P_THIS->FindName(Z_Param_Name); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDataContext) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_DataContext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDataContext(Z_Param_DataContext); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitInstance) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InitInstance(); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execExecuteConsoleCommand) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Command); \
		P_GET_OBJECT(APlayerController,Z_Param_SpecificPlayer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExecuteConsoleCommand(Z_Param_Command,Z_Param_SpecificPlayer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTimeSeconds) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetTimeSeconds(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindResource) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=P_THIS->FindResource(Z_Param_Name); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindName) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Name); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UObject**)Z_Param__Result=P_THIS->FindName(Z_Param_Name); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetDataContext) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_DataContext); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDataContext(Z_Param_DataContext); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitInstance) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InitInstance(); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_EVENT_PARMS
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_CALLBACK_WRAPPERS
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNoesisInstance(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisInstance(); \
public: \
	DECLARE_CLASS(UNoesisInstance, UUserWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_INCLASS \
private: \
	static void StaticRegisterNativesUNoesisInstance(); \
	friend NOESISRUNTIME_API class UClass* Z_Construct_UClass_UNoesisInstance(); \
public: \
	DECLARE_CLASS(UNoesisInstance, UUserWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NoesisRuntime"), NO_API) \
	DECLARE_SERIALIZER(UNoesisInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisInstance(UNoesisInstance&&); \
	NO_API UNoesisInstance(const UNoesisInstance&); \
public:


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoesisInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNoesisInstance(UNoesisInstance&&); \
	NO_API UNoesisInstance(const UNoesisInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoesisInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoesisInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoesisInstance)


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_32_PROLOG \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_EVENT_PARMS


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_RPC_WRAPPERS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_CALLBACK_WRAPPERS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_INCLASS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_CALLBACK_WRAPPERS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h_35_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class NoesisInstance."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisInstance_h


#define FOREACH_ENUM_NOESISINSTANCERENDERFLAGS(op) \
	op(NoesisInstanceRenderFlags::Normal) \
	op(NoesisInstanceRenderFlags::Wireframe) \
	op(NoesisInstanceRenderFlags::ColorBatches) \
	op(NoesisInstanceRenderFlags::Overdraw) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
