//
// Created by VEDANT KASHYAP on 1/2/2018.
//

#include <iostream>
#include "lib/Stack.h"

using namespace std;

struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->array = ((int *) malloc(sizeof(int) * capacity));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

int size(struct Stack *stack) { return stack->top + 1; }

void printStack(struct Stack *stack) {
    for (int i = 0; i < stack->top + 1; ++i) {
        cout << stack->array[i] << " ";
    }
    cout << endl;
}

bool isEmpty(struct Stack *stack) { return stack->top == -1; }

bool isFull(struct Stack *stack) { return stack->top == stack->capacity - 1; }

void Push(struct Stack *stack, int val) {
    if (isFull(stack)) {
        cout << "The Stack is full! You cannot push more values!" << endl;
        return;
    }
    stack->array[++stack->top] = val;
}

int Pop(struct Stack *stack) {
    if (isEmpty(stack)) return INT32_MIN;
    return stack->array[stack->top--];
}

void Stack() {
    int capacity;       // Total size of the Stack
    int choice;         // Decides which function to is executed
    int data;
    cout << "Input the maximum size of the stack: ";
    cin >> capacity;
    struct Stack *stack = createStack(capacity);

    while (1) {
        cout
                << "0 - QUIT\n1 - Print Stack\n2 - Print size of the stack\n3 - Push a value into the stack\n4 - Pop\n5 - Check if stack is empty\n6 - Check if stack is full"
                << endl;
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) printStack(stack);
        else if (choice == 2) cout << "The side of the stack is " << size(stack) << endl;
        else if (choice == 3) {
            cout << "Input the value to be pushed: ";
            cin >> data;
            Push(stack, data);
        } else if (choice == 4) cout << "The value removed: " << Pop(stack) << endl;
        else if (choice == 5) {
            if (isEmpty(stack)) cout << "The Stack is empty!" << endl;
            else cout << "The Stack is NOT empty!" << endl;
        } else if (choice == 6) {
            if (isFull(stack)) cout << "The Stack is full!" << endl;
            else cout << "The Stack is NOT full!" << endl;
        } else cout << "Choose a valid option i.e. a number from 0-6" << endl;
    }
}