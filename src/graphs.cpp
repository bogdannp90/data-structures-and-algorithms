// Description: This file contains the function definitions for graphs
#include "graphs.h"
#include <iostream>
#include "inputValidation.h"
using namespace std;

// // Function to convert an adjacency matrix to an adjacency list
// node* adjMatrixToList(int **AdjMatrix, const int MATRIX_SIZE) {
//
//     node **list = new node*[MATRIX_SIZE];
//
//     for (int i=0; i < MATRIX_SIZE; i++) {
//         for (int j = 0; j< MATRIX_SIZE; j++) {
//             cout << AdjMatrix[i][j] << " ";
//         }
//     }
//
//     for (int i = 0; i < MATRIX_SIZE; i++) {
//         node *newHead = new node;
//         newHead->value = i;
//         newHead->next = nullptr;
//         node *current = newHead;
//         for (int j = 0; j < MATRIX_SIZE; j++) {
//             if (AdjMatrix[i][j] == 1) {
//                 node *newNode = new node;
//                 newNode->value = j;
//                 newNode->next = nullptr;
//                 current->next = newNode;
//             }
//         }
//         list[i] = newHead;
//     }
//
//     return *list;
// }
//
// // Function to convert an adjacency list to an adjacency matrix
// int** ListToAdjMatrix(node **list) {
//     // Get dimensions of the list
//
//     int **AdjMatrix = new int*[LIST_SIZE];
//     for (int i = 0; i < LIST_SIZE; i++) {
//         AdjMatrix[i] = new int[LIST_SIZE];
//     }
//
//     for (int i = 0; i < LIST_SIZE; i++) {
//         node *current = list[i];
//         while (current != nullptr) {
//             AdjMatrix[i][current->value] = 1;
//             current = current->next;
//         }
//     }
//
//     return AdjMatrix;
// }
//
//
// enum GraphProblemsOptions {
//     EXIT = 0,                       ///< Option to exit the graph problems
//     CONVERT_ADJ_MATRIX_TO_LIST = 1, ///< Option to convert an adjacency matrix to an adjacency list
//     CONVERT_LIST_TO_ADJ_MATRIX,     ///< Option to convert an adjacency list to an adjacency matrix
// };
//
// void handleGraphs() {
//     int choice = 0;
//     do {
//         cout << endl << "GRAPH PROBLEMS" << endl;
//         cout << "1. Convert adjacency matrix to adjacency list" << endl;
//         cout << "2. Convert adjacency list to adjacency matrix" << endl;
//         cout << "0. Exit Graph Problems!" << endl;
//         cout << "Graph Problem Option: ";
//
//         choice = handleUserChoice(choice);
//         cout << endl;
//         switch (choice) {
//             case CONVERT_ADJ_MATRIX_TO_LIST: {
//                 int MATRIX_SIZE = 0;
//                 MATRIX_SIZE = handleUserInputInteger(MATRIX_SIZE);
//
//                 int AdjMatrix[MATRIX_SIZE][MATRIX_SIZE];
//
//                 AdjMatrix[0][0] = 0;
//                 AdjMatrix[0][1] = 1;
//                 AdjMatrix[0][2] = 1;
//                 AdjMatrix[1][0] = 1;
//                 AdjMatrix[1][1] = 0;
//                 AdjMatrix[1][2] = 0;
//                 AdjMatrix[2][0] = 1;
//                 AdjMatrix[2][1] = 0;
//                 AdjMatrix[2][2] = 0;
//
//                 node *list = adjMatrixToList(AdjMatrix[MATRIX_SIZE][MATRIX_SIZE], MATRIX_SIZE);
//                 cout << "Adjacency list: " << endl;
//                 for (int i = 0; i < 3; i++) {
//                     cout << i << ": ";
//                     node *current = list;
//                     while (current != nullptr) {
//                         cout << current->value << " ";
//                         current = current->next;
//                     }
//                     cout << endl;
//                 }
//                 break;
//             }
//             case CONVERT_LIST_TO_ADJ_MATRIX: {
//                 int MATRIX_SIZE = 0;
//                 MATRIX_SIZE = handleUserInputInteger(MATRIX_SIZE);
//
//                 node **list = new node*[3];
//                 list[0] = new node;
//                 list[0]->value = 1;
//                 list[0]->next = new node;
//                 list[0]->next->value = 2;
//                 list[0]->next->next = nullptr;
//
//                 list[1] = new node;
//                 list[1]->value = 0;
//                 list[1]->next = nullptr;
//
//                 list[2] = new node;
//                 list[2]->value = 0;
//                 list[2]->next = nullptr;
//
//                 int AdjMatrix[MATRIX_SIZE][MATRIX_SIZE] = ListToAdjMatrix(list);
//                 cout << "Adjacency matrix: " << endl;
//                 for (int i = 0; i < 3; i++) {
//                     for (int j = 0; j < 3; j++) {
//                         cout << AdjMatrix[i][j] << " ";
//                     }
//                     cout << endl;
//                 }
//                 break;
//             }
//
//             default: {
//                 cout << "Invalid option! Please enter a number from 0 to 2!" << endl;
//                 break;
//             }
//         }
//     }while ( choice != EXIT);
//
//
// }
