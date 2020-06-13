#include "cuboid.hh"
#include <fstream>
#include <iostream>
#include "Matrix.hh"

using namespace std;


Cuboid::Cuboid()
{
    ifstream inputFile;
    inputFile.open(kModelCuboid);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Cuboid file!" 
             << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        points.push_back(point); //tutaj points
    }
    inputFile.close();
}

void Cuboid::draw(std::string filename) const
{
    double angle=45;
    Matrix3D m;
    double radians= angle *(3,1415/180);
    m(0, 0) = cos(radians);
    m(0, 1) = -sin(radians);
    m(0, 2) = 0;
    m(1, 0) = sin(radians);
    m(1, 1) = cos(radians);
    m(1, 2) = 0;
    m(2, 0) = 0;
    m(2, 1) = 0;
    m(2, 2) = 1;


    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open drone file!" << endl;
        return;
    }
    for(int i = 0; i < points.size(); ++i)
    {
        outputFile <<points[i]+ translation; //pomnożyć to przez macierz?
        if(i % 4 == 3) // triggers after every 4 points
        {
            outputFile << "#\n\n";
        }
    }
}