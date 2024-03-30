#include "Scene.h"

#include <iostream>
#include <chrono>

uint64_t GetTimestampMs() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


#ifdef ENABLE_SFML
Scene::Scene()
	: Window({ 800, 600 }, "Default"){
}
Scene::Scene(unsigned int Width, unsigned int Height, const char* WindowName)
	: Window({ Width, Height }, WindowName) {
}
Scene::Scene(unsigned int Width, unsigned int Height, const char* WindowName, unsigned int FramerateLimit)
	: Window({ Width, Height }, WindowName) {
	Window.setFramerateLimit(FramerateLimit);
}
#else
Scene::Scene()
	: InitialTimestamp(GetTimestampMs()), PreviousDeltaTimeResetTimestamp(GetTimestampMs()) {
}
Scene::Scene(unsigned int Width, unsigned int Height, const char* WindowName)
	: InitialTimestamp(GetTimestampMs()), PreviousDeltaTimeResetTimestamp(GetTimestampMs()) {
}
Scene::Scene(unsigned int Width, unsigned int Height, const char* WindowName, unsigned int FramerateLimit)
	: InitialTimestamp(GetTimestampMs()), PreviousDeltaTimeResetTimestamp(GetTimestampMs()) {
}
#endif

void Scene::AddMovingDrawable(IDrawable& Drawable) {
	Drawables.push_back(&Drawable);
	Transformables.push_back(dynamic_cast<ITransformable*>(&Drawable));
}

void Scene::AddStaticDrawable(IDrawable& Drawable) {
	Drawables.push_back(&Drawable);
}

bool Scene::IsRunning()
{
#ifdef ENABLE_SFML
	return Window.isOpen() && isRunning;
#else
	return isRunning;
#endif
}

int64_t Scene::GetAbsoluteTimeMs()
{
#ifdef ENABLE_SFML
	return AbsoluteTime.getElapsedTime().asMilliseconds();
#else
	return GetTimestampMs() - InitialTimestamp;
#endif
}

int64_t Scene::GetDeltaTimeMs()
{
#ifdef ENABLE_SFML
	return DeltaTime.getElapsedTime().asMilliseconds();
#else
	return GetTimestampMs() - PreviousDeltaTimeResetTimestamp;
#endif
}

int64_t Scene::ResetDeltaTime()
{
#ifdef ENABLE_SFML
	return DeltaTime.restart().asMilliseconds();
#else
	uint64_t timestamp = GetTimestampMs();
	uint64_t deltaTime = timestamp - PreviousDeltaTimeResetTimestamp;
	PreviousDeltaTimeResetTimestamp = timestamp;
	return deltaTime;
#endif
}

void Scene::Stop() {
	isRunning = false;
}

void Scene::UpdateScene() {
#ifdef ENABLE_SFML
	// Events
	for (auto event = sf::Event(); Window.pollEvent(event);) {
		if (event.type == sf::Event::Closed()) {
			Window.close();
		}
	}

	// Drawing
	Window.clear(sf::Color(90, 180, 220));
	for (ITransformable* Transformable : Transformables) {
		Vector2D* Position = Transformable->GetPosition();
		Transformable->GetObjectGraphicsTransform()->setPosition(Position->x, Window.getSize().y - Position->y - 50.0f);
	}
	for (IDrawable* Drawable : Drawables) {
		Window.draw(*Drawable->GetObjectGraphics());
	}
	Window.display();
#endif
}
