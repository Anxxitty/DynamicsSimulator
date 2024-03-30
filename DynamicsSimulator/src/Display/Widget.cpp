#include "Widget.h"

#include <iostream>

Widget::Widget()
	: ObjectGraphics() {
#ifdef CONSTRUCTOR
	std::cout << "Created a Widget Class" << std::endl;
#endif
}

Widget::Widget(Graphics& ObjectGraphics, Vector2D Position)
	: ObjectGraphics(&ObjectGraphics) {
#ifdef ENABLE_SFML
	dynamic_cast<GraphicsTransform*>(&ObjectGraphics)->setPosition(Position);
#endif
#ifdef CONSTRUCTOR
	std::cout << "Created a Widget Class" << std::endl;
#endif
}

Graphics* Widget::GetObjectGraphics() {
	return ObjectGraphics;
}
