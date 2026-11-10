#include <stdio.h>
#include "io.h"
#include "commands.h"
#include "stack_logic.h"
#include <stdbool.h>
#include <math.h>


int main(void){
    bool flag = true;
    struct stack s;
    init_stack(&s);
    while (flag) {
        int command = NAN;
        if (input(&command) == SUCCESS){
            if (command == 6){
                flag = false;
                break;
            }
            operations(command, &s);
        }
    }
}
