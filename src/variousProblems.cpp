//Description: This file contains the implementation of the functions that solve various problems.
#include "variousProblems.h"
#include <iostream>
#include <cmath>

using namespace std;

void quadraticEquation(float a, float b, float c) {
    float delta = b * b - 4 * a * c;
    if (delta >= 0) {
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\nx2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
    } else {
        float im = sqrt(-delta) / (2 * a);
        float re = -b / (2 * a);
        cout << "x1 = " << re << " - i*" << im << "\nx2 = " << re << " + i*" << im << endl;
    }
}

void matrixMultiplication(int n, int m, int p, float A[10][10], float B[10][10]) {
    float result[10][10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void baseConversion(int n, int b) {
    if (n > 0) {
        baseConversion(n / b, b);
        cout << n % b;
    }
}

// Function to handle "Various Problems"
void handleVariousProblems() {
    int op; //Choice for "Various Problems"
    do {
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
            case 1: {
                float a, b, c;
                cout << "Enter the coefficients of the quadratic equation: ";
                cin >> a >> b >> c;
                cout << endl << "The solution of the equation is: " << endl;
                quadraticEquation(a, b, c);
                break;
            }
            case 2: {
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
            case 3: {
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
            case 4: {
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
            case 0:
                cout << "Back to the main menu." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (op != 0);
}

//
// Created by Bogdan on 12/20/2024.
//