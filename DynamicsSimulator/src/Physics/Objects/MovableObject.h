#pragma once
#include "DynamicsSimulator.h"

#include "Hitbox.h"
#include "Display/Graphics.h"
#include "Physics/Vector/Vector2D.h"

struct MovableObject : IDrawable, ITransformable {
	Vector2D Position, Speed, Acceleration;
	float Mass;
	Hitbox ObjectHitbox;
	Graphics* ObjectGraphics;
	GraphicsTransform* ObjectGraphicsTransform;

	MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox);
	MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox, Graphics& ObjectGraphics);
	MovableObject(float X, float Y, float Mass, Vector2D InitialSpeed, Hitbox ObjectHitbox, Graphics& ObjectGraphics, GraphicsTransform& ObjectGraphicsTransform);
#ifdef COPY_CONSTRUCTOR
	MovableObject(const MovableObject& _mo);
#endif
	Graphics* GetObjectGraphics() override;
	GraphicsTransform* GetObjectGraphicsTransform() override;
	Vector2D* GetPosition() override;
};

