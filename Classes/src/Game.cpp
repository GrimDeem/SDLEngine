#include "../include/Game.h"
using std::cerr;
using std::endl;

Game::Game()
{
	initFPS();
	initSDL();	
	is_running = true;

	Keeper::getInstance().replaceScene(InitialScene::create());
}

bool Game::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Cant init sdl", NULL);
		exit(1);
	}

	if(TTF_Init() < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Cant init sdl_ttf", NULL);
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

void Game::initFPS() 
{
	memset(frametimes, 0, sizeof(frametimes));
	framecount = 0;
	framespersecond = 0;
	frametimelast = SDL_GetTicks();
}

float Game::calcFPS() 
{
	Uint32 frametimesindex;
	Uint32 getticks;
	Uint32 count;
	Uint32 i;
	// frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
	// This value rotates back to 0 after it hits FRAME_VALUES.
	frametimesindex = framecount % FRAME_VALUES;
	// store the current time
	getticks = SDL_GetTicks();
	// save the frame time value
	frametimes[frametimesindex] = getticks - frametimelast;
	// save the last frame time for the next fpsthink
	frametimelast = getticks;
	// increment the frame count
	framecount++;
	if (framecount < FRAME_VALUES) 
		count = framecount;
	else 
		count = FRAME_VALUES;
	// add up all the values and divide to get the average frame time.
	framespersecond = 0;
	for (i = 0; i < count; i++) 
		framespersecond += frametimes[i];
	framespersecond /= count;
	// now to make it an actual frames per second value...
	framespersecond = 1000.f / framespersecond;
	return framespersecond;
}

void Game::run()
{ 
	unsigned int lastTime = 0;
	while (is_running) {
		unsigned int loopStartTime = SDL_GetTicks();
		float deltaTime = loopStartTime - lastTime;
		Keeper::getInstance().setFPS(calcFPS());
		
		processEvents();
		updateWorld(deltaTime);
		draw();

		while ((SDL_GetTicks() - lastTime) < targetFrameTime)	//frame limiting
			SDL_Delay(targetFrameTime - (SDL_GetTicks() - lastTime));

		lastTime = loopStartTime;
	}
	clean();
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

void Game::updateWorld(float dt) //1 dt = 1ms
{
	Keeper::getInstance().updateCurrentScene(dt);
}

void Game::draw()
{
	SDL_RenderClear(Keeper::getInstance().getRenderer());
	
	Keeper::getInstance().drawCurrentScene();

	SDL_RenderPresent(Keeper::getInstance().getRenderer());
}

void Game::clean()
{
	Keeper::getInstance().end();
}
