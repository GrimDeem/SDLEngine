#include "../include/Game.h"

Game::Game()
{
	initSDL();	
	is_running = true;
	auto scene = InitialScene::createScene();
	Keeper::getInstance().replaceScene(scene);
}

bool Game::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Cant init sdl", NULL);
		exit(1);
	}
	SDL_Window* window = SDL_CreateWindow(
		WINDOW_TITLE,
		WINDOW_POSITION_X,
		WINDOW_POSITION_Y,
		WINDOW_SIZE_X,
		WINDOW_SIZE_Y,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (!window) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Cant create window", NULL);
		exit(1);
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	Keeper::getInstance().initRenderer(renderer);
	Keeper::getInstance().initWindow(window);
	return true;
}

void Game::run()
{
//	float prevDeltaTime = 66.6f; // 30FPS
//	const float FPS_FILTER = 0.10f;
	unsigned int lastTime = 0;

	while (is_running) {
		unsigned int loopStartTime = SDL_GetTicks();
		unsigned int deltaTime = loopStartTime - lastTime;
//		prevDeltaTime = deltaTime * FPS_FILTER + (1 - FPS_FILTER) * prevDeltaTime;

		processEvents();
		updateWorld(deltaTime);
		draw();

#ifdef DEBUG
		auto _frameRate = 1000 / prevDeltaTime;
		std::cout << "framerate - " << round(_frameRate) << std::endl;
#endif
#ifdef FRAME_LIMIT
		while ((SDL_GetTicks() - lastTime) < targetFrameTime)
			SDL_Delay(targetFrameTime - (SDL_GetTicks() - lastTime));
#endif // FRAME_LIMIT
		lastTime = loopStartTime;
	}
	clean();
}

void Game::clean()
{
	Keeper::getInstance().end();
}

void Game::processEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			is_running = false;
			break;
		}
	}
}

void Game::updateWorld(float dt)
{
	Keeper::getInstance().updateCurrentScene(dt);
}

void Game::draw()
{
	SDL_RenderClear(Keeper::getInstance().getRenderer());

	Keeper::getInstance().drawCurrentScene();

	SDL_RenderPresent(Keeper::getInstance().getRenderer());
}
