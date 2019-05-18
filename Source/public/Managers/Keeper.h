#pragma once
#ifndef __KEEPER_H__
#define __KEEPER_H__

#include <cstdint>

#include <Managers/TextureManager.h>
#include <Managers/WindowManager.h>
#include <Managers/SceneManager.h>

#include <Objects/Camera.h>

/*  Keeper is the main class of the game engine
	Stores an unique entities such as TextureManager,
	SceneManager, renderer and provides access to them.
*/
class SDL_Renderer;
class TextureManager;
class Scheduler;

class Keeper
{
private:
	Keeper();
	Keeper(Keeper const&) = delete;		//forbid to copy and create new instances
	Keeper& operator= (Keeper const&) = delete;

	WindowManager* m_windowMgr;
	SDL_Renderer* m_renderer;
	TextureManager* m_textureMgr;
	SceneManager* m_sceneMgr;
	Camera* m_camera;
	Scheduler* m_scheduler;

	float  m_framerate;
public:
	static Keeper& getInstance();

	/*
	TMGR
	*/
	TextureManager* getTextureManager();

	/*
	Renderer
	*/
	void initRenderer(SDL_Renderer* _renderer);
	SDL_Renderer* getRenderer();

	/*
	Window
	*/
	WindowManager* getWindowManager();

	/*
	SMGR
	*/
	SceneManager* getSceneManager();
	void replaceCurrentScene(std::shared_ptr<Scene> _newScene);
	void runFirstScene(std::shared_ptr<Scene> _newScene);
	EventHandler getEventHandler();
	void drawCurrentScene();
	void updateCurrentScene(float _dt);

	/*
	FPS
	*/
	void setFPS(uint32_t fps);
	uint32_t getFPS();

	/*
	Camera
	*/
	Camera* getCamera();

	/*
	Scheduler
	*/
	Scheduler* getScheduler();

	/*End engine, release memory, destroy window*/
	void end();
};

#endif // !__KEEPER_H__
