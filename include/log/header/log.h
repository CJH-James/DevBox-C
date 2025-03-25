#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>

// Define ANSI color codes
#define GRAY   "\033[1;30m"
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define Cyan   "\033[1;36m"
#define RESET  "\033[0m"

typedef enum
{
    NONE           = 0, // none
    WITH_TIMESTAMP = 1  // with timestamp
} eTimestamp;

#define DEBUG(fmt, ...)                                                                                                   \
    do                                                                                                                    \
    {                                                                                                                     \
        fprintf(stderr, YELLOW "[DEBUG] " RESET "%s:%d %s():" fmt "\n", __FILE_NAME__, __LINE__, __func__, ##__VA_ARGS__); \
    } while (0)

// Function declarations
void log_message(const char *level, const char *color, const char *message, eTimestamp timeFlag);
void log_info(const char *message, eTimestamp timeFlag);
void log_warn(const char *message, eTimestamp timeFlag);
void log_err(const char *message, eTimestamp timeFlag);
#endif /* _LOG_H_ */