#ifndef FUNKCJAPRZYNALEZNOSCI_H
#define FUNKCJAPRZYNALEZNOSCI_H

#include "ZbiorRozmyty.h"
#include "string"

/**
 * @brief Abstrakcyjna klasa funkcji przynależności - gwarantuje, że zwróci wartość przynależności dla wartości ostrej
 */
class FunkcjaPrzynaleznosci
{
    public:

        /**
         * @brief Zwraca nazwę etykiety funkcji rozmytej
         * @return Etykieta funkcji rozmytej
         */
        const string getEtykieta();
        /**
         * @brief Generuje zbiór rozmyty odpowiadający danej funkcji
         * @param rozdzielczosc Rozdzielczość generowanego zbioru
         * @return Zbiór rozmyty funkcji
         */
        ZbiorRozmyty* generujZbiorRozmyty(float rozdzielczosc);
        /**
         * @brief Generuje zbiór rozmyty danej funkcji odpalony na zadanym poziomie
         * @param rozdzielczosc Rozdzielczość generowanego zbioru
         * @param wartoscPrzynaleznosci Poziom odpalenia
         * @return Zbiór rozmyty funkcji z wartościami nie większymi niż zadana
         */
        ZbiorRozmyty* generujZbiorRozmyty(float rozdzielczosc, float wartoscPrzynaleznosci);
        /**
         * @brief Pobierz lewy wierzchołek funkcji
         * @return
         */
        virtual float getLW() = 0;
        /**
         * @brief Pobierz prawy wierzchołek funkcji
         * @return
         */
        virtual float getPW() = 0;
        /**
         * @brief Oblicza wartość przynależności dla ostrej wartości
         * @param ostraWartosc Ostra wartość
         * @return Funkcja przynależności ostrej wartości
         */
        virtual float obliczWartoscPrzynaleznosci(float ostraWartosc) = 0;
        /**
         * @brief Ustaw lewy kres
         * @param _LK Lewy kres funkcji
         */
        void setLK(float _LK);
        /**
         * @brief Ustaw prawy kres
         * @param _PK Prawy kres funkcji
         */
        void setPK(float _PK);

    protected:
        /**
         * @brief Etyketa funkcji przynależności
         */
        string etykieta;
        /**
         * @brief Lewy kres - największa wartość dla której funkcja jeszcze przyjmuje wartość 0
         */
        float LK;
        /**
         * @brief Prawy kres - pierwsza wartość od której funkcja przyjmuje już wartości 0
         */
        float PK;
};

#endif // FUNKCJAPRZYNALEZNOSCI_H
