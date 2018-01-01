//
// Created by VEDANT KASHYAP on 12/31/2017.
//

#include <iostream>
#include "lib/LinkedList.h"

using namespace std;

void printList(struct LL_node *LL) {
    while (LL != NULL) {
        cout << LL->data << " ";
        LL = LL->next;
    }
    cout << endl;
}

void Delete(struct LL_node **LL, int val) {
    struct LL_node *temp = *LL;
    struct LL_node *prev = NULL;

    if (temp != NULL && temp->data == val) {    // Check if we have to remove the head node itself
        *LL = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != val) { // Find the node with data = val
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;                   // If you don't find the node then return;

    prev->next = temp->next;                      // Previous's next node will be the current's next basically skipping a node

    free(temp);
}

void Insert(struct LL_node **LL, int index, int val) {
    struct LL_node *newNode = (struct LL_node *) malloc(sizeof(struct LL_node));
    struct LL_node *last = *LL;
    newNode->data = val;

    for (int i = 0; i < index - 1; ++i)
        last = last->next;

    newNode->next = last->next;
    last->next = newNode;

    return;
}

void Append(struct LL_node **LL, int val) {
    struct LL_node *newNode = (struct LL_node *) malloc(sizeof(struct LL_node));
    struct LL_node *last = *LL;
    newNode->data = val;
    newNode->next = NULL;

    if (*LL == NULL) {
        *LL = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
}

void Single_LinkedList() {
    struct LL_node *LL = NULL; // Linked List
    int n;              // Size of the Linked List
    int data;           // Data to be put in the nodes of the Linked List

    cout << "Enter the size of the linked list: ";
    cin >> n;

    cout << "Enter the values in the linked list: ";
    for (int i = 0; i < n; ++i) {
        cin >> data;
        Append(&LL, data);
    }
}