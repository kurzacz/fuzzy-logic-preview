#ifndef REGULA_H
#define REGULA_H

#include <FunkcjaPrzynaleznosci.h>
#include <Rozmywanie.h>
#include <vector>
#include <WejscieRozmyte.h>
#include "Wyostrzanie.h"
#include <Wyrazenie.h>

/**
 * @brief Reguła dla maszyny Mamdaniego
 */
class Regula
{

public:
    /**
     * @brief Dodaje następnik reguły
     * @param _zmienna Zmienna rozmyta
     * @param _wartosc Jedna z podlegających powyższej zmiennej funkcja rozmyta
     */
    void dodajNastepnik(Wyostrzanie* _zmienna, FunkcjaPrzynaleznosci* _wartosc);
    /**
     * @brief Dodaje następnik reguły
     * @param _zmienna Zmienna rozmyta
     * @param _wartosc Jedna z podlegających powyższej zmiennej funkcja rozmyta
     */
    void dodajPoprzednik(Rozmywanie* _zmienna, FunkcjaPrzynaleznosci* _wartosc);
    /**
     * @brief Pobiera następnik reguły
     * @param nrSlotu Id następnika
     * @return Wskaźnik do następnika
     */
    Wyrazenie* getNastepnik(int nrSlotu);
    /**
     * @brief Pobiera ilość następników
     * @return Ilość następników
     */
    int ileNastepnikow();
    /**
     * @brief Odpala regułę
     * @param _wejscie Wejście rozmyte, z którego pobierane są wartości
     * @return Poziom odpalenia
     */
    float odpal(WejscieRozmyte* _wejscie);
    /**
     * @brief Kasuje następnik
     * @param nrSlotu Id następnika
     */
    void usunNastepnik(int nrSlotu);
    /**
     * @brief Kasuje poprzednik
     * @param nrSlotu Id poprzednika
     */
    void usunPoprzednik(int nrSlotu);
    ~Regula();

private:
    vector<Wyrazenie*> poprzedniki;
    vector<Wyrazenie*> nastepniki;
};

#endif // REGULA_H
