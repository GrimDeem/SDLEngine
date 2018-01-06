#pragma once
#ifndef __KEEPER_H__
#define __KEEPER_H__

#include <cassert>
#include <iostream>
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "Managers/TextureManager.h"
#include "Managers/WindowManager.h"
#include "Managers/SceneManager.h"

#include "Objects/Camera.h"

/*  Keeper is the main class of the game engine
	Stores an unique entities such as TextureManager,
	SceneManager, renderer and provides access to them.
*/
class TextureManager;

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
	void setFPS(float fps);
	float getFPS();

	/*
	Camera
	*/
	Camera* getCamera();

	/*End engine, release memory, destroy window*/
	void end(); 
};

#endif // !__KEEPER_H__
