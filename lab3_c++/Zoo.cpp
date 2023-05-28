#include "Zoo.h"


Zoo::Zoo()
{

    _animalsCount = 0;

}

void Zoo::Print()
{
    for (int i = 0; i < _list.GetSize(); i++)
    {
        cout << _list[i] << endl;
    }
}

Zoo::~Zoo()
{

    _list.Delete_list();
}

Zoo& Zoo::operator+(Animal obj)
{
    _list + obj;
    _animalsCount++;
    return *this;
}

Zoo& Zoo::operator=(const Zoo& obj)
{
    _list = obj._list;
    this->_animalsCount = obj._animalsCount;
    return *this;
}

Zoo& Zoo::operator-(Animal obj)
{
    _list - obj;

    _animalsCount--;
    return *this;
}

int Zoo::GetAnimalsCount()
{
    return _animalsCount;
}

List Zoo::Iterator_pop(bool(*action)(Animal, double), const double weight)
{
    List obj = _list.Iterator_pop(action, weight);

    return obj;
}

List Zoo::Iterator_str(bool(*action)(Animal, string), const string smth)
{
    List obj = _list.Iterator_str(action, smth);

    return obj;
}