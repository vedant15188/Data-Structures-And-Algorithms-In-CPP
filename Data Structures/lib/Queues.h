//
// Created by VEDANT KASHYAP on 1/3/2018.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_QUEUES_H
#define DATA_STRUCTURES_AND_ALGORITHMS_QUEUES_H

#endif //DATA_STRUCTURES_AND_ALGORITHMS_QUEUES_H

struct Queue {
    int front, rear, size, capacity;
    int *array;
};

void Queues();

struct Queue *createQueue(int capacity);

bool isFull(struct Queue *queue);

bool isEmpty(struct Queue *queue);

void Enqueue(struct Queue *queue, int data);

int Dequeue(struct Queue *queue);

void printQueue(struct Queue *queue);

int Front(struct Queue *queue);

int Rear(struct Queue *queue);