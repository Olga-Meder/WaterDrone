#pragma once

#include<iostream>
#include<vector>
#include "Vector.hh"

/**
 * @brief Główna klasa abstrakcyjna, służąca do dziedziczenia obiektów
 *
 */
class MainObject
{
protected:
//  wektor współrzędnych obiektów
    std::vector<Vector3D> points;
//  wektor translacji/ przemieszczenia
    Vector3D translation;
public:

/**
 * @brief Pusty konstruktor obiektór MainObject
 *
 */
    MainObject() {}; //konstruktor

/**
 * @brief Pusty destruktor obiektór MainObject
 *
 */
    ~MainObject() {};

/**
 * @brief  czysto wirtualna metoda służąca do rysowanie obiektów
 *
 * @param filename - nazwa pliku do zapisu
 */
    virtual void draw(std::string filename) const=0;

// licznik ilości narysowanych wektorów
     static int counter;
};