// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpartaPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UUserWidget;
#ifdef CH3_ASSIGNMENT8_SpartaPlayerController_generated_h
#error "SpartaPlayerController.generated.h already included, missing '#pragma once' in SpartaPlayerController.h"
#endif
#define CH3_ASSIGNMENT8_SpartaPlayerController_generated_h

#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEndGame); \
	DECLARE_FUNCTION(execResumeGame); \
	DECLARE_FUNCTION(execStartGame); \
	DECLARE_FUNCTION(execShowMainMenu); \
	DECLARE_FUNCTION(execShowGameHUD); \
	DECLARE_FUNCTION(execGetHUdWidget); \
	DECLARE_FUNCTION(execToggleInventory);


#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpartaPlayerController(); \
	friend struct Z_Construct_UClass_ASpartaPlayerController_Statics; \
public: \
	DECLARE_CLASS(ASpartaPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CH3_assignment8"), NO_API) \
	DECLARE_SERIALIZER(ASpartaPlayerController)


#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASpartaPlayerController(ASpartaPlayerController&&); \
	ASpartaPlayerController(const ASpartaPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpartaPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpartaPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpartaPlayerController) \
	NO_API virtual ~ASpartaPlayerController();


#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_10_PROLOG
#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_13_INCLASS_NO_PURE_DECLS \
	FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CH3_ASSIGNMENT8_API UClass* StaticClass<class ASpartaPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
