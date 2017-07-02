#[[project(SDLEngine)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -w")
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Classes)

file( GLOB SOURCES
      "${SOURCE_DIR}/include/*/*.h"
      "${SOURCE_DIR}/include/*.h"
      "${SOURCE_DIR}/src/*/*.cpp"
      "${SOURCE_DIR}/src/*/*.inl"
      "${SOURCE_DIR}/src/*.cpp"
      "${SOURCE_DIR}/*.*"
      "${SOURCE_DIR}/../SDL-basedEngine/main.cpp")
      
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/../SDL-basedEngine/main.cpp)

set_target_properties(SDLEngine PROPERTIES LINKER_LANGUAGE CXX)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})]]

















cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(SDLEngine)

set(SDL_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/Linux/libs/SDL2/)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Classes/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -w")

include_directories(${CMAKE_SOURCE_DIR}/Linux/include/SDL2)
link_directories(${SDL_LIBRARIES_DIR})

file( GLOB HEADERS
      "${SOURCE_DIR}/include/*/*.h"
      "${SOURCE_DIR}/include/*.h"
      "${SOURCE_DIR}/*.h")


file( GLOB SOURCES
      "${SOURCE_DIR}/src/*/*.cpp"
#      "${SOURCE_DIR}/src/*/*.inl"
      "${SOURCE_DIR}/src/*.cpp"
      "${SOURCE_DIR}/*.cpp"
      "${SOURCE_DIR}/../SDL-basedEngine/main.cpp")

find_library(SDL2	libSDL2.so		${SDL_LIBRARIES_DIR})
find_library(SDL2_IMAGE	libSDL2_image.so	${SDL_LIBRARIES_DIR})
find_library(SDL2_MIXER	libSDL2_mixer.so	${SDL_LIBRARIES_DIR})
find_library(SDL2_NET	libSDL2_net.so		${SDL_LIBRARIES_DIR})
find_library(SDL2_TTF	libSDL2_ttf.so	 	${SDL_LIBRARIES_DIR})

message("\nChecking libraries...")
message(STATUS "	      sdl2: " ${SDL2})
message(STATUS "      sdl_image: " ${SDL2_IMAGE})
message(STATUS "      sdl_mixer: " ${SDL2_MIXER})
message(STATUS "        sdl_net: " ${SDL2_NET})
message(STATUS "        sdl_ttf: " ${SDL2_TTF})
message("")

add_executable(run ${SOURCES} ${HEADERS})

target_link_libraries(run
		${SDL2}
		${SDL2_IMAGE}
		${SDL2_MIXER}
		${SDL2_NET}
		${SDL2_TTF})
	
