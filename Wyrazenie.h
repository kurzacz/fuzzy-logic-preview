#ifndef WYRAZENIE_H
#define WYRAZENIE_H

#include <Rozmywanie.h>
#include <FunkcjaPrzynaleznosci.h>

using namespace std;

/**
 * @brief Abstrakcyjna klasa zbierająca funkcjonalności poprzedników i następników
 */
struct Wyrazenie
{
    /**
     * @brief Zmienna rozmywana na funkcje
     */
    ObslugaPrzynaleznosci* zmienna;
    /**
     * @brief Funkcja przynależności, należąca do zmiennej
     */
    FunkcjaPrzynaleznosci* wartosc;
};

#endif // WYRAZENIE_H
