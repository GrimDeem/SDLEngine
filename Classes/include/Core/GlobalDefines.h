#pragma once
#ifndef __GLOBAL_DEFINES_H__
#define __GLOBAL_DEFINES_H__ 

#define LOGGING 0

#if !defined(LOGGING) || LOGGING == 0
#define LOG(...)       do {} while (0)

#elif LOGGING >= 1
#include "Logger.h"
#define LOG(string, ...)  log(string, ##__VA_ARGS__);
#endif

#endif __GLOBAL_DEFINES_H__