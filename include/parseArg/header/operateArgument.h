#ifndef _OPERATE_ARGUMENT_H_
#define _OPERATE_ARGUMENT_H_

#include <stdbool.h>

#define _ARGUMENT_ELEMENT_CNT 3 //

typedef enum
{
    OPT_NONE     = 0,
    OPT_REQUIRED = 1,
    OPT_OPTIONAL = 2,
} eOptionStatus;

/**
 * @brief The structure define the arguments
 */
typedef struct _argument sArgument;
struct _argument
{
    char         *option;      // The option flag (-i, -s, -d ... something likes that)
    eOptionStatus eStatus;     // The argument status (none/require/optional for executing program)
    char         *val;         // The value associated with the option.(-i "interface" <-- the value after option)
    char         *default_val; // The default value when no input argument
    sArgument    *next_argv;   // The pointer to next argument structure
};

void printArgument(sArgument *psArgList);

sArgument *initialArgument();

void addArgument(sArgument **head, sArgument *newArg);

void freeArguments(sArgument *head);

#endif /* _OPERATE_ARGUMENT_H_ */