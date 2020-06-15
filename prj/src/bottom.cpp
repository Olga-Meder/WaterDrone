#include "bottom.hh"
#include <fstream>
#include <iostream>
#include "mainObject.hh"
using namespace std;


Bottom::Bottom()
{
    ifstream inputFile;
    inputFile.open(kModelBottom);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Bottom file!"
             << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        points.push_back(point); //tutaj dodaje points
        ++counter;
    }
    inputFile.close();
}
void Bottom::draw(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open water file!" << endl;
        return;
    }
    for(int i = 0; i < points.size(); ++i)
    {
        outputFile << points[i]+ translation;
        if(i % 4 == 3) // triggers after every 4 points
        {
            outputFile << "#\n\n";
        }
    }
}
