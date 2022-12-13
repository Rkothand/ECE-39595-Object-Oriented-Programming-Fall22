#include <iostream>
#include "float.h"

Float::Float( ) : data(0) { }

Float::Float(float _data) : data(_data) { }

bool Float::operator==(const Float& other) const {
   return data == other.data;
}

std::ostream& operator<<(std::ostream& os, const Float& toPrFloat) {
   os << toPrFloat.data;
   return os;
}

bool Float::operator<(const Float& other) const {
   return data < other.data;
}

bool Float::operator> (const Float& other) const {
   return data > other.data;
}