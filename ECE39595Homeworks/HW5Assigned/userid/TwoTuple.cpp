#include <iostream>

#include "TwoTuple.h"

TwoTuple::TwoTuple(std::string _name, int _age) : name(_name), age(_age) { }

void TwoTuple::displayTuple( ) {
   std::cout << "(" << name << ", " << age << ")";
}
