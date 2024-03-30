#pragma once
#include <vector>

#include "DynamicsSimulator.h"
#include "Display/Graphics.h"

#ifdef ENABLE_SFML
#include "SFML/Graphics.hpp"
#endif


class Scene {
private:
#ifdef ENABLE_SFML
	sf::RenderWindow Window;

	sf::Clock AbsoluteTime;
	sf::Clock DeltaTime;
#else
	int64_t InitialTimestamp;
	int64_t PreviousDeltaTimeResetTimestamp;
#endif
	std::vector<IDrawable*> Drawables;
	std::vector<ITransformable*> Transformables;
	bool isRunning = true;

public:
	Scene();
	Scene(unsigned int Width, unsigned int Height, const char* WindowName);
	Scene(unsigned int Width, unsigned int Height, const char* WindowName, unsigned int FramerateLimit);

	void AddMovingDrawable(IDrawable& Drawable);
	void AddStaticDrawable(IDrawable& Drawable);
	void UpdateScene();
	bool IsRunning();
	void Stop();
	int64_t GetAbsoluteTimeMs();
	int64_t GetDeltaTimeMs();
	int64_t ResetDeltaTime();
};