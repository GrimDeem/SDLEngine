#pragma once
#ifndef __GLOBAL_DEFINES_H__
#define __GLOBAL_DEFINES_H__

// define from some settings file (cmake?) would be better
#define LOGGING 1

#if !defined(LOGGING) || LOGGING == 0
#define LOG(...)       do {} while (0)

#elif LOGGING >= 1
#include "Core/Logger.h"
#define LOG(string, ...)  log(string, ##__VA_ARGS__);
#endif

#endif __GLOBAL_DEFINES_H__