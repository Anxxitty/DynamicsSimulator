#pragma once
#include "DynamicsSimulator.h"
#include "Physics/Vector/Vector2D.h"
#include "Display/Graphics.h"

struct Widget : IDrawable {
	Graphics* ObjectGraphics;
	Widget();
	Widget(Graphics& ObjectGraphics, Vector2D Position);
	Graphics* GetObjectGraphics() override;
};
