#ifndef SINGLETONOWAFUNKCJAPRZYNALEZNOSCI_H
#define SINGLETONOWAFUNKCJAPRZYNALEZNOSCI_H

#include "FunkcjaPrzynaleznosci.h"
#include "string"
#include "ZbiorRozmyty.h"


/**
 * @brief Funkcja przynależności o kształcie pojedynczego piku
 */
class SingletonowaFunkcjaPrzynaleznosci : public FunkcjaPrzynaleznosci
{
public:
    /**
     * @brief Konstruktor klasy
     * @param _etykieta Nazwa funkcji przynależności
     * @param _W Wierzchołek funkcji
     */
    SingletonowaFunkcjaPrzynaleznosci(string _etykieta, float _W);
    /**
     * @brief Pobiera lewy wierzchołek funkcji, dla którego wartość funkcji jest maksymalna
     * @return Lewy wierzchołek (szczyt funkcji)
     */
    float getLW();
    /**
     * @brief Pobiera prawy wierzchołek funkcji, dla którego wartość funkcji jest maksymalna
     * @return Prawy wierzchołek (szczyt funkcji)
     */
    float getPW();
    /**
     * @brief Oblicza wartość przynależności
     * @param ostraWartosc Wejściowa ostra wartość
     * @return Poziom przynależności
     */
    float obliczWartoscPrzynaleznosci(float ostraWartosc);


private:
    float W;
};

#endif // SINGLETONOWAFUNKCJAPRZYNALEZNOSCI_H
