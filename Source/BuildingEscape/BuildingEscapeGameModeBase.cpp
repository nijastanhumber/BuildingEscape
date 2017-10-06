// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscapeGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
//#include "Kismet/GameplayStatics.h"

ABuildingEscapeGameModeBase::ABuildingEscapeGameModeBase()
{

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_DefaultPawn"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PrimaryActorTick.bCanEverTick = true;

}


