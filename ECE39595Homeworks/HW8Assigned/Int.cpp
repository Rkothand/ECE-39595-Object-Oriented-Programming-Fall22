#include <iostream>
#include "Int.h"

Int::Int( ) : data(0) { }

Int::Int(int _data) : data(_data) { }

bool Int::operator==(const Int& other) const {
   return data == other.data;
}

bool Int::operator<(const Int& other) const {
   return data < other.data;
}

bool Int::operator> (const Int& other) const {
   return data > other.data;
}

std::ostream& operator<<(std::ostream& os, const Int& toPrint) {
   os << toPrint.data;
   return os;
}
