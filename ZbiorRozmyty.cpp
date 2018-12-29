#include "ZbiorRozmyty.h"
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

ZbiorRozmyty::ZbiorRozmyty(int _ileLiczb)
{
    iloscLiczb = _ileLiczb;
    liczbyRozmyte = new LiczbaRozmyta[_ileLiczb];
}

int ZbiorRozmyty::getIloscLiczb()
{
    return iloscLiczb;
}

LiczbaRozmyta* ZbiorRozmyty::getLiczba(int id)
{
    if (id >= iloscLiczb)
        throw runtime_error("Indeks poza zakresem!");

    return &liczbyRozmyte[id];
}

ZbiorRozmyty::~ZbiorRozmyty()
{
    delete[] liczbyRozmyte;
}
