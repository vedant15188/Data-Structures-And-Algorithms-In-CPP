//
// Created by VEDANT KASHYAP on 1/4/2018.
//

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_BINARYTREE_H
#define DATA_STRUCTURES_AND_ALGORITHMS_BINARYTREE_H

#endif //DATA_STRUCTURES_AND_ALGORITHMS_BINARYTREE_H

struct BTnode {
    int data;
    struct BTnode *left;
    struct BTnode *right;
};

void BinaryTree();

struct BTnode *createNode(int data);

void BFS(struct BTnode *root);

void DFSPreOrder(struct BTnode *root);

void DFSInOrder(struct BTnode *root);