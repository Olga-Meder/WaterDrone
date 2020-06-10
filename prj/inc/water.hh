#pragma once

#include<iostream>
#include <string>
#include "mainObject.hh"

const std::string kModelWater("solid/model.dat");

class water: public mainObject
{
    double height; // wysokość na jakiej jest woda
public:
    water();
    ~water() {};
    void draw(std::string filename) const override;
};