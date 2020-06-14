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
//    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    bottom.draw(kBottomFile);
    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
    cin.ignore(100000, '\n');
    /*****************************************************************************************
     * MENU
     */
    char choice;
    double a;
    double angle_rot;
    double distance;
    do
    {
        cout << "MENU:" << endl
             << "o - obrót wokół osi " << endl
             << "r - ruch" << endl
             << "k - koniec" << endl;
        cout << "obliczeanie obiektów: " /*<< Vector3D::counter*/ << endl;
        cin >> choice;
        if(choice=='o')
        {
            cout << "Podaj obrót w stopniach: " << endl;
            cin >> angle_rot;
            //animacja
            for(int i=0;i<angle_rot;i++)
            {
                cuboid.rotateZ(1);
                sleep_for(nanoseconds(SLEEP));
                cuboid.draw(kDroneFile);
                link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
            }

        }
        else if(choice=='r')
        {
            cout << "Podaj odległość " << endl;
            cin >> distance;
            cout << "Podaj kąt wznoszenia w stopniach" << endl;
            cin >> a;
            double rad=a*M_PI/180;
            Vector3D change;
            change[0]=1*cos(rad);;
            change[1]=0;
            change[2]=1*sin(rad);
            //animacja
            for(int i=0;i<distance;i++)
            {
                cuboid.translate(change);
                sleep_for(nanoseconds(SLEEP));
                cuboid.draw(kDroneFile);
                link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                if(cuboid.checkCollision()==1)
                {
                    cerr <<"Uwaga, jesteś na dnie" <<endl;
                    distance=0;
                }
                else if(cuboid.checkCollision()==2)
                {
                    cerr << "Uwaga, jesteś na powierzchni" << endl;
                    distance=0;
                }
            }
        }
        else if(choice=='k')
        {
            cout<<"Koniec programu"<< endl;
            return 0;
        }
        else
        {
            cout<<"Błędny wybór, spróbuj ponownie"<<endl;
        }


    } while (choice != 'k');


    return 0;

}
