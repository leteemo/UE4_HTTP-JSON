// Fill out your copyright notice in the Description page of Project Settings.


#include "HTTPactor.h"
#include "Http.h"

// Sets default values
AHTTPactor::AHTTPactor()
{
	donneesBrute = "tout";
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}


// Called when the game starts or when spawned
void AHTTPactor::BeginPlay()
{
	Super::BeginPlay();
	donneesBrute = "rien";

}

// Called every frame
void AHTTPactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHTTPactor::RecevoirRequeteTest(FString lien)
{
	UE_LOG(LogTemp, Log, TEXT("tentative... "));
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();

	TSharedRef<FJsonObject> requestObject = MakeShared<FJsonObject>();
	requestObject->SetStringField("title", "foo");

	FString RequestBody;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
	FJsonSerializer::Serialize(requestObject, Writer);

	Request->OnProcessRequestComplete().BindUObject(this, &AHTTPactor::HttpRecu);
	Request->SetURL(lien);
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(RequestBody);
	Request->ProcessRequest();
}

void AHTTPactor::RecevoirRequete(FString lien, FString contenu)
{
	UE_LOG(LogTemp, Log, TEXT("tentative... "));
	field = contenu;
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AHTTPactor::HttpRecu);
	Request->SetURL(lien);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

FString AHTTPactor::afficherBrute()
{
	return donneesBrute;
}

FString AHTTPactor::afficher()
{
	return donnees;
}

void AHTTPactor::HttpRecu(FHttpRequestPtr Request, FHttpResponsePtr Response, bool reponse)
{
	TSharedPtr<FJsonObject> responseObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	FJsonSerializer::Deserialize(Reader, responseObject);

	donneesBrute = *Response->GetContentAsString();
	donnees = responseObject->GetStringField(field);
	UE_LOG(LogTemp, Display, TEXT("Alors: %s"), *donneesBrute);
}


















