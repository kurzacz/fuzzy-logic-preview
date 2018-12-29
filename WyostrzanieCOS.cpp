#include "WyostrzanieCOS.h"
#include "ZbiorRozmyty.h"
#include "LiczbaRozmyta.h"

WyostrzanieCOS::WyostrzanieCOS(string _nazwa, float _granicaL, float _granicaP) : Wyostrzanie(_nazwa, _granicaL, _granicaP)
{}

float WyostrzanieCOS::wyostrz()
{
    int ileZbiorow = ileRozmyc();
    float sumaPozMas = 0;
    float sumaMas = 0;

    wyznaczSrodki();


    for (int i=0; i<ileZbiorow; i++) {
        sumaPozMas += srodkiY[i]*srodkiMasy[i];
        sumaMas += srodkiMasy[i];
    }

    // Zwolnij pamięć stworzonych tablic mas
    delete [] srodkiY;
    delete [] srodkiMasy;

    return sumaPozMas/sumaMas;
}

void WyostrzanieCOS::wyznaczSrodki()
{
    int ileZbiorow = ileRozmyc();
    int ileLiczbRozmytych;
    ZbiorRozmyty* zr;
    float sumMi;
    float sumMiXFp;
    LiczbaRozmyta* liczbaRozmyta;

    przypiszKresy();
    // Zwalnianie tej pamieci w WyostrzanieCOS::wyostrz()
    srodkiY = new float [ileZbiorow];
    srodkiMasy = new float [ileZbiorow];

    // Dla każdej funkcji przynależności wyznacz środek masy
    for (int i=0; i<ileZbiorow; i++) {
        // Inicjuj wartości tablicy dynamicznej
        srodkiY[i] = 0;
        srodkiMasy[i] = 0;
        // Jeżeli funkcja przynależności ma poziom 0 to nie przeliczaj nic tylko pozostaw zera
        if (poziomy[i] == 0)
            continue;
        // Tutaj łapię wskaźnik na wygenerowany zbiór rozmyty
        zr = funkcjePrzynaleznosci[i]->generujZbiorRozmyty(rozdzielczosc, poziomy[i]);
        ileLiczbRozmytych = zr->getIloscLiczb();
        sumMi = 0;
        sumMiXFp = 0;
        for (int j=0; j<ileLiczbRozmytych; j++) {
            liczbaRozmyta = zr->getLiczba(j);
            sumMiXFp += liczbaRozmyta->x*liczbaRozmyta->fp;
            sumMi += liczbaRozmyta->fp;
            srodkiMasy[i] += liczbaRozmyta->fp;
        }
        // Wyznaczam środek zbioru
        srodkiY[i] = sumMiXFp/sumMi;
        // Tutaj zwalniam pamięć po obliczeniach na zbiorze
        delete zr;
    }

}
