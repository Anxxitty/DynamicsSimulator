#pragma once
#include "DynamicsSimulator.h"
#include "Physics/Vector/Vector2D.h"

#ifdef ENABLE_SFML
#include "SFML/Graphics.hpp"
typedef sf::Drawable Graphics;
typedef sf::Transformable GraphicsTransform;
#else
struct Graphics {
	virtual ~Graphics() {}
};
struct GraphicsTransform {
	virtual ~GraphicsTransform() {}
};
struct GraphicsAndTransform : Graphics, GraphicsTransform {
};
#endif

struct IDrawable {
	virtual ~IDrawable() {}
	virtual Graphics* GetObjectGraphics() = 0;
};

struct ITransformable {
	virtual ~ITransformable() {}
	virtual GraphicsTransform* GetObjectGraphicsTransform() = 0;
	virtual Vector2D* GetPosition() = 0;
};