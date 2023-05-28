#pragma once
#include "Header.h"

class Animal
{

    friend ostream& operator<<(ostream& out, const Animal& object);
    friend istream& operator>>(istream& in, Animal& object);

private:
    string _name;
    string _clss;
    double _weight;

public:
    Animal();
    Animal(string name, string clss, double weight);
    Animal(const Animal& original);
    Animal(double x);
    ~Animal();
    int SetName(string name);
    string GetName();
    string GetNameBuff(string buff, int size);
    int SetClass(string clss);
    string GetClassBuff(string buff, int size);
    string GetClass();
    int SetWeight(double weight);
    double GetWeight();
    void Print();


    bool operator==(Animal obj);
    bool operator!=(Animal obj);

};

