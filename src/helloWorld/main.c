
#include "log.h"
#include "operateArgument.h"
#include <stdlib.h>


char *inputArg_arr[][_ARGUMENT_ELEMENT_CNT] = 
{
    {"0", "-h", NULL},
    {"1", "-a", "0"},
    {"0", "-b", "eth0"},
    {"1", "-c", "Hi"},
};
int inputArg_rows = sizeof(inputArg_arr)/sizeof(inputArg_arr[0]);



int main (int argc, char *argv[])
{
    sArgument *argList = NULL;
    int ret = -1;
    int i;
    
    argList = initialArgument();
    if (argList == NULL)
    {
        log_err("alloc memory fail!", NONE);
        return -1;
    }

    for (i = 0 ; i < inputArg_rows ; i++)
    {
        sArgument *tmp_argList = initialArgument();
        if (tmp_argList == NULL)
        {
            log_err("alloc memory fail!", NONE);
            return -1;
        }

        tmp_argList->necessary   = strtol(inputArg_arr[i][0], NULL, 10);
        tmp_argList->option      = inputArg_arr[i][1];
        tmp_argList->default_val = inputArg_arr[i][2];

        addArgument(&argList, tmp_argList);
    }

    printArgument(argList);

    DEBUG("freeArguments");
    freeArguments(argList);
    DEBUG("test");

    return 0;
}