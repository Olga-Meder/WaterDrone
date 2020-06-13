#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "Matrix.hh"
#include "mainObject.hh"


class Solid: public MainObject{


public:
    Solid() {}; //konstruktor
    ~Solid() {}; //destruktor
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }
    void rotateX( double angle);
    void rotateY( double angle);
    void rotateZ( double angle);
    Matrix3D matrix_rot;
};