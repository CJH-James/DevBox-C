#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "log.h"

/**
 * @brief Get the current timestamp in HH:MM:SS.mmm format
 *
 * @param[out] timeStr The buffer to store the formatted
 * @param[in]  size    The size of the buffer (should be at least 13 bytes).
 */
void get_timestamp(char *timeStr, size_t size)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm *tm_info = localtime(&tv.tv_sec);
    strftime(timeStr, size, "%H:%M:%S", tm_info);
    snprintf(timeStr + 8, size - 8, ".%03ld", tv.tv_usec / 1000);
}

/**
 * @brief General function for printing log message
 *
 * @param[in] level    The pre-fix string
 * @param[in] color    The pre-fix string color
 * @param[in] message  The log message
 * @param[in] timeFlag The timestamp flag (eTimestamp)
 */
void log_message(const char *level, const char *color, const char *message, eTimestamp timeFlag)
{
    char timestamp[16] = "";
    if (timeFlag)
    {
        get_timestamp(timestamp, sizeof(timestamp));
        printf("|%s|", timestamp);
    }

    printf("%s%-4s" RESET "│ %s\n", color, level, message);
}

/**
 * @brief The [INFO] log message
 *
 * @param[in] message  The log message
 * @param[in] timeFlag The timestamp flag (eTimestamp)
 */
void log_info(const char *message, eTimestamp timeFlag)
{
    log_message("INFO", BLUE, message, timeFlag);
}

/**
 * @brief The [WARN] log message
 *
 * @param[in] message  The log message
 * @param[in] timeFlag The timestamp flag (eTimestamp)
 */
void log_warn(const char *message, eTimestamp timeFlag)
{
    log_message("WARN", GRAY, message, timeFlag);
}

/**
 * @brief The [ERR] log message
 *
 * @param[in] message  The log message
 * @param[in] timeFlag The timestamp flag (eTimestamp)
 */
void log_err(const char *message, eTimestamp timeFlag)
{
    log_message("ERR", RED, message, timeFlag);
}
