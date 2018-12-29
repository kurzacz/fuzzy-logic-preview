#include "Rozmywanie.h"
#include "FunkcjaPrzynaleznosci.h"
#include "TrojkatnaFunkcjaPrzynaleznosci.h"
#include "TrapezowaFunkcjaPrzynaleznosci.h"
#include <iostream>
using namespace std;

Rozmywanie::Rozmywanie(string _nazwa, float _granicaL, float _granicaP) : ObslugaPrzynaleznosci(_nazwa, _granicaL, _granicaP)
{}
/*Rozmywanie::Rozmywanie(string _nazwa, float _granicaL, float _granicaP) : ObslugaPrzynaleznosci(_nazwa)
{
    granicaL = _granicaL;
    granicaP = _granicaP;

    skonfigurowana = false;
}*/

/*FunkcjaPrzynaleznosci* Rozmywanie::dodajRozmywanieTrapezowe(string _etykieta, float _LW, float _PW)
{
    if (_LW >= _PW)
        throw runtime_error("Prawy wierzcholek f. trapezowej nie jest wiekszy od lewego");

    if (_PW < granicaL || granicaP < _LW)
        throw runtime_error("Wierzcholek funkcji poza przestrzenia rozwazan");

    FunkcjaPrzynaleznosci* nowaFunkcja;
    // Jeśli to pierwsza funkcja rozmyta, to po prostu ją wstawiamy
    if (funkcjePrzynaleznosci.size() == 0) {
        nowaFunkcja = new TrapezowaFunkcjaPrzynaleznosci(_etykieta, _LW, _PW);
        funkcjePrzynaleznosci.push_back(nowaFunkcja);
        skonfigurowana = false;
    }

    // Jeśli nie jest to pierwsza funkcja, to MUSI znaleźć się za ostatnią
    // W przeciwnym razie należy kasować poprzednie
    else {
        if(_LW < funkcjePrzynaleznosci[funkcjePrzynaleznosci.size()-1]->getPW())
            throw runtime_error("Funkcja nie moze byc wstawiona, gdyz jej wierzcholek jest mniejszy od wierzcholka ostatniej funkcji.");
        else {
            nowaFunkcja = new TrapezowaFunkcjaPrzynaleznosci(_etykieta, _LW, _PW);
            funkcjePrzynaleznosci.push_back(nowaFunkcja);
            skonfigurowana = false;
            return nowaFunkcja;
        }
    }
}*/

/*int Rozmywanie::ileRozmyc()
{
    return funkcjePrzynaleznosci.size();
}*/

/*FunkcjaPrzynaleznosci* Rozmywanie::dodajRozmywanieTrojkatne(string _etykieta, float _W)
{
    if (_W < granicaL || granicaP < _W)
        throw runtime_error("Wierzcholek funkcji poza przestrzenia rozwazan");

    FunkcjaPrzynaleznosci* nowaFunkcja;
    // Jeśli to pierwsza funkcja rozmyta, to po prostu ją wstawiamy
    if (funkcjePrzynaleznosci.size() == 0) {
        nowaFunkcja = new TrojkatnaFunkcjaPrzynaleznosci(_etykieta, _W);
        funkcjePrzynaleznosci.push_back(nowaFunkcja);
        skonfigurowana = false;
    }

    // Jeśli nie jest to pierwsza funkcja, to MUSI znaleźć się za ostatnią
    // W przeciwnym razie należy kasować poprzednie
    else {
        if(_W < funkcjePrzynaleznosci[funkcjePrzynaleznosci.size()-1]->getPW())
            throw runtime_error("Funkcja nie moze byc wstawiona, gdyz jej wierzcholek jest mneijszy od wierzcholka ostatniej funkcji.");
        else {
            nowaFunkcja = new TrojkatnaFunkcjaPrzynaleznosci(_etykieta, _W);
            funkcjePrzynaleznosci.push_back(nowaFunkcja);
            skonfigurowana = false;
            return nowaFunkcja;
        }
    }
}*/

Przynaleznosc* Rozmywanie::rozmyj(float _x)
{
    if (!skonfigurowana)
        przypiszKresy();

    int ileRozmyc = funkcjePrzynaleznosci.size();
    Przynaleznosc *przynaleznosci;
    przynaleznosci = new Przynaleznosc[ileRozmyc];
    for (int i=0; i<ileRozmyc; i++) {
        przynaleznosci[i].zmienna = funkcjePrzynaleznosci[i];
        przynaleznosci[i].fp = funkcjePrzynaleznosci[i]->obliczWartoscPrzynaleznosci(_x);
    }
    return przynaleznosci;
}

/*void Rozmywanie::usunRozmywanie(int nrSlotu)
{
    funkcjePrzynaleznosci.erase(funkcjePrzynaleznosci.begin()+nrSlotu);
}*/


/*void Rozmywanie::przypiszKresy()
{
    int s = funkcjePrzynaleznosci.size();
    switch (s) {
        // Gdy nie ma funkcji
        case 0:
        throw runtime_error("Nie ma czego rozmywac!");
        // Jeśli jest tylko 1 funkcja
        case 1:
        funkcjePrzynaleznosci[0]->setLK(granicaL);
        funkcjePrzynaleznosci[0]->setPK(granicaP);
        break;

        // Jeśli są tylko 2 funkcje
        case 2:
        funkcjePrzynaleznosci[0]->setLK(granicaL);
        funkcjePrzynaleznosci[0]->setPK(funkcjePrzynaleznosci[1]->getLW());
        funkcjePrzynaleznosci[1]->setLK(funkcjePrzynaleznosci[0]->getPW());
        funkcjePrzynaleznosci[1]->setPK(granicaP);
        break;

    // 3 i więcej funkcji
        default:
        funkcjePrzynaleznosci[0]->setLK(granicaL);
        funkcjePrzynaleznosci[0]->setPK(funkcjePrzynaleznosci[1]->getLW());
        for (int i=1; i<s-1; i++){
            funkcjePrzynaleznosci[i]->setLK(funkcjePrzynaleznosci[i-1]->getPW());
            funkcjePrzynaleznosci[i]->setPK(funkcjePrzynaleznosci[i+1]->getLW());
        }
        funkcjePrzynaleznosci[s-1]->setLK(funkcjePrzynaleznosci[s-2]->getPW());
        funkcjePrzynaleznosci[s-1]->setPK(granicaP);
    }

    skonfigurowana = true;
}*/
