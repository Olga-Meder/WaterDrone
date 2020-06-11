#pragma once

#include<iostream>
#include <string>
#include "mainObject.hh"

const std::string kModelBottom("solid/bottom.dat");

class Bottom: public MainObject
{
    double depth=100; // wysokość na jakiej jest woda
public:
    Bottom();
    void draw(std::string filename) const override;
    ~Bottom() {};
    double get_height(){return depth;}
};