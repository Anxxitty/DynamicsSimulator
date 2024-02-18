#pragma once
#include "../../DynamicsSimulator.h"

#include "ReferenceFrame.h"

class NoFrictionTerrestrialReferenceFrame : public ReferenceFrame {
private:
	float m_IntensityOfGravity;
	float m_AngleOfGravity;
public:
	NoFrictionTerrestrialReferenceFrame();
#ifdef COPY_CONSTRUCTOR
	NoFrictionTerrestrialReferenceFrame(const NoFrictionTerrestrialReferenceFrame& _trf);
#endif
	void AddObject(MovableObject& Object) override;
	void UpdateObjects(uint64_t deltaTime) override;
};