// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Ecriture.generated.h"

/**
 * 
 */
UCLASS()
class PLANETEDESTRUCTION_API UEcriture : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "ecriture")
	static void ecrire(TArray<FVector> VArray, FString file, FString mode);

	UFUNCTION(BlueprintCallable, Category = "ecriture")
	static void ecrireJSON(TArray<FVector> VArray, FString file, FString mode);

	UFUNCTION(BlueprintCallable, Category = "ecriture")
	static void ecrireNULL(FString file);

	UFUNCTION(BlueprintCallable, Category = "ecriture")
	static void ecrireBrute(FString donnes, FString file, FString mode);
	
};





