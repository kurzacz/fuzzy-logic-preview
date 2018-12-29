#ifndef ZBIORROZMYTY_H
#define ZBIORROZMYTY_H

#include "LiczbaRozmyta.h"

/**
 * @brief Zbiór złożony z liczb rozmytych
 */
class ZbiorRozmyty
{
    public:
        /**
         * @brief Tablica liczb rozmytych
         */
        LiczbaRozmyta *liczbyRozmyte;
        /**
         * @brief Konstruktor klasy
         * @param _ileLiczb Ilość liczb w zbiorze
         */
        ZbiorRozmyty(int _ileLiczb);
        /**
         * @brief Zwraca ilość liczb w zbiorze
         * @return Ilość liczb
         */
        int getIloscLiczb();
        /**
         * @brief Pobiera liczbę rozmytą ze zbioru
         * @param id Id liczby
         * @return
         */
        LiczbaRozmyta* getLiczba(int id);
        ~ZbiorRozmyty();

    private:
        int iloscLiczb;

};

#endif // ZBIORROZMYTY_H
