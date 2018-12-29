#ifndef TROJKATNAFUNKCJAPRZYNALEZNOSCI_H
#define TROJKATNAFUNKCJAPRZYNALEZNOSCI_H

#include "FunkcjaPrzynaleznosci.h"
#include "string"
#include "ZbiorRozmyty.h"

/**
 * @brief Funkcja przynależności o kształcie trójkąta
 */
class TrojkatnaFunkcjaPrzynaleznosci : public FunkcjaPrzynaleznosci
{
    public:
    /**
         * @brief Konstruktor klasy
         * @param _etykieta Nazwa funkcji przynależności
         * @param _W Wierzchołek funkcji
         */
        TrojkatnaFunkcjaPrzynaleznosci(string _etykieta, float _W);
        /**
         * @brief Pobiera lewy wierzchołek funkcji (szczyt)
         * @return Szczyt funkcji
         */
        float getLW();
        /**
         * @brief Pobiera prawy wierzchołek funkcji (szczyt)
         * @return Szczyt funkcji
         */
        float getPW();
        /**
         * @brief Oblicza poziom przynależności wartości do funkcji
         * @param ostraWartosc Wielkość wejściowa ostra
         * @return Poziom przynależności
         */
        float obliczWartoscPrzynaleznosci(float ostraWartosc);

        //~TrojkatnaFunkcjaPrzynaleznosci();

    private:
        float W;
};

#endif // TROJKATNAFUNKCJAPRZYNALEZNOSCI_H
