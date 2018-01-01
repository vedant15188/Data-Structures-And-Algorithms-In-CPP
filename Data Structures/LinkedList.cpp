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

    printList(LL);

//    Insert(LL,0,0,n);
}