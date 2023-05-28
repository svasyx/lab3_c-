#pragma once
#include "Header.h"
#include "Animal.h"
#include "List.h"

 class Zoo
{
public:

	Zoo();
	void Print();
	~Zoo();

	int GetAnimalsCount();

	List Iterator_pop(bool(*action)(Animal, double), const double weight);
	List Iterator_str(bool(*action)(Animal, string), const string smth);

	Zoo& operator+(Animal obj);
	Zoo& operator-(Animal obj);
	Zoo& operator=(const Zoo& obj);


private:

	int _animalsCount;
	List _list;

};

