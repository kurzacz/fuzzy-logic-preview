#include <algorithm>
#include <WejscieRozmyte.h>
#include <Rozmywanie.h>

using namespace std;

/*WejscieRozmyte::WejscieRozmyte()
{

}*/

Rozmywanie* WejscieRozmyte::dodajWejscie(string _nazwa, float _granicaL, float _granicaP)
{
    Rozmywanie* noweWejscie;

    noweWejscie = new Rozmywanie(_nazwa, _granicaL, _granicaP);
    wejscia.push_back(noweWejscie);
    wartosci.resize(wartosci.size()+1);

    return noweWejscie;
}

int WejscieRozmyte::ileRozmyc(int nrSlotu)
{
    return wejscia[nrSlotu]->ileRozmyc();
}

int WejscieRozmyte::ileWejsc()
{
    return wejscia.size();
}

Przynaleznosc* WejscieRozmyte::pobierzZmiennaRozmyta(int nrSlotu)
{
    int rozmiar = wejscia.size();
    if (nrSlotu >= rozmiar)
        throw runtime_error("Nie mozna pobrac wartosci z tego slotu.");

    float wartosc;

    // Tak się chyba nie robi (powinien być iterator na początkowy element)
    // ale inne sposoby nie działają
    wartosc = wartosci[nrSlotu];
    //wartosci[nrSlotu].erase(wartosci[nrSlotu].begin());

    return wejscia[nrSlotu]->rozmyj(wartosc);
}

Przynaleznosc* WejscieRozmyte::pobierzZmiennaRozmyta(Rozmywanie* _zmienna)
{
    vector<Rozmywanie*>::iterator slot;
    int nrSlotu;
    float wartosc;

    slot = find(wejscia.begin(), wejscia.end(), _zmienna);
    // Pouszkaj w wektorze wejscia zmiennej którą chcemy wykorzystać
    if (slot != wejscia.end() ) {
        nrSlotu = distance(wejscia.begin(), slot);
        // Tak się chyba nie robi (powinien być iterator na początkowy element)
        // ale inne sposoby nie działają
        wartosc = wartosci[nrSlotu];
        return wejscia[nrSlotu]->rozmyj(wartosc);
    }
    else
        throw runtime_error("Nie istnieje takie wejscie rozmyte");
}

void WejscieRozmyte::usunWejscie()
{
    delete (wejscia[wejscia.size()-1]);
    wartosci.pop_back();
}

void WejscieRozmyte::wczytajWartosc(int nrSlotu, float _x)
{
    int rozmiar = wejscia.size();
    if (nrSlotu >= rozmiar)
        throw runtime_error("Nie mozna wczytac wartosci do tego slotu");

    wartosci[nrSlotu] = _x;
}

WejscieRozmyte::~WejscieRozmyte()
{
    int ileWejsc = wejscia.size();
    for (int i=0; i<ileWejsc; i++) {
        delete (wejscia[i]);
    }
}
