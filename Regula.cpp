#include "Regula.h"
#include <Wyrazenie.h>
#include <iostream>

using namespace std;

void Regula::dodajNastepnik(Wyostrzanie *_zmienna, FunkcjaPrzynaleznosci *_wartosc)
{
    Wyrazenie* nastepnik;

    nastepnik = new Wyrazenie;
    nastepnik->zmienna = _zmienna;
    nastepnik->wartosc = _wartosc;
    nastepniki.push_back(nastepnik);
}

void Regula::dodajPoprzednik(Rozmywanie* _zmienna, FunkcjaPrzynaleznosci* _wartosc)
{
    Wyrazenie* poprzednik;

    poprzednik = new Wyrazenie;
    poprzednik->zmienna = _zmienna;
    poprzednik->wartosc = _wartosc;
    poprzedniki.push_back(poprzednik);
}

Wyrazenie* Regula::getNastepnik(int nrSlotu)
{
    if (nrSlotu >= nastepniki.size())
        throw runtime_error("Proba pobrania nastepnika poza zakresem.");
    return nastepniki[nrSlotu];
}

int Regula::ileNastepnikow()
{
    return nastepniki.size();
}

float Regula::odpal(WejscieRozmyte *_wejscie)
{
    // Pojemnik na rozmywanie dla zmiennej która będzie obrabiana ze względu na poprzednik
    int ileRozmyc;
    // Dynamiczna tablica na rozmycia
    Przynaleznosc* rozmycieWartosci;
    // Zmienna do której wyłuskujemy poprzedniki
    Wyrazenie poprzednik;
    // Zmienna wskaźnikowa do konwersji na wskaźnik rozmywania - potrzebujemy go bo wyrażanie zawiera ogólne wskaźniki typu obsługaPrzynależności
    Rozmywanie *rozWsk;
    // Zmienna do indeksowania tablicy rozmycieWartosci
    int i;
    // Poziom zaplonu przyjmujemy na 1, a potem poprzez minimum (iloczyn logiczny) będziemy ewentualnie obkrajać
    float zaplon = 1;
    // Flaga przeszukiwania rozmyc w poszukiwaniu wartości
    bool znalezione;


    i = 0;
    for(vector<Wyrazenie*>::iterator it = poprzedniki.begin(); it != poprzedniki.end(); ++it) {
        // Podwójne wyłuskanie - najpierw na obiekt iteratora, a potem z niego na ten właściwy
        poprzednik = **it;
        rozWsk = static_cast<Rozmywanie*> (poprzednik.zmienna);
        // Wykonaj rozmycie dla zmiennej zapisanej w poprzedniku
        // Wartość do rozmycia zostanie pobrana jako pierwsza z bufora WejściaRozmytego
        // Otrzymuję wskaźnik do rozmycia wartości
        rozmycieWartosci = _wejscie->pobierzZmiennaRozmyta(rozWsk);
        // Pobierz ilość zmiennych, na które została rozmyta wartość, aby wiedzieć wśród ilu elementów szukać naszej zmiennej
        ileRozmyc = poprzednik.zmienna->ileRozmyc();
        // Poszukiwanie wartości wśród rozmycia
        znalezione = false;
        for (int j=0; j<ileRozmyc; j++) {
            // Jeśli znaleziono odpowiednią funkcję przyneleżności (wartość)
            if (rozmycieWartosci[j].zmienna == poprzednik.wartosc) {
                znalezione = true;
                // Obkrój wartość poziomu zapłonu
                zaplon = min(zaplon, rozmycieWartosci[j].fp);
                break;
            }

        }
        // Popsprzątaj - usuń rozmyte przynależności
        delete [] rozmycieWartosci;
        // Jeśli nie znaleziono funkcji wśród zmiennej rozmytej, to znaczy że gdzieś jest błąd w związkach
        if (!znalezione)
            throw runtime_error("Nie znaleziono wartości (funkcji przynaleznosci) przy przeszukiwaniu rozmycia");
        i++;
    }


    return zaplon;
}

void Regula::usunNastepnik(int nrSlotu)
{
    delete nastepniki[nrSlotu];
    nastepniki.erase(poprzedniki.begin()+nrSlotu);
}

void Regula::usunPoprzednik(int nrSlotu)
{
    delete (poprzedniki[nrSlotu]);
    poprzedniki.erase(poprzedniki.begin()+nrSlotu);
}

Regula::~Regula()
{
    int ilePop = poprzedniki.size();
    int ileNast = nastepniki.size();
    int i;
    Wyrazenie* ptr;

    for (i=0; i<ilePop; i++) {
        ptr = poprzedniki[i];
        delete ptr;
    }

    for (i=0; i<ileNast; i++) {
        ptr = nastepniki[i];
        delete ptr;
    }

}
