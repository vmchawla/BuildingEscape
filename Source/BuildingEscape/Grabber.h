// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
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

	UPROPERTY(EditAnywhere)
		float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//Ray-cast and grab whats in Reach
	void Grab();

	void Release();

	void FindPhysicsHandleComponent();

	void SetupInputComponent();

	//Return hit for first physics body in reach..helper function CAN BE NULL
	const FHitResult GetFirstPhysicsBodyHitInReach();

	//helper Function to get Player Location
	FVector GetReachLineEnd();

	//helper function to get Player Location + (direction.magnitude * reach)
	FVector GetReachLineStart();
	
};
