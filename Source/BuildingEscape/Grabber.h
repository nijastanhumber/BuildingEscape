// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.0f;

	UPROPERTY()
	UPhysicsHandleComponent *PhysicsHandle = nullptr;	

	UPROPERTY()
	UInputComponent *InputComponent = nullptr;

	// Ray-cast and grab what is in reach
	UFUNCTION()
	void Grab();

	UFUNCTION()
	void Release();
	
	// Find (assumed) attached physics handle
	UFUNCTION()
	void FindPhysicsHandleComponent();

	// Setup (assumed) attached input component
	UFUNCTION()
	void SetupInputComponent();

	// Returns hit for first physics body in reach
	UFUNCTION()
	FHitResult GetFirstPhysicsBodyInReach() const;

	// Returns current start of reach line
	UFUNCTION()
	FVector GetReachLineStart() const;

	// Returns current end of reach line
	UFUNCTION()
	FVector GetReachLineEnd() const;
};
