#ifndef WEJSCIEROZMYTE_H
#define WEJSCIEROZMYTE_H

#include <Rozmywanie.h>
#include <string>
#include <Przynaleznosc.h>

using namespace std;

/**
 * @brief Wejście rozmyte, które obsługuje rozmyte zmienne wejściowe i rozmywa ich ostre wartości
 */
class WejscieRozmyte
{
public:
    /**
     * @brief Dodaje wejściową zmienną rozmytą
     * @param _nazwa Nazwa zmiennej rozmytej
     * @param _granicaL Lewa granica wartości zmiennej
     * @param _granicaP Prawa granica wartości zmiennej
     * @return Wskaźnik do nowo utworzonej zmiennej rozmytej
     */
    Rozmywanie* dodajWejscie(string _nazwa, float _granicaL, float _granicaP);
    /**
     * @brief Odpytuje zmienną o ilość funkcji rozmycia
     * @param nrSlotu Id zmiennej rozmytej
     * @return Ilość funkcji przynależności, jakie posiada zmienna rozmyta
     */
    int ileRozmyc(int nrSlotu);
    /**
     * @brief Pobiera ilość zmiennych wejściowych
     * @return Ilość wejściowych zmiennych rozmytych
     */
    int ileWejsc();

    /**
     * @brief Oblicza przynależności danej zmiennej wejściowej na podstawie załadowane wartości wejściowej
     * @param nrSlotu Id zmiennej
     * @return Rozmycie zmiennej na funkcje razem z wartościami ich przynależności
     */
    Przynaleznosc* pobierzZmiennaRozmyta(int nrSlotu);
    /**
     * @brief Oblicza przynależności danej zmiennej wejściowej na podstawie załadowane wartości wejściowej
     * @param _zmienna Wskaźnik do zmiennej wejściowej
     * @return Rozmycie zmiennej na funkcje razem z wartościami ich przynależności
     */
    Przynaleznosc* pobierzZmiennaRozmyta(Rozmywanie* _zmienna);
    /**
     * @brief Kasuje zmienną wejściową, tę która była utworzona jako ostatnia
     */
    void usunWejscie();
    /**
     * @brief Wczytuje wartość do bufora
     * @param nrSlotu Numer zmiennej, dla której wczytujemy wejście
     * @param _x Ostra wartość
     */
    void wczytajWartosc(int nrSlotu, float _x);
    ~WejscieRozmyte();
private:
    vector<Rozmywanie*> wejscia;
    vector<float> wartosci;
    // Może dodać jeszcze timestampy albo coś w tym guście

};

#endif // WEJSCIEROZMYTE_H
