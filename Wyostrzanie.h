#ifndef WYOSTRZANIE_H
#define WYOSTRZANIE_H

#include <vector>
#include "FunkcjaPrzynaleznosci.h"
#include "ObslugaPrzynaleznosci.h"
#include "Przynaleznosc.h"

/**
 * @brief Abstrakcyjna klasa wyostrzająca na podstawie odpaleń
 */
class Wyostrzanie : public ObslugaPrzynaleznosci
{
    public:

    /**
     * @brief Konstruktor klasy
     * @param _nazwa Nazwa zmiennej wyostrzanej
     * @param _granicaL Lewa granica wartości
     * @param _granicaP Prawa granica wartości
     */
    Wyostrzanie(string _nazwa, float _granicaL, float _granicaP);
    /**
     * @brief Dodaje nową funkcję przynależności - Singletonową. Przeciążona - dodaje element do wektora poziomów na nową funkcję
     * @param _etykieta Nazwa funkcji
     * @param _W Wierzchołek
     * @return Wskaźnik do nowej funkcji
     */
    virtual FunkcjaPrzynaleznosci* dodajRozmywanieSingletonowe(string _etykieta, float _W);


    /**
     * @brief Dodaje nową funkcję przynależności - Trapezową. Przeciążona - dodaje element do wektora poziomów na nową funkcję
     * @param _etykieta Nazwa funkcji
     * @param _LW Lewy wierzchołek
     * @param _PW Prawy wierzchołek
     * @return Wskaźnik do nowej funkcji
     */
    virtual FunkcjaPrzynaleznosci* dodajRozmywanieTrapezowe(string _etykieta, float _LW, float _PW);
    // Przeciążona - dodaje element do wektora poziomów na nową funkcję
    /**
     * @brief Dodaje nową funkcję przynależności - Trójkątną. Przeciążona - dodaje element do wektora poziomów na nową funkcję
     * @param _etykieta Nazwa funkcji
     * @param _W Wierzchołek
     * @return Wskaźnik do nowej funkcji
     */
    virtual FunkcjaPrzynaleznosci* dodajRozmywanieTrojkatne(string _etykieta, float _W);

    /**
     * @brief Ustawia wartość poziomu rozmycia dla składowej funkcji rozmytej
     * @param nrSlotu Id funkcji rozmytej
     * @param fp Poziom odpalenia
     */
    void ustawPoziomRozmytej(int nrSlotu, float fp);
    /**
     * @brief Usuwa funkcję przynależności, razem z jej slotem
     * @param nrSlotu Id slotu
     */
    virtual void usunRozmywanie(int nrSlotu);
    /**
     * @brief Ta funkcja używa wskaźnika na tablicę przynależności aby wyznaczyć ostrą wartość
     * @return Wyostrzona wartość
     */
    virtual float wyostrz() = 0;

    protected:
        /**
         * @brief Rozdzielczość generowanych zbiorów rozmytych. Domyślnie 0,5
         */
        float rozdzielczosc;
        /**
         * @brief Dla danego rozmycia zmiennej ten wektor przechowuje poziomy odpalenia każdej funkcji przynależności
         * Na przykład poziom xN = 0,2; xZ = 0,5; zP = 0,7
         */
        vector<float> poziomy;
};

#endif // WYOSTRZANIE_H
