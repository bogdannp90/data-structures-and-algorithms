#ifndef DYNAMIC_LISTS_H
#define DYNAMIC_LISTS_H

#include <string>

// Struct for singly linked list node
struct number {
    int value;
    number *next;
};

// Struct for doubly linked list node
struct number2 {
    int value;
    number2 *next;
    number2 *prev;
};

// Struct for doubly linked list
struct list2 {
    number2 *first;
    number2 *last;
};

// Struct for polynomial monomial
struct monomial {
    int degree;
    float coefficient;
    monomial *next;
};

// Struct for character stack node
struct character {
    char ch;
    character *next;
};

// Function declarations for singly linked list
number *createSimpleList();
void traverseSimpleList(number *head);
number *deleteFromSimpleList(number *head);
number *addToSimpleList(number *head, int value);
number *modifyInSimpleList(number *head, int oldValue, int newValue);
number *createOrderedList();
number *addToOrderedList(number *head, int value);
number *mergeLists(number *list1, number *list2);

// Function declarations for doubly linked list
list2 *createDoubleList();
void traverseDoubleListForward(const list2 *list);
void traverseDoubleListBackward(const list2 *list);
list2 *addToDoubleList(list2 *list, int value);
list2 *deleteFromDoubleList(list2 *list);
list2 *modifyInDoubleList(list2 *list, int oldValue, int newValue);

// Function declarations for stack
number *createStack();
void traverseStack(number *head);
number *addToStack(number *head, int value);
number *deleteFromStack(number *head);

// Function declarations for queue
list2 *createQueue();
list2 *addToQueue(list2 *list, int value);
list2 *deleteFromQueue(list2 *list);
void traverseQueue(const list2 *list);

// Function declarations for polynomial operations
monomial *createPolynomial();
void addPolynomials(monomial *poly1, monomial *poly2);
void multiplyPolynomials(monomial *poly1, monomial *poly2);
void sortPolynomial(monomial *poly);
void printPolynomial(monomial *poly);

// Function declarations for parentheses verification
bool checkParentheses(const std::string &expression);

// Function declarations for character stack
character *deleteFromCharacterStack(const character *head);

// Function to handle dynamic lists
void handleDynamicLists();

#endif // DYNAMIC_LISTS_H