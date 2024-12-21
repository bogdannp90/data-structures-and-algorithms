//
// Created by Bogdan on 12/20/2024.
//

#include "algoritmi_sortare.h"
#include <iostream>
#include <algorithm>
using namespace std;

void interclasare(int s, int m, int d, float x[100]) {
    int i = s;
    int j = m + 1;
    int k = 0;
    float y[100];

    while (i <= m and j <= d) {
        if (x[i] <= x[j]) y[k++] = x[i++];
        else y[k++] = x[j++];
    }
    if (i <= m)
        for (int r = i; r <= m; r++)
            y[k++] = x[r];

    if (j <= d)
        for (int r = j; r <= d; r++)
            y[k++] = x[r];

    for (int r = 0; r < k; r++) x[s + r] = y[r];
}

int NumarCifre(int x) {
    int nr_cifre = 0;

    if (x == 0)
        return 1;
    else
        while (x > 0) {
            nr_cifre++;
            x = x / 10;
        }
    return nr_cifre;
}

void bubbleSort(int n, float x[100]) {
    bool sortat; // ok este true daca sirul este ordonat crescator, este false, altfel
    do {
        sortat = true;
        for (int i = 0; i <= n - 2; i++) {
            if (x[i] > x[i + 1]) {
                sortat = false;
                float aux = x[i];
                x[i] = x[i + 1];
                x[i + 1] = aux;
            }
        }
    } while (not sortat);
}

void selectionSort(int n, float x[100]) {
    for (int j = 0; j <= n - 2; j++) {
        float minim = x[j];
        int poz = j;
        for (int k = j + 1; k <= n - 1; k++) {
            if (x[k] < minim) {
                minim = x[k];
                poz = k;
            }
        }
        if (poz != j) swap(x[poz], x[j]);
    }
}

void countingSort(int n, float x[100]) {
    int c[100] = {0};
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            if (x[i] <= x[j]) c[j]++;
            else c[i]++;
        }
    }
    float y[n];
    copy_n(x, n, y);
    for (int j = 0; j <= n - 1; j++) x[c[j]] = y[j];
}

void mergeSort(int s, int d, float x[100]) {
    if (s < d) {
        int m = (s + d) / 2;
        mergeSort(s, m, x);
        mergeSort(m + 1, d, x);
        interclasare(s, m, d, x);
    }
}

void quickSort(int s, int d, float x[100]) {
    if (s < d) {
        float pivot = x[s];
        int c = 0;
        for (int i = s + 1; i <= d; i++) if (x[i] <= pivot) c++;
        swap(x[s], x[s + c]);
        int i = s;
        int j = d;
        while (i < j) {
            while (x[i] < pivot) i++;
            while (x[j] >= pivot) j--;
            if (i < j) {
                swap(x[i], x[j]);
                if (i < d) i++;
                if (j > s) j--;
            }
        }
        quickSort(s, s + c - 1, x);
        quickSort(s + c + 1, d, x);
    }
}

void insertionSort(int n, float x[100]) {
    for (int i = 0; i < n; i++) {
        float aux = x[i];
        int j = i - 1;
        while (j >= 0 && aux < x[j]) {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = aux;
    }
}

void shellSort(int n, float x[100]) {
    int pas = n / 2;
    while (pas >= 1) {
        int i = 0;
        while ((i + pas) <= (n - 1)) {
            int j = i;
            float aux = x[i + pas];
            while (x[j] > aux and j >= 0) {
                x[j + pas] = x[j];
                j = j - pas;
            }
            x[j + pas] = aux;
            i++;
        }
        pas = pas / 2;
    }
}

void radixSort(int n, int x[100]) {
    int max_x = 0;

    // Determinăm valoarea maximă din vector
    for (int i = 0; i < n; i++)
        if (max_x < x[i]) max_x = x[i];

    // Calculăm numărul maxim de cifre
    int M = NumarCifre(max_x);

    // Sortăm fiecare cifră
    for (int exp = 1; max_x / exp > 0; exp *= 10) {
        int output[100]; // Vector auxiliar pentru rezultate
        int count[10] = {0}; // Frecvențele cifrelor (0-9)

        // Calculăm frecvența cifrelor curente
        for (int i = 0; i < n; i++) {
            int cifra = (x[i] / exp) % 10;
            count[cifra]++;
        }

        // Calculăm pozițiile elementelor în vectorul sortat
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Construim vectorul sortat
        for (int i = n - 1; i >= 0; i--) {
            int cifra = (x[i] / exp) % 10;
            output[count[cifra] - 1] = x[i];
            count[cifra]--;
        }

        // Copiem rezultatele în vectorul original
        for (int i = 0; i < n; i++)
            x[i] = output[i];
    }
}

void cautareSecventiala(int n, float x[100], float y) {
    int nr_aparitii = 0;
    for (int i = 0; i < n; i++) if (x[i] == y) nr_aparitii++;
    if (nr_aparitii == 0) cout << "Nu s-a gasit elementul in sir!";
    if (nr_aparitii == 1) cout << "Elementul " << y << " apare o data in sir." << endl << endl;
    if (nr_aparitii != 1) cout << "Elementul " << y << " apare de " << nr_aparitii << " ori in sir." << endl << endl;
}

void cautareBinara(int s, int d, float x[100], float y) {
    if (y < x[s] or y > x[d]) {
        cout << "Nu s-a gasit elementul in sir!\n";
        return;
    }
    if (s < d) {
        //exista minim 2 elemente in sir
        int m = (s + d) / 2;
        if (x[m] == y) {
            cout << "Elementul cautat se afla in sir pe pozitia " << m << "\n";
            return;
        }
        if (y < x[m] and s <= m - 1) cautareBinara(s, m - 1, x, y);
        if (y > x[m]) cautareBinara(m + 1, d, x, y);
    } else {
        // sirul are doar un element (s==d)
        if (x[s] == y)
            cout << "Elementul cautat se afla in sir pe pozitia " << s << endl << endl;
        else
            cout << "Nu s-a gasit elementul in sir!" << endl << endl;
    }
}

void handleAlgoritmiSortare() {
    int op; //Choice for "Algoritmi de sortare"
    int n;
    float v[100], w[100];
    // citim sirul
    cout << "Introducti numarul de elemente din sir: ";
    cin >> n;
    cout << endl << "Introduceti elementele sirului: ";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << endl;

    do {
        cout << "Algoritmi de sortare" << endl;
        cout << "2.1. Bubble Sort" << endl;
        cout << "2.2. Counting Sort" << endl;
        cout << "2.3. Selection Sort" << endl;
        cout << "2.4. Quicksort" << endl;
        cout << "2.5. Merge Sort" << endl;
        cout << "2.6. Insertion Sort" << endl;
        cout << "2.7. Shell Sort" << endl;
        cout << "2.8. Radix Sort" << endl;
        cout << "2.9. Cautarea secventiala intr-un sir" << endl;
        cout << "2.10. Cautarea binara intr-un sir" << endl;
        cout << "2.0. Exit algoritmi de sortare!" << endl;
        cout << "Optiune algoritmi de sortare: ";
        cin >> op;
        cout << endl;

        switch (op) {
            case 1: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                bubbleSort(n, w); // w este vectorul ordonat
                cout << "Vectorul ordonat cu Bubble Sort este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl << endl;
            } //Bubble Sort
            break;

            case 2: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                countingSort(n, w); // w este vectorul ordonat
                cout << "Vectorul ordonat cu Counting Sort este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl << endl;
            } // Counting Sort
            break;

            case 3: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                selectionSort(n, w); // w este vectorul ordonat
                cout << "Vectorul ordonat cu Selection Sort este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl << endl;
            } //Selection Sort
            break;

            case 4: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                quickSort(0, n - 1, w); // w este vectorul ordonat
                cout << "Vectorul ordonat cu Quick Sort este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl << endl;
            } //Quick Sort
            break;

            case 5: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                mergeSort(0, n - 1, w); // w este vectorul ordonat
                cout << "Vectorul ordonat cu Merge Sort este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl << endl;
            } //Merge Sort
            break;

            case 6: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                insertionSort(n, w); // w este vectorul ordonat
                cout << "Vectorul ordonat cu Insertion Sort este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl << endl;
            } //Insertion Sort
            break;

            case 7: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                shellSort(n, w); // w este vectorul ordonat
                cout << "Vectorul ordonat cu Shell Sort este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl << endl;
            } //Shell Sort
            break;

            case 8: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                cout << "Matricea ordonata cu RadixSort este: ";
                int w_int[100];
                for (int i = 0; i < 5; i++) {
                    w_int[i] = static_cast<int>(w[i]); // Conversie float -> int
                }
                radixSort(n, w_int); // w este vectorul ordonat
                for (int i = 0; i < n; i++)
                    cout << w_int[i] << " ";
                cout << endl << endl;
            } //Radix Sort
            break;

            case 9: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                cout << "Introduceti elementul pe care il cautati: ";
                float y;
                cin >> y;
                cautareSecventiala(n, w, y);
            } //Cautare secventiala
            break;

            case 10: {
                for (int i = 0; i < n; i++)
                    w[i] = v[i];
                quickSort(0, n - 1, w);
                cout << "Sirul sortat este: ";
                for (int i = 0; i < n; i++)
                    cout << w[i] << " ";
                cout << endl;
                cout << "Introduceti elementul pe care il cautati: ";
                float y;
                cin >> y;
                cautareBinara(0, n - 1, w, y);
            } //Cautare binara
            break;

            case 0:
                cout << "Ai terminat submeniu 2" << endl;
                break;

            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    } while (op != 0);
}