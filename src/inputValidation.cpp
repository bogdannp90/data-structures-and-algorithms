// Description: This file contains the input validation functions.

#include "../include/inputValidation.h"
#include <iostream>
#include <limits>

using namespace std;

// Function to handle invalid input
void handleInvalidInput() {
    cout << "Invalid input! Please enter an integer: ";
}

// Function to handle user choice
int handleUserChoice(int choice) {
    while ( !(cin>>choice)) {
        handleInvalidInput();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

// Function to handle input for the number of elements in the array
int handleUserInputForArraySize(int number) {
    while ( !(cin>>number) || number < 1 ) {
        cout << "Invalid input! Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}

// Function to handle input for the elements of the array
float handleUserInputFloat(float element) {
    while ( !(cin>>element)) {
        cout << "Invalid input! Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return element;
}

// Function to handle input for the coefficients of a quadratic equation
float handleUserInputForQuadraticEquation(float element) {
    while ( !(cin>>element)) {
        cout << "Invalid input! Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return element;
}

// Function to handle input for the dimensions of a matrix
int handleUserInputForMatrixDimension(int dimension) {
    while ( !(cin>>dimension) || dimension < 1 || dimension > 10 ) {
        cout << "Invalid input! Please enter a positive integer less than or equal to 10: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return dimension;
}

// Function to handle input for a number
int handleUserInputInteger(int number) {
    while ( !(cin>>number)) {
        handleInvalidInput();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}
