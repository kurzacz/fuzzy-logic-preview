#include "SingletonowaFunkcjaPrzynaleznosci.h"
#include <iostream>
using namespace std;

SingletonowaFunkcjaPrzynaleznosci::SingletonowaFunkcjaPrzynaleznosci(string _etykieta, float _W)
{
    etykieta = _etykieta;
    W = _W;
}

float SingletonowaFunkcjaPrzynaleznosci::getLW()
{
    return W;
}

float SingletonowaFunkcjaPrzynaleznosci::getPW()
{
    return W;
}

float SingletonowaFunkcjaPrzynaleznosci::obliczWartoscPrzynaleznosci(float ostraWartosc)
{
    if (ostraWartosc == W)
        return 1;
    else
        return 0;
}
