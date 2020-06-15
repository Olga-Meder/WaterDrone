#pragma once

#include<iostream>
#include <string>
#include "mainObject.hh"

const std::string kModelBottom("solid/bottom.dat");

/**
 * @brief  Klasa dno, dziedziczy z MainObject
 *
 */
class Bottom: public MainObject
{
    double depth=-200; // głębokość na jakiej jest dno
public:
/**
 * @brief Konstruktor dna, czyta z pliku kModelBottom
 *
 */
    Bottom();
/**
 * @brief Destruktor dna
 *
 */
    ~Bottom() {};

/**
 * @brief metoda, która zapisuje do pliku punkty dna
 *
 * @param filename - plik, do którego zapisujemy
 */
    void draw(std::string filename) const override;

/**
 * @brief Metoda, dająca dostęp do prywatnej danej depth
 * @return double
 */
    double getDepth(){ return depth;}
};