#include "menu.hh"
#include <iostream>
#include <math.h>
#include "cuboid.hh"

/*using namespace std;
void menu()
{
    char choice;
    double angle_rot;
    double distance;
    do
    {
        cout << "MENU:" << endl
             << "o - obrót wokół osi " << endl
             << "r - ruch" << endl
             << "k - koniec" << endl;
        cout << "obliczeanie obiektów: " << Vector3D::counter << endl;
        cin >> choice;
        switch (choice)
        {
            case 'o':
                cout << "Podaj obrót w stopniach: " << endl;
                cin >> angle_rot;

                break;
            case 'r':
                cout << "Podaj odległość " << endl;
                cin >> distance;
                cout << "Podaj kąt wznoszenia w stopniach" << endl;
                cin >> angle;
                double rad=angle*M_PI/180;
                double x=1*cos(rad);
                double y=0;
                double z=1*sin(rad);

                break;
            case 'k':
                break;
            default:
                cout << "Zła opcja, spróbuj ponownie" << endl;
                break;
        }
    } while (choice != 'k');
}
*/