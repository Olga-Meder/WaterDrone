#include "water.hh"
#include <fstream>
#include <iostream>
#include "mainObject.hh"
using namespace std;

//konstruktor i metoda rysowania tak samo jak w Cuboid
Water::Water()
{
    ifstream inputFile;
    inputFile.open(kModelWater);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Water file!" //zamienić to później na polski
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
void Water::draw(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open water file!" << endl; //to też na polski zamienić
        return;
    }
    for(int i = 0; i < points.size(); ++i)
    {
        outputFile << points[i]+ translation; //points  i translation
        if(i % 4 == 3) // triggers after every 4 points
        {
            outputFile << "#\n\n";
        }
    }
}