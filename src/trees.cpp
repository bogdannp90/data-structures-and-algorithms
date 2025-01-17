
#include "trees.h"
#include <iostream>
#include "inputValidation.h"
using namespace std;

treeNode *createBinaryTree() {
    int value;
    cin >> value;
    cout << endl;
    // Base case: -1 indicates a null node
    if (value == -1) {
        return nullptr;
    }

    // Create a new node
    treeNode* newNode = new treeNode(value);

    cout << "Enter left child of " << value << "(-1 for NULL):";
    newNode->left = createBinaryTree(); // Recursive call for left subtree

    cout << "Enter right child of " << value << "(-1 for NULL):";
    newNode->right = createBinaryTree(); // Recursive call for right subtree

    return newNode;
}

void traverseInorder(treeNode *root) {
    if (root == nullptr) {
        return;
    }

    traverseInorder(root->left);
    cout << root->value << " ";
    traverseInorder(root->right);
}

void traversePostorder(treeNode *root) {
    if (root == nullptr) {
        return;
    }

    traversePostorder(root->left);
    traversePostorder(root->right);
    cout << root->value << " ";
}

void traversePreorder(treeNode *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->value << " ";
    traversePreorder(root->left);
    traversePreorder(root->right);
}

enum TreesMenuOptions {
    EXIT = 0,
    CREATE_BINARY_TREES,
    TRAVERSE_BINARY_TREES
};

void displayTreesMenu() {
    cout << endl;
    cout << "TREES " << endl;
    cout << "4.1. Create binary trees" << endl;
    cout << "4.2. Traverse Inorder (SRD), Postorder (SDR), Preorder (RSD) for binary trees." << endl;
    cout << "4.0. Exit Trees." << endl;
}

void handleTrees() {
    int choice = 0;
    do {
        displayTreesMenu();
        choice = handleUserInput<int>("Trees Problem Option: ",
                                      [](const int x) { return x >= 0 && x <= 2; },
                                      "Invalid input! Please enter a number between 0 and 2: ");
        cout << endl;

        switch (choice) {
            case CREATE_BINARY_TREES: {
                cout << "Create a binary tree: " << endl;
                cout << "Enter the root node(-1 for NULL): ";
                treeNode *root = createBinaryTree();
                cout << "Inorder traversal(SRD): ";
                traverseInorder(root);
                cout << endl;
            }
            break;

            case TRAVERSE_BINARY_TREES: {
                int localChoice;
                cout << "Create a binary tree: " << endl;
                cout << "Enter the root node(-1 for NULL): ";
                treeNode *root = createBinaryTree();

                do {

                    localChoice = handleUserInput<int>(
                        "1. Inorder traversal(SRD)\n2. Postorder traversal(SDR)\n3. Preorder traversal(RSD)\n0. Exit \nEnter your choice: ",
                        [](const int x) { return x >= 0 && x <= 3; },
                        "Invalid input! Please enter a number between 1 and 3: ");

                    switch (localChoice) {
                        case 1: {
                            cout << "Inorder traversal: ";
                            traverseInorder(root);
                            cout << endl;
                        }
                        break;
                        case 2: {
                            cout << "Postorder traversal: ";
                            traversePostorder(root);
                            cout << endl;
                        }
                        break;
                        case 3: {
                            cout << "Preorder traversal: ";
                            traversePreorder(root);
                            cout << endl;
                        }
                        break;
                        default:
                            cout << "Invalid option! Please enter a number from 1 to 3!" << endl;
                        break;

                        case EXIT:
                            cout << "Exiting Trees menu." << endl;
                        break;
                    }
                } while (localChoice != EXIT);
            }
            break;

            case EXIT:
                cout << "Exiting Trees menu." << endl;
            break;

            default: {
                cout << "Invalid option! Please enter a number from 0 to 2!" << endl;
            }
        }
    }while (choice != EXIT);
}
