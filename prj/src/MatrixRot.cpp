/*#include "MatrixRot.hh"
#include <cmath>


void  Solid::rotateX(const double angle)
{
    double radians= angle *(3,1415/180);
    matrix_rot(0, 0) = 1;
    matrix_rot(0, 1) = 0;
    matrix_rot(0, 2) = 0;
    matrix_rot(1, 0) = 0;
    matrix_rot(1, 1) = cos(radians);
    matrix_rot(1, 2) = -sin(radians);
    matrix_rot(2, 0) = 0;
    matrix_rot(2, 1) = sin(radians);
    matrix_rot(2, 2) = cos(radians);
}
void Solid::rotateY(const double angle)
{
    double radians= angle *(3,1415/180);
    matrix_rot(0, 0) = cos(radians);
    matrix_rot(0, 1) = 0;
    matrix_rot(0, 2) = sin(radians);
    matrix_rot(1, 0) = 0;
    matrix_rot(1, 1) = 1;
    matrix_rot(1, 2) = 0;
    matrix_rot(2, 0) = -sin(radians);
    matrix_rot(2, 1) = 0;
    matrix_rot(2, 2) = cos(radians);

}
void Solid::rotateZ(const double angle)
{
    double radians= angle *(3,1415/180);
    matrix_rot(0, 0) = cos(radians);
    matrix_rot(0, 1) = -sin(radians);
    matrix_rot(0, 2) = 0;
    matrix_rot(1, 0) = sin(radians);
    matrix_rot(1, 1) = cos(radians);
    matrix_rot(1, 2) = 0;
    matrix_rot(2, 0) = 0;
    matrix_rot(2, 1) = 0;
    matrix_rot(2, 2) = 1;
} */