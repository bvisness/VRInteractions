// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Hand.h"

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "Grabbable.generated.h"

class UHand;

UCLASS(Blueprintable, ClassGroup = (VR), meta = (BlueprintSpawnableComponent))
class VRINTERACTIONS_API AGrabbable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabbable();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, Category = "VR|Interactions")
	UHand* Hand;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "VR|Interactions")
	void BeforeGrab();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "VR|Interactions")
	void AfterGrab();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "VR|Interactions")
	void BeforeDrop();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "VR|Interactions")
	void AfterDrop();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
	void Show();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
	void Hide();

	//
	// Motion Controller Events "Interface"
	//

	// BEGIN copy-paste from autogen_result.txt
	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton1Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton1Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton2Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton2Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton3Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton3Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton4Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton4Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton5Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton5Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton6Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton6Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton7Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton7Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton8Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void FaceButton8Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void Grip1Axis(float AxisValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void Grip1Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void Grip1Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void Grip2Axis(float AxisValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void Grip2Pressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void Grip2Released();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ShoulderPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ShoulderReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickDownPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickDownReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickLeftPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickLeftReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickRightPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickRightReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickUpPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickUpReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickX(float AxisValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void ThumbstickY(float AxisValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void TriggerPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void TriggerReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = "VR|Interactions")
		void TriggerAxis(float AxisValue);
	// END copy-paste
	
};
