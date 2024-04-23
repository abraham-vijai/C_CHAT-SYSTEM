/*
Filename    : logger.c
Author      : Abraham Vijai
Date        : 2024-04-02
Description : This is the logger class
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

char* filePath = NULL;

/*
Function name   : logInit
Description     : Initializes the logging mechanism by opening the log file specified by the provided path.
Parameters      : path - The path to the log file.
Return value    : void
*/
void logInit(char* path)
{
    FILE *fp = NULL;
    filePath = path;

    fp = fopen(filePath, "a");
    if (fp == NULL) 
    {
        printf("ERROR: Cannot open log file");
        fflush(stdout);
        return;
    }
}

/*
Function name   : logEvent
Description     : Logs an event message with a timestamp to the log file.
Parameters      : message - The message format string to be logged, followed by variable arguments.
Return value    : void
*/
void logEvent(const char* format, ...)
{
    FILE *fp = NULL;
    time_t current_time;
    struct tm *local_time;
    char timestamp[64];
    
    // Get current time
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Format the timestamp
    strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", local_time);  
    
    fp = fopen(filePath, "a"); // Open the file
    
    // Check if file opened successfully
    if (fp == NULL) 
    {
        printf("ERROR: Cannot open log file");
        fflush(stdout);
        return;
    }
    
    // Print the timestamp and message to the log file
    fprintf(fp, "%s : ", timestamp);
    
    va_list args; // Initialize argument struct

    // Print the formatted message
    va_start(args, format);
    vfprintf(fp, format, args); 
    va_end(args);
    
    fprintf(fp, "\n");

    fclose(fp);
}