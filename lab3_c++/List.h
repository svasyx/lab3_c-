#pragma once
#include "Header.h"
#include "Animal.h"
#include "Node.h"

class List
{

public:
	List();
	List(Animal obj);
	List(const List& list);

	int GetSize()const;


	void DeleteElem();

	void Delete_list();



	List Iterator_pop(bool(*action)(Animal, double), const double weight);
	List Iterator_str(bool(*action)(Animal, string), const string smth);

	Animal& operator[](const int index);
	List& operator+(Animal obj);
	List& operator-(Animal obj);
	List& operator=(const List& list);
	bool operator==(const List& list);
	~List();
private:



	Node* _head;
	void Add(const string name, const string clss, int weight);
	void Invert(const string name, const string clss, int weight);
	



}; 

