#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "gnuplot_link.hh"
#include "cuboid.hh"
#include "Matrix.hh"

#include <chrono>
#include <thread>

#define SLEEP 16666667
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

const string kDroneFile("solid/drone.dat");

int main()
{
    Cuboid cuboid;        // zczytuje z pliku modelowego
    PzG::GnuplotLink link; // Ta zmienna jest potrzebna do wizualizacji

    link.Init();
    link.AddFilename(kDroneFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.SetDrawingMode(PzG::DM_3D);

    cuboid.draw(kDroneFile); //funkcja zapisujaca do pliku kDroneFile


    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
    cin.ignore(100000, '\n');


   Vector3D translation;
    translation[0] = 50;
    translation[1] = 50;
    translation[2] = 50;
    /*************************************************************************/
    // animacja
    for(int i=0;i<60;i++)
    {
        cuboid.translate(translation/10);
        sleep_for(nanoseconds(SLEEP));
        cuboid.draw(kDroneFile);
        link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        cin.ignore(100000, '\n');
    }

 /*   cuboid.translate(translation);
    cuboid.draw(kDroneFile);


    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    cout << "Naciśnij ENTER, aby kontynuowac" << endl; */
 /***********************************************************************************************/
    cuboid.rotateX(20);
    cuboid.draw(kDroneFile);
    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    cout << "Naciśnij ENTER, aby kontynuowac" << endl;

    cin.ignore(100000, '\n');


}
