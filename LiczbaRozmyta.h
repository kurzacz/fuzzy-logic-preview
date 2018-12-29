#ifndef LICZBAROZMYTA_H
#define LICZBAROZMYTA_H
#include <algorithm>

using namespace std;

/**
 * @brief Struktura przechowująca pary: liczba rzeczywista - wartość funkcji przynależności
 */
struct LiczbaRozmyta
{
    /**
     * @brief Wartość liczbowa ostra
     */
    float x;
    /**
     * @brief Wartość funkcji przynależności
     */
    float fp;
};

inline LiczbaRozmyta operator*(LiczbaRozmyta a, LiczbaRozmyta b)
{
    if (a.x != b.x)
        throw 20;
    LiczbaRozmyta c;
    c.x = a.x;
    c.fp = min(a.fp, b.fp);
    return c;
}

inline LiczbaRozmyta operator+(LiczbaRozmyta a, LiczbaRozmyta b)
{
    if (a.x != b.x)
        throw 20;
    LiczbaRozmyta c;
    c.x = a.x;
    c.fp = max(a.fp, b.fp);
    return c;
}

#endif // LICZBAROZMYTA_H
