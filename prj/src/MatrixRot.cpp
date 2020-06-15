#include "MatrixRot.hh"
#include <cmath>
#include <iostream>

MatrixRot::MatrixRot(const char axis, const double &angle)
{
    double radians= angle *M_PI/180; //zamiana na radiany
    if(axis=='X')
    {
        (*this)(0, 0) = 1;
        (*this)(0, 1) = 0;
        (*this)(0, 2) = 0;
        (*this)(1, 0) = 0;
        (*this)(1, 1) = cos(radians);
        (*this)(1, 2) = -sin(radians);
        (*this)(2, 0) = 0;
        (*this)(2, 1) = sin(radians);
        (*this)(2, 2) = cos(radians);
    }
    else if(axis =='Y')
    {
        (*this)(0, 0) = cos(radians);
        (*this)(0, 1) = 0;
        (*this)(0, 2) = sin(radians);
        (*this)(1, 0) = 0;
        (*this)(1, 1) = 1;
        (*this)(1, 2) = 0;
        (*this)(2, 0) = -sin(radians);
        (*this)(2, 1) = 0;
        (*this)(2, 2) = cos(radians);
    }
    else if(axis =='Z')
    {
        (*this)(0, 0) = cos(radians);
        (*this)(0, 1) = -sin(radians);
        (*this)(0, 2) = 0;
        (*this)(1, 0) = sin(radians);
        (*this)(1, 1) = cos(radians);
        (*this)(1, 2) = 0;
        (*this)(2, 0) = 0;
        (*this)(2, 1) = 0;
        (*this)(2, 2) = 1;
    }
    else
    {
        std::cout<<"Błędny zapis osi"<<std::endl;
    }
}


