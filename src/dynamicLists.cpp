#include "dynamicLists.h"

#include <iostream>
#include <string>

using namespace std;

// Function to create a simple list
number* createSimpleList() {
    number *head = nullptr;
    int value;
    cout << "Enter values for the list (enter -1 to end): ";
    while (cin >> value && value != -1) {
        head = addToSimpleList(head, value);
    }
    return head;
}

// Function to traverse and print a simple list
void traverseSimpleList(number *head) {
    number *current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to add a value to a simple list
number* addToSimpleList(number *head, int value) {
    number *newNode = new number;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

// Function to delete a value from a simple list
number* deleteFromSimpleList(number *head) {
    if (head == nullptr) return nullptr;
    number *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to modify a value in a simple list
number* modifyInSimpleList(number *head, int oldValue, int newValue) {
    number *current = head;
    while (current != nullptr) {
        if (current->value == oldValue) {
            current->value = newValue;
            break;
        }
        current = current->next;
    }
    return head;
}

// Function to create an ordered list
number* createOrderedList() {
    number *head = nullptr;
    int value;
    cout << "Enter values for the ordered list (enter -1 to end): ";
    while (cin >> value && value != -1) {
        head = addToOrderedList(head, value);
    }
    return head;
}

// Function to add a value to an ordered list
number* addToOrderedList(number *head, int value) {
    number *newNode = new number;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr || head->value >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        number *current = head;
        while (current->next != nullptr && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Function to merge two ordered lists
number* mergeLists(number *list1, number *list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    number *mergedHead = nullptr;
    if (list1->value < list2->value) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }

    number *current = mergedHead;
    while (list1 && list2) {
        if (list1->value < list2->value) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedHead;
}

// Function to create a doubly linked list
list2* createDoubleList() {
    list2 *list = new list2;
    list->first = nullptr;
    list->last = nullptr;
    int value;
    cout << "Enter values for the doubly linked list (enter -1 to end): ";
    while (cin >> value && value != -1) {
        list = addToDoubleList(list, value);
    }
    return list;
}

// Function to traverse a doubly linked list forward
void traverseDoubleListForward(const list2 *list) {
    number2 *current = list->first;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to traverse a doubly linked list backward
void traverseDoubleListBackward(const list2 *list) {
    number2 *current = list->last;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}

// Function to add a value to a doubly linked list
list2* addToDoubleList(list2 *list, int value) {
    number2 *newNode = new number2;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = list->last;

    if (list->first == nullptr) {
        list->first = newNode;
        list->last = newNode;
    } else {
        list->last->next = newNode;
        list->last = newNode;
    }
    return list;
}

// Function to delete a value from a doubly linked list
list2* deleteFromDoubleList(list2 *list) {
    if (list->first == nullptr) return list;

    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    number2 *current = list->first;
    while (current != nullptr) {
        if (current->value == value) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                list->first = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                list->last = current->prev;
            }
            delete current;
            break;
        }
        current = current->next;
    }
    return list;
}

// Function to modify a value in a doubly linked list
list2* modifyInDoubleList(list2 *list, int oldValue, int newValue) {
    number2 *current = list->first;
    while (current != nullptr) {
        if (current->value == oldValue) {
            current->value = newValue;
            break;
        }
        current = current->next;
    }
    return list;
}

// Function to create a stack
number* createStack() {
    return createSimpleList();
}

// Function to traverse a stack
void traverseStack(number *head) {
    traverseSimpleList(head);
}

// Function to add a value to a stack
number* addToStack(number *head, int value) {
    return addToSimpleList(head, value);
}

// Function to delete a value from a stack
number* deleteFromStack(number *head) {
    return deleteFromSimpleList(head);
}

// Function to create a queue
list2* createQueue() {
    return createDoubleList();
}

// Function to add a value to a queue
list2* addToQueue(list2 *list, int value) {
    return addToDoubleList(list, value);
}

// Function to delete a value from a queue
list2* deleteFromQueue(list2 *list) {
    if (list->first == nullptr) return list;

    number2 *temp = list->first;
    list->first = list->first->next;
    if (list->first != nullptr) {
        list->first->prev = nullptr;
    } else {
        list->last = nullptr;
    }
    delete temp;
    return list;
}

// Function to traverse a queue
void traverseQueue(const list2 *list) {
    traverseDoubleListForward(list);
}

// Function to create a polynomial
monomial* createPolynomial() {
    monomial *head = nullptr;
    int degree;
    float coefficient;
    cout << "Enter monomials (degree coefficient, enter -1 to end): ";
    while (cin >> degree && degree != -1) {
        cin >> coefficient;
        monomial *newNode = new monomial;
        newNode->degree = degree;
        newNode->coefficient = coefficient;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to add two polynomials
void addPolynomials(monomial *poly1, monomial *poly2) {
    monomial *result = nullptr;
    monomial *current1 = poly1;
    monomial *current2 = poly2;

    while (current1 != nullptr && current2 != nullptr) {
        monomial *newNode = new monomial;
        if (current1->degree == current2->degree) {
            newNode->degree = current1->degree;
            newNode->coefficient = current1->coefficient + current2->coefficient;
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->degree > current2->degree) {
            newNode->degree = current1->degree;
            newNode->coefficient = current1->coefficient;
            current1 = current1->next;
        } else {
            newNode->degree = current2->degree;
            newNode->coefficient = current2->coefficient;
            current2 = current2->next;
        }
        newNode->next = result;
        result = newNode;
    }

    while (current1 != nullptr) {
        monomial *newNode = new monomial;
        newNode->degree = current1->degree;
        newNode->coefficient = current1->coefficient;
        newNode->next = result;
        result = newNode;
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        monomial *newNode = new monomial;
        newNode->degree = current2->degree;
        newNode->coefficient = current2->coefficient;
        newNode->next = result;
        result = newNode;
        current2 = current2->next;
    }

    while (result != nullptr) {
        cout << result->coefficient << "x^" << result->degree << " ";
        result = result->next;
    }
    cout << endl;
}

// Function to multiply two polynomials
void multiplyPolynomials(monomial *poly1, monomial *poly2) {
    monomial *result = nullptr;
    for (monomial *current1 = poly1; current1 != nullptr; current1 = current1->next) {
        for (monomial *current2 = poly2; current2 != nullptr; current2 = current2->next) {
            monomial *newNode = new monomial;
            newNode->degree = current1->degree + current2->degree;
            newNode->coefficient = current1->coefficient * current2->coefficient;
            newNode->next = result;
            result = newNode;
        }
    }

    while (result != nullptr) {
        cout << result->coefficient << "x^" << result->degree << " ";
        result = result->next;
    }
    cout << endl;
}

// Function to sort a polynomial
void sortPolynomial(monomial *poly) {
    if (!poly || !poly->next) return;

    bool sorted;
    do {
        sorted = true;
        monomial *prev = nullptr;
        monomial *current = poly;
        while (current->next != nullptr) {
            if (current->degree < current->next->degree) {
                sorted = false;
                monomial *next = current->next;
                current->next = next->next;
                next->next = current;
                if (prev == nullptr) {
                    poly = next;
                } else {
                    prev->next = next;
                }
                prev = next;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (!sorted);
}

// Function to delete from character stack
character* deleteFromCharacterStack(character *head) {
    if (head == nullptr) {
        cout << "The stack is empty! No values to delete!" << endl;
        return nullptr;
    }
    character *temp = head->next;
    delete head;
    return temp;
}

// Function to check parentheses in an expression
bool checkParentheses(const string &expression) {
    character *stack = nullptr;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            character *newNode = new character;
            newNode->ch = c;
            newNode->next = stack;
            stack = newNode;
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack == nullptr) return false;
            char top = stack->ch;
            stack = deleteFromCharacterStack(stack);
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stack == nullptr;
}

enum DynamicListsOptions {
    EXIT_DYNAMIC_LISTS = 0,
    SINGLY_LINKED_LISTS,
    ORDERED_SINGLY_LINKED_LIST,
    DOUBLY_LINKED_LISTS,
    STACKS,
    QUEUES,
    POLYNOMIALS,
    MERGE_ORDERED_LISTS,
    PARENTHESES_VERIFICATION
};

void handleDynamicLists() {
    int option;
    do {
        cout << endl << "Dynamic Lists" << endl;
        cout << "1. Singly Linked Lists" << endl;
        cout << "2. Ordered Singly Linked List from Input" << endl;
        cout << "3. Doubly Linked Lists" << endl;
        cout << "4. Stacks" << endl;
        cout << "5. Queues" << endl;
        cout << "6. Addition and Multiplication of Two Polynomials" << endl;
        cout << "7. Merging Two Ordered Lists" << endl;
        cout << "8. Parentheses Verification in an Arithmetic Expression" << endl;
        cout << "0. Exit Dynamic Lists!" << endl;

        cout << "Dynamic Lists Option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case SINGLY_LINKED_LISTS: {
                number *list = createSimpleList();
                cout << "List after creation: ";
                traverseSimpleList(list);
                cout << endl;

                int subOption;
                cout << "Do you want to add elements to the list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int value;
                    cout << "Enter value to add: ";
                    cin >> value;
                    list = addToSimpleList(list, value);
                    cout << "List after addition: ";
                    traverseSimpleList(list);
                }
                cout << endl;

                cout << "Do you want to delete elements from the list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    list = deleteFromSimpleList(list);
                    cout << "List after deletion: ";
                    traverseSimpleList(list);
                }
                cout << endl;

                cout << "Do you want to modify elements in the list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int oldValue, newValue;
                    cout << "Enter the element you want to modify: ";
                    cin >> oldValue;
                    cout << "Enter the new value: ";
                    cin >> newValue;
                    list = modifyInSimpleList(list, oldValue, newValue);
                    cout << "List after modification: ";
                    traverseSimpleList(list);
                }
                cout << endl;

                // Deallocate memory
                while (list != nullptr) {
                    list = deleteFromSimpleList(list);
                }
            }
            break;

            case ORDERED_SINGLY_LINKED_LIST: {
                number *list = createOrderedList();
                cout << "List after creation: ";
                traverseSimpleList(list);
                cout << endl;

                int subOption;
                cout << "Do you want to add elements to the ordered list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int value;
                    cout << "Enter value to add to the list: ";
                    cin >> value;
                    list = addToOrderedList(list, value);
                    cout << "List after addition: ";
                    traverseSimpleList(list);
                }
                cout << endl;

                cout << "Do you want to delete elements from the list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    list = deleteFromSimpleList(list);
                    cout << "List after deletion: ";
                    traverseSimpleList(list);
                }
                cout << endl;

                // Deallocate memory
                while (list != nullptr) {
                    list = deleteFromSimpleList(list);
                }
            }
            break;

            case DOUBLY_LINKED_LISTS: {
                list2 *list = createDoubleList();
                cout << "List after creation, traversed forward: ";
                traverseDoubleListForward(list);
                cout << endl;
                cout << "List after creation, traversed backward: ";
                traverseDoubleListBackward(list);
                cout << endl;

                int subOption;
                cout << "Do you want to add elements to the list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int value;
                    cout << "Enter value to add: ";
                    cin >> value;
                    list = addToDoubleList(list, value);
                    cout << "List after addition: ";
                    traverseDoubleListForward(list);
                }
                cout << endl;

                cout << "Do you want to delete elements from the list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    list = deleteFromDoubleList(list);
                    cout << "List after deletion: ";
                    traverseDoubleListForward(list);
                }
                cout << endl;

                cout << "Do you want to modify elements in the list? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int oldValue, newValue;
                    cout << "Enter the element you want to modify: ";
                    cin >> oldValue;
                    cout << "Enter the new value: ";
                    cin >> newValue;
                    list = modifyInDoubleList(list, oldValue, newValue);
                    cout << "List after modification: ";
                    traverseDoubleListForward(list);
                }
                cout << endl;

                // Deallocate memory
                while (list->first != nullptr) {
                    list = deleteFromDoubleList(list);
                }
                delete list;
            }
            break;

            case STACKS: {
                number *stack = createStack();
                cout << "Stack after creation: ";
                traverseStack(stack);
                cout << endl;

                int subOption;
                cout << "Do you want to add elements to the stack? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int value;
                    cout << "Enter value to add: ";
                    cin >> value;
                    stack = addToStack(stack, value);
                    cout << "Stack after addition: ";
                    traverseStack(stack);
                }
                cout << endl;

                cout << "Do you want to delete elements from the stack? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int count;
                    cout << "How many elements do you want to delete from the stack? ";
                    cin >> count;
                    for (int i = 0; i < count; i++) {
                        stack = deleteFromStack(stack);
                    }
                    cout << "Stack after deletion: ";
                    traverseStack(stack);
                }
                cout << endl;

                // Deallocate memory
                while (stack != nullptr) {
                    stack = deleteFromStack(stack);
                }
            }
            break;

            case QUEUES: {
                list2 *queue = createQueue();
                cout << "Queue after creation: ";
                traverseQueue(queue);
                cout << endl;

                int subOption;
                cout << "Do you want to add elements to the queue? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int value;
                    cout << "Enter value to add: ";
                    cin >> value;
                    queue = addToQueue(queue, value);
                    cout << "Queue after addition: ";
                    traverseQueue(queue);
                }
                cout << endl;

                cout << "Do you want to delete elements from the queue? [0/1] ";
                cin >> subOption;
                if (subOption == 1) {
                    int count;
                    cout << "How many elements do you want to delete from the queue? ";
                    cin >> count;
                    for (int i = 0; i < count; i++) {
                        queue = deleteFromQueue(queue);
                    }
                    cout << "Queue after deletion: ";
                    traverseQueue(queue);
                }
                cout << endl;

                // Deallocate memory
                while (queue->first != nullptr) {
                    queue = deleteFromQueue(queue);
                }
                delete queue;
            }
            break;

            case POLYNOMIALS: {
                monomial *poly1 = createPolynomial();
                monomial *poly2 = createPolynomial();

                cout << "The result of adding the polynomials is: ";
                addPolynomials(poly1, poly2);
                cout << endl;

                cout << "The result of multiplying the polynomials is: ";
                multiplyPolynomials(poly1, poly2);
                cout << endl;

                // Deallocate memory
                while (poly1 != nullptr) {
                    monomial *temp = poly1;
                    poly1 = poly1->next;
                    delete temp;
                }
                while (poly2 != nullptr) {
                    monomial *temp = poly2;
                    poly2 = poly2->next;
                    delete temp;
                }
            }
            break;

            case MERGE_ORDERED_LISTS: {
                number *list1 = createOrderedList();
                cout << "First list after creation: ";
                traverseSimpleList(list1);
                cout << endl;

                number *list2 = createOrderedList();
                cout << "Second list after creation: ";
                traverseSimpleList(list2);
                cout << endl;

                number *mergedList = mergeLists(list1, list2);
                cout << "Merged list: ";
                traverseSimpleList(mergedList);
                cout << endl;

                // Deallocate memory
                while (list1 != nullptr) {
                    list1 = deleteFromSimpleList(list1);
                }
                while (list2 != nullptr) {
                    list2 = deleteFromSimpleList(list2);
                }
                while (mergedList != nullptr) {
                    mergedList = deleteFromSimpleList(mergedList);
                }
            }
            break;

            case PARENTHESES_VERIFICATION: {
                string expression;
                cout << "Enter the expression: ";
                cin >> expression;

                cout << "Parentheses verification: ";
                if (checkParentheses(expression)) {
                    cout << "The expression is correct!" << endl;
                } else {
                    cout << "The expression is incorrect!" << endl;
                }
            }
            break;

            case EXIT_DYNAMIC_LISTS:
                cout << "Exiting Dynamic Lists menu." << endl;
                break;

            default:
                cout << "Invalid option! Please enter a number from 0 to 8!" << endl;
                break;
        }
    } while (option != 0);
}