# VRInteractions
A flexible platform for making interactive VR objects in Unreal Engine 4.

## Why?
Setting up basic VR object interactions in Unreal Engine 4 usually requires a lot of boilerplate Blueprint code. There are also tricky situations to handle, like grabbing an object out of your other hand versus picking it up off the ground. And how do you make sure the object you're holding in your right hand can receive input events from the right controller and not the left?

VRInteractions solves all of these issues with a single engine plugin. It provides three classes that your Blueprints can extend: `Hand`, `Grabbable`, and `Interactable`.

## Hand
A `Hand` is an Actor which is intended to be attached to a Motion Controller Component. Each `Hand` does the following:

- Handle the grabbing and dropping of `Grabbables` and `Interactables`
- Pass input events from the motion controller along to the current `Grabbable` or `Interactable`

The `Hand` provides a layer between the controller and the object that lets your objects not worry which hand is holding them.

## Grabbable
A `Grabbable` is an Actor that can be picked up and dropped. Whenever a `Grabbable` is grabbed, it is attached to the hand that grabbed it, so `Grabbables` are usually physics objects that the player can pick up and inspect.

There are four major events that happen in a `Grabbable`'s lifecycle:

- `BeforeGrab`, which fires immediately before the object is grabbed
- `AfterGrab`, which fires immediately after the object is grabbed
- `BeforeDrop`, which fires immediately before the object is dropped
- `AfterDrop`, which fires immediately after the object is dropped

Each of these are Blueprint functions that can be overridden by subclasses of `Grabbable`.

Whenever a `Grabbable` is being held, it receives input events from the `Hand` that is holding it. The `Hand` will not drop the object until it is told to, so `Grabbables` often listen for a particular input event and then tell their `Hand` to drop them.

## Interactable
An `Interactable` is an Actor that is intended to receive inputs from a `Hand` without being picked up. An `Interactable` might be a drawer, a doorknob, or that awesome Xortex arcade joystick from The Lab that lets you play Breakout with the credits.

There are two major events that happen in an `Interactable`'s lifecycle:

- `Grabbed`, which fires immediately after the object is grabbed
- `Released`, which fires immediately *before* the object is completely released and all the variables are unset.

When an `Interactable` is currently active, it receives input events from the `Hand` that grabbed it.

## Examples
Someday...
