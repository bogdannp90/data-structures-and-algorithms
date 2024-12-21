//
// Created by Bogdan on 12/20/2024.
//

#include "liste_dinamice.h"

#include <iostream>
#include <string>

using namespace std;

numar *creareListaSimpla() {
    numar *cap, *u, *c;
    int x, n;
    // creare capat lista
    cout << "Valoare capat lista x = ";
    cin >> x;
    cap = new numar;
    cap->v = x;
    cap->urm = NULL;
    u = cap; // ultimul element din lista
    cout << "Numarul de elemente care se adauga in lista la ceare: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Valoare de adaugat in lista x = ";
        cin >> x;
        c = new numar;
        c->v = x;
        c->urm = NULL;
        u->urm = c; // stabileste legatura intre ultimul elemnt si noul element adaugat
        u = c; // c devine ultimul element
    }
    return cap;
}

void parcurgereListaSimpla(numar *cap) {
    numar *c;
    if (cap == NULL)
        cout << "Lista este vida!" << endl;
    else {
        c = cap;
        while (c != NULL) {
            cout << c->v << " ";
            c = c->urm;
        }
    }
}

numar *stergereDinListaSimpla(numar *cap) {
    int cont = 0;
    int s;

    numar *c, *p;

    do {
        if (cap == NULL)
            cout << "Lista este vida! Nu sunt valori de sters!" << endl;
        else {
            //sterge elementul cu valoarea s de cate ori apare in lista
            cout << "Valoare de sters s = ";
            cin >> s;
            int nrs = 0; // numara de cate ori am sters s din lista
            // stergem valoarea s daca se afla la inceput la lista
            while (cap->v == s) {
                cap = cap->urm;
                nrs++;
                if (cap == NULL)
                    break;
            }
            if (cap != NULL) {
                c = cap->urm;
                p = cap; // precedentul elementului curent c
                while (c != NULL) {
                    if (c->v == s) {
                        // sterge din lista pe c
                        p->urm = c->urm;
                        nrs++;
                        c = c->urm;
                    } else {
                        p = c;
                        c = c->urm;
                    }
                }
            }
            cout << "Elementul de sters " << s << " a fost sters de " << nrs << " ori" << endl;
            cout << "Lista ramasa este: ";
            parcurgereListaSimpla(cap);
            cout << endl;
        }
        cout << "Continua stergerea [0/1]? ";
        cin >> cont;
    } while (cont);
    return cap;
}

numar *adaugareInListaSimpla(numar *cap, int a) {
    int opa;
    numar *p;
    do {
        cout << endl << "Tip adaugare:" << endl;
        cout << "1. Adaugare la inceput de lista:" << endl;
        cout << "2. Adaugare dupa element din interiorul listei:" << endl;
        cout << "3. Adaugare la sfarsitul listei:" << endl;
        cout << "0. Incheiere adaugare!" << endl;
        cout << "Optiune adaugare: ";
        cin >> opa;
        switch (opa) {
            case 1: // adauga la inceput
                p = new numar;
                p->v = a;
                p->urm = cap;
                cap = p;
                cout << "Lista dupa adaugare este: ";
                parcurgereListaSimpla(cap);
                cout << endl;
                break;
            case 2: // adauga dupa elemnet cu valoare dat din lista
                // citim valoarea dupa care se adauga
                int y;
                numar *c; // c - elementul curent din lista
                cout << "Valoare dupa care se face adaugarea y = ";
                cin >> y;
                c = cap;
                while (c != NULL) {
                    if (c->v == y) {
                        // adauga valoare a dupa y
                        if (c->urm == NULL) // c este ultimul element din lista
                        {
                            p = new numar;
                            p->v = a;
                            p->urm = NULL;
                            c->urm = p;
                            c = c->urm;
                        } else // c se afla in interiorul listei
                        {
                            p = new numar;
                            p->v = a;
                            p->urm = c->urm;
                            c->urm = p;
                            c = c->urm;
                        }
                    }
                    c = c->urm;
                } // end while *c
                cout << "Lista dupa adaugare este: ";
                parcurgereListaSimpla(cap);
                cout << endl;
                break;
            case 3: // adauga la sfarsitul la listei
                numar *u;
                u = cap;
            //parcurgem lista pentru a ajunge la ultimul element
                while (u->urm != NULL)
                    u = u->urm;
                p = new numar;
                p->v = a;
                p->urm = NULL;
                u->urm = p;
                cout << "Lista dupa adaugare este: ";
                parcurgereListaSimpla(cap);
                cout << endl;
                break;
            case 0:
                cout << "Incheiat adaugare!" << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
                break;
        } // end switch
    } while (opa);
    return cap;
}

numar *modificareInListaSimpla(numar *cap, int y, int w) {
    numar *c;
    for (c = cap; c != NULL; c = c->urm) {
        if (c->v == y)
            c->v = w;
    }
    return cap;
}

numar *creareListaOrdonata() {
    numar *cap, *u, *c;
    int x, n;
    // creare capat lista
    cout << "Valoare cap lista x = ";
    cin >> x;
    cap = new numar;
    cap->v = x;
    cap->urm = NULL;
    u = cap; // ultimul element din lista
    cout << "Numarul de elemente care se adauga in lista la ceare: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Valoare de adaugat in lista x = ";
        cin >> x;
        c = new numar;
        c->v = x;
        c->urm = NULL;
        if (x < cap->v) {
            c->urm = cap;
            cap = c;
        } else {
            numar *p;
            p = cap;
            while (p->urm != NULL && p->urm->v < x)
                p = p->urm;
            c->urm = p->urm;
            p->urm = c;
        }
    }
    return cap;
}

numar *adaugareInListaOrdonata(numar *cap, int a) {
    // adaugare element in lista ordonata
    numar *p;
    if (a < cap->v) {
        p = new numar;
        p->v = a;
        p->urm = cap;
        cap = p;
    } else {
        numar *c;
        c = cap;
        while (c->urm != NULL && c->urm->v < a)
            c = c->urm;
        p = new numar;
        p->v = a;
        p->urm = c->urm;
        c->urm = p;
    }
    return cap;
}

lista2 *creareListaDubla() {
    lista2 *L;
    L = new lista2;
    L->prim = NULL;
    L->ultim = NULL;
    int x, n;
    cout << "Numarul de elemente care se adauga in lista la ceare: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Valoare de adaugat in lista x = ";
        cin >> x;
        numar2 *c;
        c = new numar2;
        c->v = x;
        c->urm = NULL;
        c->prec = L->ultim;
        if (L->prim == NULL) {
            L->prim = c;
            L->ultim = c;
        } else {
            L->ultim->urm = c;
            L->ultim = c;
        }
    }
    return L;
}

void parcurgereListaDublaDirect(lista2 *L) {
    numar2 *c;
    c = L->prim;
    if (c == NULL) { cout << "Lista este vida!"; } else {
        while (c != NULL) {
            cout << c->v << " ";
            c = c->urm;
        }
    }
}

void parcurgereListaDublaInvers(lista2 *L) {
    numar2 *c;
    c = L->ultim;
    if (c == NULL)
        cout << "Lista este vida!";
    else {
        while (c != NULL) {
            cout << c->v << " ";
            c = c->prec;
        }
    }
}

lista2 *adaugareInListaDubla(lista2 *L, int a) {
    int opa;
    numar2 *p;
    do {
        cout << endl << "Tip adaugare:" << endl;
        cout << "1. Adaugare la inceput de lista:" << endl;
        cout << "2. Adaugare dupa element din interiorul listei:" << endl;
        cout << "3. Adaugare la sfarsitul listei:" << endl;
        cout << "0. Incheiere adaugare!" << endl;
        cout << "Optiune adaugare: ";
        cin >> opa;
        switch (opa) {
            case 1: // adauga la inceput
                p = new numar2;
                p->v = a;
                p->urm = L->prim;
                p->prec = NULL;
                L->prim->prec = p;
                L->prim = p;
                parcurgereListaDublaDirect(L);
                cout << endl;
                break;
            case 2: // adauga dupa elemnet cu valoare dat din lista
                // citim valoarea dupa care se adauga
                int y;
                numar2 *c; // c - elementul curent din lista
                cout << "Valoare dupa care se face adaugarea y = ";
                cin >> y;
                c = L->prim;
                while (c != NULL) {
                    if (c->v == y) {
                        // adauga valoare a dupa y
                        if (c->urm == NULL) // c este ultimul element din lista
                        {
                            p = new numar2;
                            p->v = a;
                            p->urm = NULL;
                            p->prec = c;
                            c->urm = p;
                            c = c->urm;
                        } else // c se afla in interiorul listei
                        {
                            p = new numar2;
                            p->v = a;
                            p->urm = c->urm;
                            p->prec = c;
                            c->urm->prec = p;
                            c->urm = p;
                            c = c->urm;
                        }
                    }
                    c = c->urm;
                } // end while *c
                parcurgereListaDublaDirect(L);
                cout << endl;
                break;
            case 3: // adauga la sfarsitul la listei
                numar2 *u;
                u = L->prim;
                while (u->urm != NULL)
                    u = u->urm;
                p = new numar2;
                p->v = a;
                p->urm = NULL;
                p->prec = u;
                u->urm = p;
                L->ultim = p;
                parcurgereListaDublaDirect(L);
                cout << endl;
                break;
            case 0:
                cout << "incheiat adaugare!" << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    } while (opa);
    return L;
}

lista2 *stergereDinListaDubla(lista2 *L) {
    int cont = 0;
    int s;
    numar2 *c;
    do {
        if (L->prim == NULL)
            cout << "Lista este vida! Nu sunt valori de sters!" << endl;
        else {
            //sterge elementul cu valoarea s de cate ori apare in lista
            cout << "Valoare de sters s = ";
            cin >> s;
            int nrs = 0; // numara de cate ori am sters s din lista
            // stergem valoarea s daca se afla la inceput la lista
            while (L->prim->v == s) {
                L->prim = L->prim->urm;
                L->prim->prec = NULL;
                nrs++;
                if (L->prim == NULL)
                    break;
            }
            if (L->prim != NULL) {
                c = L->prim->urm;
                while (c != NULL) {
                    if (c->v == s) {
                        // sterge din lista pe c
                        c->prec->urm = c->urm;
                        if (c->urm != NULL)
                            c->urm->prec = c->prec;
                        nrs++;
                        c = c->urm;
                    } else {
                        c = c->urm;
                    }
                }
            }
            cout << "Elementul de sters " << s << " a fost sters de " << nrs << " ori" << endl;
            cout << "Lista ramasa este: ";
            parcurgereListaDublaDirect(L);
            cout << endl;
        }
        cout << "Continua stergerea [0/1]? ";
        cin >> cont;
    } while (cont);
    return L;
}

lista2 *modificareInListaDubla(lista2 *L, int y, int w) {
    numar2 *c;
    for (c = L->prim; c != NULL; c = c->urm) {
        if (c->v == y)
            c->v = w;
    }
    return L;
}

numar *creareStiva() {
    numar *c, *d;
    int x, n;
    cout << "Introduceti primul element din stiva: ";
    cin >> x;
    c = new numar;
    c->v = x;
    c->urm = NULL;
    cout << "Numarul de elemente care se adauga in stiva: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Valoare de adaugat in stiva x = ";
        cin >> x;
        d = new numar;
        d->v = x;
        d->urm = c;
        c = d;
    }
    return c;
}

void parcurgereStiva(numar *cap) {
    numar *s;
    if (cap == NULL)
        cout << "Stiva este vida!" << endl;
    else {
        s = cap;
        while (s != NULL) {
            cout << s->v << " ";
            s = s->urm;
        }
    }
}

numar *adaugareInStiva(numar *c, int x) {
    numar *d;
    d = new numar;
    d->v = x;
    d->urm = c;
    return d;
}

numar *stergereDinStiva(numar *cap) {
    numar *c = nullptr;
    if (cap == NULL) {
        cout << "Stiva este vida! Nu sunt valori de sters!" << endl;
        return NULL;
    }
    c = cap->urm;
    c->v = (cap->urm)->v;
    delete cap;
    return c;
}

lista2 *creareCoada() {
    lista2 *L;
    L = new lista2;
    L->prim = NULL;
    L->ultim = NULL;
    int x, n;
    cout << "Numarul de elemente care se adauga in coada: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Valoare de adaugat in coada: x = ";
        cin >> x;
        numar2 *c;
        c = new numar2;
        c->v = x;
        c->urm = NULL;
        c->prec = L->ultim;
        if (L->prim == NULL) {
            L->prim = c;
            L->ultim = c;
        } else {
            L->ultim->urm = c;
            L->ultim = c;
        }
    }
    return L;
}

lista2 *adaugareInCoada(lista2 *L, int x) {
    numar2 *c;
    c = new numar2;
    c->v = x;
    c->urm = NULL;
    c->prec = L->ultim;
    if (L->prim == NULL) {
        L->prim = c;
        L->ultim = c;
    } else {
        L->ultim->urm = c;
        L->ultim = c;
    }
    return L;
}

lista2 *stergereDinCoada(lista2 *L) {
    if (L->prim == NULL)
        cout << "Coada este vida! Nu sunt valori de sters!" << endl;
    else {
        ((L->prim)->urm)->prec = NULL;
        L->prim = (L->prim)->urm;
    }
    return L;
}

void parcurgereCoada(lista2 *L) {
    numar2 *c;
    c = L->prim;
    if (c == NULL)
        cout << "Coada este vida!";
    else {
        while (c != NULL) {
            cout << c->v << " ";
            c = c->urm;
        }
    }
}

numar *interclasareListe(numar *L1, numar *L2) {
    numar *L = new numar;
    numar *p1, *p2;
    if (L1->v < L2->v) {
        L->v = L1->v;
        L->urm = NULL;
        p1 = L1->urm;
        p2 = L2;
    } else {
        L->v = L2->v;
        L->urm = NULL;
        p1 = L1;
        p2 = L2->urm;
    }
    numar *u = L;
    numar *c;

    while (p1 != NULL and p2 != NULL) {
        c = new numar;
        if (p1->v < p2->v) {
            c->v = p1->v;
            c->urm = NULL;
            p1 = p1->urm;
        } else {
            c->v = p2->v;
            c->urm = NULL;
            p2 = p2->urm;
        }
        u->urm = c;
        u = c;

        if (p1 != NULL) {
            while (p1 != NULL) {
                c = new numar;
                c->v = p1->v;
                c->urm = NULL;
                u->urm = c;
                u = c;
                p1 = p1->urm;
            }
            if (p2 != NULL) {
                while (p2 != NULL) {
                    c = new numar;
                    c->v = p2->v;
                    c->urm = NULL;
                    u->urm = c;
                    u = c;
                    p2 = p2->urm;
                }
            }
        }
        return L;
    }
    return L;
}

monom *crearePolinom() {
    monom *p;
    p = new monom;
    p->coef = 0;
    p->grad = 0;
    p->urm = NULL;
    int n;
    cout << "Numarul de monoame care se adauga in polinom n = ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        monom *c;
        c = new monom;
        cout << "Introduceti coeficientul si gradul monomului: ";
        cin >> c->coef;
        cout << "x^";
        cin >> c->grad;
        c->urm = NULL;
        if (p->urm == NULL) {
            p->urm = c;
        } else {
            monom *u;
            u = p;
            while (u->urm != NULL)
                u = u->urm;
            u->urm = c;
        }
    }
    return p;
}

void adunarePolinoame(monom *p1, monom *p2) {
    monom *p3 = new monom;
    monom *c1 = p1->urm;
    monom *c2 = p2->urm;
    monom *c3 = p3;
    while (c1 != NULL and c2 != NULL) {
        if (c1->grad == c2->grad) {
            c3->coef = c1->coef + c2->coef;
            c3->grad = c1->grad;
            c1 = c1->urm;
            c2 = c2->urm;
        } else if (c1->grad > c2->grad) {
            c3->coef = c1->coef;
            c3->grad = c1->grad;
            c1 = c1->urm;
        } else {
            c3->coef = c2->coef;
            c3->grad = c2->grad;
            c2 = c2->urm;
        }
        c3->urm = new monom;
        c3 = c3->urm;
        c3->urm = NULL;
    }
    if (c1 != NULL) {
        while (c1 != NULL) {
            c3->coef = c1->coef;
            c3->grad = c1->grad;
            c1 = c1->urm;
            c3->urm = new monom;
            c3 = c3->urm;
            c3->urm = NULL;
        }
    }
    if (c2 != NULL) {
        while (c2 != NULL) {
            c3->coef = c2->coef;
            c3->grad = c2->grad;
            c2 = c2->urm;
            c3->urm = new monom;
            c3 = c3->urm;
            c3->urm = NULL;
        }
    }
    c3 = p3;
    while (c3->urm->urm != NULL) {
        cout << c3->coef << "x^" << c3->grad << " + ";
        c3 = c3->urm;
    }
    cout << c3->coef << "x^" << c3->grad << endl;
}

void sorteazaPolinom(monom *p3) {
    if (!p3 || !p3->urm) {
        return; // Lista are mai puțin de 2 noduri - deja este sortată.
    }
    bool sortat;
    do {
        sortat = true;
        monom *prev = NULL; // Pointer pentru nodul anterior.
        monom *current = p3; // Pointer pentru nodul curent.
        while (current->urm != NULL) {
            if (current->grad < current->urm->grad) {
                // Schimbă nodurile current și current->urm.
                sortat = false;
                monom *next = current->urm;
                current->urm = next->urm;
                next->urm = current;
                if (prev == NULL) {
                    // Dacă schimbăm la începutul listei.
                    p3 = next;
                } else {
                    // Dacă schimbăm în interiorul listei.
                    prev->urm = next;
                }
                // Ajustează prev și current.
                prev = next;
            } else {
                // Trecem la următorul nod.
                prev = current;
                current = current->urm;
            }
        }
    } while (!sortat);
}

void inmulirePolinoame(monom *p1, monom *p2) {
    //Functie pentru inmultirea a doua polinoame
    monom *p3 = new monom;
    monom *c1 = p1->urm;
    monom *c2 = p2->urm;
    monom *c3 = p3;
    while (c1 != NULL) {
        while (c2 != NULL) {
            c3->coef = c1->coef * c2->coef;
            c3->grad = c1->grad + c2->grad;
            c2 = c2->urm;
            c3->urm = new monom;
            c3 = c3->urm;
            c3->urm = NULL;
        }
        c1 = c1->urm;
        c2 = p2->urm;
    }
    c3 = p3;

    //Ordonarea polinomului rezultat
    sorteazaPolinom(c3);
    while (c3->urm->urm != NULL) {
        cout << c3->coef << "x^" << c3->grad << " + ";
        c3 = c3->urm;
    }
    cout << c3->coef << "x^" << c3->grad << endl;
}

caracter *stergereDinStivaCaractere(caracter *cap) {
    if (cap == NULL) {
        cout << "Stiva este vida! Nu sunt valori de sters!" << endl;
        return NULL;
    }
    caracter *c = cap->urm;
    delete cap;
    return c;
}

bool verificareParanteze(const string sir) {
    caracter *paranteze = NULL;

    for (int i = 0; i < sir.length(); i++) {
        char c = sir[i]; // Caracterul curent
        // Dacă este o paranteză deschisă, o adăugăm în stivă
        if (c == '(' || c == '{' || c == '[') {
            caracter *d = new caracter;
            d->car = c;
            d->urm = paranteze;
            paranteze = d;
        }
        // Dacă este o paranteză închisă
        else if (c == ')' || c == '}' || c == ']') {
            // Verificăm dacă stiva este goală sau paranteza nu se potrivește
            if (paranteze == NULL) {
                return false; // Nu există o paranteză deschisă pentru aceasta
            }
            char top = paranteze->car; // Paranteza de pe vârful stivei
            paranteze = stergereDinStivaCaractere(paranteze); // Scoatem paranteza deschisă din stivă

            // Verificăm dacă paranteza închisă se potrivește cu cea de pe vârful stivei
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; // Paranteza nu se potrivește
            }
        }
    }
    // Verificăm dacă există paranteze deschise care nu au fost închise
    return paranteze == NULL;
}

void handleListeDinamice() {
    int op; //Choice for "Liste dinamice"
    do {
        cout << endl << "Liste dinamice" << endl;
        cout << "3.1. Liste simplu inlantuite " << endl;
        cout << "3.2. Aplicatie: Lista simplu inlantuite ordonata din citire" << endl;
        cout << "3.3. Liste dublu inlantuite " << endl;
        cout << "3.4. Stive " << endl;
        cout << "3.5. Cozi " << endl;
        cout << "3.6. Aplicatia 1: Adunarea si inmultirea a doua polinoame " << endl;
        cout << "3.7. Aplicatia 2: Interclasarea a doua liste ordonate " << endl;
        cout << "3.8. Aplicatia 3: Verificarea parantezelor intr-o expresie aritmetica " << endl;
        cout << "3.0. Exit liste dinamice!" << endl;

        cout << "Optiune liste dinamice: ";
        cin >> op;
        cout << endl;

        switch (op) {
            case 1: //liste simplu inlatuite
            {
                numar *lista;

                lista = creareListaSimpla();
                cout << "Lista dupa creare este: ";
                parcurgereListaSimpla(lista);
                cout << endl;

                int op1;
                cout << "Doriti sa adaugati elemente in lista? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    int ad;
                    cout << "Citeste valoare de adaugat: ";
                    cin >> ad;
                    lista = adaugareInListaSimpla(lista, ad);
                }
                cout << endl;

                cout << "Doriti sa stergeti elemente din lista? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    lista = stergereDinListaSimpla(lista);
                    cout << "Lista dupa stergere este: ";
                    parcurgereListaSimpla(lista);
                }
                cout << endl << endl;

                int y, w;
                cout << "Doriti sa modificati elemente din lista? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    cout << "Introduceti elementul pe care doriti sa il modificati: ";
                    cin >> y;
                    cout << "Introduceti noua valoare: ";
                    cin >> w;
                    lista = modificareInListaSimpla(lista, y, w);
                    cout << "Lista dupa modificare este: ";
                    parcurgereListaSimpla(lista);
                }
                cout << endl;
            }
            break;

            case 2:
                // Creare lista ordonata din citire
            {
                numar *lista;

                lista = creareListaOrdonata();
                cout << "Lista dupa creare este: ";
                parcurgereListaSimpla(lista);
                cout << endl;

                int op1;
                cout << "Vrei sa adaugi elemente in lista ordonata? [0/1] ";
                cin >> op1;
                if (op1 > 0) {
                    int ad;
                    cout << "Citeste valoare de adaugat in lista: ";
                    cin >> ad;
                    lista = adaugareInListaOrdonata(lista, ad);
                    cout << "Lista dupa adaugare este: ";
                    parcurgereListaSimpla(lista);
                }
                cout << endl;

                cout << "Doriti sa stergeti elemente din lista? [0/1] ";
                cin >> op1;
                if (op1 == 1)
                    lista = stergereDinListaSimpla(lista);
                cout << "Lista dupa stergere este: ";
                parcurgereListaSimpla(lista);
                cout << endl;
            }
            break;

            case 3: // Liste dublu inlatuite
            {
                lista2 *lista;

                lista = creareListaDubla();
                cout << "Lista dupa creare, parcursa direct, este: ";
                parcurgereListaDublaDirect(lista);
                cout << endl;
                cout << "Lista dupa creare, parcursa invers, este: ";
                parcurgereListaDublaInvers(lista);
                cout << endl;

                int op1;
                cout << "Doriti sa adaugati elemente in lista? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    int ad;
                    cout << "Citeste valoare de adaugat: ";
                    cin >> ad;
                    lista = adaugareInListaDubla(lista, ad);
                    cout << "Lista dupa adaugare este: ";
                    parcurgereListaDublaDirect(lista);
                }
                cout << endl;

                cout << "Doriti sa stergeti elemente din lista? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    lista = stergereDinListaDubla(lista);
                    cout << "Lista dupa stergere este: ";
                    parcurgereListaDublaDirect(lista);
                }
                cout << endl;

                cout << "Doriti sa modificati elemente din lista? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    int y, w;
                    cout << "Introduceti elementul pe care doriti sa il modificati: ";
                    cin >> y;
                    cout << "Introduceti noua valoare: ";
                    cin >> w;
                    lista = modificareInListaDubla(lista, y, w);
                    cout << "Lista dupa modificare este: ";
                    parcurgereListaDublaDirect(lista);
                }
                cout << endl;
            }
            break;

            case 4: //Stive
            {
                numar *stiva;

                stiva = creareStiva();
                cout << "Stiva dupa creare este: ";
                parcurgereStiva(stiva);
                cout << endl;

                int op1;
                cout << "Doriti sa adaugati elemente in stiva? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    int ad;
                    cout << "Citeste valoare de adaugat: ";
                    cin >> ad;
                    stiva = adaugareInStiva(stiva, ad);
                    cout << "Stiva dupa adaugare este: ";
                    parcurgereStiva(stiva);
                }
                cout << endl;

                cout << "Doriti sa stergeti elemente din stiva? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    int n;
                    cout << "Cate elemente doresti sa stergi din stiva? n = ";
                    cin >> n;
                    for (int i = 0; i < n; i++)
                        stiva = stergereDinStiva(stiva);
                    parcurgereStiva(stiva);
                }
                cout << endl;
            }
            break;

            case 5: //Cozi
            {
                lista2 *coada;

                coada = creareCoada();
                cout << "Coada dupa creare este: ";
                parcurgereCoada(coada);
                cout << endl;

                int op1;
                cout << "Doriti sa adaugati elemente in coada? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    int ad;
                    cout << "Citeste valoare de adaugat: ";
                    cin >> ad;
                    coada = adaugareInCoada(coada, ad);
                    cout << "Coada dupa adaugare este: ";
                    parcurgereCoada(coada);
                    cout << endl;
                }
                cout << endl;

                cout << "Doriti sa stergeti elemente din coada? [0/1] ";
                cin >> op1;
                if (op1 == 1) {
                    int n;
                    cout << "Cate elemente doresti sa stergi din coada? n = ";
                    cin >> n;
                    for (int i = 0; i < n; i++)
                        coada = stergereDinCoada(coada);
                    cout << "Coada dupa stergere este: ";
                    parcurgereCoada(coada);
                    cout << endl;
                }
                cout << endl;
            }
            break;

            case 6: //Operatii cu polinoame
            {
                monom *p1, *p2;
                cout << "Introduceti primul polinom: " << endl;
                p1 = crearePolinom();
                cout << "Introduceti al doilea polinom: ";
                p2 = crearePolinom();

                cout << "Rezultatul adunarii polinoamelor este: ";
                adunarePolinoame(p1, p2);
                cout << endl;

                cout << "Rezultatul inmultirii polinoamelor este: ";
                inmulirePolinoame(p1, p2);
                cout << endl;
            }
            break;

            case 7: //Interclasare liste ordonate
            {
                numar *lista1, *lista2;

                cout << "Introduceti elementele primei liste! " << endl;;
                lista1 = creareListaOrdonata();
                cout << "Prima lista dupa creare este: ";
                parcurgereListaSimpla(lista1);
                cout << endl;

                cout << "Introduceti elementele celei de-a doua liste! " << endl;;
                lista2 = creareListaOrdonata();
                parcurgereListaSimpla(lista2);
                cout << "A doua lista dupa creare este: ";
                cout << endl;

                numar *lista = interclasareListe(lista1, lista2);
                cout << "Lista interclasata este: ";
                parcurgereListaSimpla(lista);
                cout << endl;
            }
            break;

            case 8: //Verificare paranteze
            {
                string expresie;
                cout << "Introduceti expresia: ";
                cin >> expresie;

                //verificare paranteze
                cout << "Verificare paranteze: ";
                if (verificareParanteze(expresie))
                    cout << "Expresia este corecta!" << endl;
                else
                    cout << "Expresia nu este corecta!" << endl;
            }
            break;

            case 0:
                cout << "Ai terminat submeniu 2" << endl << endl;
                break;

            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    } while (op != 0);
}