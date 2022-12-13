#include <iostream>
#include "Base.h"
void Base::f3( ) {
   std::cout << "Base::f3" << std::endl;
}

void Base::f4( ) {
   std::cout << "Base::f4" << std::endl;
}

void Base::f5( ) {
   std::cout << "Base::f5" << std::endl;
}

void Base::foo0( ) {
   std::cout << "Base::foo0" << std::endl;
   f0( );
}

void Base::foo1( ) {
   std::cout << "Base::foo1" << std::endl;
   f1( );
}

void Base::foo2( ) {
   std::cout << "Base::foo2" << std::endl;
   f2( );
}

void Base::f0( ) {
   std::cout << "Base::f0" << std::endl;
}

void Base::f1( ) {
   std::cout << "Base::f1" << std::endl;
}

void Base::f2( ) {
   std::cout << "Base::f2" << std::endl;
}
