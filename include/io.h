#pragma once
#include "commands.h"

#define SOFT_ASSERT(to_check, to_print, to_out)     \
    do {                                            \
        if (to_check){                              \
            printf(to_print "\n");                  \
            to_out;                                 \
        }                                           \
    } while(0)

ERROR_CODES input(int *command);
int input_clear(void);


