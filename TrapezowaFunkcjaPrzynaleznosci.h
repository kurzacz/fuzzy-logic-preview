#ifndef TRAPEZOWAFUNKCJAPRZYNALEZNOSCI_H
#define TRAPEZOWAFUNKCJAPRZYNALEZNOSCI_H

#include "FunkcjaPrzynaleznosci.h"
#include "string"
#include "ZbiorRozmyty.h"

/**
 * @brief Funkcja przyneleżności o kształcie trapezu
 */
class TrapezowaFunkcjaPrzynaleznosci : public FunkcjaPrzynaleznosci
{
public:
    /**
     * @brief Konstruktor klasy
     * @param _etykieta Nazwa funkcji rozmycia
     * @param _LW Lewy wierzchołek
     * @param _PW Prawy wierzchołek
     */
    TrapezowaFunkcjaPrzynaleznosci(string _etykieta, float _LW, float _PW);
    /**
     * @brief Pobiera lewy wierzchołek
     * @return Lewy wierzchołek dla którego wartość przynależności jest maksymalna
     */
    float getLW();
    /**
     * @brief Pobiera prawy wierzchołek
     * @return Prawy wierzchołek dla którego wartość przynależności jest maksymalna
     */
    float getPW();
    /**
     * @brief Zwraca wartość przynależności
     * @param ostraWartosc Liczba dla której chcemy wyznaczyć poziom przynależności do funkcji
     * @return Poziom przynależności
     */
    float obliczWartoscPrzynaleznosci(float ostraWartosc);


private:
    float LW, PW;
};

#endif // TRAPEZOWAFUNKCJAPRZYNALEZNOSCI_H
