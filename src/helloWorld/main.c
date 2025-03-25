#include <stdio.h>
#include <unistd.h> /* getopt*/

#include "log.h"

static void printHelp(char *argv[])
{
    printf("\n");
    printf("Usage: %s -p N [-oString]\n", argv[0]);
    printf("\n");
    printf("Arguments:\n");
    printf("    -p N       (necessary argument)\n");
    printf("    -oString   (optional argument)\n");
}

int main(int argc, char *argv[])
{
    int  opt      = 0;
    char msg[128] = {0};

    // at least 1 arg
    if (argc == 1)
    {
        printHelp(argv);
        return 0;
    }

    sprintf(msg, "Process Idx = %d, error=%d", optind, opterr);
    log_info(msg, NONE);
    log_warn(msg, NONE);
    log_err(msg, NONE);
    log_info(msg, WITH_TIMESTAMP);
    log_warn(msg, WITH_TIMESTAMP);
    log_err(msg, WITH_TIMESTAMP);

    while ((opt = getopt(argc, argv, "hp:o::")) != -1)
    {
        // h   -> no arg
        // p:  -> 1 arg
        // o:: -> optional arg
        switch (opt)
        {
            case 'p':
                DEBUG("optarg = %s", optarg);
                break;
            case 'o':
                DEBUG("optarg = %s", optarg);
                break;
            case 'h':
            default:
                printHelp(argv);
                break;
        }
    }

    return 0;
}