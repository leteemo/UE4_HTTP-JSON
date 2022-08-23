// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "HTTPactor.generated.h"


UCLASS()
class PLANETEDESTRUCTION_API AHTTPactor : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties

	AHTTPactor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		FString donnees;

	UPROPERTY(EditAnywhere)
		FString donneesBrute;

	UPROPERTY(EditAnywhere)
		FString field;

	UFUNCTION(BlueprintCallable, Category = "HTTP")
		void RecevoirRequete(FString lien, FString conteneu);

	UFUNCTION(BlueprintCallable, Category = "HTTP")
		void RecevoirRequeteTest(FString lien);

	UFUNCTION(BlueprintCallable, Category = "HTTP")
		FString afficher();

	UFUNCTION(BlueprintCallable, Category = "HTTP")
		FString afficherBrute();

	void HttpRecu(FHttpRequestPtr Request, FHttpResponsePtr Response, bool reponse);

};
