#include "cuboid.hh"
#include <fstream>
#include <iostream>
#include "Matrix.hh"
#include <cmath>
#include "bottom.hh"
#include "water.hh"
using namespace std;


Cuboid::Cuboid() :angle {0} // wczytanie pliku modelowego
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
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open drone file!" << endl;
        return;
    }
    for(int i = 0; i < points.size(); ++i)
    {
        outputFile << points[i]+ translation; //pomnożyć to przez macierz?
        if(i % 4 == 3) // triggers after every 4 points
        {
            outputFile << "#\n\n";
        }
    }
}

void Cuboid::rotateZ(double kat)
{

    MatrixRot rot_matrix('Z',kat);
    rot_matrix.transpose();
    for (int i = 0; i < points.size(); ++i)
    {
     //   cout<<rot_matrix<<endl;
     //cout<<points[i];
        points[i] = rot_matrix * points[i];
     //   cout<<points[i];
    }
}

void Cuboid::rotateY(double kat) {

    MatrixRot rot_matrix('Y', kat);
 //   rot_matrix.transpose();
    for (int i = 0; i < points.size(); ++i) {

        cout << points[i];
        points[i] = rot_matrix * points[i];
        cout << points[i];
    }
}

void Cuboid::rotateX(double kat) {

    MatrixRot rot_matrix('X', kat);
 //   rot_matrix.transpose();
    for (int i = 0; i < points.size(); ++i) {

        cout << points[i];
        points[i] = rot_matrix * points[i];
        cout << points[i];
    }
}
int Cuboid::checkCollision()
{
    Bottom b;
    Water w;
    int result;
   // cout<< translation;
    if (translation[2] < b.getDepth()+20) //te punkty wyznaczone doświadczalnie
    {
        result=1;
        return result;
    }
    else if(translation[2]>= w.getHeight()-5)
    {
        result=2;
        return result;
    }
}