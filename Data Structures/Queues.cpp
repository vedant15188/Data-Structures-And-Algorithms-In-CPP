//
// Created by VEDANT KASHYAP on 1/3/2018.
//

#include <iostream>
#include "lib/Queues.h"

using namespace std;

struct Queue *createQueue(int capacity) {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = -1;
    queue->array = (int *) malloc(sizeof(int) * capacity);
    return queue;
}

void printQueue(struct Queue *queue) {
    for (int i = queue->rear; i >= queue->front; --i) {
        cout << queue->array[i] << " ";
    }
    cout << endl;
}

bool isFull(struct Queue *queue) { return queue->size == queue->capacity; }

bool isEmpty(struct Queue *queue) { return queue->size == 0; }

int Dequeue(struct Queue *queue) {
    if (isEmpty(queue)) return INT32_MIN;
    int temp = queue->array[queue->front];
    queue->front = (queue->front + 1);
    queue->size--;
    return temp;
}

void Enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        cout << "Queue is full! Dequeue to get more space." << endl;
        return;
    }
    queue->rear = (queue->rear + 1);
    queue->array[queue->rear] = data;
    queue->size++;
}

int Front(struct Queue *queue) {
    if (isEmpty(queue)) return INT32_MIN;
    return queue->array[queue->front];
}

int Rear(struct Queue *queue) {
    if (isEmpty(queue)) return INT32_MIN;
    return queue->array[queue->rear];
}

void Queues() {
    int capacity;   // Total capacity of the queue
    int choice;     // Determines which function to run
    int data;
    struct Queue *queue;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;
    queue = createQueue(capacity);

    while (1) {
        cout
                << "0 - QUIT\n1 - Print Queue\n2 - Enqueue data\n3 - Dequeue data\n4 - Check if queue is empty\n5 - Check if queue is full\n6 - Print the element in thr front\n7 - Print the element in the rear"
                << endl;
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) printQueue(queue);
        else if (choice == 2) {
            cout << "Input the data you want to enqueue: ";
            cin >> data;
            Enqueue(queue, data);
        } else if (choice == 3) cout << "Dequeued element: " << Dequeue(queue) << endl;
        else if (choice == 4) {
            if (isEmpty(queue))
                cout << "Queue is empty!" << endl;
            else
                cout << "Queue is NOT empty!" << endl;
        } else if (choice == 5) {
            if (isFull(queue))
                cout << "Queue is full!" << endl;
            else
                cout << "Queue is NOT full!" << endl;
        } else if (choice == 6) cout << "The front element is " << Front(queue) << endl;
        else if (choice == 7) cout << "The rear element is " << Rear(queue) << endl;
        else cout << "Choose a valid option i.e. A number between 0-7" << endl;
    }
}