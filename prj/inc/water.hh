#pragma once

#include<iostream>
#include <string>
#include "mainObject.hh"

const std::string kModelWater("solid/water.dat");

class Water: public MainObject
{
    double height=100; // wysokość na jakiej jest woda
public:
/**
 * @brief Konstruktor wody, czyta z pliku kModelWater
 * "Fale" zrobione są na sztywno, czyli wpisane do pliku modelowego
 *
 */
    Water();

/**
 * @brief Destruktor wody
 *
 */
    ~Water() {};

/**
 * @brief metoda, która zapisuje do pliku punkty wody
 *
 * @param filename - plik, do którego zapisujemy
 */
    void draw(std::string filename) const override;

/**
 * @brief Metoda, dająca dostęp do prywatnej danej height
 * @return double
 */
    double getHeight(){return height;}
};