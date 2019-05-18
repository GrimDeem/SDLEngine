#include <fstream>
#include <EngineSettings.h>

EngineSettings::EngineSettings()
	: m_wsettings()
{}

EngineSettings::EngineSettings(const std::string& config_path)
{
	// Try to initialize with data from config
	try {
		std::ifstream config(config_path);
		config >> m_dataSource;
	} catch(...) {
		// Do nothing, all members will be initialized in another catch()'es
	}

	try {
		m_wsettings = WindowSettings(m_dataSource.at("window"));
	} catch (...) {
		m_wsettings = WindowSettings();
	}
}

const WindowSettings& EngineSettings::getWindowSettings() const {
	return m_wsettings;
}
