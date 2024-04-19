// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"

// Sets default values
AMyTestActor::AMyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Value = 100; 
	ReadonlyValue = 999;
	ValueA = 0;
	ValueB = 0;
}

int32 AMyTestActor::calculateValue() {
	int32 result = ValueA + ValueB;
	onValueCalculated(result);
	onValueCalculatedNative(result);
	return result;
}



void AMyTestActor::onValueCalculatedNative_Implementation(int32 result) {
	// Takhle slozite je vypsat text s promennou! To neni jako v JAVA "Calculated value from NATIVE = " + result ACHJO :-( 
	FString message = FString::Printf(TEXT("Calculated value from NATIVE = %d"), result);
	GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Magenta, message);
}

// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

