#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

/**
 * @brief Handles invalid input.
 */
void handleInvalidInput();

/**
 * @brief Handles the user's choice input.
 * @param choice The user's choice.
 * @return Processed user choice.
 */
int handleUserChoice(int choice);

/**
 * @brief Handles the user's input for array size.
 * @param number The input number for array size.
 * @return Validated array size.
 */
int handleUserInputForArraySize(int number);

/**
 * @brief Handles the user's input for a float value.
 * @param element The input float value.
 * @return Validated float value.
 */
float handleUserInputFloat(float element);

/**
 * @brief Handles the user's input for a quadratic equation element.
 * @param element The input float value for the quadratic equation.
 * @return Validated float value.
 */
float handleUserInputForQuadraticEquation(float element);

/**
 * @brief Handles the user's input for matrix dimension.
 * @param dimension The input dimension for the matrix.
 * @return Validated matrix dimension.
 */
int handleUserInputForMatrixDimension(int dimension);

/**
 * @brief Handles the user's input for an integer value.
 * @param number The input integer value.
 * @return Validated integer value.
 */
int handleUserInputInteger(int number);

#endif //INPUTVALIDATION_H