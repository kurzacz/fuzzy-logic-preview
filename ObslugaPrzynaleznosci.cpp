#include "ObslugaPrzynaleznosci.h"
#include "FunkcjaPrzynaleznosci.h"
#include "SingletonowaFunkcjaPrzynaleznosci.h"
#include "TrojkatnaFunkcjaPrzynaleznosci.h"
#include "TrapezowaFunkcjaPrzynaleznosci.h"
#include <iostream>
using namespace std;

ObslugaPrzynaleznosci::ObslugaPrzynaleznosci(string _nazwa, float _granicaL, float _granicaP)
{
    nazwa = _nazwa;
    granicaL = _granicaL;
    granicaP = _granicaP;

    skonfigurowana = false;
}

FunkcjaPrzynaleznosci* ObslugaPrzynaleznosci::dodajRozmywanieSingletonowe(string _etykieta, float _W)
{
    if (_W < granicaL || granicaP < _W)
        throw runtime_error("Wierzcholek funkcji poza przestrzenia rozwazan");

    FunkcjaPrzynaleznosci* nowaFunkcja;
    // Jeśli to pierwsza funkcja rozmyta, to po prostu ją wstawiamy
    if (funkcjePrzynaleznosci.size() == 0) {
        nowaFunkcja = new SingletonowaFunkcjaPrzynaleznosci(_etykieta, _W);
        funkcjePrzynaleznosci.push_back(nowaFunkcja);
        skonfigurowana = false;
        return nowaFunkcja;
    }

    // Jeśli nie jest to pierwsza funkcja, to MUSI znaleźć się za ostatnią
    // W przeciwnym razie należy kasować poprzednie
    else {
        if(_W < funkcjePrzynaleznosci[funkcjePrzynaleznosci.size()-1]->getPW())
            throw runtime_error("Funkcja nie moze byc wstawiona, gdyz jej wierzcholek jest mneijszy od wierzcholka ostatniej funkcji.");
        else {
            nowaFunkcja = new SingletonowaFunkcjaPrzynaleznosci(_etykieta, _W);
            funkcjePrzynaleznosci.push_back(nowaFunkcja);
            skonfigurowana = false;
            return nowaFunkcja;
        }
    }
}

FunkcjaPrzynaleznosci* ObslugaPrzynaleznosci::dodajRozmywanieTrapezowe(string _etykieta, float _LW, float _PW)
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
        return nowaFunkcja;
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
}

int ObslugaPrzynaleznosci::ileRozmyc()
{
    return funkcjePrzynaleznosci.size();
}

FunkcjaPrzynaleznosci* ObslugaPrzynaleznosci::dodajRozmywanieTrojkatne(string _etykieta, float _W)
{
    if (_W < granicaL || granicaP < _W)
        throw runtime_error("Wierzcholek funkcji poza przestrzenia rozwazan");

    FunkcjaPrzynaleznosci* nowaFunkcja;
    // Jeśli to pierwsza funkcja rozmyta, to po prostu ją wstawiamy
    if (funkcjePrzynaleznosci.size() == 0) {
        nowaFunkcja = new TrojkatnaFunkcjaPrzynaleznosci(_etykieta, _W);
        funkcjePrzynaleznosci.push_back(nowaFunkcja);
        skonfigurowana = false;
        return nowaFunkcja;
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
}

FunkcjaPrzynaleznosci* ObslugaPrzynaleznosci::getFunkcja(int nrSlotu)
{
    if (nrSlotu >= funkcjePrzynaleznosci.size())
        throw runtime_error("Proba pobrania wskaznika do funkcji przynaleznosci poza zakresem");
    return funkcjePrzynaleznosci[nrSlotu];
}

void ObslugaPrzynaleznosci::przypiszKresy()
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
}

void ObslugaPrzynaleznosci::usunRozmywanie(int nrSlotu)
{
    funkcjePrzynaleznosci.erase(funkcjePrzynaleznosci.begin()+nrSlotu);
}

ObslugaPrzynaleznosci::~ObslugaPrzynaleznosci()
{
    int ileRozmyc = funkcjePrzynaleznosci.size();
    FunkcjaPrzynaleznosci *ptr;

    for (int i=0; i<ileRozmyc; i++) {
        ptr = funkcjePrzynaleznosci[i];
        delete ptr;
    }
}
