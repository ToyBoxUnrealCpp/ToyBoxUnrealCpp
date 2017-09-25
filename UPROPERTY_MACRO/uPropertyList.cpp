// Fill out your copyright notice in the Description page of Project Settings.

#include "uPropertyList.h"
#include "DrawDebugHelpers.h"

// Sets default values
AuPropertyList::AuPropertyList()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AuPropertyList::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AuPropertyList::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Ref:	Only valid on function param declaration.
//		Value is copied out after function call.
void AuPropertyList::meaninglessFunction(UPROPERTY(Ref)int32 reference)
{
	reference = 114514;
}