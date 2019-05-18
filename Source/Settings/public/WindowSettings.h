#pragma once
#ifndef __WINDOW_SETTINGS_H__
#define __WINDOW_SETTINGS_H__

#include <string>
#include <nlohmann/json.hpp>

namespace
{
constexpr char WINDOW_TITLE[] = "SDLEngine Preview";
constexpr uint32_t WINDOW_POSITION_X = 200;
constexpr uint32_t WINDOW_POSITION_Y = 200;
constexpr uint32_t WINDOW_SIZE_X = 1366;
constexpr uint32_t WINDOW_SIZE_Y = 768;
constexpr bool WINDOW_FULLSCREEN = false;
}

/*
Class that extracts configuration data from .json or applies default values

Expected json data format:

	"window": {
        "title": "SDLEngine Preview",
        "size": {
            "x": 1366,
            "y": 768
        },
        "position": {
            "x": 200,
            "y": 200
        },
        "fullscreen": false
    }

Full config can be found at {repo_root}/Resources/engine_config.json
*/

class WindowSettings
{
private:
	// Text to be displayed as window title
	std::string m_title;
	// Window spawn position
	uint32_t m_positionX;
	uint32_t m_positionY;
	// Window spawn size
	uint32_t m_sizeX;
	uint32_t m_sizeY;
	// Whether or not window should be spawned as fullscreen
	bool m_fullscreen;

public:
	// Initialize with default settings
	WindowSettings();
	// Initialize with settings from config file
	WindowSettings(const nlohmann::json& data);

	const std::string& getTitle() const;
	uint32_t getPositionX() const;
	uint32_t getPositionY() const;
	uint32_t getSizeX() const;
	uint32_t getSizeY() const;
	bool isFullscreen() const;
};


#endif //__WINDOW_SETTINGS_H__
