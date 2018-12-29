#ifndef WYOSTRZANIECOS_H
#define WYOSTRZANIECOS_H

#include "Wyostrzanie.h"
#include <exception>
#include <stdexcept>

/**
 * @brief Wyostrzanie na podstawie metody środka sum
 */
class WyostrzanieCOS : public Wyostrzanie
{
    public:
        /**
         * @brief Konstruktor klasy
         * @param _nazwa Nazwa funkcji wyostrzania
         * @param _granicaL Lewa granica
         * @param _granicaP Prawa granica
         */
        WyostrzanieCOS(string _nazwa, float _granicaL, float _granicaP);
        /**
         * @brief Wyznacza ostrą wartość metodą środka sum
         * @return Ostra wartość
         */
        float wyostrz();

    private:
        // Poniższe dwa wskaźniki pokazują na tablice środków i mas funkcji przynależności z których generujemy wniosek rozmyty
        float *srodkiY;
        float *srodkiMasy;
        void wyznaczSrodki();
};

#endif // WYOSTRZANIECOS_H
