#include "TrapezowaFunkcjaPrzynaleznosci.h"
#include <iostream>
using namespace std;

TrapezowaFunkcjaPrzynaleznosci::TrapezowaFunkcjaPrzynaleznosci(string _etykieta, float _LW, float _PW)
{
    etykieta = _etykieta;
    LW = _LW;
    PW = _PW;
}
/*
ZbiorRozmyty* TrapezowaFunkcjaPrzynaleznosci::generujZbiorRozmyty(float rozdzielczosc)
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

ZbiorRozmyty* TrapezowaFunkcjaPrzynaleznosci::generujZbiorRozmyty(float rozdzielczosc, float wartoscPrzynaleznosci)
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
*/
float TrapezowaFunkcjaPrzynaleznosci::getLW()
{
    return LW;
}
float TrapezowaFunkcjaPrzynaleznosci::getPW()
{
    return PW;
}

float TrapezowaFunkcjaPrzynaleznosci::obliczWartoscPrzynaleznosci(float ostraWartosc)
{
    if (ostraWartosc <= LK)
        return 0;
    else if ((LK < ostraWartosc) && (ostraWartosc < LW))
        return (ostraWartosc-LK)/(LW-LK);
    else if ((LW <= ostraWartosc) && (ostraWartosc <= PW))
        return 1;
    else if ((PW < ostraWartosc) && (ostraWartosc < PK))
        return (PK-ostraWartosc)/(PK-PW);
    else
        return 0;
}
