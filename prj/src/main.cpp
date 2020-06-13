#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "gnuplot_link.hh"
#include "cuboid.hh"
#include "Matrix.hh"
#include"water.hh"
#include <chrono>
#include <thread>
#include"bottom.hh"
#include <cmath>

#define SLEEP 16666667
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

const string kDroneFile("solid/drone.dat");
const string kWaterFile("solid/water2.dat");
const string kBottomFile("solid/bottom2.dat");

int main()
{
    Cuboid cuboid;        // zczytuje z pliku modelowego
    Water water;
    Bottom bottom;
    PzG::GnuplotLink link; // Ta zmienna jest potrzebna do wizualizacji

    link.Init(); // inicjacja
    //dodanie wszystkich plików
    link.AddFilename(kDroneFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kWaterFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kBottomFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.SetDrawingMode(PzG::DM_3D);

    cuboid.draw(kDroneFile); //funkcja zapisujaca do pliku kDroneFile
    water.draw(kWaterFile);
    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    bottom.draw(kBottomFile);

    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku


    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
    cin.ignore(100000, '\n');

    /*tutaj obliczamy tylko przemieszczenie środka
    double distance;
    double r;
    double a;
    cout<< "jaki dystans?"<<endl;
    cin>>distance;
    cout<< "jaki kąt?"<<endl;
    cin>>a;
    r=a*3,1415/180;
    double x=(-1)*distance*cos(r);
    double y=0;
    double z=(-1)*distance*sin(r);

   Vector3D translation;
    translation[0] = x;
    translation[1] = y;
    translation[2] = z; */
    /*************************************************************************/
    // animacja
   /* for(int i=0;i<60;i++)
    {
        cuboid.translate(translation/10);
        sleep_for(nanoseconds(SLEEP));
        cuboid.draw(kDroneFile);
        link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        cin.ignore(100000, '\n');
    } */

  /*  cuboid.translate(translation); //tutaj przeniesienie
    cuboid.draw(kDroneFile); //wczytanie do tego samego pliku

    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
    double abs;
    cin>>abs;
    cin.ignore(100000, '\n'); */
 /***********************************************************************************************/
    cuboid.rotateZ(5);
    cuboid.draw(kDroneFile);
    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    cout << "Naciśnij ENTER, aby kontynuowac" << endl;

    cin.ignore(100000, '\n');

    return 0;

}
