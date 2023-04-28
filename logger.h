#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

typedef enum Log_Level {
    INFO,
    TRACE,
} Log_Level;

#ifdef NO_TRACE
#define LOG_TRACE(message) ((void)0)
#else
#define LOG_TRACE(message) log_trace(__FILE__, __LINE__, message)
#endif

#endif //LOGGER_H