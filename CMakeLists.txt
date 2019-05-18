cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME KDEngine)
project(${PROJECT_NAME} VERSION 1.0.1)

if(WIN32)
    message("Detected platform: WIN32")
    set(PLATFORM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External/Windows)
endif(WIN32)

if(UNIX)
    message("Detected platform: UNIX")
    set(PLATFORM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External/Linux/)
endif(UNIX)

set(SDL2_DIR ${PLATFORM_DIR}/SDL2)
set(SDL2_LIBRARIES_DIR ${SDL2_DIR}/libs)
set(SDL2_INCLUDE_DIR ${SDL2_DIR}/include)

# TODO: REMOVE
set(SDL2_INCLUDE_DIR_P ${SDL2_DIR}/include PARENT_SCOPE)
set(SDL2_LIBRARIES_DIR_P ${SDL2_DIR}/libs PARENT_SCOPE)
message(WARNING "Get rid of this hack!")

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -w -fPIC")

add_subdirectory(External/TaskScheduler)

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

set(KDENGINE_HEADERS
    ${SOURCE_DIR}/public/Core/GlobalDefines.h
    ${SOURCE_DIR}/public/Core/Logger.h
    ${SOURCE_DIR}/public/Core/Vec2.h

    ${SOURCE_DIR}/public/Input/EventHandler.h
    ${SOURCE_DIR}/public/Input/KeyboardEventHolder.h
    ${SOURCE_DIR}/public/Input/MouseEventHolder.h

    ${SOURCE_DIR}/public/Managers/Keeper.h
    ${SOURCE_DIR}/public/Managers/SceneManager.h
    ${SOURCE_DIR}/public/Managers/TextureManager.h
    ${SOURCE_DIR}/public/Managers/WindowManager.h

    ${SOURCE_DIR}/public/Objects/AnimatedSprite.h
    ${SOURCE_DIR}/public/Objects/Camera.h
    ${SOURCE_DIR}/public/Objects/Node.h
    ${SOURCE_DIR}/public/Objects/Scene.h
    ${SOURCE_DIR}/public/Objects/Sprite.h
    ${SOURCE_DIR}/public/Objects/TextLabel.h

    ${SOURCE_DIR}/public/Game.h
)

if(UNIX)
    find_library(SDL2_LIB	    libSDL2.so		    ${SDL2_LIBRARIES_DIR})
    find_library(SDL2_IMAGE_LIB	libSDL2_image.so	${SDL2_LIBRARIES_DIR})
    find_library(SDL2_MIXER_LIB	libSDL2_mixer.so	${SDL2_LIBRARIES_DIR})
    find_library(SDL2_NET_LIB	libSDL2_net.so		${SDL2_LIBRARIES_DIR})
    find_library(SDL2_TTF_LIB	libSDL2_ttf.so	 	${SDL2_LIBRARIES_DIR})
endif(UNIX)

if(WIN32)
    # probably will require copying .dll's to output dir
    # so need to be aware of this.
	set(SDL2_DLL ${SDL2_LIBRARIES_DIR}/SDL2.dll)

    # Also we aint using available _SDL2main.lib,
    # but looks like its linking fine for now, so dont really care
    set(SDL2_LIB ${SDL2_LIBRARIES_DIR}/SDL2.lib)
	set(SDL2_MAIN_LIB ${SDL2_LIBRARIES_DIR}/SDL2main.lib)
    set(SDL2_IMAGE_LIB ${SDL2_LIBRARIES_DIR}/SDL2_image.lib)
    set(SDL2_MIXER_LIB ${SDL2_LIBRARIES_DIR})
    set(SDL2_NET_LIB ${SDL2_LIBRARIES_DIR}/SDL2_net.lib)
    set(SDL2_TTF_LIB ${SDL2_LIBRARIES_DIR}/SDL2_ttf.lib)
endif(WIN32)

message("Checking libraries...")
message(STATUS "	      sdl2: " ${SDL2_LIB})
message(STATUS "       sdl_main: " ${SDL2_MAIN_LIB})
message(STATUS "      sdl_image: " ${SDL2_IMAGE_LIB})
message(STATUS "      sdl_mixer: " ${SDL2_MIXER_LIB})
message(STATUS "        sdl_net: " ${SDL2_NET_LIB})
message(STATUS "        sdl_ttf: " ${SDL2_TTF_LIB})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(${PROJECT_NAME} SHARED ${KDENGINE_SOURCES} ${KDENGINE_HEADERS})

target_include_directories(${PROJECT_NAME}
        PUBLIC ${SOURCE_DIR}/public/
        PUBLIC ${SDL2_INCLUDE_DIR}/
        PUBLIC ${SDL2_INCLUDE_DIR}/
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/External
)

target_link_libraries(${PROJECT_NAME}
		PUBLIC ${SDL2_LIB}
		PUBLIC ${SDL2_MAIN_LIB}
		PUBLIC ${SDL2_IMAGE_LIB}
		PUBLIC ${SDL2_MIXER_LIB}
		PUBLIC ${SDL2_NET_LIB}
		PUBLIC ${SDL2_TTF_LIB}
        PUBLIC task_scheduler
        )
