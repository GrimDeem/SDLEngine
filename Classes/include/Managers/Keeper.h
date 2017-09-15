#pragma once
#ifndef __KEEPER_H__
#define __KEEPER_H__

#include <cassert>
#include <iostream>
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "TextureManager.h"
#include "SceneManager.h"

#include "../Objects/Camera.h"

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
	
	Camera* camera;
	SDL_Renderer* renderer;
	SDL_Window* window;
	TextureManager* texManager;
	SceneManager* sceneManager;
	float  framerate;
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
	void initWindow(SDL_Window* _window);
	SDL_Window* getWindow(); 

	/*
	SMGR
	*/
	SceneManager* getSceneManager();
	void replaceCurrentScene(std::shared_ptr<Scene> newScene);
	void runFirstScene(std::shared_ptr<Scene> newScene);
	EventHandler getEventHandler();
	void drawCurrentScene();
	void updateCurrentScene(float dt);

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
