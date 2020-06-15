#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "MatrixRot.hh"
#include "mainObject.hh"



const std::string kModelCuboid("solid/model.dat");

/**
 * @brief Klasa prostopadłościan, dziedziczy z MainObject
 *
 */
class Cuboid: public MainObject{

public:
/**
 * @brief Konstruktor nowych prostopadłościanów, czyta z pliku kModelCuboid
 *
 */
    Cuboid();
/**
 * @brief Konstruktor nowych prostopadłościanów, odejmuje licznik
 *
 */
    ~Cuboid() {--counter;}

/**
 * @brief metoda, która zapisuje do pliku punkty po translacji
 *
 * @param filename - plik, do któ©ego zapisujemy
 */
    void draw(std::string filename) const override;

/**
 * @brief Metoda, która przesuwa o wektor change
 *
 * @param change - wektor przesunięcia
 */
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }

/**
 * @brief Metoda, która przesuwa o wektor change
 *
 * @param change - wektor przesunięcia
 */
    void rotateZ(double angle);

//    zakomentowane, bo w tej części zadania, nie są potrzebne
//    void rotateY(double kat);
//    void rotateX(double kat);

/**
 * @brief Metoda, która sprawdza, czy nie ma kolizcji z dnem i powierzchnią
 * (1 -kolizja z dnem 2- kolizja z powierzchnią)
 * @return int
 */
    int checkCollision();
};


