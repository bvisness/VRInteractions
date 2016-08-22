

// Fill out your copyright notice in the Description page of Project Settings.

#include "VRInteractionsPrivatePCH.h"

#include "Hand.h"

UHand::UHand()
{
	// No default values to set right now
}

void UHand::BeginPlay()
{
	/* We are not doing automatic input binding for now since it's super weird

	// InputComponent = NewObject<UInputComponent>();
	InputComponent = Cast<APawn>(GetOwner())->InputComponent;

	if (!InputComponent) {
		UE_LOG(LogTemp, Error, TEXT("Could not get input component for hand! (Name: %s)"), *GetName());
		return;
	}

	InputComponent->bBlockInput = false;
	// BEGIN copy-paste from autogen_result.txt
	if (MotionController->Hand == EControllerHand::Left) {
		UE_LOG(LogTemp, Warning, TEXT("Binding stuff for the left hand"));
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton1, EInputEvent::IE_Pressed, this, &UHand::FaceButton1Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton1, EInputEvent::IE_Released, this, &UHand::FaceButton1Released);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton2, EInputEvent::IE_Pressed, this, &UHand::FaceButton2Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton2, EInputEvent::IE_Released, this, &UHand::FaceButton2Released);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton3, EInputEvent::IE_Pressed, this, &UHand::FaceButton3Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton3, EInputEvent::IE_Released, this, &UHand::FaceButton3Released);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton4, EInputEvent::IE_Pressed, this, &UHand::FaceButton4Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton4, EInputEvent::IE_Released, this, &UHand::FaceButton4Released);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton5, EInputEvent::IE_Pressed, this, &UHand::FaceButton5Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton5, EInputEvent::IE_Released, this, &UHand::FaceButton5Released);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton6, EInputEvent::IE_Pressed, this, &UHand::FaceButton6Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton6, EInputEvent::IE_Released, this, &UHand::FaceButton6Released);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton7, EInputEvent::IE_Pressed, this, &UHand::FaceButton7Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton7, EInputEvent::IE_Released, this, &UHand::FaceButton7Released);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton8, EInputEvent::IE_Pressed, this, &UHand::FaceButton8Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_FaceButton8, EInputEvent::IE_Released, this, &UHand::FaceButton8Released);
		InputComponent->BindAxisKey(EKeys::MotionController_Left_Grip1Axis, this, &UHand::Grip1Axis);
		InputComponent->BindKey(EKeys::MotionController_Left_Grip1, EInputEvent::IE_Pressed, this, &UHand::Grip1Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Grip1, EInputEvent::IE_Released, this, &UHand::Grip1Released);
		InputComponent->BindAxisKey(EKeys::MotionController_Left_Grip2Axis, this, &UHand::Grip2Axis);
		InputComponent->BindKey(EKeys::MotionController_Left_Grip2, EInputEvent::IE_Pressed, this, &UHand::Grip2Pressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Grip2, EInputEvent::IE_Released, this, &UHand::Grip2Released);
		InputComponent->BindKey(EKeys::MotionController_Left_Shoulder, EInputEvent::IE_Pressed, this, &UHand::ShoulderPressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Shoulder, EInputEvent::IE_Released, this, &UHand::ShoulderReleased);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick, EInputEvent::IE_Pressed, this, &UHand::ThumbstickPressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick, EInputEvent::IE_Released, this, &UHand::ThumbstickReleased);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Down, EInputEvent::IE_Pressed, this, &UHand::ThumbstickDownPressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Down, EInputEvent::IE_Released, this, &UHand::ThumbstickDownReleased);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Left, EInputEvent::IE_Pressed, this, &UHand::ThumbstickLeftPressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Left, EInputEvent::IE_Released, this, &UHand::ThumbstickLeftReleased);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Right, EInputEvent::IE_Pressed, this, &UHand::ThumbstickRightPressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Right, EInputEvent::IE_Released, this, &UHand::ThumbstickRightReleased);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Up, EInputEvent::IE_Pressed, this, &UHand::ThumbstickUpPressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Thumbstick_Up, EInputEvent::IE_Released, this, &UHand::ThumbstickUpReleased);
		InputComponent->BindAxisKey(EKeys::MotionController_Left_Thumbstick_X, this, &UHand::ThumbstickX);
		InputComponent->BindAxisKey(EKeys::MotionController_Left_Thumbstick_Y, this, &UHand::ThumbstickY);
		InputComponent->BindKey(EKeys::MotionController_Left_Trigger, EInputEvent::IE_Pressed, this, &UHand::TriggerPressed);
		InputComponent->BindKey(EKeys::MotionController_Left_Trigger, EInputEvent::IE_Released, this, &UHand::TriggerReleased);
		InputComponent->BindAxisKey(EKeys::MotionController_Left_TriggerAxis, this, &UHand::TriggerAxis);
	} else if (MotionController->Hand == EControllerHand::Right) {
		UE_LOG(LogTemp, Warning, TEXT("Binding stuff for the right hand"));
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton1, EInputEvent::IE_Pressed, this, &UHand::FaceButton1Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton1, EInputEvent::IE_Released, this, &UHand::FaceButton1Released);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton2, EInputEvent::IE_Pressed, this, &UHand::FaceButton2Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton2, EInputEvent::IE_Released, this, &UHand::FaceButton2Released);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton3, EInputEvent::IE_Pressed, this, &UHand::FaceButton3Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton3, EInputEvent::IE_Released, this, &UHand::FaceButton3Released);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton4, EInputEvent::IE_Pressed, this, &UHand::FaceButton4Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton4, EInputEvent::IE_Released, this, &UHand::FaceButton4Released);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton5, EInputEvent::IE_Pressed, this, &UHand::FaceButton5Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton5, EInputEvent::IE_Released, this, &UHand::FaceButton5Released);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton6, EInputEvent::IE_Pressed, this, &UHand::FaceButton6Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton6, EInputEvent::IE_Released, this, &UHand::FaceButton6Released);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton7, EInputEvent::IE_Pressed, this, &UHand::FaceButton7Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton7, EInputEvent::IE_Released, this, &UHand::FaceButton7Released);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton8, EInputEvent::IE_Pressed, this, &UHand::FaceButton8Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_FaceButton8, EInputEvent::IE_Released, this, &UHand::FaceButton8Released);
		InputComponent->BindAxisKey(EKeys::MotionController_Right_Grip1Axis, this, &UHand::Grip1Axis);
		InputComponent->BindKey(EKeys::MotionController_Right_Grip1, EInputEvent::IE_Pressed, this, &UHand::Grip1Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Grip1, EInputEvent::IE_Released, this, &UHand::Grip1Released);
		InputComponent->BindAxisKey(EKeys::MotionController_Right_Grip2Axis, this, &UHand::Grip2Axis);
		InputComponent->BindKey(EKeys::MotionController_Right_Grip2, EInputEvent::IE_Pressed, this, &UHand::Grip2Pressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Grip2, EInputEvent::IE_Released, this, &UHand::Grip2Released);
		InputComponent->BindKey(EKeys::MotionController_Right_Shoulder, EInputEvent::IE_Pressed, this, &UHand::ShoulderPressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Shoulder, EInputEvent::IE_Released, this, &UHand::ShoulderReleased);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick, EInputEvent::IE_Pressed, this, &UHand::ThumbstickPressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick, EInputEvent::IE_Released, this, &UHand::ThumbstickReleased);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Down, EInputEvent::IE_Pressed, this, &UHand::ThumbstickDownPressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Down, EInputEvent::IE_Released, this, &UHand::ThumbstickDownReleased);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Left, EInputEvent::IE_Pressed, this, &UHand::ThumbstickLeftPressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Left, EInputEvent::IE_Released, this, &UHand::ThumbstickLeftReleased);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Right, EInputEvent::IE_Pressed, this, &UHand::ThumbstickRightPressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Right, EInputEvent::IE_Released, this, &UHand::ThumbstickRightReleased);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Up, EInputEvent::IE_Pressed, this, &UHand::ThumbstickUpPressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Thumbstick_Up, EInputEvent::IE_Released, this, &UHand::ThumbstickUpReleased);
		InputComponent->BindAxisKey(EKeys::MotionController_Right_Thumbstick_X, this, &UHand::ThumbstickX);
		InputComponent->BindAxisKey(EKeys::MotionController_Right_Thumbstick_Y, this, &UHand::ThumbstickY);
		InputComponent->BindKey(EKeys::MotionController_Right_Trigger, EInputEvent::IE_Pressed, this, &UHand::TriggerPressed);
		InputComponent->BindKey(EKeys::MotionController_Right_Trigger, EInputEvent::IE_Released, this, &UHand::TriggerReleased);
		InputComponent->BindAxisKey(EKeys::MotionController_Right_TriggerAxis, this, &UHand::TriggerAxis);
	}
	// END copy-paste

	//GetWorld()->GetFirstPlayerController()->PushInputComponent(InputComponent);

	*/
}

AActor* UHand::ClosestActorToLocation(FVector Location, TArray<AActor*> Actors, TArray<AActor*> Exclude)
{
	if (Actors.Num() == 0) {
		return nullptr;
	}
	if (Actors.Num() == 1) {
		if (Exclude.Contains(Actors[0])) {
			return nullptr;
		}
		return Actors[0];
	}

	AActor* closestActor = nullptr;
	float shortestDistance = MAX_FLT;
	for (auto& actor : Actors) {
		if (Exclude.Contains(actor)) {
			continue;
		}

		FVector vectorToLocation = actor->GetActorLocation() - Location;
		float thisDistance = vectorToLocation.SizeSquared();
		if (thisDistance < shortestDistance) {
			closestActor = actor;
			shortestDistance = thisDistance;
		}
	}

	return closestActor;
}

AActor* UHand::ClosestActorToComponent(USceneComponent* component, TArray<AActor*> Actors, TArray<AActor*> Exclude)
{
	return ClosestActorToLocation(component->GetComponentLocation(), Actors, Exclude);
}

bool UHand::TryToGrab()
{
	// Get overlapping grabbable actors
	TArray<AActor*> grabbableOverlappingActors;
	GrabCollision->GetOverlappingActors(grabbableOverlappingActors, AGrabbable::StaticClass());
	UE_LOG(LogTemp, Log, TEXT("There are %d overlapping grabbable actors!"), grabbableOverlappingActors.Num());

	TArray<AActor*> grabbableExclude;
	if (Grabbed->IsValidLowLevel()) {
		grabbableExclude.Add(Grabbed);
	}
	
	AActor* closestGrabbableActor = ClosestActorToComponent(GrabCollision, grabbableOverlappingActors, grabbableExclude);
	UE_LOG(LogTemp, Log, TEXT("The closest grabbable actor has pointer %p"), closestGrabbableActor);

	if (closestGrabbableActor->IsValidLowLevel()) {
		// We can grab a grabbable
		AGrabbable* grabbedAsGrabbable = Cast<AGrabbable>(closestGrabbableActor);
		UE_LOG(LogTemp, Log, TEXT("About to run GrabGrabbable"));
		GrabGrabbable(grabbedAsGrabbable);
		return true;
	}

	// Try to grab an interactable instead

	TArray<AActor*> interactableOverlappingActors;
	GrabCollision->GetOverlappingActors(interactableOverlappingActors, AInteractable::StaticClass());
	UE_LOG(LogTemp, Log, TEXT("There are %d overlapping interactable actors!"), interactableOverlappingActors.Num());

	TArray<AActor*> interactableExclude; // we leave this empty

	AActor* closestInteractableActor = ClosestActorToComponent(GrabCollision, interactableOverlappingActors, interactableExclude);
	UE_LOG(LogTemp, Log, TEXT("The closest interactable actor has pointer %p"), closestInteractableActor);

	if (closestInteractableActor->IsValidLowLevel()) {
		// We can grab an interactable
		AInteractable* grabbedAsInteractable = Cast<AInteractable>(closestInteractableActor);
		UE_LOG(LogTemp, Log, TEXT("About to run GrabInteractable"));
		GrabInteractable(grabbedAsInteractable);
		return true;
	}

	// Didn't grab anything

	return false;
}

void UHand::GrabGrabbable(AGrabbable* GrabbableObject)
{
	// If we are carrying something, drop it
	if (Grabbed->IsValidLowLevel()) {
		DropGrabbed();
	}

	// If it is already grabbed, tell the other hand to drop it
	if (GrabbableObject->Hand->IsValidLowLevel()) {
		GrabbableObject->Hand->DropGrabbed();
	}

	// Grab it!

	GrabbableObject->BeforeGrab();

	FAttachmentTransformRules attachRules = FAttachmentTransformRules(
		EAttachmentRule::KeepWorld,
		EAttachmentRule::KeepWorld,
		EAttachmentRule::KeepWorld,
		true
	);
	GrabbableObject->AttachToComponent(this, attachRules);
	
	GrabbableObject->Hand = this;
	Grabbed = GrabbableObject;
	
	GrabbableObject->AfterGrab();
}

void UHand::GrabInteractable(AInteractable* InteractableObject)
{
	// If held by other hand, tell the other hand to release it
	if (InteractableObject->Hand->IsValidLowLevel()) {
		InteractableObject->Hand->ReleaseInteractable();
	}

	// Grab it!

	InteractableObject->Hand = this;
	this->Interacting = InteractableObject;

	InteractableObject->Grabbed();

	if (Grabbed->IsValidLowLevel()) {
		Grabbed->Hide();
	}
}

void UHand::DropGrabbed()
{
	// Return early if nothing to drop
	if (!Grabbed->IsValidLowLevel()) {
		return;
	}

	Grabbed->BeforeDrop();

	FDetachmentTransformRules detachRules = FDetachmentTransformRules(
		EDetachmentRule::KeepWorld,
		EDetachmentRule::KeepWorld,
		EDetachmentRule::KeepWorld,
		true
	);
	Grabbed->DetachFromActor(detachRules);

	Grabbed->Hand = nullptr;

	Grabbed->AfterDrop();

	Grabbed = nullptr;
}

void UHand::ReleaseInteractable()
{
	// Return early if nothing to drop
	if (!Interacting->IsValidLowLevel()) {
		return;
	}

	Interacting->Released();

	Interacting->Hand = nullptr;
	Interacting = nullptr;

	if (Grabbed->IsValidLowLevel()) {
		Grabbed->Show();
	}
}

//
// Motion Controller Events "Interface"
//

// BEGIN copy-paste from autogen_result.txt
void UHand::FaceButton1Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton1Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton1Pressed();
	}
}

void UHand::FaceButton1Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton1Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton1Released();
	}
}

void UHand::FaceButton2Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton2Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton2Pressed();
	}
}

void UHand::FaceButton2Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton2Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton2Released();
	}
}

void UHand::FaceButton3Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton3Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton3Pressed();
	}
}

void UHand::FaceButton3Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton3Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton3Released();
	}
}

void UHand::FaceButton4Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton4Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton4Pressed();
	}
}

void UHand::FaceButton4Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton4Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton4Released();
	}
}

void UHand::FaceButton5Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton5Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton5Pressed();
	}
}

void UHand::FaceButton5Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton5Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton5Released();
	}
}

void UHand::FaceButton6Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton6Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton6Pressed();
	}
}

void UHand::FaceButton6Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton6Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton6Released();
	}
}

void UHand::FaceButton7Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton7Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton7Pressed();
	}
}

void UHand::FaceButton7Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton7Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton7Released();
	}
}

void UHand::FaceButton8Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton8Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton8Pressed();
	}
}

void UHand::FaceButton8Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->FaceButton8Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->FaceButton8Released();
	}
}

void UHand::Grip1Axis_Implementation(float AxisValue) {
	if (Interacting->IsValidLowLevel()) {
		Interacting->Grip1Axis(AxisValue);
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->Grip1Axis(AxisValue);
	}
}

void UHand::Grip1Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->Grip1Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->Grip1Pressed();
	}
}

void UHand::Grip1Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->Grip1Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->Grip1Released();
	}
}

void UHand::Grip2Axis_Implementation(float AxisValue) {
	if (Interacting->IsValidLowLevel()) {
		Interacting->Grip2Axis(AxisValue);
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->Grip2Axis(AxisValue);
	}
}

void UHand::Grip2Pressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->Grip2Pressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->Grip2Pressed();
	}
}

void UHand::Grip2Released_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->Grip2Released();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->Grip2Released();
	}
}

void UHand::ShoulderPressed_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("Shoulder pressed!"));
	if (Interacting->IsValidLowLevel()) {
		Interacting->ShoulderPressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ShoulderPressed();
	}
}

void UHand::ShoulderReleased_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ShoulderReleased();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ShoulderReleased();
	}
}

void UHand::ThumbstickPressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickPressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickPressed();
	}
}

void UHand::ThumbstickReleased_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickReleased();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickReleased();
	}
}

void UHand::ThumbstickDownPressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickDownPressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickDownPressed();
	}
}

void UHand::ThumbstickDownReleased_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickDownReleased();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickDownReleased();
	}
}

void UHand::ThumbstickLeftPressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickLeftPressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickLeftPressed();
	}
}

void UHand::ThumbstickLeftReleased_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickLeftReleased();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickLeftReleased();
	}
}

void UHand::ThumbstickRightPressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickRightPressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickRightPressed();
	}
}

void UHand::ThumbstickRightReleased_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickRightReleased();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickRightReleased();
	}
}

void UHand::ThumbstickUpPressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickUpPressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickUpPressed();
	}
}

void UHand::ThumbstickUpReleased_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickUpReleased();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickUpReleased();
	}
}

void UHand::ThumbstickX_Implementation(float AxisValue) {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickX(AxisValue);
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickX(AxisValue);
	}
}

void UHand::ThumbstickY_Implementation(float AxisValue) {
	if (Interacting->IsValidLowLevel()) {
		Interacting->ThumbstickY(AxisValue);
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->ThumbstickY(AxisValue);
	}
}

void UHand::TriggerPressed_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->TriggerPressed();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->TriggerPressed();
	}
}

void UHand::TriggerReleased_Implementation() {
	if (Interacting->IsValidLowLevel()) {
		Interacting->TriggerReleased();
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->TriggerReleased();
	}
}

void UHand::TriggerAxis_Implementation(float AxisValue) {
	if (Interacting->IsValidLowLevel()) {
		Interacting->TriggerAxis(AxisValue);
	} else if (Grabbed->IsValidLowLevel()) {
		Grabbed->TriggerAxis(AxisValue);
	}
}
// END copy-paste
