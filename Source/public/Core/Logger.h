#pragma once
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <iostream>
#include <stdarg.h>
#include <stdio.h>

static void log(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// This macro magic selects
// LOG_0() if 0 args passed to the LOG() macro
// LOG_1() if 1 arg  passed to the LOG() macro etc.

// General utility macro
#define CAT( A, B ) A ## B
#define EXPAND(...) __VA_ARGS__

// Macro overloading feature support
#define VA_ARG_SIZE(...) EXPAND(APPLY_ARG_N((ZERO_ARGS_DETECT(__VA_ARGS__), RSEQ_N)))

#define ZERO_ARGS_DETECT(...) EXPAND(ZERO_ARGS_DETECT_PREFIX_ ## __VA_ARGS__ ## _ZERO_ARGS_DETECT_SUFFIX)
#define ZERO_ARGS_DETECT_PREFIX__ZERO_ARGS_DETECT_SUFFIX ,,,,,,,,,,,0

#define APPLY_ARG_N(ARGS) EXPAND(ARG_N ARGS)
#define ARG_N(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N,...) N
#define RSEQ_N 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define OVERLOAD_SELECT(NAME, NUM) CAT( NAME ## _, NUM)
#define MACRO_OVERLOAD(NAME, ...) OVERLOAD_SELECT(NAME, VA_ARG_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define LOG(...)         MACRO_OVERLOAD(LOG, __VA_ARGS__)
#define LOG_0()          std::cout

// TODO: temporary solution for backwards compatiblity sake, needs to be replaced by the new logger
// supporting logging levels etc.
#define LOG_1(...)  log(...)
#define LOG_2(...)  log(...)
#define LOG_3(...)  log(...)

#endif // !__LOGGER_H__
