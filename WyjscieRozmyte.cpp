#include "WyjscieRozmyte.h"

#include "WyostrzanieCOS.h"
#include "Wyostrzanie.h"

void WyjscieRozmyte::aktualizujPoziomy(int nrSlotu, float *_poziomy)
{
    // lista poziomów tworzona (new) w maszynie wnoiskujacej
    // kopiowane jest tylko tyle poziomów ile aktualnie jest wpisanych w wyjściu

    int ileWyjsc = wyjscia[nrSlotu]->ileRozmyc();
    for (int i=0; i<ileWyjsc; i++) {
        wyjscia[nrSlotu]->ustawPoziomRozmytej(i, _poziomy[i]);
    }

    // zwolnij pamięć
    delete [] _poziomy;
}

/*void WyjscieRozmyte::aktualizujPoziomy(Wyostrzanie* wyjscie, float* _poziomy)
{
    vector<Wyostrzanie*>::iterator wyIt;
    int wyId;

    // Najpierw znajdź wyjście po wskaźniku
    wyIt = find(wyjscia.begin(), wyjscia.end(), wyjscie);
    if (wyIt == wyjscia.end())
        throw runtime_error("Brak wyjscia o podanym wskazniku");

    wyId = distance(wyjscia.begin(), wyIt);

    // Wykonaj aktualizację poziomów tak jakby był dany Id:
    aktualizujPoziomy(wyId, _poziomy);
}*/

Wyostrzanie* WyjscieRozmyte::dodajWyostrzanieCOS(string _nazwa, float _granicaL, float _granicaP)
{
    Wyostrzanie *noweWyjscie;

    noweWyjscie = new WyostrzanieCOS(_nazwa, _granicaL, _granicaP);
    wyjscia.push_back(noweWyjscie);
    //poziomy.resize(poziomy.size()+1);
    wyniki.resize(wyniki.size()+1);

    return noweWyjscie;
}

Wyostrzanie* WyjscieRozmyte::getWyjscie(int nrSlotu)
{
    if (nrSlotu >= wyjscia.size())
        throw runtime_error("Proba pobrania wskaznika wyjscia poza zakresem");
    return wyjscia[nrSlotu];
}

float WyjscieRozmyte::getWynik(int nrSlotu)
{
    if (nrSlotu >= wyniki.size())
        throw runtime_error("Proba pobrania wyniku poza zakresem");
    return wyniki[nrSlotu];
}

int WyjscieRozmyte::ileWyjsc()
{
    return wyjscia.size();
}

void WyjscieRozmyte::wyostrz(int nrSlotu)
{
    if (nrSlotu >= wyjscia.size())
        throw runtime_error("Proba wyostrzenia wyjscia poza zakresem");

    wyniki[nrSlotu] = wyjscia[nrSlotu]->wyostrz();
}

void WyjscieRozmyte::wyostrz()
{
    int ileWyjsc = wyjscia.size();
    for (int i=0; i<ileWyjsc; i++) {
        wyostrz(i);
    }
}

void WyjscieRozmyte::usunWyostrzanie()
{
    delete (wyjscia[wyjscia.size()-1]);
    //poziomy.pop_back();
    wyniki.pop_back();
}

WyjscieRozmyte::~WyjscieRozmyte()
{
    int ileWyjsc = wyjscia.size();
    Wyostrzanie *ptr;

    for (int i=0; i<ileWyjsc; i++) {
        ptr = wyjscia[i];
        delete ptr;
    }
}
