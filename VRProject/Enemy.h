// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BaseP.h"
#include "BallShoot.h"
#include "Enemy.generated.h"

UCLASS()
class VRPROJECT_API AEnemy : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ShootingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 ShootingInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 oldInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool Spawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ABallShoot *Laser;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) UShapeComponent* CSphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<ABallShoot> Ball; //Send in blueprint
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector BlueBaseLoc;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) FRotator BlueBaseRot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool DoShoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector locBall;

	UFUNCTION()
		void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	// Sets default values for this actor's properties
	AEnemy(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

private:
	FRotator rotBall;

};