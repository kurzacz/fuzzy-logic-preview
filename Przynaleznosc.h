#ifndef PRZYNALEZNOSC_H
#define PRZYNALEZNOSC_H

#include <string>
#include "FunkcjaPrzynaleznosci.h"

/**
 * @brief Obiekt określający poziom przynależności dla funkcji rozmytej
 */
struct Przynaleznosc
{
    /**
     * @brief Zmienna rozmyta
     */
    FunkcjaPrzynaleznosci *zmienna;
    /**
     * @brief Funkcja przynależności
     */
    float fp;
};


#endif // PRZYNALEZNOSC_H
