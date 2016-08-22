// Fill out your copyright notice in the Description page of Project Settings.

#include "VRInteractionsPrivatePCH.h"

#include "Grabbable.h"

// Sets default values
AGrabbable::AGrabbable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrabbable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabbable::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGrabbable::Show_Implementation()
{
	GetRootComponent()->SetVisibility(true, true);
}

void AGrabbable::Hide_Implementation()
{
	GetRootComponent()->SetVisibility(false, true);
}
