// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Grabbable.h"
#include "Interactable.h"

#include "EngineMinimal.h"
#include "MotionControllerComponent.h"
#include "Components/SceneComponent.h"
#include "Hand.generated.h"

class AGrabbable;
class AInteractable;

UCLASS(Blueprintable, ClassGroup = (VR), meta = (BlueprintSpawnableComponent))
class VRINTERACTIONS_API UHand : public USceneComponent
{
	GENERATED_BODY()
	
public:

	// Sets default values for this component's properties
	UHand();

	// Initializes input in player controller
	void BeginPlay() override;

	UInputComponent* InputComponent;

	// The component currently being grabbed by this hand.
	UPROPERTY(BlueprintReadOnly, Category = "VR|Interactions")
	AGrabbable* Grabbed;

	// The component currently being interacted with by this hand.
	UPROPERTY(BlueprintReadOnly, Category = "VR|Interactions")
	AInteractable* Interacting;

	// The motion controller to which this hand is attached. This should be set at construction time.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VR|Interactions")
	UMotionControllerComponent* MotionController;

	// The collision component used for grabbing things. This should be set at construction time.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VR|Interactions")
	UPrimitiveComponent* GrabCollision;

	static AActor* ClosestActorToLocation(FVector Location, TArray<AActor*> Actors, TArray<AActor*> Exclude);

	static AActor* ClosestActorToComponent(USceneComponent* component, TArray<AActor*> Actors, TArray<AActor*> Exclude);

	// Tries to grab a grabbable or interactable that is overlapping GrabCollision. Returns whether a new object was successfully grabbed.
	UFUNCTION(BlueprintCallable, Category = "VR|Interactions")
	bool TryToGrab();

	// Grabs a grabbable object
	UFUNCTION(BlueprintCallable, Category = "VR|Interactions")
	void GrabGrabbable(AGrabbable* GrabbableObject);

	// Grabs an interactable object
	UFUNCTION(BlueprintCallable, Category = "VR|Interactions")
	void GrabInteractable(AInteractable* InteractableObject);

	// Drops the currently grabbed object, if any
	UFUNCTION(BlueprintCallable, Category = "VR|Interactions")
	void DropGrabbed();

	// Releases the currently interacting object, if any
	UFUNCTION(BlueprintCallable, Category = "VR|Interactions")
	void ReleaseInteractable();

	//
	// MotionControllerEvents_Interface passthrough implementation
	//
	// I can't use macros here because the Unreal Header Tool doesn't
	// understand them and it ignores all the UFUNCTIONs the macro would put
	// in. :( So I have a python script generating this for me.
	//

	// BEGIN copy-paste from autogen_result.txt
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton1Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton1Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton2Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton2Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton3Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton3Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton4Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton4Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton5Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton5Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton6Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton6Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton7Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton7Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton8Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void FaceButton8Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void Grip1Axis(float AxisValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void Grip1Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void Grip1Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void Grip2Axis(float AxisValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void Grip2Pressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void Grip2Released();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ShoulderPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ShoulderReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickDownPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickDownReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickLeftPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickLeftReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickRightPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickRightReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickUpPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickUpReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickX(float AxisValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void ThumbstickY(float AxisValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void TriggerPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void TriggerReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VR|Interactions")
		void TriggerAxis(float AxisValue);
	// END copy-paste

};
