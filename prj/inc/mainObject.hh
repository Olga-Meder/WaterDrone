#pragma once

#include<iostream>
#include<vector>
#include "Vector.hh"

/*
 * Głowna klasa od której wszystko się dziedziczy.
 * Tutaj ma być metoda rysowania, wektor translacji, konstruktor.
 */
class mainObject
{
protected:
    std::vector<Vector3D> points;
    Vector3D translation;
public:
    mainObject() {}; //konstruktor
    ~mainObject() {}; //destruktor
    virtual void draw(std::string filename) const=0; // metoda czysto wirtualna do rysowania obiektów

};