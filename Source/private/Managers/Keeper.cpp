#include <cassert>

#include <SDL_ttf.h>
#include <SDL_render.h>

#include <TaskScheduler/TaskScheduler.h>
#include <Managers/Keeper.h>

Keeper::Keeper()
	: m_renderer(nullptr)
	, m_framerate(0) {
	m_windowMgr = new WindowManager();
	m_textureMgr = new TextureManager();
	m_sceneMgr = new SceneManager();
	m_camera = new Camera(m_windowMgr->getWindowSize());
	m_scheduler = new Scheduler();
}

Keeper & Keeper::getInstance() {
	static Keeper inst;
	return inst;
}

TextureManager* Keeper::getTextureManager() {
	return m_textureMgr;
}

void Keeper::initRenderer(SDL_Renderer* _renderer) {
	assert(_renderer != nullptr);
	m_renderer = _renderer;
}

SDL_Renderer* Keeper::getRenderer() {
	assert(m_renderer != nullptr);
	return m_renderer;
}

WindowManager * Keeper::getWindowManager() {
	return m_windowMgr;
}

SceneManager * Keeper::getSceneManager() {
	return m_sceneMgr;
}

void Keeper::replaceCurrentScene(std::shared_ptr<Scene> _newScene) {
	m_sceneMgr->replaceCurrentScene(_newScene);
}

void Keeper::runFirstScene(std::shared_ptr<Scene> _newScene) {
	m_sceneMgr->runFirstScene(_newScene);
}

EventHandler Keeper::getEventHandler() {
	return m_sceneMgr->getCurrentSceneEventHandler();
}

void Keeper::drawCurrentScene() {
	m_sceneMgr->drawCurrentScene();
}

void Keeper::updateCurrentScene(float _dt) {
	m_sceneMgr->updateCurrentScene(_dt);
}

void Keeper::setFPS(uint32_t _fps) {
	m_framerate = _fps;
}

uint32_t Keeper::getFPS() {
	return m_framerate;
}

Camera* Keeper::getCamera() {
	return m_camera;
}

Scheduler* Keeper::getScheduler() {
	return m_scheduler;
}

void Keeper::end() {
	delete m_camera;
	delete m_sceneMgr;
	delete m_textureMgr;
	delete m_windowMgr;

	SDL_DestroyRenderer(m_renderer);
	TTF_Quit();
	SDL_Quit();
}
