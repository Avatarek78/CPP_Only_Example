// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTestActor.generated.h"

UCLASS()
class CPP_ONLY_EXAMPLE_API AMyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "TestValues") int32 Value;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "TestValues") int32 ReadonlyValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestValues") int32 ValueA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestValues") int32 ValueB;

	UFUNCTION(BlueprintCallable, Category = "TestFunctions") int32 calculateValue();

	// Tato fce nema definici v cpp, protoze oznaceni BlueprintImplementableEvent znamena, ze je to udalost, kterou lze implementovat (odchytit) v UE BluePrint-tech
	// Naopak pokus o definici v cpp povede k tomu, ze tady to pujde normalne zkompilovat, ale pri kompilaci z UE to bude hlasit chybu:
	// MyTestActor.gen.cpp.obj : error LNK2005: "public: void __cdecl AMyTestActor::OnValueCalculated(void)" (?OnValueCalculated@AMyTestActor@@QEAAXXZ) už je definované v MyTestActor.cpp.obj. 
	// Takze na to pozor tohle je trochu zakerne.
	UFUNCTION(BlueprintImplementableEvent, Category = "TestFunctions") void onValueCalculated(int32 result);

	// Oproti udalosti vyse tato udalost oznacena BlueprintNativeEvent bude mit definici v cpp a nepujde tak pouzit v UE BluePrint-u.
	// Navic je tu jedna zvlastnost a to ta, ze implementace se jmenuje onValueCalculatedNative_Implementation!
	UFUNCTION(BlueprintNativeEvent, Category = "TestFunctions") void onValueCalculatedNative(int32 result);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
