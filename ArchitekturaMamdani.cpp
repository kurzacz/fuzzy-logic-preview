#include <iostream>
#include "ArchitekturaMamdani.h"

using namespace std;

ArchitekturaMamdani::ArchitekturaMamdani(WejscieRozmyte *_we, WyjscieRozmyte *_wy)
{
    we = _we;
    wy = _wy;
}

/*void ArchitekturaMamdani::aktualizujRozmiarWe()
{
    int ileZmiennychWe = we->ileWejsc();
    int ileDodac = ileZmiennychWe - rozmyciaZmiennych.size();

    for (int i=0; i<ileDodac; i++) {
        rozmyciaZmiennych.push_back(NULL);
        rozmyciaIle.push_back(0);
    }
}*/

Regula* ArchitekturaMamdani::stworzNowaRegule()
{
    Regula *nowaReg;
    nowaReg = new Regula();
    reguly.push_back(nowaReg);
    odpalenia.push_back(0);
    return nowaReg;
}

ArchitekturaMamdani::~ArchitekturaMamdani()
{
    int ile;
    // usuń reguły
    Regula *regWsk;
    ile = reguly.size();
    for (int i=0; i<ile; i++) {
        regWsk = reguly[i];
        delete regWsk;
    }
}


void ArchitekturaMamdani::odpalReguly()
{
    int ile = reguly.size();

    for(int i=0; i<ile; i++) {
        odpalenia[i] = reguly[i]->odpal(we);
    }

}

void ArchitekturaMamdani::wyznaczPoziomyWyjsc()
{
    int ileReg = reguly.size();
    int ileNast;
    int ileRozmyc;
    int ileWyjsc;
    Wyrazenie* nastepnik;
    int i, j, idWy;
    // Do odnajdywania wyjścia
    vector<Wyostrzanie*>::iterator itWy;
    // Flaga odnalezienia funkcji wyostrzania
    bool fWyostrzZnal;

    // Wstępne czyszczenie po ewentualnych poprzednich wyznaczeniach
    ileWyjsc = pozWyostrz.size();
    for (i=0; i<ileWyjsc; i++) {
        ileRozmyc = pozWyostrz[i].size();
        for (j=0; j<ileRozmyc; j++) {
            pozWyostrz[i][j].fp = 0;
        }
    }


    for (i=0; i<ileReg; i++) {
        ileNast = reguly[i]->ileNastepnikow();
        for (j=0; j<ileNast; j++) {
            nastepnik = reguly[i]->getNastepnik(j);
            // Szukaj zmiennej w wektorze zmiennych wyjściowych
            itWy = find (wskWyjsc.begin(), wskWyjsc.end(), nastepnik->zmienna);
            // Taka sytuacja nie powinna mieć miejsca - wskaźnik nie odnaleziony, wyrzuć błąd bo znaczy że źle skonfigurowana reguła
            if (itWy == wskWyjsc.end())
                throw runtime_error("Nie odnaleziono wskaźnika wyjścia z reguły w wektorze wyjść - wygląda na to że następnik był źle ustawiony");
            idWy = distance(wskWyjsc.begin(), itWy);

            // Po namierzeniu wyjścia należy namierzyć jeszcze jego funkcję i wgrać jej wartość poziomu
            //pozWyostrzWyjscia = &pozWyostrz[idWy];
            ileRozmyc = nastepnik->zmienna->ileRozmyc();
            // Łatwiej jest poszukać funkcji ręcznie...
            fWyostrzZnal = false;
            for (int k=0; k<ileRozmyc; k++) {
                if (pozWyostrz[idWy][k].zmienna == nastepnik->wartosc) {
                    fWyostrzZnal = true;
                    pozWyostrz[idWy][k].fp = max(pozWyostrz[idWy][k].fp, odpalenia[i]);
                }

            }
            if (!fWyostrzZnal)
                throw runtime_error("Nie odnaleziono funkcji wyostrzania przy próbie zlokalizowania");
        }
    }
}

void ArchitekturaMamdani::przepiszDaneWyjsc()
{
    int ileWy = wy->ileWyjsc();
    int ileWyostrzen;
    Wyostrzanie* wyjscie;

    // Wyczyść wektor aby uniknąć duplikatów
    wskWyjsc.clear();

    for (int i=0; i<ileWy; i++) {
        wyjscie = wy->getWyjscie(i);
        // Wrzuć wyjście do wektora wskaźników
        wskWyjsc.push_back(wyjscie);
        // Załóż danemu wyjściu tablicę przynależności
        ileWyostrzen = wyjscie->ileRozmyc();
        pozWyostrz.push_back(vector<Przynaleznosc>(ileWyostrzen));

        for (int j=0; j<ileWyostrzen; j++) {
            pozWyostrz[i][j].zmienna = wyjscie->getFunkcja(j);
            pozWyostrz[i][j].fp = 0;
        }
    }
}

void ArchitekturaMamdani::aktualizujWyjscia()
{
    int ileWyjsc = wskWyjsc.size();
    int ileRozmyc;
    float *poziomy;

    for (int i=0; i<ileWyjsc; i++) {
        ileRozmyc = pozWyostrz[i].size();
        poziomy = new float[ileRozmyc];
        for (int j=0; j<ileRozmyc; j++) {
            poziomy[j] = pozWyostrz[i][j].fp;
        }
        // Można wysyłać wartości liczbowe, bo w funkcji przepiszDaneWyjsc zostaly one skopiowane w odpowiedniej kolejnosci
        wy->aktualizujPoziomy(i, poziomy);
    }
    wy->wyostrz();

}

void ArchitekturaMamdani::przelicz()
{
    odpalReguly();
    przepiszDaneWyjsc();
    wyznaczPoziomyWyjsc();
    aktualizujWyjscia();
}

