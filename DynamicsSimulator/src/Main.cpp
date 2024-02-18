#include <iostream>
#include <chrono>
#include <iostream>
#include <fstream>

#include "Physics/Physics.h"

int GetTimeMs() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


int main() {
	std::cout << "Welcome to DynamicsSimulator" << std::endl;

	double mass;
	std::cout << "Object Mass (kg): ";
	std::cin >> mass;

	double initialHeight;
	std::cout << "Initial Height (m): ";
	std::cin >> initialHeight;

	double initialSpeed;
	std::cout << "Initial Speed (m/s): ";
	std::cin >> initialSpeed;

	double initialAngle;
	std::cout << "Initial Angle (deg): ";
	std::cin >> initialAngle;

	NoFrictionTerrestrialReferenceFrame ReferenceFrame;
	MovableObject Object(0.0, initialHeight, mass, Force(initialSpeed, initialAngle), Hitbox(), Graphics());
	ReferenceFrame.AddObject(Object);
	std::time_t initialTimestamp = GetTimeMs();
	std::time_t previousTimestamp = GetTimeMs();
	std::ofstream output;
	output.open("output.csv");

	while (Object.GetPosition().y >= 0.0f) {
		int deltaTime = GetTimeMs() - previousTimestamp;
		if (deltaTime > 5) {
			previousTimestamp = GetTimeMs();
			ReferenceFrame.UpdateObjects(deltaTime);
			std::cout << "dt: " << GetTimeMs() - initialTimestamp << " " << Object.GetPosition() << "\t\ts: " << Object.GetSpeed() << "\t\ta: " << Object.GetAcceleration() << std::endl;
			output << GetTimeMs() - initialTimestamp << "," << Object.GetPosition().x << "," << Object.GetPosition().y << ",\n";
		}
	}

	output.close();



	return 0;
}