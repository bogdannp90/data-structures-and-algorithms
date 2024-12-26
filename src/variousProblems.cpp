// Description: This file contains the implementation of the functions that solve various problems.
#include "variousProblems.h"
#include <iostream>
#include <cmath>

using namespace std;

// Function to solve a quadratic equation
void quadraticEquation(float a, float b, float c) {
    float delta = b * b - 4 * a * c; // Calculate the discriminant
    if (delta >= 0) {
        // Real roots
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\nx2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
    } else {
        // Complex roots
        float im = sqrt(-delta) / (2 * a); // Imaginary part
        float re = -b / (2 * a); // Real part
        cout << "x1 = " << re << " - i*" << im << "\nx2 = " << re << " + i*" << im << endl;
    }
}

// Function to multiply two matrices
void matrixMultiplication(int n, int m, int p, float A[10][10], float B[10][10]) {
    float result[10][10] = {0}; // Initialize result matrix with zeros
    // Multiply matrices A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // Print the result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false; // Numbers less than or equal to 1 are not prime
    if (n == 2) return true; // 2 is the only even prime number
    if (n % 2 == 0) return false; // Even numbers greater than 2 are not prime
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false; // If n is divisible by any number other than 1 and itself, it is not prime
    }
    return true; // n is prime
}

// Function to convert a number to a different base
void baseConversion(int n, int b) {
    if (n > 0) {
        baseConversion(n / b, b); // Recursive call to process the higher order digits
        cout << n % b; // Print the remainder which is the current digit in the new base
    }
}

// Enum for various problems options
enum VariousProblemsOptions {
    EXIT = 0,
    QUADRATIC_EQUATION,
    MATRIX_MULTIPLICATION,
    PRIME_NUMBER_CHECK,
    BASE_CONVERSION
};

// Function to handle "Various Problems"
void handleVariousProblems() {
    int op; // Choice for "Various Problems"
    do {
        // Display the menu
        cout << endl << "Various Problems" << endl;
        cout << "1.1. Solving quadratic equation" << endl;
        cout << "1.2. Matrix multiplication" << endl;
        cout << "1.3. Prime number check" << endl;
        cout << "1.4. Base conversion of a natural number" << endl;
        cout << "1.0. Exit various problems!" << endl;
        cout << "Option for various problems: ";
        cin >> op;
        cout << endl;

        switch (op) {
            case QUADRATIC_EQUATION: {
                // Solve quadratic equation
                float a, b, c;
                cout << "Enter the coefficients of the quadratic equation: ";
                cin >> a >> b >> c;
                cout << endl << "The solution of the equation is: " << endl;
                quadraticEquation(a, b, c);
                break;
            }
            case MATRIX_MULTIPLICATION: {
                // Matrix multiplication
                int n, m, p, q;
                cout << "Enter the dimensions of matrix A: ";
                cin >> n >> m;
                cout << "Enter the dimensions of matrix B: ";
                cin >> q >> p;
                cout << endl;

                if (m == q) {
                    float A[10][10], B[10][10];
                    cout << "Enter the elements of matrix A: ";
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                            cin >> A[i][j];
                    cout << endl;

                    cout << "Enter the elements of matrix B: ";
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                            cin >> B[i][j];
                    cout << endl;
                    cout << "The result of matrix multiplication is:" << endl;
                    matrixMultiplication(n, m, p, A, B);
                } else
                    cout << "The matrices cannot be multiplied!" << endl;
                break;
            }
            case PRIME_NUMBER_CHECK: {
                // Prime number check
                int n;
                cout << "Enter the number you want to check: ";
                cin >> n;
                cout << endl;

                if (isPrime(n))
                    cout << "The number " << n << " is a prime number.";
                else
                    cout << "The number " << n << " is not a prime number.";
                cout << endl;
                break;
            }
            case BASE_CONVERSION: {
                // Base conversion
                int n, b;
                cout << "Enter the number: ";
                cin >> n;
                cout << endl;

                cout << "In which base do you want to convert the number? ";
                cin >> b;
                cout << endl;

                cout << "The number in base " << b << " is: ";
                baseConversion(n, b);
                cout << endl;
                break;
            }
            case EXIT:
                // Exit to main menu
                cout << "Back to the main menu." << endl;
                break;
            default:
                // Invalid option
                cout << "Invalid option! Please enter a number from 0 to 4!" << endl;
        }
    } while (op != 0);
}