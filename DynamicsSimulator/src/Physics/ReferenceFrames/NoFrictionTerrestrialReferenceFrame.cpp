#include "NoFrictionTerrestrialReferenceFrame.h"

#include <iostream>

NoFrictionTerrestrialReferenceFrame::NoFrictionTerrestrialReferenceFrame()
	: m_IntensityOfGravity(9.81), m_AngleOfGravity(-90) {
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

void NoFrictionTerrestrialReferenceFrame::UpdateObjects(double deltaTime) {
	for (ObjectAndForces& objectAndForces : m_ObjectsInReferenceFrame) {
		MovableObject& Object = std::get<0>(objectAndForces);
		std::vector<Force> Forces = std::get<1>(objectAndForces);
		Force SumOfForces(0, 0);

		// Computing the sum of forces
		for (Force &force : Forces) {
			SumOfForces += force;
		}

		// Computing position, speed and acceleration of the object
		Object.SetPosition(Object.GetPosition() + Object.GetSpeed() * deltaTime * 0.001);
		Object.SetSpeed(Object.GetSpeed() + Object.GetAcceleration() * deltaTime * 0.001);
		Object.SetAcceleration(SumOfForces / Object.Mass);
	}
}

