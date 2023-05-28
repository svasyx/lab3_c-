#pragma once
#include "Header.h"
#include "List.h"
#include "Animal.h"

class Node
{

	friend class List;

public:
	Animal Get_data();

private:
	Animal _data;
	Node* _next;
	Node(string _name, string _clss, double _weight);

};

