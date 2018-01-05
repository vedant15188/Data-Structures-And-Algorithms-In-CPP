//
// Created by VEDANT KASHYAP on 1/4/2018.
//

#include <iostream>
#include "lib/BinaryTree.h"
#include <queue>
#include <stack>

using namespace std;

struct BTnode *createNode(int data) {
    struct BTnode *node = (struct BTnode *) malloc(sizeof(struct BTnode));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void BFS(struct BTnode *root) {
    queue<struct BTnode *> queue1;
    if (root == NULL) return;
    cout << root->data << " ";
    if (root->left != NULL) cout << root->left->data << " " << root->right->data << " ";
    if (root->left->left == NULL) return;

    queue1.push(root->left);
    queue1.push(root->right);

    BTnode *first = NULL;
    BTnode *second = NULL;

    while (!queue1.empty()) {
        first = queue1.front();
        queue1.pop();
        second = queue1.front();
        queue1.pop();

        cout << first->left->data << " " << first->right->data << " ";
        cout << second->left->data << " " << second->right->data << " ";

        if (first->left->left != NULL) {
            queue1.push(first->left);
            queue1.push(first->right);
            queue1.push(second->left);
            queue1.push(second->right);
        }
    }
    cout << endl;
}

void DFSPreOrder(struct BTnode *root) {
    if (root == NULL) return;

    stack<BTnode *> stack1;
    stack1.push(root);

    while (!stack1.empty()) {
        struct BTnode *temp = stack1.top();
        stack1.pop();
        cout << temp->data << " ";

        if (temp->right) stack1.push(temp->right);
        if (temp->left) stack1.push(temp->left);
    }
    cout << endl;
}

void BinaryTree() {
    struct BTnode *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

//    root->left->left->left = createNode(8);
//    root->left->left->right = createNode(9);
//    root->left->right->left = createNode(10);
//    root->left->right->right = createNode(11);
//    root->right->left->left = createNode(12);
//    root->right->left->right = createNode(13);
//    root->right->right->left = createNode(14);
//    root->right->right->right = createNode(15);
//
//    root->left->left->left->left = createNode(16);
//    root->left->left->left->right = createNode(17);
//    root->left->left->right->left = createNode(18);
//    root->left->left->right->right = createNode(19);
//    root->left->right->left->left = createNode(20);
//    root->left->right->left->right = createNode(21);
//    root->left->right->right->left = createNode(22);
//    root->left->right->right->right = createNode(23);
//    root->right->left->left->left = createNode(24);
//    root->right->left->left->right = createNode(25);
//    root->right->left->right->left = createNode(26);
//    root->right->left->right->right = createNode(27);
//    root->right->right->left->left = createNode(28);
//    root->right->right->left->right = createNode(29);
//    root->right->right->right->left = createNode(30);
//    root->right->right->right->right = createNode(31);

    DFSInOrder(root);
}
