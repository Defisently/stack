#include "io.h"
#include "stack_logic.h"
#include <stdio.h>
#include <math.h>
#include "io.h"

int operations(int command, struct stack *self){
    int num = NAN;
    switch (command) {
        case 1: {
            printf("Enter number that you want to push: ");
            if (scanf("%d", &num) != 1) {
                input_clear();
                printf("Please, enter a number\n");
                return INVALID_PUSH_INPUT;
            }
            push(self, num);
            break;
        }
        case 2: {
           pop(self);
           break;
        }
        case 3: {
            printf("Enter new size of stack: ");
            if (scanf("%d", &num) != 1){
                input_clear();
                printf("Please, enter a number\n");
            }
            new_size(self, num);
            break;
        }
        case 4: {
            check_size(self);
            break;
        }
        case 5: {
           print_el(self);
           break;
        }
    }
    return 0;
}
