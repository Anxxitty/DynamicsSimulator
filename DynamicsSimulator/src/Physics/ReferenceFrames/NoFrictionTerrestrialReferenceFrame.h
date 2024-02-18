#pragma once
#include "../../DynamicsSimulator.h"

#include "ReferenceFrame.h"

class NoFrictionTerrestrialReferenceFrame : public ReferenceFrame {
private:
	double m_IntensityOfGravity;
	double m_AngleOfGravity;
public:
	NoFrictionTerrestrialReferenceFrame();
#ifdef COPY_CONSTRUCTOR
	NoFrictionTerrestrialReferenceFrame(const NoFrictionTerrestrialReferenceFrame& _trf);
#endif
	void AddObject(MovableObject& Object) override;
	void UpdateObjects(double deltaTime) override;
};