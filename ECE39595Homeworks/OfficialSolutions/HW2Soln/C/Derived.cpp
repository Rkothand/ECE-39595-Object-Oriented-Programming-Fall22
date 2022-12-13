#include <iostream>
#include "Derived.h"

void Derived::f3( ) {
   std::cout << "Derived::f3" << std::endl;
}

void Derived::f4( ) {
   std::cout << "Derived::f4" << std::endl;
}

void Derived::f5( ) {
   std::cout << "Derived::f5" << std::endl;
}

void Derived::f6( ) {
   std::cout << "Derived::f6" << std::endl;
}

void Derived::f1( ) {
   std::cout << "Derived::f1" << std::endl;
}

void Derived::f2( ) {
   std::cout << "Derived::f2" << std::endl;
}

void Derived::foo1( ) {
   std::cout << "Derived::foo1" << std::endl;
   f1( );
}
