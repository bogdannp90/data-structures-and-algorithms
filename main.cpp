#include <iostream>
#include <limits>

#include "include/variousProblems.h"
#include "include/sortingAlgorithms.h"
#include "include/dynamicLists.h"
#include "include/graphs.h"

using namespace std;

// Enum for main menu options
enum MainMenuOptions {
    EXIT = 0,
    VARIOUS_PROBLEMS,
    SORTING_ALGORITHMS,
    DYNAMIC_LISTS
};

// Function prototypes
void displayMainMenu();
void handleInvalidInput();
void handleInvalidOption();

int main() {
    int op; // Choice for main menu

    do {
        displayMainMenu();
        cin>>op;

        switch (op) {
            case VARIOUS_PROBLEMS:
                handleVariousProblems();
                break;
            case SORTING_ALGORITHMS:
                handleSortingAlgorithms();
                break;
            case DYNAMIC_LISTS:
                handleDynamicLists();
                break;
            case EXIT:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Please enter a number from 0 to 3!" << endl;
                break;
        }
    } while (op != EXIT);

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    cout << endl << "DATA STRUCTURES AND ALGORITHMS PROGRAMS" << endl;
    cout << "1. Various problems" << endl;
    cout << "2. Sorting algorithms" << endl;
    cout << "3. Dynamic lists" << endl;
    cout << "0. Exit program" << endl;
    cout << "Option: ";
}
