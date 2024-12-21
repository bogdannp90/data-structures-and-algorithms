#include <iostream>
#include "include/probleme_diverse.h"
#include "include/algoritmi_sortare.h"
#include "include/liste_dinamice.h"
#include "include/grafuri.h"

using namespace std;

// Function prototypes
void displayMainMenu();

int main() {
    int op; //Choice for main menu

    do {
        displayMainMenu();
        cin >> op;

        switch (op) {
            case 1:
                handleProblemeDiverse();
                break;
            case 2:
                handleAlgoritmiSortare();
                break;
            case 3:
                handleListeDinamice();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (op != 0);

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    cout << endl << "ASD PROGRAMS" << endl;
    cout << "1. Various problems" << endl;
    cout << "2. Sorting algorithms" << endl;
    cout << "3. Dynamic lists" << endl;
    cout << "0. Exit program." << endl;
    cout << "Option: ";
}