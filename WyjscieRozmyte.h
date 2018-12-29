#ifndef WYJSCIEROZMYTE_H
#define WYJSCIEROZMYTE_H

#include <vector>
#include <string>
#include "Wyostrzanie.h"


/**
 * @brief Wyjście rozmyte, które zbiera zmienne wyjściowe i wyznacza im ostre wartości na podstawie poziomów odpaleń poszczególnych funkcji rozmytych
 */
class WyjscieRozmyte
{
    public:
        /**
         * @brief Dla zmiennej wyjściowej ustawia poziomy przynależności funkcji wyostrzania
         * @param nrSlotu Id zmiennej wyjściowej
         * @param _poziomy Poziomy wyostrzeń
         */
        void aktualizujPoziomy(int nrSlotu, float* _poziomy);
        /**
         * @brief Dodaj wyostrzanie środka sum (Center Of Sum)
         * @param _nazwa Nazwa wyostrzanej zmiennej
         * @param _granicaL Lewa granica wartości
         * @param _granicaP Prawa granica wartości
         * @return Wskaźnik do zmiennej wyjściowej
         */
        Wyostrzanie* dodajWyostrzanieCOS(string _nazwa, float _granicaL, float _granicaP);
        /**
         * @brief Pobierz zmienną wyjściową
         * @param nrSlotu Numer zmiennej
         * @return Wskaźnik do zmiennej wyostrzanej
         */
        Wyostrzanie* getWyjscie(int nrSlotu);
        /**
         * @brief Pobiera wyostrzoną wartość wyjścia
         * @param nrSlotu Id zmiennej
         * @return Ostra wartość
         */
        float getWynik(int nrSlotu);
        /**
         * @brief Pobiera ilość wyjść
         * @return Ilość wyjść
         */
        int ileWyjsc();
        /**
         * @brief Wyostrza zmienną na podstawie załadowanych wartości odpaleń
         * @param nrSlotu Id zmiennej
         */
        void wyostrz(int nrSlotu);
        /**
         * @brief Wyostrza wszystkie zmienne
         */
        void wyostrz();
        /**
         * @brief Kasuje ostatnio utworzoną zmienną wyostrzania
         */
        void usunWyostrzanie ();
        ~WyjscieRozmyte();
    private:
        // Uzyskane z Architektury poziomy dla zmiennych
        // wejście z Mamdaniego do wyjścia rozmytego
        // nie potrzeba poziomów tutaj, bo one są wewnątrz zmiennych do rozmywania
        //vector <vector<float>> poziomy;
        // Tutaj będą zmienne wyjściowe w stylu CV itd
        vector<Wyostrzanie*> wyjscia;
        // Bufor na wyjście - tutaj są wartości wyostrzone wyjściowe
        // Wymiar tablicy odpowiada ilości wyjść
        // Stąd zgarniamy wyliczone wartości wyjść
        vector<float> wyniki;

};
#endif // WYJSCIEROZMYTE_H
