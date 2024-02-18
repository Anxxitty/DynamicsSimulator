#include "NoFrictionTerrestrialReferenceFrame.h"

#include <iostream>

NoFrictionTerrestrialReferenceFrame::NoFrictionTerrestrialReferenceFrame()
	: m_IntensityOfGravity(9.81f), m_AngleOfGravity(-90) {
#ifdef CONSTRUCTOR
	std::cout << "Created a No Friction Terrestrial Reference Frame" << std::endl;
#endif
}

#ifdef COPY_CONSTRUCTOR
NoFrictionTerrestrialReferenceFrame::NoFrictionTerrestrialReferenceFrame(const NoFrictionTerrestrialReferenceFrame& _trf) 
	: ReferenceFrame(_trf.m_ObjectsInReferenceFrame), m_IntensityOfGravity(_trf.m_IntensityOfGravity), m_AngleOfGravity(_trf.m_AngleOfGravity) {
	std::cout << "Copy-Created a No Friction Terrestrial Reference Frame" << std::endl;
}
#endif

void NoFrictionTerrestrialReferenceFrame::AddObject(MovableObject& Object) {
	m_ObjectsInReferenceFrame.push_back( ObjectAndForces(Object, std::vector<Force>{Force(Object.Mass * m_IntensityOfGravity, m_AngleOfGravity)}) );
}

void NoFrictionTerrestrialReferenceFrame::UpdateObjects(int64_t deltaTime) {
	for (ObjectAndForces& objectAndForces : m_ObjectsInReferenceFrame) {
		MovableObject& Object = std::get<0>(objectAndForces);
		std::vector<Force> Forces = std::get<1>(objectAndForces);
		Force SumOfForces(0, 0);
		const float fixedDeltaTime = static_cast<float>(deltaTime);

		// Computing the sum of forces
		for (Force &force : Forces) {
			SumOfForces += force;
		}

		// Computing position, speed and acceleration of the object
		Object.Position += Object.Speed * fixedDeltaTime * 0.001f;
		Object.Speed += Object.Acceleration * fixedDeltaTime * 0.001f;
		Object.Acceleration = SumOfForces / Object.Mass;
	}
}

NoFrictionTerrestrialReferenceFrame::~NoFrictionTerrestrialReferenceFrame() {}

