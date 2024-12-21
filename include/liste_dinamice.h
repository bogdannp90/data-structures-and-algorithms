//
// Created by Bogdan on 12/20/2024.
//
#ifndef LISTE_DINAMICE_H
#define LISTE_DINAMICE_H

#include <string>

struct numar {
    int v;
    numar *urm;
};

struct numar2 {
    int v;
    numar2 *urm;
    numar2 *prec;
};

struct lista2 {
    numar2 *prim;
    numar2 *ultim;
};

struct monom {
    int grad;
    float coef;
    monom *urm;
};

struct caracter {
    char car;
    caracter *urm;
};

numar *creareListaSimpla();

void parcurgereListaSimpla(numar *cap);

numar *stergereDinListaSimpla(numar *cap);

numar *adaugareInListaSimpla(numar *cap, int a);

numar *modificareInListaSimpla(numar *cap, int y, int w);

numar *creareListaOrdonata();

numar *adaugareInListaOrdonata(numar *cap, int a);

lista2 *creareListaDubla();

void parcurgereListaDublaDirect(lista2 *L);

void parcurgereListaDublaInvers(lista2 *L);

lista2 *adaugareInListaDubla(lista2 *L, int a);

lista2 *stergereDinListaDubla(lista2 *L);

lista2 *modificareInListaDubla(lista2 *L, int y, int w);

numar *creareStiva();

void parcurgereStiva(numar *cap);

numar *adaugareInStiva(numar *c, int x);

numar *stergereDinStiva(numar *cap);

lista2 *creareCoada();

lista2 *adaugareInCoada(lista2 *L, int x);

lista2 *stergereDinCoada(lista2 *L);

void parcurgereCoada(lista2 *L);

numar *interclasareListe(numar *L1, numar *L2);

monom *crearePolinom();

void adunarePolinoame(monom *p1, monom *p2);

void inmulirePolinoame(monom *p1, monom *p2);

bool verificareParanteze(const std::string sir);

void handleListeDinamice();

#endif // LISTE_DINAMICE_H
