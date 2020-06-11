#pragma once

#include<iostream>
#include <string>
#include "mainObject.hh"

const std::string kModelWater("solid/water.dat");

class Water: public MainObject
{
    double height=100; // wysokość na jakiej jest woda
public:
    Water();
    void draw(std::string filename) const override;
    ~Water() {};
    double get_height(){return height;}
};