// Fill out your copyright notice in the Description page of Project Settings.


#include "Ecriture.h"
#include <iostream>
#include <string>

void UEcriture::ecrireBrute(FString donnes, FString file, FString mode)
{
    FILE* fichier = NULL;
    char* resultFile = TCHAR_TO_ANSI(*file);
    char* resultMode = TCHAR_TO_ANSI(*mode);
    fichier = fopen(resultFile, resultMode);
    fputs(TCHAR_TO_ANSI(*donnes), fichier);

    fclose(fichier);
}

void UEcriture::ecrire(TArray<FVector> VArray, FString file, FString mode)
{
    FILE* fichier = NULL;
    fichier = fopen(TCHAR_TO_ANSI(*file), TCHAR_TO_ANSI(*mode));
    char ptr1[10];
    int fToInt;

    for (int Index = 0; Index != VArray.Num(); ++Index)
    {
        fToInt = (int)VArray[Index][0];
        sprintf(ptr1, "%d", fToInt);

        UE_LOG(LogTemp, Log, TEXT("%d"), fToInt);
        fputs(ptr1, fichier);
        fputs(":", fichier);
    }
    fclose(fichier);
}



void UEcriture::ecrireJSON(TArray<FVector> VArray, FString file, FString mode)
{
    FILE* fichier = NULL;
    fichier = fopen(TCHAR_TO_ANSI(*file), TCHAR_TO_ANSI(*mode));
    char charIndex[10];
    char ptr1[10];
    char ptr2[10];
    char ptr3[10];
    char indexString[10];
    int fToInt1;
    int fToInt2;
    int fToInt3;

    fputs("{", fichier);

    for (int Index = 0; Index != VArray.Num(); ++Index)
    {
        sprintf(charIndex, "%d", Index);
        fToInt1 = (int)VArray[Index][0];
        sprintf(ptr1, "%d", fToInt1);
        fToInt2 = (int)VArray[Index][1];
        sprintf(ptr2, "%d", fToInt2);
        fToInt3 = (int)VArray[Index][2];
        sprintf(ptr3, "%d", fToInt3);

        sprintf(indexString, "%d", Index);

        fputs("\"", fichier); fputs(indexString, fichier); fputs("\":", fichier);
        fputs("{\"x\":", fichier);
        fputs(ptr1, fichier);
        fputs(",\"y\": ", fichier);
        fputs(ptr2, fichier);
        fputs(",\"z\": ", fichier);
        fputs(ptr3, fichier);
        fputs("}\n", fichier);
        if (Index < VArray.Num() - 1) {
            fputs(",", fichier);
        }
    }
    fputs("}", fichier);
    fclose(fichier);
}

void UEcriture::ecrireNULL(FString file)
{
    FILE* fichier = NULL;
    fichier = fopen(TCHAR_TO_ANSI(*file), "w");
    fputs("", fichier);
}