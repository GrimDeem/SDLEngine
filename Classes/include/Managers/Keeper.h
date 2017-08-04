#pragma once
#ifndef __KEEPER_H__
#define __KEEPER_H__

#include <cassert>
#include <iostream>
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "TextureManager.h"
#include "SceneManager.h"

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
	
	SDL_Renderer* renderer;
	SDL_Window* window;
	TextureManager* texManager;
	SceneManager* sceneManager;
	float  framerate;
public:
	static Keeper& getInstance();
	TextureManager* getTextureManager();

	void initRenderer(SDL_Renderer* _renderer);
	SDL_Renderer* getRenderer();

	void initWindow(SDL_Window* _window);
	SDL_Window* getWindow(); 

	SceneManager* getSceneManager();
	/*replaces current scene with a passed new one*/
	void replaceCurrentScene(std::shared_ptr<Scene> newScene);
	void runFirstScene(std::shared_ptr<Scene> newScene);
	EventHandler getEventHandler();
	void drawCurrentScene();
	void updateCurrentScene(float dt);

	void setFPS(float fps);
	float getFPS();

	/*End engine, release memory, destroy window*/
	void end(); 
};

#endif // !__KEEPER_H__
