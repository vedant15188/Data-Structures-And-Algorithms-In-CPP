//
// Created by VEDANT KASHYAP on 1/2/2018.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_STACK_H
#define DATA_STRUCTURES_AND_ALGORITHMS_STACK_H

#endif //DATA_STRUCTURES_AND_ALGORITHMS_STACK_H

struct Stack {
    int top;
    int capacity;
    int *array;
};

void Stack();

struct Stack *createStack(int capacity);

bool isEmpty(struct Stack *stack);

bool isFull(struct Stack *stack);

int Pop(struct Stack *stack);

void printStack(struct Stack *stack);

int size(struct Stack *stack);