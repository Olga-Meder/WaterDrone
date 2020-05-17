#pragma once

#include <vector>
#include <string>
#include "Vector.hh"

const std::string kModelCuboid("solid/model.dat");

class Cuboid{
    std::vector<Vector3D> points;
    Vector3D translation;
    double angle;

public:
    Cuboid();
    void draw(std::string filename) const;
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }
    static int counter;
};


