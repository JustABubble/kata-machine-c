#include "stack.h"
#include <stdlib.h>

struct Stack {
    // TODO: Define your stack structure
    // Common implementations: linked list or dynamic array
};

Stack* stack_create(void) {
    return NULL;
}

void stack_push(Stack *s, int value) {
    (void)s;
    (void)value;
}

int stack_pop(Stack *s) {
    (void)s;
    return 0;
}

int stack_peek(const Stack *s) {
    (void)s;
    return 0;
}

bool stack_is_empty(const Stack *s) {
    (void)s;
    return true;
}

size_t stack_size(const Stack *s) {
    (void)s;
    return 0;
}

void stack_destroy(Stack *s) {
    (void)s;
}
