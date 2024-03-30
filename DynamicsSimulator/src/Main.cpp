#include <iostream>
#include <chrono>
#include <iostream>
#include <fstream>
#include <map>

#ifdef ENABLE_SFML
#include <SFML/Graphics.hpp>
#endif

#include "DynamicsSimulator.h"
#include "Physics/Physics.h"
#include "Scene.h"
#include "Display/Widget.h"


int main(int argc, char* argv[]) {
	std::cout << "Welcome to DynamicsSimulator" << std::endl;

	const char* OutputFile;
	if (argc > 1) 
		OutputFile = argv[1];
	else
		OutputFile = "output.csv";

	float mass;
	std::cout << "Object Mass (kg): ";
	std::cin >> mass;

	float initialHeight;
	std::cout << "Initial Height (m): ";
	std::cin >> initialHeight;

	float initialSpeed;
	std::cout << "Initial Speed (m/s): ";
	std::cin >> initialSpeed;

	float initialAngle;
	std::cout << "Initial Angle (deg): ";
	std::cin >> initialAngle;

	float SCALE;
	std::cout << "Scale (px / m): ";
	std::cin >> SCALE;

	float CUBE_SIDE;
	std::cout << "Cube dimensions (m): ";
	std::cin >> CUBE_SIDE;

	// Setting up SFML
	unsigned int WIDTH = 1920u;
	unsigned int HEIGHT = 1080u;
	Scene SimulationScene(WIDTH, HEIGHT, "DynamicsSimulator", 170u);


#ifdef ENABLE_SFML
	  // Moving object
	sf::RectangleShape ObjectGraphics(Vector2D(CUBE_SIDE * SCALE, CUBE_SIDE * SCALE));
	ObjectGraphics.setFillColor(sf::Color::Yellow);
	MovableObject Object(0.0f, initialHeight, mass, Force(initialSpeed, initialAngle), Hitbox(), ObjectGraphics, ObjectGraphics);
	SimulationScene.AddMovingDrawable(Object);
	  // Floor
	sf::RectangleShape FloorGraphics(Vector2D(WIDTH, 50.0f));
	FloorGraphics.setFillColor(sf::Color(10, 130, 50));
	Widget Floor(FloorGraphics, Vector2D(0.0f, HEIGHT-50.0f));
	  // Scale reference
	sf::RectangleShape ScaleReferenceGraphics(Vector2D(SCALE, SCALE));
	ScaleReferenceGraphics.setFillColor(sf::Color::Red);
	Widget ScaleReference(ScaleReferenceGraphics, Vector2D(0.0f, HEIGHT - 50.0f - SCALE));
	SimulationScene.AddStaticDrawable(ScaleReference);
#else
	GraphicsAndTransform graphicsAndTransform;
	MovableObject Object(0.0f, initialHeight, mass, Force(initialSpeed, initialAngle), Hitbox(), graphicsAndTransform, graphicsAndTransform);
#endif

	// Setting up dynamics
	NoFrictionTerrestrialReferenceFrame ReferenceFrame;
	ReferenceFrame.AddObject(Object);

	// Setting up output
	std::ofstream output;
	output.open(OutputFile);

	// Main loop
	while (SimulationScene.IsRunning()) {

		// Physics update
		if (SimulationScene.GetDeltaTimeMs() > 5 && Object.Position.y > 0) {
			int64_t timeElapsed = SimulationScene.ResetDeltaTime();
			ReferenceFrame.UpdateObjects(timeElapsed);
			std::cout << "dt: " << SimulationScene.GetAbsoluteTimeMs() << " " << Object.Position << "\t\ts: " << Object.Speed << "\t\ta: " << Object.Acceleration << std::endl;
			output << SimulationScene.GetAbsoluteTimeMs() << "," << Object.Position.x << "," << Object.Position.y << ",\n";
		}

		SimulationScene.UpdateScene();
	}

	output.close();

	return 0;
}