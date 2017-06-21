#pragma once
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdarg.h>
#include <stdio.h>
static void log(const char* format, ...) 
{
	char buffer[256];
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

#endif // !__LOGGER_H__
