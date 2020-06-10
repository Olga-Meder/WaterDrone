#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "Matrix.hh"
#include "mainObject.hh"


class Solid: public mainObject{

protected:
    double angle; //kąt w stopniach
    Matrix3D matrix_rot;
    double radians= angle *(3,1415/180);
public:
    Solid() {}; //konstruktor
    ~Solid() {}; //destruktor
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }
    void rotateX(const double angle);
    void rotateY(const double angle);
    void rotateZ(const double angle);

};