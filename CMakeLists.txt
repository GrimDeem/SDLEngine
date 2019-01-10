cmake_minimum_required(VERSION 3.9)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(PROJECT_NAME KDEngine)

project(${PROJECT_NAME} VERSION 1.0.1)

set(SDL2_DIR ${CMAKE_SOURCE_DIR}/External/Linux/SDL2)
set(SDL2_LIBRARIES_DIR ${SDL2_DIR}/libs)
set(SDL2_INCLUDE_DIR ${SDL2_DIR}/include)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Source/)
set(OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -w")

set(KDENGINE_SOURCES
    ${SOURCE_DIR}/private/Input/EventHandler.cpp
    ${SOURCE_DIR}/private/Input/KeyboardEventHolder.cpp
    ${SOURCE_DIR}/private/Input/MouseEventHolder.cpp

    ${SOURCE_DIR}/private/Managers/Keeper.cpp
    ${SOURCE_DIR}/private/Managers/SceneManager.cpp
    ${SOURCE_DIR}/private/Managers/TextureManager.cpp
    ${SOURCE_DIR}/private/Managers/WindowManager.cpp

    ${SOURCE_DIR}/private/Objects/AnimatedSprite.cpp
    ${SOURCE_DIR}/private/Objects/Camera.cpp
    ${SOURCE_DIR}/private/Objects/Node.cpp
    ${SOURCE_DIR}/private/Objects/Scene.cpp
    ${SOURCE_DIR}/private/Objects/Sprite.cpp
    ${SOURCE_DIR}/private/Objects/TextLabel.cpp

    ${SOURCE_DIR}/private/Game.cpp
)

find_library(SDL2	    libSDL2.so		    ${SDL2_LIBRARIES_DIR})
find_library(SDL2_IMAGE	libSDL2_image.so	${SDL2_LIBRARIES_DIR})
find_library(SDL2_MIXER	libSDL2_mixer.so	${SDL2_LIBRARIES_DIR})
find_library(SDL2_NET	libSDL2_net.so		${SDL2_LIBRARIES_DIR})
find_library(SDL2_TTF	libSDL2_ttf.so	 	${SDL2_LIBRARIES_DIR})

message("\nChecking libraries...")
message(STATUS "	      sdl2: " ${SDL2})
message(STATUS "      sdl_image: " ${SDL2_IMAGE})
message(STATUS "      sdl_mixer: " ${SDL2_MIXER})
message(STATUS "        sdl_net: " ${SDL2_NET})
message(STATUS "        sdl_ttf: " ${SDL2_TTF})
message("")

add_library(${PROJECT_NAME} SHARED ${KDENGINE_SOURCES})

target_include_directories(${PROJECT_NAME} 
        PUBLIC ${SOURCE_DIR}/public/
        PUBLIC ${SDL2_INCLUDE_DIR}/
)


target_link_libraries(${PROJECT_NAME} 
		PUBLIC ${SDL2}
		PUBLIC ${SDL2_IMAGE}
		PUBLIC ${SDL2_MIXER}
		PUBLIC ${SDL2_NET}
		PUBLIC ${SDL2_TTF}
        )
