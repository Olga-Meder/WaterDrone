#include <iostream>
#include <string>
#include "gnuplot_link.hh"
#include "cuboid.hh"
#include"water.hh"
#include <chrono>
#include <thread>
#include"bottom.hh"
#include <cmath>
#include "mainObject.hh"
#include "Vector.hh"

constexpr int SLEEP= 10000000;
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

const string kDroneFile("solid/drone.dat");
const string kWaterFile("solid/water2.dat");
const string kBottomFile("solid/bottom2.dat");

int main()
{
//  STWORZONE NOWE OBIEKTY
    Cuboid cuboid;
    Water water;
    Bottom bottom;

    PzG::GnuplotLink link; // Ta zmienna jest potrzebna do wizualizacji

//  INICJACJA
    link.Init();

//  DODANIE WSZYSTKICH PLIKÓW
    link.AddFilename(kDroneFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kWaterFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kBottomFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.SetDrawingMode(PzG::DM_3D);

//  ZAPISANIE PUNKTÓW DO PLIKÓW
    cuboid.draw(kDroneFile);
    water.draw(kWaterFile);
    bottom.draw(kBottomFile);

    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
    cin.ignore(100000, '\n');
    /*****************************************************************************************
     * MENU
     */
    char choice; //wybór w menu
    double a; //wybór kąta
    double angle_rot; //wybór kąta rotacji
    double distance=1; //dystans do pokonania
    int c=(MainObject::counter)/distance; //zliczanie aktualnych wektorów
    int allCounter=0; // zmienna opisująca łączną sumę obiektów wraz z animacją
    do
    {
        cout << "MENU:" << endl;
        cout << "o - obrót wokół osi " << endl;
        cout<< "r - ruch" << endl;
        cout<< "k - koniec" << endl;

        cout << "aktualna liczba obiektów(aktualnych): " <<c<< endl;
        allCounter=allCounter+MainObject::counter;
        cout << "łączna liczba obiektów (liczy też podczas animacji): " <<allCounter<<endl;
        cin >> choice;
        if(choice=='o')
        {
            cout << "Podaj obrót w stopniach: " << endl;
            cin >> angle_rot;

//          PĘTLA TWORZĄCA ANIMACJĘ
            for(int i=0;i<angle_rot;i++) //użytkownik decyduje ile razy się powtórzy
            {
                cuboid.rotateZ(1); // rotacja o jeden stopień
                sleep_for(nanoseconds(SLEEP));
                cuboid.draw(kDroneFile);
                link.Draw();
            }

        }
        else if(choice=='r')
        {
            cout << "Podaj odległość " << endl;
            cin >> distance;
            cout << "Podaj kąt wznoszenia/opadania w stopniach" << endl;
            cin >> a;
            double rad=a*M_PI/180; //zamiana na radiany
            Vector3D change; //wektor zmiany
            change[0]=1*cos(rad); //współrzędne kartezjańskie
            change[1]=0;
            change[2]=1*sin(rad);
//          PĘTLA TWORZĄCA ANIMACJĘ
            for(int i=0;i<distance;i++)
            {
                cuboid.translate(change); //translacja
                sleep_for(nanoseconds(SLEEP));
                cuboid.draw(kDroneFile);
                link.Draw();
//              SPRAWDZANIE KOLIZJI
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
            MainObject::counter =0;
        }


    } while (choice != 'k');


    return 0;

}
