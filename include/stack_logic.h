#pragma once
#include <stddef.h>
#include "commands.h"


struct stack{
    int *stack;
    size_t size;
    size_t capacity;
    int pop_el;
};

void init_stack(struct stack *self);

ERROR_CODES new_size(struct stack *self, size_t new_capacity);
ERROR_CODES push(struct stack *self, int num);
ERROR_CODES pop(struct stack *self);
ERROR_CODES check_size(struct stack *self);
ERROR_CODES print_el(struct stack *self);




