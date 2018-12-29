#ifndef ARCHITEKTURAMAMDANI_H
#define ARCHITEKTURAMAMDANI_H

#include "Regula.h"
#include <vector>
#include "Przynaleznosc.h"
#include "WejscieRozmyte.h"
#include "WyjscieRozmyte.h"
#include "Wyostrzanie.h"


using namespace std;
/**
 * @brief Maszyna rozmyta, która korzystając z wejścia rozmytego, wyznacza wartości wyjść
 */
class ArchitekturaMamdani
{
    public:
        /**
         * @brief Konstruktor klasy
         * @param _we Wskaźnik do wejścia rozmytego
         * @param _wy Wskaźnik do wyjścia rozmytego
         */
        ArchitekturaMamdani(WejscieRozmyte *_we, WyjscieRozmyte *_wy);
        /**
         * @brief Tworzy nową, pustą regułę, w której należy wytworzyć poprzedniki i następniki
         * @return Zwraca wskaźnik do nowo utworzonej reguły
         */
        Regula* stworzNowaRegule();
        /**
         * @brief Uruchamia proces wyznaczania wyjść na podstawie wejść i skonfigurowanych reguł
         */
        void przelicz();
        /**
         * @brief Usuwa istniejącą regułe
         * @param nrSlotu Numer reguły do skasowania
         */
        void usunRegule(int nrSlotu);          
        ~ArchitekturaMamdani();


    private:
        WejscieRozmyte *we;
        WyjscieRozmyte *wy;
        vector<Regula*> reguly;
        // Wartości odpaleń dla reguł
        vector<float> odpalenia;
        // Odnalezione wyjscia rozmyte
        vector<Wyostrzanie*> wskWyjsc;
        // Dla każdego wyjścia rozmytego rozkład poziomów przynależności funkcji wyostrzeń
        vector<vector<Przynaleznosc> > pozWyostrz;

        void odpalReguly();
        void wyznaczPoziomyWyjsc();
        // Odnajduje wszystkie rozmyte wyjscia i ich funkcje wyostrzen
        void przepiszDaneWyjsc();
        void aktualizujWyjscia();


        //void aktualizujRozmiarWe();
};

#endif // ARCHITEKTURAMAMDANI_H
