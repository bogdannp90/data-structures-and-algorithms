#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H


#include <iostream>
#include <functional>

/**
 * @brief Handles user input with validation.
 *
 * @tparam T The type of input to handle.
 * @param message The message to display to the user.
 * @param condition The condition to validate the input.
 * @param error_message The error message to display if the input is invalid.
 * @return T The validated user input.
 */
template <typename T>
T handleUserInput(const std::string &message, std::function<bool(T)> condition, const std::string &error_message) {
    T input;
    std::cout << message;
    while (!(std::cin >> input) || !condition(input)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << error_message;
    }
    return input;
}

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