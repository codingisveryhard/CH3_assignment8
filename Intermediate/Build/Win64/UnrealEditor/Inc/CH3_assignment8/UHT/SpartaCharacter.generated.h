// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpartaCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionValue;
#ifdef CH3_ASSIGNMENT8_SpartaCharacter_generated_h
#error "SpartaCharacter.generated.h already included, missing '#pragma once' in SpartaCharacter.h"
#endif
#define CH3_ASSIGNMENT8_SpartaCharacter_generated_h

#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHasKey); \
	DECLARE_FUNCTION(execAddKey); \
	DECLARE_FUNCTION(execChangeMaxHealth); \
	DECLARE_FUNCTION(execAddHealth); \
	DECLARE_FUNCTION(execGetHealth); \
	DECLARE_FUNCTION(execStopSprint); \
	DECLARE_FUNCTION(execStartSprint); \
	DECLARE_FUNCTION(execLook); \
	DECLARE_FUNCTION(execStopJump); \
	DECLARE_FUNCTION(execStartJump); \
	DECLARE_FUNCTION(execMove);


#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpartaCharacter(); \
	friend struct Z_Construct_UClass_ASpartaCharacter_Statics; \
public: \
	DECLARE_CLASS(ASpartaCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CH3_assignment8"), NO_API) \
	DECLARE_SERIALIZER(ASpartaCharacter)


#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASpartaCharacter(ASpartaCharacter&&); \
	ASpartaCharacter(const ASpartaCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpartaCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpartaCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpartaCharacter) \
	NO_API virtual ~ASpartaCharacter();


#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_12_PROLOG
#define FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_15_INCLASS_NO_PURE_DECLS \
	FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CH3_ASSIGNMENT8_API UClass* StaticClass<class ASpartaCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
