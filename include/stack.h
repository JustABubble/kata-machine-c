#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Stack Stack;

// Create a new stack
Stack* stack_create(void);

// Push a value onto the stack
void stack_push(Stack *s, int value);

// Pop a value from the stack
// Returns the popped value (behavior undefined if stack is empty)
int stack_pop(Stack *s);

// Peek at the top value without removing it
// Returns the top value (behavior undefined if stack is empty)
int stack_peek(const Stack *s);

// Check if stack is empty
bool stack_is_empty(const Stack *s);

// Get the number of elements in the stack
size_t stack_size(const Stack *s);

// Destroy the stack and free all memory
void stack_destroy(Stack *s);

#endif // STACK_H
