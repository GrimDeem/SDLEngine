#include <iostream>
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
    m_sizeX = extract(data, "size", "x", WINDOW_SIZE_X);
    m_sizeY = extract(data, "size", "y", WINDOW_SIZE_Y);

    m_positionX = extract(data, "position", "x", WINDOW_POSITION_X);
    m_positionY = extract(data, "position", "y", WINDOW_POSITION_Y);

    m_fullscreen = extract(data, "fullscreen", WINDOW_FULLSCREEN);

    std::cout << "m_sizeX: " << m_sizeX
            << "m_sizeY: " << m_sizeY << std::endl;
}

const std::string& WindowSettings::getTitle() const {
    return m_title;
}

uint32_t WindowSettings::getPositionX() const {
    return m_positionX;
}

uint32_t WindowSettings::getPositionY() const {
    return m_positionY;
}

uint32_t WindowSettings::getSizeX() const {
    return m_sizeX;
}

uint32_t WindowSettings::getSizeY() const {
    return m_sizeY;
}

bool WindowSettings::isFullscreen() const {
    return m_fullscreen;
}
