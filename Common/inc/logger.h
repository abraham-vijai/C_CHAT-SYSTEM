/*
Filename    : logger.h
Author      : Abraham Vijai
Date        : 2024-04-09
Description : Header file for logger.c
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>

#define APPEND_MODE "a"
#define WRITE_MODE "w"

void logInit(char* path);
void logEvent(const char* format, ...);
void logError(const char* errorMessage);

#endif