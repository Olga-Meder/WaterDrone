#pragma once
#include "Vector.hh"
#include "Size.hh"
#include <iostream>
#include <math.h>
constexpr double ERR = 0.000001;
using std::abs;

/*
 *  KLASA MATRIX
 *  Przechowuje dane w postaci tablicy SIZE wektorów
 *  Dostęp do prywatnych danych jest tylko przez metody publiczne
 *  Przeciążenia operatorów () nie są konieczne.
 *  Klasa zamieniona na szablon klasy o dwóch argumentach:
 *  - typ zmiennych przechowywanych w tablicy;
 *  - rozmiar tablicy (macierzy);
 */
template <typename T,int SIZE>
class Matrix
{

    Vector<T,SIZE> data[SIZE]; //dane przechowywane w Matrixie

public:

    // METODY PUBLICZNE

    T determinant() const; // obliczanie wyznacznika
    Matrix<T,SIZE> ReplaceColumn(Vector<T,SIZE> v,int index) const; // zamiana kolumn
    void transpose(); //transpozycja macierzy (wiersze zamienione z kolumnami)

    //PRZECIAZENIA OPERATOROW

    const T &operator()( int index1,  int index2) const;
    T &operator()( int index_1, int index_2);
    Vector<T,SIZE> operator * (Vector<T,SIZE> v); //mnożenie macierzy przez wektor


    //przeciążenie operatora wczytania - funkcja zaprzyjaźniona
    friend std::istream &operator>>(std::istream &in, Matrix<T,SIZE> &matrix)
    {

        for(int i=0;i<SIZE;i++)
        {
            for(int n=0;n<SIZE;n++)
            {
                in>>matrix.data[i][n];
            }
        }
        return in;
    }
    //przeciążenie operatora wyświetlania - funkcja zaprzyjaźniona
    friend std::ostream &operator<<(std::ostream &out, Matrix<T,SIZE>&matrix)
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int n=0;n<SIZE;n++)
            {
                out<<matrix.data[i][n]<<"    ";
            }
            out<<std::endl;
        }
        return out;
    }

};

using Matrix3D = Matrix<double,3>; //alias do używania nazwy Matirx3D zamiast szablonu
/************************************************************************************************/

//obliczanie wyznacznika metodą eliminacji Gaussa
template <typename T,int SIZE>
T Matrix<T,SIZE>::determinant() const
{
    //KOPIOWANIE DANYCH DO TABLICY TYMCZASOWEJ
    T copy[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int n=0;n<SIZE;n++)
        {
            copy[i][n]=data[i][n];

        }
    }

    T det=1;
    for(int i=0;i<SIZE;i++) //pętla główna
    {
        if(abs(copy[i][i])<ERR )// jeśli wyraz (na przekątnej) jest równy zero
        {   int j;
            for(j=i+1;j<SIZE;j++)
                if(abs(copy[j][i])>ERR) //szukamy takieo wiersza, w którym nie będzie zera
                {
                    for(int k=i;k<SIZE;k++)
                    {
                        T tmp= copy[i][k]; // zamieniamy cały wiersz
                        copy[i][k]=copy[j][k];

                        copy[j][k]=tmp;


                    }
                    det*=-1; // zamieniamy znak wyznacznika, bo zamieniliśmy wiersz
                    break;
                }
            if(j==SIZE)
            {
                det=0;
            }
        }
        for(int j=i+1;j<SIZE; j++) //petla, w której wykonywane są wszystkie odejmowania wierszy
        {
            if(abs(copy[j][i])<ERR) continue; //nie będziemy mnożyć przez zero
            T p=copy[j][i]/copy[i][i];
            for(int k=i+1;k<SIZE;k++)
            {
                copy[i][k]*=p;
                copy[j][k]-=copy[i][k]; //odejmujemy przemnożone przez konkretną liczbę p
            }


        }
    }
    //wychodząc z tej pętli mamy pewność, że pod przekątną są same zera
    for(int i=0;i<SIZE;i++)
    {
        det*=copy[i][i]; //przemnożenie wszystkich wartości na przekątnej macierzy
    }

    return det;
}

//Transpozycja macierzy
template <typename T, int SIZE>
void Matrix<T,SIZE>::transpose()
{
    T tmp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tmp[i][j] = data[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::swap(data[j][i], tmp[i][j]); //funkcja z wykładu
        }
    }
}


//przeciazenie operatora () const
template <typename T,int SIZE>
const T &Matrix<T,SIZE>::operator()( int index_1,  int index_2) const
{
    if(index_1 < 0 || index_1 >= SIZE || index_2 < 0 || index_2 >= SIZE)
    {
        std::cerr<<"Blad indeksowania"<<std::endl;
        exit(0);
    }
    return data[index_1][index_2];
}
//przeciazenie operatora () bez const
template <typename T,int SIZE>
T &Matrix<T,SIZE>::operator()( int index_1, int index_2)
{
    return const_cast<T &>(const_cast<const Matrix<T,SIZE>*>(this)->operator()(index_1,index_2));
}

//zamiana kolumn
template <typename T,int SIZE>
Matrix<T,SIZE> Matrix<T,SIZE>::ReplaceColumn(Vector<T,SIZE> v, int index) const
{
    auto copy=*this;
    copy.data[index]=v;
    return copy;
}

template <typename T,int SIZE>
Vector<T,SIZE> Matrix<T,SIZE>:: operator * (Vector<T,SIZE> v)
{
    Vector<T, SIZE> result;
    //KOPIOWANIE DANYCH DO TABLICY TYMCZASOWEJ
    T copy[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int n=0;n<SIZE;n++)
        {
            copy[i][n]=data[i][n];

        }
    }
    for (int i = 0; i < SIZE; i++)
    {
//        result[i]=0;
        for (int j = 0; j < SIZE; j++)
        {
            result[i]= result[i] + v[j] * copy[i][j];
        }
    }
    return result;
}


