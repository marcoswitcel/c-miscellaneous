#include "./logger.h"

static const char *log_level_names[] = {
    "INFO",
    "TRACE",
};

void logger(Log_Level log_level, const char *message)
{
    time_t now;
    time(&now);
    char formated_date_buff[20];

    strftime(formated_date_buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("%s %s :: %s", formated_date_buff, log_level_names[log_level], message);
    printf("\n");
}

void log_info(const char * message)
{
    logger(INFO, message);
}

void log_trace(const char *file_name, int line, const char *message)
{
    time_t now;
    time(&now);
    char formated_date_buff[20];
    strftime(formated_date_buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("%s %s src/%s:%d :: %s", formated_date_buff, log_level_names[TRACE], file_name, line, message);
    printf("\n");
}