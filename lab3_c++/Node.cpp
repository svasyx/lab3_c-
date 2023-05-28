
#include "Node.h"

Animal Node::Get_data()
{
    return _data;
}



Node::Node(string _name, string _clss, double _weight) : _data(_name, _clss, _weight)
{
    this->_next = nullptr;
}