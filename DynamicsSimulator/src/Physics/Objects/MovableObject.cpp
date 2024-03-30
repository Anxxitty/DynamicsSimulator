#include "MovableObject.h"

#include <iostream>


MovableObject::MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox)
	: Position(X, Y), Speed(0, 0), Acceleration(0, 0), Mass(Mass), ObjectHitbox(ObjectHitbox), ObjectGraphics(), ObjectGraphicsTransform() {
#ifdef CONSTRUCTOR
	std::cout << "Created a MovableObject" << std::endl;
#endif
}

MovableObject::MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox, Graphics& ObjectGraphics)
	: Position(X, Y), Speed(0, 0), Acceleration(0, 0), Mass(Mass), ObjectHitbox(ObjectHitbox), ObjectGraphics(&ObjectGraphics), ObjectGraphicsTransform(dynamic_cast<GraphicsTransform*>(&ObjectGraphics)) {
#ifdef CONSTRUCTOR
	std::cout << "Created a MovableObject" << std::endl;
#endif
}

MovableObject::MovableObject(float X, float Y, float Mass, Vector2D InitialSpeed, Hitbox ObjectHitbox, Graphics& ObjectGraphics, GraphicsTransform& ObjectGraphicsTransform)
	: Position(X, Y), Speed(InitialSpeed), Acceleration(0, 0), Mass(Mass), ObjectHitbox(ObjectHitbox), ObjectGraphics(&ObjectGraphics), ObjectGraphicsTransform(&ObjectGraphicsTransform) {
#ifdef CONSTRUCTOR
	std::cout << "Created a MovableObject" << std::endl;
#endif
}

#ifdef COPY_CONSTRUCTOR
MovableObject::MovableObject(const MovableObject& _mo) 
	: Position(_mo.Position), Speed(_mo.Speed), Acceleration(_mo.Acceleration), Mass(_mo.Mass), ObjectHitbox(_mo.ObjectHitbox), ObjectGraphics(_mo.ObjectGraphics), ObjectGraphicsTransform(_mo.ObjectGraphicsTransform) {
	std::cout << "Copy-Created a MovableObject" << std::endl;
}
#endif

Graphics* MovableObject::GetObjectGraphics() {
	return ObjectGraphics;
}

GraphicsTransform* MovableObject::GetObjectGraphicsTransform() {
	return ObjectGraphicsTransform;
}

Vector2D* MovableObject::GetPosition() {
	return &Position;
}

