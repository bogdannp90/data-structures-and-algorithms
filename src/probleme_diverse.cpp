#include "probleme_diverse.h"
#include <iostream>
#include <cmath>

using namespace std;

void ecuatieDeGradul2(float a, float b, float c) {
    float delta = b * b - 4 * a * c;
    if (delta >= 0) {
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\nx2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
    } else {
        float im = sqrt(-delta) / (2 * a);
        float re = -b / (2 * a);
        cout << "x1 = " << re << " - i*" << im << "\nx2 = " << re << " + i*" << im << endl;
    }
}

void inmultireMatrici(int n, int m, int p, float A[10][10], float B[10][10]) {
    float rezultat[10][10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                rezultat[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << rezultat[i][j] << " ";
        }
        cout << endl;
    }
}

bool nrPrim(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void schimbareBaza(int n, int b) {
    if (n > 0) {
        schimbareBaza(n / b, b);
        cout << n % b;
    }
}

// Function to handle "Probleme diverse"
void handleProblemeDiverse() {
    int op; //Choice for "Probleme diverse"
    do {
        cout << endl << "Probleme diverse" << endl;
        cout << "1.1. Rezolvarea ecuatiei de gradul al doilea" << endl;
        cout << "1.2. Inmultire de matrici" << endl;
        cout << "1.3. Verificare numar prim" << endl;
        cout << "1.4. Schimbare baza numar natural" << endl;
        cout << "1.0. Exit probleme diverse!" << endl;
        cout << "Optiune probleme diverse: ";
        cin >> op;
        cout << endl;

        switch (op) {
            case 1: {
                float a, b, c;
                cout << "Introduceti coeficientii ecuatiei de gradul al doilea: ";
                cin >> a >> b >> c;
                cout << endl << "Solutia ecuatiei este: " << endl;
                ecuatieDeGradul2(a, b, c);
                break;
            }
            case 2: {
                int n, m, p, q;
                cout << "Introduceti dimensiunile matricei A: ";
                cin >> n >> m;
                cout << "Introduceti dimensiunile matricei B: ";
                cin >> q >> p;
                cout << endl;

                if (m == q) {
                    float A[10][10], B[10][10];
                    cout << "Introduceti elementele matricei A: ";
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                            cin >> A[i][j];
                    cout << endl;

                    cout << "Introduceti elementele matricei B: ";
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                            cin >> B[i][j];
                    cout << endl;
                    cout << "Rezultatul inmultirii matricelor este:" << endl;
                    inmultireMatrici(n, m, p, A, B);
                } else
                    cout << "Matricile nu pot fi inmultite!" << endl;
                break;
            }
            case 3: {
                int n;
                cout << "Introduceti numarul pe care doriti sa il verificati: ";
                cin >> n;
                cout << endl;

                if (nrPrim(n))
                    cout << "Numarul " << n << " este numar prim.";
                else
                    cout << "Numarul " << n << " nu este numar prim.";
                cout << endl;
                break;
            }
            case 4: {
                int n, b;
                cout << "Introduceti numarul: ";
                cin >> n;
                cout << endl;

                cout << "In ce baza vreti sa schimbati numarul? ";
                cin >> b;
                cout << endl;

                cout << "Numarul in baza " << b << " este: ";
                schimbareBaza(n, b);
                cout << endl;
                break;
            }
            case 0:
                cout << "Inapoi la meniul principal." << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    } while (op != 0);
}

//
// Created by Bogdan on 12/20/2024.
//
