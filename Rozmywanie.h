#ifndef ROZMYWANIE_H
#define ROZMYWANIE_H

#include "ObslugaPrzynaleznosci.h"
#include "TrojkatnaFunkcjaPrzynaleznosci.h"
#include "FunkcjaPrzynaleznosci.h"
#include "Przynaleznosc.h"
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * @brief Klasa zmiennych rozmywanych na pewne funkcje przynależności
 */
class Rozmywanie : public ObslugaPrzynaleznosci
{
    public:
    /**
         * @brief Konstruktor klasy
         * @param _nazwa Nazwa rozmywanego obiektu
         * @param _granicaL Lewa granica
         * @param _granicaP Prawa granica
         */
        Rozmywanie(string _nazwa, float _granicaL, float _granicaP);
        /**
         * @brief Rozmywa wartość ostrą na stopnie przynależności podlegajacych funkcji rozmytych
         * @param _x Ostra wartość do rozmycia
         * @return
         */
        Przynaleznosc* rozmyj(float _x);
};

#endif // ROZMYWANIE_H
