//
// Created by Bogdan Pîrvu on 17.01.2025.
//

#ifndef TREES_H
#define TREES_H

struct treeNode {
    int value;
    treeNode* left;
    treeNode* right;

    // Constructor
    explicit treeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

treeNode* createBinaryTree();

void traverseInorder(treeNode* root); // SRD (Left-Root-Right)

void traversePostorder(treeNode* root);  // SDR (Left-Right-Root)

void traversePreorder(treeNode* root);  // RSD (Root-Left-Right)

void displayTreesMenu();

void handleTrees();



#endif //TREES_H
