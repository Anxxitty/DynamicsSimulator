#include <iostream>
#include <chrono>
#include <iostream>
#include <fstream>

#include "Physics/Physics.h"

int64_t GetTimeMs() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


int main(int argc, char* argv[]) {
	std::cout << "Welcome to DynamicsSimulator" << std::endl;

	const char* OutputFile;
	if (argc > 0) 
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

	NoFrictionTerrestrialReferenceFrame ReferenceFrame;
	MovableObject Object(0.0, initialHeight, mass, Force(initialSpeed, initialAngle), Hitbox(), Graphics());
	ReferenceFrame.AddObject(Object);
	int64_t initialTimestamp = GetTimeMs();
	int64_t previousTimestamp = GetTimeMs();
	std::ofstream output;
	output.open(OutputFile);

	while (Object.Position.y >= 0.0f) {
		int64_t deltaTime = GetTimeMs() - previousTimestamp;
		if (deltaTime > 5) {
			previousTimestamp = GetTimeMs();
			ReferenceFrame.UpdateObjects(deltaTime);
			std::cout << "dt: " << GetTimeMs() - initialTimestamp << " " << Object.Position << "\t\ts: " << Object.Speed << "\t\ta: " << Object.Acceleration << std::endl;
			output << GetTimeMs() - initialTimestamp << "," << Object.Position.x << "," << Object.Position.y << ",\n";
		}
	}

	output.close();



	return 0;
}