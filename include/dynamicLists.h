#ifndef DYNAMIC_LISTS_H
#define DYNAMIC_LISTS_H

#include <string>

// Struct for singly linked list node
struct number {
    int value;      ///< Value of the node
    number *next;   ///< Pointer to the next node
};

// Struct for doubly linked list node
struct number2 {
    int value;      ///< Value of the node
    number2 *next;  ///< Pointer to the next node
    number2 *prev;  ///< Pointer to the previous node
};

// Struct for doubly linked list
struct list2 {
    number2 *first; ///< Pointer to the first node
    number2 *last;  ///< Pointer to the last node
};

// Struct for polynomial monomial
struct monomial {
    int degree;         ///< Degree of the monomial
    float coefficient;  ///< Coefficient of the monomial
    monomial *next;     ///< Pointer to the next monomial
};

// Struct for character stack node
struct character {
    char ch;            ///< Character value of the node
    character *next;    ///< Pointer to the next node
};

// Function declarations for singly linked list

/**
 * @brief Creates a simple singly linked list.
 * @return Pointer to the head of the list.
 */
number *createSimpleList();

/**
 * @brief Traverses a simple singly linked list.
 * @param head Pointer to the head of the list.
 */
void traverseSimpleList(number *head);

/**
 * @brief Deletes a node from a simple singly linked list.
 * @param head Pointer to the head of the list.
 * @return Pointer to the new head of the list.
 */
number *deleteFromSimpleList(number *head);

/**
 * @brief Adds a node to a simple singly linked list.
 * @param head Pointer to the head of the list.
 * @param value Value to be added.
 * @return Pointer to the new head of the list.
 */
number *addToSimpleList(number *head, int value);

/**
 * @brief Modifies a node in a simple singly linked list.
 * @param head Pointer to the head of the list.
 * @param oldValue Value to be modified.
 * @param newValue New value to be set.
 * @return Pointer to the head of the list.
 */
number *modifyInSimpleList(number *head, int oldValue, int newValue);

/**
 * @brief Creates an ordered singly linked list.
 * @return Pointer to the head of the list.
 */
number *createOrderedList();

/**
 * @brief Adds a node to an ordered singly linked list.
 * @param head Pointer to the head of the list.
 * @param value Value to be added.
 * @return Pointer to the new head of the list.
 */
number *addToOrderedList(number *head, int value);

/**
 * @brief Merges two singly linked lists.
 * @param list1 Pointer to the head of the first list.
 * @param list2 Pointer to the head of the second list.
 * @return Pointer to the head of the merged list.
 */
number *mergeLists(number *list1, number *list2);

// Function declarations for doubly linked list

/**
 * @brief Creates a doubly linked list.
 * @return Pointer to the list.
 */
list2 *createDoubleList();

/**
 * @brief Traverses a doubly linked list forward.
 * @param list Pointer to the list.
 */
void traverseDoubleListForward(const list2 *list);

/**
 * @brief Traverses a doubly linked list backward.
 * @param list Pointer to the list.
 */
void traverseDoubleListBackward(const list2 *list);

/**
 * @brief Adds a node to a doubly linked list.
 * @param list Pointer to the list.
 * @param value Value to be added.
 * @return Pointer to the updated list.
 */
list2 *addToDoubleList(list2 *list, int value);

/**
 * @brief Deletes a node from a doubly linked list.
 * @param list Pointer to the list.
 * @return Pointer to the updated list.
 */
list2 *deleteFromDoubleList(list2 *list);

/**
 * @brief Modifies a node in a doubly linked list.
 * @param list Pointer to the list.
 * @param oldValue Value to be modified.
 * @param newValue New value to be set.
 * @return Pointer to the updated list.
 */
list2 *modifyInDoubleList(list2 *list, int oldValue, int newValue);

// Function declarations for stack

/**
 * @brief Creates a stack.
 * @return Pointer to the head of the stack.
 */
number *createStack();

/**
 * @brief Traverses a stack.
 * @param head Pointer to the head of the stack.
 */
void traverseStack(number *head);

/**
 * @brief Adds a node to a stack.
 * @param head Pointer to the head of the stack.
 * @param value Value to be added.
 * @return Pointer to the new head of the stack.
 */
number *addToStack(number *head, int value);

/**
 * @brief Deletes a node from a stack.
 * @param head Pointer to the head of the stack.
 * @return Pointer to the new head of the stack.
 */
number *deleteFromStack(number *head);

// Function declarations for queue

/**
 * @brief Creates a queue.
 * @return Pointer to the queue.
 */
list2 *createQueue();

/**
 * @brief Adds a node to a queue.
 * @param list Pointer to the queue.
 * @param value Value to be added.
 * @return Pointer to the updated queue.
 */
list2 *addToQueue(list2 *list, int value);

/**
 * @brief Deletes a node from a queue.
 * @param list Pointer to the queue.
 * @return Pointer to the updated queue.
 */
list2 *deleteFromQueue(list2 *list);

/**
 * @brief Traverses a queue.
 * @param list Pointer to the queue.
 */
void traverseQueue(const list2 *list);

// Function declarations for polynomial operations

/**
 * @brief Creates a polynomial.
 * @return Pointer to the polynomial.
 */
monomial *createPolynomial();

/**
 * @brief Adds two polynomials.
 * @param poly1 Pointer to the first polynomial.
 * @param poly2 Pointer to the second polynomial.
 */
void addPolynomials(monomial *poly1, monomial *poly2);

/**
 * @brief Multiplies two polynomials.
 * @param poly1 Pointer to the first polynomial.
 * @param poly2 Pointer to the second polynomial.
 */
void multiplyPolynomials(monomial *poly1, monomial *poly2);

/**
 * @brief Sorts a polynomial.
 * @param poly Pointer to the polynomial.
 */
void sortPolynomial(monomial *poly);

/**
 * @brief Prints a polynomial.
 * @param poly Pointer to the polynomial.
 */
void printPolynomial(monomial *poly);

// Function declarations for parentheses verification

/**
 * @brief Checks if the parentheses in an expression are balanced.
 * @param expression The expression to be checked.
 * @return True if the parentheses are balanced, false otherwise.
 */
bool checkParentheses(const std::string &expression);

// Function declarations for character stack

/**
 * @brief Deletes a node from a character stack.
 * @param head Pointer to the head of the stack.
 * @return Pointer to the new head of the stack.
 */
character *deleteFromCharacterStack(const character *head);

// Function to handle dynamic lists

/**
 * @brief Handles dynamic lists.
 */
void handleDynamicLists();

#endif // DYNAMIC_LISTS_H