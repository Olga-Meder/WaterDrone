#include "solid.hh"
#include <cmath>


void Solid::rotateX(const double radians)
{
    matrix_rot(0, 0) = 1;
    matrix_rot(0, 1) = 0;
    matrix_rot(0, 2) = 0;
    matrix_rot(1, 0) = 0;
    matrix_rot(1, 1) = cos(radians);
    matrix_rot(1, 2) = -sin(radians);
    matrix_rot(2, 0) = 0;
    matrix_rot(2, 1) = sin(radians);
    matrix_rot(2, 2) = cos(radians);

    for(int i=0;i<points.size();i++)
    {
        points[i]= matrix_rot*points[i];

    }

}
void Solid::rotateY(const double angle)
{
    matrix_rot(0, 0) = cos(radians);
    matrix_rot(0, 1) = 0;
    matrix_rot(0, 2) = sin(radians);
    matrix_rot(1, 0) = 0;
    matrix_rot(1, 1) = 1;
    matrix_rot(1, 2) = 0;
    matrix_rot(2, 0) = -sin(radians);
    matrix_rot(2, 1) = 0;
    matrix_rot(2, 2) = cos(radians);

    for(int i=0;i<points.size();i++)
    {
        points[i]= matrix_rot*points[i];

    }
}
void Solid::rotateZ(const double angle)
{
    matrix_rot(0, 0) = -cos(radians);
    matrix_rot(0, 1) = -sin(radians);
    matrix_rot(0, 2) = 0;
    matrix_rot(1, 0) = sin(radians);
    matrix_rot(1, 1) = cos(radians);
    matrix_rot(1, 2) = 0;
    matrix_rot(2, 0) = 0;
    matrix_rot(2, 1) = 0;
    matrix_rot(2, 2) = 1;

    for(int i=0;i<points.size();i++)
    {
        points[i]= matrix_rot*points[i];

    }
}