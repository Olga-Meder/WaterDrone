#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "solid.hh"

const std::string kModelCuboid("solid/model.dat");

class Cuboid: public Solid{

public:

    Cuboid();
    void draw(std::string filename) const override;

};


