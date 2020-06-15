#pragma once

#include "Size.hh"
#include <iostream>

/*
 *  KLASA VECTOR
 *  Przechowuje dane w postaci jednowymiarowej tablicy double
 *  W polu publicznym wystepuja przeciazenia operatorow,
 *  przez ktore mamy dostep do prywatnych danych.
 *  Klasa zamieniona na szablon klasy o dwóch argumentach:
 *  - typ zmiennych przechowywanych w tablicy;
 *  - rozmiar tablicy (macierzy);
 */

template <typename T,int SIZE>
class Vector
{
    T data[SIZE]; //wektor z rozwiązaniami
public:
    //KONSTRUKTOR
    Vector();

    //PRZECIAZENIA OPERATOROW

  Vector<T,SIZE> operator +(Vector<T,SIZE>  v) const; // dodawanie dwóch wektorów
  Vector<T,SIZE> operator -(Vector<T,SIZE>  v) const; // odejmowanie dwóch wektorów
  T operator *(Vector<T,SIZE>  v) const; // mnożenie dwóch wektórów
  Vector<T,SIZE>  operator *(T a) const; // mnożenie wektora przez liczbę
  Vector<T,SIZE> operator /(T a) const; // dzielenie wektora przez liczbę

  const T &operator[](int index) const;
  T &operator[](int index);


    //przeciążenie operatora wczytania - funkcja zaprzyjaźniona
    friend std::istream &operator>>(std::istream &in, Vector<T,SIZE>  &v)
    {
        for(int i=0;i<SIZE;i++)
        {
            in>>v.data[i];
        }
        return in;
    }
    //przeciążenie operatora wyświetlania - funkcja zaprzyjazniona
    friend std::ostream &operator<<(std::ostream &out, Vector<T,SIZE>  v)
    {
        for(int i=0;i<SIZE;i++)
        {
            out<<v.data[i]<<"   ";
        }
        out <<std::endl;
        return out;
    }
};
using Vector3D = Vector<double,3>; //alias do używania nazwy Vector3D zamiast szablonu
/****************************************************************************************/

//przeciążenie operatora dodawania dwóch wektorów
template <typename T,int SIZE>
Vector<T,SIZE> Vector<T,SIZE> ::operator+(Vector<T,SIZE>  v) const
{
    Vector<T,SIZE>  temp; //zmienna tymczasowa
    for(int i=0;i<SIZE;i++)
    {
        temp.data[i]=data[i]+v.data[i];
    }
    return temp;
}
//przeciążenie operatora odejmowania dwóch wektorów
template <typename T,int SIZE>
Vector<T,SIZE>  Vector<T,SIZE> ::operator-(Vector<T,SIZE>  v) const
{
    Vector<T,SIZE>  temp; //zmienna tymczasowa
    for(int i=0;i<SIZE;i++)
    {
        temp.data[i]=data[i]-v.data[i];
    }
    return temp;
}
//przeciążenie operatora mnożenia wektora przez wektor
template <typename T,int SIZE>
T Vector<T,SIZE> ::operator*(Vector<T,SIZE>  v) const
{
    T result;
    for(int i=0;i<SIZE;i++)
    {
        result+=(data[i]*v.data[i]);
    }
    return result;
}
//przeciążenie operatora mnożenia wektora przez liczbę 
template <typename T,int SIZE>
Vector<T,SIZE>  Vector<T,SIZE> ::operator *(T a) const
{
    Vector<T,SIZE>  temp; //zmienna tymczasowa
    for(int i=0;i<SIZE;i++)
    {
        temp.data[i]=data[i]*a;
    }
    return temp;
}
//przeciążenie operatora dzielenie wektora przez liczbę 
template <typename T,int SIZE>
Vector<T,SIZE>  Vector<T,SIZE> ::operator /(T a) const
{
    if(a==0)
    {
        std::cerr<<"Blad, nie mozna dzielic przez zero!"<<std::endl;
        exit(0);
    }
    else
    {
        Vector<T,SIZE>  temp; //zmienna tymczasowa
        for (int i = 0; i < SIZE; i++)
        {
            temp.data[i] = data[i] / a;
        }
        return temp;
    }
}
//przeciązenie operatora [] const
template <typename T,int SIZE>
const T &Vector<T,SIZE> ::operator[](int index) const
{
    if(index<0 && index>=SIZE)
    {
        std::cerr<<"Blad indeksowania"<<std::endl;
        exit(0);
    }
    return data[index];
}
//przeciazenie operatora [] bez const
template <typename T,int SIZE>
T &Vector<T,SIZE> ::operator[](int index)
{
    return const_cast<T &>(const_cast<const Vector<T,SIZE> *>(this)->operator[](index));
}

template<typename T, int SIZE>
Vector<T, SIZE>::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        data[i]=0;
    }
}
