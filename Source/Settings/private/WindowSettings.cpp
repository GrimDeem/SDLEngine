#include <WindowSettings.h>
#include <Extractor.h>

WindowSettings::WindowSettings()
    : m_title(WINDOW_TITLE)
    , m_positionX(WINDOW_POSITION_X)
    , m_positionY(WINDOW_POSITION_Y)
    , m_sizeX(WINDOW_SIZE_X)
    , m_sizeY(WINDOW_SIZE_Y)
    , m_fullscreen(WINDOW_FULLSCREEN)
{ }

WindowSettings::WindowSettings(const nlohmann::json& data) {
    m_title = extract(data, "title", std::string(WINDOW_TITLE));
    try {
        auto size = data["size"];
        m_sizeX = extract(size, "x", WINDOW_SIZE_X);
        m_sizeY = extract(size, "y", WINDOW_SIZE_Y);
    } catch (...) {
        m_sizeX = WINDOW_SIZE_X;
        m_sizeY = WINDOW_SIZE_Y;
    }

    try {
        auto position = data["position"];
        m_positionX = extract(position, "x", WINDOW_POSITION_X);
        m_positionY = extract(position, "y", WINDOW_POSITION_Y);
    } catch (...) {
        m_positionX = WINDOW_POSITION_X;
        m_positionY = WINDOW_POSITION_Y;
    }

    m_fullscreen = extract(data, "fullscreen", WINDOW_FULLSCREEN);
}
