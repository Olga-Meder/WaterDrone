#pragma once

#include "Matrix.hh"


class MatrixRot: public Matrix3D
{
public:

/**
 * @brief metoda, która tworzy macierz rotacji, potrzebną do obrotu bryły
 *
 * @param axis - oś obrotu, X,Y,Z
 * @param angle - kąt obrotu
 */
    MatrixRot(const char axis, const double &angle);

};