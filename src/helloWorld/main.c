#include <stdio.h>

#include "log.h"

int main(int argc, char *argv[])
{
    int  opt      = 0;
    char msg[128] = {0};

    sprintf(msg, "Hello World");
    log_info(msg, NONE);
    log_warn(msg, NONE);
    log_err(msg, NONE);
    log_info(msg, WITH_TIMESTAMP);
    log_warn(msg, WITH_TIMESTAMP);
    log_err(msg, WITH_TIMESTAMP);

    return 0;
}