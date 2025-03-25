
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "log.h"
#include "../../log/header/log.h"
#include "operateArgument.h"

/**
 * @brief Print the sArgument structure
 * 
 * @param psArgList the pointer of sArgument structure 
 */
void printArgument(sArgument *psArgList)
{
    printf("printArgument\n");

    while (psArgList != NULL)
    {
        printf("Option: %s\n", psArgList->option);
        // printf("  Necessary: %s\n", psArgList->necessary ? "true" : "false");
        printf("  Value: %s\n", psArgList->val ? psArgList->val : "(null)");
        printf("  Default Value: %s\n", psArgList->default_val ? psArgList->default_val : "(null)");
        printf("\n");
        psArgList = psArgList->next_argv;
    }
}

/**
 * @brief Alloc the memory of the sArgument sturcture
 *
 * @return The pointer of sArgument
 */
sArgument *initialArgument()
{
    sArgument *tmp_Argument = NULL;

    // alloc memory
    tmp_Argument = (sArgument *)calloc(1, sizeof(sArgument));
    if (tmp_Argument == NULL)
    {
        return NULL;
    }

    return tmp_Argument;
}


/**
 * @brief 
 * 
 * @param psHead 
 * @param psNewArg 
 */
void addArgument(sArgument **psHead, sArgument *psNewArg)
{
    sArgument *psCurrent = *psHead;

    if (psCurrent->option == NULL)
    {
        DEBUG("First argument");
        *psHead = psNewArg;
    }
    else
    {
        DEBUG("NOT First argument");
        while (psCurrent->next_argv != NULL)
        {
            psCurrent = psCurrent->next_argv;
        }
        psCurrent->next_argv = psNewArg;
    }
}

// Function to find an argument by option
/**
 * @brief 
 * 
 * @param head 
 * @param option 
 * @return
 */
sArgument* findArgument(sArgument* head, const char *option) {
    sArgument* current = head;
    while (current != NULL) {
        if (strcmp(current->option, option) == 0) {
            return current;
        }
        current = current->next_argv;
    }
    return NULL;
}


/**
 * @brief Free the sArgument structure
 *
 * @param head The sArgument structure
 */
void freeArguments(sArgument *head)
{
    sArgument *current = head;
    while (current != NULL)
    {
        sArgument *next = current->next_argv;
        if (current != NULL)
        {
            free(current);
        }
        current = next;
    }
}
