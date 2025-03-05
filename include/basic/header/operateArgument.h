#ifndef _OPERATE_ARGUMENT_H_
#define _OPERATE_ARGUMENT_H_

#include <stdbool.h>



#define _ARGUMENT_ELEMENT_CNT 3 // 

/**
 * @brief The structure define the arguments
 */
typedef struct _argument sArgument;
struct _argument
{
    bool necessary;       // this argument is nessary for executing program
    char *option;         // the option, -i, -s, -d ... something likes that
    char *val;            // -i "interface" <-- the value after option
    char *default_val;    // The default value when no input argument
    sArgument* next_argv; // The pointer to next argument structure 
}; 


void printArgument(sArgument *psArgList);

sArgument* initialArgument();

void addArgument(sArgument** head, sArgument* newArg);

void freeArguments(sArgument *head);


#endif /* _OPERATE_ARGUMENT_H_ */