#pragma once
#include "DynamicsSimulator.h"

#include <vector>
#include <tuple>

#include "Physics/Force/Force.h"
#include "Physics/Objects/MovableObject.h"

class ReferenceFrame {
protected:
	typedef std::tuple<MovableObject&, std::vector<Force>> ObjectAndForces ;
	std::vector<ObjectAndForces> m_ObjectsInReferenceFrame;
	ReferenceFrame();
	ReferenceFrame(std::vector<ObjectAndForces> ObjectsInReferenceFrame);

public:
	virtual void AddObject(MovableObject& MovableObject) = 0;
	// TODO: GetObjects and RemoveObject
	virtual void UpdateObjects(int64_t deltaTime) = 0;
	virtual ~ReferenceFrame() = default;
};