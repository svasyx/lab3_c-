#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include "time.h"

#include "Animal.h"
#define FU

using namespace::std;

Animal::Animal()
{
    _name = "";
    _name = "NoName";
    _clss = "";
    _clss = "NoClass";
    _weight = 0;
#ifdef FU
    cout << "ініціалізація () \n";
#endif
}

Animal::Animal(string name, string clss, double weight)
{

    _name = name;
    this->_clss = "";


    _clss = clss;
    if (weight > 0)
    {
        this->_weight = weight;
    }
#ifdef FU
    cout << "ініціалізація (параметри) \n";
#endif

}
Animal::Animal(const Animal& original)
{

    _clss = "";

    _name = original._name;
    _clss = original._clss;
    _weight = original._weight;
#ifdef FU
    cout << "ініціалізація (копіювання) \n";
#endif
}

Animal::Animal(double x)
{
    if (x > 0)
    {
        this->_weight = x;
    }
    else
    {
#ifdef FU
        cout << "Initialisation problem\n";
#endif
        exit(2);
    }
#ifdef FU
    cout << "ініціалізація (перетворення) \n";
#endif
}

Animal::~Animal()
{
#ifdef FU
    cout << "знищення\n";
#endif

    _name = nullptr;

    _clss = nullptr;

}

bool Animal::operator==(Animal obj)
{

    if (_name == obj._name && _clss == obj._clss && _weight == obj._weight)
    {
        return true;

    }
    else
    {
        return false;
    }

}
bool Animal::operator!=(Animal obj)
{
    if (_name != obj._name && _clss != obj._clss && _weight != obj._weight)
    {
        return true;

    }
    else
    {
        return false;
    }
}


string Animal::GetName()
{
    /*
    pomylka
    char* name="\0";
    name=_name;
    */
    string name;
    name = _name;

    return name;
}

string Animal::GetNameBuff(string buff, int size)
{

    buff = _name;

    return buff;
}

int Animal::SetName(string name)
{
    _name = nullptr;

    this->_name = "";
    this->_name = name;

    return 1;
}

void Animal::Print()
{
    cout << endl << _name << endl << _clss << endl << _weight << endl;
}

int Animal::SetWeight(double weight)
{
    if (weight > 0)
    {
        _weight = weight;
        return 0;
    }
    else
    {
        //#ifdef FU
        cout << "Weight cannot be 0 or less \n";
        //#endif
        return 1;

    }
}

double Animal::GetWeight()
{
    return _weight;
}

int Animal::SetClass(string clss)
{
    _clss = nullptr;

    this->_clss = "";
    _clss = clss;

    return 1;
}

string Animal::GetClass()
{
    string clss;
    clss = "";
    clss = _clss;

    return clss;
}

string Animal::GetClassBuff(string buff, int size)
{
    buff = _clss;
    return buff;
}

