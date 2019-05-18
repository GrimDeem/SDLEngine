#pragma once
#ifndef __ENGINE_SETTINGS_H__
#define __ENGINE_SETTINGS_H__

#include <string>
#include <nlohmann/json.hpp>
#include <WindowSettings.h>

class EngineSettings
{
private:
	nlohmann::json m_dataSource;
	WindowSettings m_wsettings;
public:
	// Initialize with default settings
	EngineSettings();
	// Initialize with settings from config file
	EngineSettings(const std::string& config_path);
};


#endif //__ENGINE_SETTINGS_H__