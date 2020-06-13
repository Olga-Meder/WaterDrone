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
    /*********************************************/
    Matrix3D matrix_rot;
    double angle=45;
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

    for(int i=0;i<points.size();i++)
    {
      //  points[i]= matrix_rot*points[i]; //nie ma przypisania ?

    }
    /********************************************/

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