#include "TrojkatnaFunkcjaPrzynaleznosci.h"
#include <iostream>
using namespace std;

TrojkatnaFunkcjaPrzynaleznosci::TrojkatnaFunkcjaPrzynaleznosci(string _etykieta, float _W)
{
    etykieta = _etykieta;
    W = _W;
}
/*
ZbiorRozmyty* TrojkatnaFunkcjaPrzynaleznosci::generujZbiorRozmyty(float rozdzielczosc)
{
    ZbiorRozmyty *zr;
    float ilosc = (PK-LK)/rozdzielczosc+1;
    int ile = static_cast<int>(ilosc);
    zr = new ZbiorRozmyty(ile);
    LiczbaRozmyta lr;
    for (int i=0; i<ile; i++) {
        lr.x = LK+i*rozdzielczosc;
        lr.fp = obliczWartoscPrzynaleznosci(LK+i*rozdzielczosc);
        zr->liczbyRozmyte[i] = lr;
    }

    return zr;
}

ZbiorRozmyty* TrojkatnaFunkcjaPrzynaleznosci::generujZbiorRozmyty(float rozdzielczosc, float wartoscPrzynaleznosci)
{
    ZbiorRozmyty *zr;
    float ilosc = (PK-LK)/rozdzielczosc+1;
    int ile = static_cast<int>(ilosc);
    zr = new ZbiorRozmyty(ile);
    LiczbaRozmyta lr;
    LiczbaRozmyta prog;
    prog.fp = wartoscPrzynaleznosci;

    for (int i=0; i<ile; i++) {
        lr.x = LK+i*rozdzielczosc;
        prog.x = lr.x;
        lr.fp = obliczWartoscPrzynaleznosci(LK+i*rozdzielczosc);
        lr = lr*prog;
        zr->liczbyRozmyte[i] = lr;
    }

    return zr;
}*/

float TrojkatnaFunkcjaPrzynaleznosci::getLW()
{
    return W;
}
float TrojkatnaFunkcjaPrzynaleznosci::getPW()
{
    return W;
}

float TrojkatnaFunkcjaPrzynaleznosci::obliczWartoscPrzynaleznosci(float ostraWartosc)
{
    // Wierzcholek sprawdzamy pierwszy na wypadek gdy funkcja jest np. [0,0,1]
    // bo zostala skonfigurowana na koncu przedzialu
    if (ostraWartosc == W)
        return 1;
    else if (ostraWartosc <= LK)
        return 0;
    else if ((LK < ostraWartosc) && (ostraWartosc < W))
        return (ostraWartosc-LK)/(W-LK);
    else if ((W < ostraWartosc) && (ostraWartosc < PK))
        return (PK-ostraWartosc)/(PK-W);
    else
        return 0;
}

/*TrojkatnaFunkcjaPrzynaleznosci::~TrojkatnaFunkcjaPrzynaleznosci()
{

}*/
