// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CH3_assignment8/Public/SpartaGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpartaGameInstance() {}

// Begin Cross Module References
CH3_ASSIGNMENT8_API UClass* Z_Construct_UClass_USpartaGameInstance();
CH3_ASSIGNMENT8_API UClass* Z_Construct_UClass_USpartaGameInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
UPackage* Z_Construct_UPackage__Script_CH3_assignment8();
// End Cross Module References

// Begin Class USpartaGameInstance Function AddToHealth
struct Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics
{
	struct SpartaGameInstance_eventAddToHealth_Parms
	{
		int32 Amount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpartaGameInstance_eventAddToHealth_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::NewProp_Amount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpartaGameInstance, nullptr, "AddToHealth", nullptr, nullptr, Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::SpartaGameInstance_eventAddToHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::SpartaGameInstance_eventAddToHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpartaGameInstance_AddToHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpartaGameInstance_AddToHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpartaGameInstance::execAddToHealth)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddToHealth(Z_Param_Amount);
	P_NATIVE_END;
}
// End Class USpartaGameInstance Function AddToHealth

// Begin Class USpartaGameInstance Function AddToScore
struct Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics
{
	struct SpartaGameInstance_eventAddToScore_Parms
	{
		int32 Amount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpartaGameInstance_eventAddToScore_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::NewProp_Amount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpartaGameInstance, nullptr, "AddToScore", nullptr, nullptr, Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::PropPointers), sizeof(Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::SpartaGameInstance_eventAddToScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::SpartaGameInstance_eventAddToScore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USpartaGameInstance_AddToScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpartaGameInstance_AddToScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USpartaGameInstance::execAddToScore)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddToScore(Z_Param_Amount);
	P_NATIVE_END;
}
// End Class USpartaGameInstance Function AddToScore

// Begin Class USpartaGameInstance
void USpartaGameInstance::StaticRegisterNativesUSpartaGameInstance()
{
	UClass* Class = USpartaGameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddToHealth", &USpartaGameInstance::execAddToHealth },
		{ "AddToScore", &USpartaGameInstance::execAddToScore },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USpartaGameInstance);
UClass* Z_Construct_UClass_USpartaGameInstance_NoRegister()
{
	return USpartaGameInstance::StaticClass();
}
struct Z_Construct_UClass_USpartaGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SpartaGameInstance.h" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalScore_MetaData[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RewardScore_MetaData[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLevelIndex_MetaData[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWaveIndex_MetaData[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "GameData" },
		{ "ModuleRelativePath", "Public/SpartaGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalScore;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RewardScore;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentLevelIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentWaveIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USpartaGameInstance_AddToHealth, "AddToHealth" }, // 2399429293
		{ &Z_Construct_UFunction_USpartaGameInstance_AddToScore, "AddToScore" }, // 2901152938
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USpartaGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_TotalScore = { "TotalScore", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpartaGameInstance, TotalScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalScore_MetaData), NewProp_TotalScore_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_RewardScore = { "RewardScore", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpartaGameInstance, RewardScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RewardScore_MetaData), NewProp_RewardScore_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_CurrentLevelIndex = { "CurrentLevelIndex", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpartaGameInstance, CurrentLevelIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLevelIndex_MetaData), NewProp_CurrentLevelIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_CurrentWaveIndex = { "CurrentWaveIndex", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpartaGameInstance, CurrentWaveIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWaveIndex_MetaData), NewProp_CurrentWaveIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USpartaGameInstance, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USpartaGameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_TotalScore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_RewardScore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_CurrentLevelIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_CurrentWaveIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpartaGameInstance_Statics::NewProp_MaxHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USpartaGameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_USpartaGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_CH3_assignment8,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USpartaGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USpartaGameInstance_Statics::ClassParams = {
	&USpartaGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USpartaGameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USpartaGameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USpartaGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_USpartaGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USpartaGameInstance()
{
	if (!Z_Registration_Info_UClass_USpartaGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USpartaGameInstance.OuterSingleton, Z_Construct_UClass_USpartaGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USpartaGameInstance.OuterSingleton;
}
template<> CH3_ASSIGNMENT8_API UClass* StaticClass<USpartaGameInstance>()
{
	return USpartaGameInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(USpartaGameInstance);
USpartaGameInstance::~USpartaGameInstance() {}
// End Class USpartaGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USpartaGameInstance, USpartaGameInstance::StaticClass, TEXT("USpartaGameInstance"), &Z_Registration_Info_UClass_USpartaGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USpartaGameInstance), 2244553874U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaGameInstance_h_4012830513(TEXT("/Script/CH3_assignment8"),
	Z_CompiledInDeferFile_FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_VS_CH3_assignment8_Source_CH3_assignment8_Public_SpartaGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
