#pragma once

#include <vector>
#include <tuple>

#include "../Force/Force.h"
#include "../Objects/MovableObject.h"

class ReferenceFrame {
protected:
	typedef std::tuple<MovableObject&, std::vector<Force>> ObjectAndForces ;
	std::vector<ObjectAndForces> m_ObjectsInReferenceFrame;
	ReferenceFrame();
	ReferenceFrame(std::vector<ObjectAndForces> ObjectsInReferenceFrame);

public:
	virtual void AddObject(MovableObject& MovableObject) = 0;
	// TODO: GetObjects and RemoveObject
	virtual void UpdateObjects(uint64_t deltaTime) = 0;
};