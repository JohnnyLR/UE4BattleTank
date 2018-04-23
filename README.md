# UE4BattleTank
UE4 game with simple terrain, AI and advanced control system.

---
## Lecture List
* 01 Intro, Notes & Assets
* 02 open world terrain created with a heightmap and flat textured layers from high resolution landscape
* 03 created azimuth gimbal on tank, main menu and player ui
* 04 new c++ Tank Pawn class, Player and AI Controller classes linked to its blueprints
* 05 get ScreenLocation, LookDirection, HitLocation and BarrelLocation in new c++ TankAiming Actor Component class
* 06 new c++ Barrel Static Mesh Component class replacement to animate pitch. Important, aim solution SuggestProjectilVelocity parameters, and remove tick from Tank.cpp
* 07 new c++ Turret Static Mesh Component class replacement to animate yaw. Important, hide category collision causes physics colapse, and remove tick from TankAimingComponent.cpp
* 08 new c++ Projectile Actor class, Track Static Mesh Component class and Nav Movement Component class to move forward and turn right on axis. Problem Barrel and Turret collision meshes, set to notCollision
* 09 created AI movement and code refactored
* 10 changed game architecture and code refactoring from green
* 11 change ability of player crosshair UI color and applied Hit on ground forces on Tracks
* 12 more few corrections, fire rounds limit, new Mortar Pawn Blueprint and deleted StartContent assets
* 13 new Particle System Components, Radial Force component, Health Bar UI, Declared Dynamic Multicast Delegate, Detach From and Start Spectating on death and FP camera