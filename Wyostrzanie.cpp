#include "Wyostrzanie.h"

Wyostrzanie::Wyostrzanie(string _nazwa, float _granicaL, float _granicaP) : ObslugaPrzynaleznosci(_nazwa, _granicaL, _granicaP)
{
    rozdzielczosc = 0.5;
}

FunkcjaPrzynaleznosci* Wyostrzanie::dodajRozmywanieSingletonowe(string _etykieta, float _W)
{
    FunkcjaPrzynaleznosci* wsk;
    poziomy.push_back(0);
    wsk = ObslugaPrzynaleznosci::dodajRozmywanieSingletonowe(_etykieta, _W);
    return wsk;

}

FunkcjaPrzynaleznosci* Wyostrzanie::dodajRozmywanieTrapezowe(string _etykieta, float _LW, float _PW)
{
    FunkcjaPrzynaleznosci* wsk;
    poziomy.push_back(0);
    wsk = ObslugaPrzynaleznosci::dodajRozmywanieTrapezowe(_etykieta, _LW, _PW);
    return wsk;

}

FunkcjaPrzynaleznosci* Wyostrzanie::dodajRozmywanieTrojkatne(string _etykieta, float _W)
{
    FunkcjaPrzynaleznosci* wsk;
    poziomy.push_back(0);
    wsk = ObslugaPrzynaleznosci::dodajRozmywanieTrojkatne(_etykieta, _W);
    return wsk;

}

void Wyostrzanie::ustawPoziomRozmytej(int nrSlotu, float fp)
{
    if (nrSlotu >= poziomy.size())
        throw runtime_error("Przekroczony indeks dostepu do poziomow");
    poziomy[nrSlotu] = fp;
}

void Wyostrzanie::usunRozmywanie(int nrSlotu)
{
    ObslugaPrzynaleznosci::usunRozmywanie(nrSlotu);
    poziomy.erase(poziomy.begin()+nrSlotu);
}
