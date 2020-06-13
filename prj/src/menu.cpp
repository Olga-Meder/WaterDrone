
void menu()
{
    do
    {
        cout << "MENU:" << endl
             << "o - obrót wokół osi " << endl
             << "r - ruch" << endl
             << "k - koniec" << endl;
        cout << "obliczeanie obiektów: " /*<< Vector3D::counter*/ << endl;
        cin >> choice;
        switch (choice)
        {
            case 'o':
                cout << "Podaj obrót w stopniach: " << endl;
                cin >> angle;

                break;
            case 'r':
                cout << "Podaj odległość " << endl;
                cin >> distance;
                cout << "Podaj kąt wznoszenia w stopniach" << endl;
                cin >> angle;
                //trzeba będzie tutaj coś dodać
                break;
            case 'k':
                break;
            default:
                cout << "Zła opcja, spróbuj ponownie" << endl;
                break;
        }
    } while (choice != 'k');
}