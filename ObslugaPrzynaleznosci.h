#ifndef OBSLUGAPRZYNALEZNOSCI_H
#define OBSLUGAPRZYNALEZNOSCI_H

#include "TrojkatnaFunkcjaPrzynaleznosci.h"
#include "FunkcjaPrzynaleznosci.h"
#include "Przynaleznosc.h"
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>

/**
 * @brief Ujednolicona klasa zbierająca własności zmiennej rozmywanej i wyostrzanej
 */
class ObslugaPrzynaleznosci
{
    public:
        /**
         * @brief Konstruktor klasy
         * @param _nazwa : nazwa obiektu
         * @param _granicaL : lewa granica zbioru
         * @param _granicaP : prawa granica zbioru
         */
        ObslugaPrzynaleznosci(string _nazwa, float _granicaL, float _granicaP);
        /**
         * @brief Dodaje rozmycie funkcją pojedynczego piku
         * @param _etykieta : etykieta funkcji rozmycia
         * @param _W : wierzchołek funkcji
         * @return : zwraca wskaźnik do funkcji
         */
        FunkcjaPrzynaleznosci* dodajRozmywanieSingletonowe(string _etykieta, float _W);
        /**
         * @brief dodaje rozmycie w kształcie funkcji trapezowej
         * @param _etykieta etykieta funkcji rozmycia
         * @param _LW lewy wierzchołek
         * @param _PW prawy wierzchołek
         * @return zwraca wskaźnik do utworzonej funkcji
         */
        FunkcjaPrzynaleznosci* dodajRozmywanieTrapezowe(string _etykieta, float _LW, float _PW);
        /**
         * @brief Dodaje rozmycie funkcją trójkątną
         * @param _etykieta etykieta funkcji rozmycia
         * @param _W wierzchołek
         * @return zwraca wskaźnik do utworzonej funkcji
         */
        FunkcjaPrzynaleznosci* dodajRozmywanieTrojkatne(string _etykieta, float _W);
        /**
         * @brief Pobiera funkcję o podanym identyfikatorze
         * @param nrSlotu id funkcji
         * @return Wskaźnik do funkcji rozmywającej
         */
        FunkcjaPrzynaleznosci* getFunkcja(int nrSlotu);
        /**
         * @brief Pobiera ilość rozmyć danego obiektu
         * @return Ilość rozmyć
         */
        int ileRozmyc();
        /**
         * @brief Kasuje zadaną funkcję rozmycia
         * @param nrSlotu Id funkcji do usunięcia
         */
        void usunRozmywanie(int nrSlotu);
        ~ObslugaPrzynaleznosci();

    protected:
        /**
         * @brief Wektor funkcji przynależności, na których obiekt pracuje - niezależnie od tego, czy rozmywa czy wyostrza
         */
        vector<FunkcjaPrzynaleznosci*> funkcjePrzynaleznosci;
        /**
         * @brief Lewa granica rozważań
         */
        float granicaL;
        /**
         * @brief Prawa granica rozważań
         */
        float granicaP;
        /**
         * @brief Nazwa zmiennej
         */
        string nazwa;
        /**
         * @brief Flaga która określa, czy funkcje przynależności mają przypisane kresy
         */
        bool skonfigurowana;
        /**
         * @brief Przypisuje kresy funkcjom przynależności
         */
        void przypiszKresy();
};

#endif // OBSLUGAPRZYNALEZNOSCI_H
