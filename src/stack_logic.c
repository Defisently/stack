#include "commands.h"
#include <stddef.h>
#include <stdlib.h>
#include "stack_logic.h"
#include <stdio.h>
#include "io.h"


void init_stack(struct stack *self){
    self->stack = NULL;
    self->size = 0;
    self->capacity = 0;
    self->pop_el = 0;
}


ERROR_CODES new_size(struct stack *self, size_t new_capacity){

    SOFT_ASSERT(new_capacity < (self->size), "New size < count elements\n", return INVALID_SIZE_INPUT);

    self->stack = realloc(self->stack, new_capacity * sizeof(int));
    self->capacity = new_capacity;
    return SUCCESS;
}

ERROR_CODES push(struct stack *self, int num){
    ERROR_CODES err = SUCCESS;
    int new_capacity = 0;
    if (self->capacity == 0){
        self->capacity = 1;
        self->stack = calloc(self->capacity, sizeof(int));
    }
    if (self->size == self->capacity){
        new_capacity = self->capacity + 2 * (self->capacity);
        err = new_size(self, new_capacity);
    }

    self->stack[self->size] = num;
    self->size++;

    return SUCCESS;
}

ERROR_CODES pop(struct stack *self){
    int new_capacity = 0;
    ERROR_CODES err = SUCCESS;

    SOFT_ASSERT(self->size == 0, "Stack is empty", return INVALID_OPERATION_INPUT);

    self->pop_el = self->stack[self->size - 1];
    self->stack[self->size - 1] = 0;
    self->size--;
    if (self->size <= 2 * self->capacity){
        new_capacity = self->capacity / 1.5;
        err = new_size(self, new_capacity);
    }
    printf("Pop_el = %d\n", self->pop_el);
    return err;

}


ERROR_CODES check_size(struct stack *self){
    printf("Stack size: %zu\n", self->size);
    return SUCCESS;
}

ERROR_CODES print_el(struct stack *self){
    SOFT_ASSERT(self->size == 0, "Stack is empty", return EMPTY_STACK);
    printf("Stack elements: ");
    for (size_t i = 0; i < self->size; i++){
        printf("%d ", self->stack[i]);
    }
    printf("\n");
    return SUCCESS;
}


