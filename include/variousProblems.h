#ifndef VARIOUS_PROBLEMS_H
#define VARIOUS_PROBLEMS_H

//Description: Header file for the implementation of the functions that solve various problems.

/**
 * @brief Solves a quadratic equation.
 * @param a Coefficient of x^2.
 * @param b Coefficient of x.
 * @param c Constant term.
 */
void quadraticEquation(float a, float b, float c);

/**
 * @brief Multiplies two matrices.
 * @param n Number of rows in matrix A.
 * @param m Number of columns in matrix A and rows in matrix B.
 * @param p Number of columns in matrix B.
 * @param A First matrix.
 * @param B Second matrix.
 */
void matrixMultiplication(int n, int m, int p, float A[10][10], float B[10][10]);

/**
 * @brief Checks if a number is prime.
 * @param n The number to check.
 * @return True if the number is prime, false otherwise.
 */
bool isPrime(int n);

/**
 * @brief Converts a number to a different base.
 * @param n The number to convert.
 * @param b The base to convert to.
 */
void baseConversion(int n, int b);

/**
 * @brief Handles various problems.
 */
void handleVariousProblems();

#endif // VARIOUS_PROBLEMS_H