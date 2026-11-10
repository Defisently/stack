#pragma once

typedef enum {
    SUCCESS                 = 0,
    INVALID_SIZE_INPUT      = 1,
    INVALID_INPUT           = 2,
    INVALID_OPERATION_INPUT = 3,
    INVALID_PUSH_INPUT      = 4,
    EMPTY_STACK             = 5,
} ERROR_CODES;

struct stack;

int operations(int command, struct stack *self);

