#include "FunkcjaPrzynaleznosci.h"
#include "string"
#include <iostream>

const string FunkcjaPrzynaleznosci::getEtykieta()
{
    return etykieta;
}

ZbiorRozmyty* FunkcjaPrzynaleznosci::generujZbiorRozmyty(float rozdzielczosc)
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

ZbiorRozmyty* FunkcjaPrzynaleznosci::generujZbiorRozmyty(float rozdzielczosc, float wartoscPrzynaleznosci)
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
}

void FunkcjaPrzynaleznosci::setLK(float _LK)
{
    LK = _LK;
}

void FunkcjaPrzynaleznosci::setPK(float _PK)
{
    PK = _PK;
}
