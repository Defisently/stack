#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "io.h"
#include <math.h>
#include "io.h"
#include <ctype.h>


int input_clear(void){
    int c = '\0';

    while ((c = getchar()) != EOF && c != '\n'){
    }
    return c;
}

ERROR_CODES input(int *command){
   int inp = NAN;
   printf("1 - push\n2 - pop\n3 - newsize\n4 - check size\n5 - print elements\n6 - exit\nEnter command: ");
   inp = scanf("%d", command);

   if (isalpha(inp) || inp != 1 || !strchr("123456", inp)){
       SOFT_ASSERT((input_clear() == EOF || inp == EOF), "Incorrect input", return INVALID_INPUT);
   }
   return SUCCESS;
}

