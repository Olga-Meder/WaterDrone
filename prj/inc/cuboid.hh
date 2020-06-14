#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "MatrixRot.hh"
#include "mainObject.hh"



const std::string kModelCuboid("solid/model.dat");

class Cuboid: public MainObject{

protected:
    double angle;
public:

    Cuboid();
    void draw(std::string filename) const override;
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }
    void rotateZ(double kat);
    void rotateY(double kat);
    void rotateX(double kat);
    double get_angle()
    {
        return angle;
    }

};


