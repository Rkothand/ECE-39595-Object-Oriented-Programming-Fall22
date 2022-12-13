#include <iostream>
#include "Base.h"
#include "Derived.h"

int main(int argc, char** args) {
   std::cout << "XYZ" << std::endl; // S0
   Base* b = new Base( ); // S1
   b->f1( ); // S2
   b->f2( ); // S3
   b->f3( ); // S4
   b->f4( ); // S5
   b->f5( ); // S6
   b->f6( ); // S7
   b->foo0( ); // S8
   b->foo1( ); // S9
   b->foo2( ); // S10

   b = new Derived( ); // S11
   b->f1( ); // S12
   b->f2( ); // S13
   b->f3( ); // S14
   b->f4( ); // S15
   b->f5( ); // S16
   b->f6( ); // S17
   b->foo0( ); // S18
   b->foo1( ); // S19
   b->foo2( ); // S20

   Derived* d = new Derived( ); // 21
   d->f1( ); // 22
   d->f2( ); // 23
   d->f3( ); // 24
   d->f4( ); // 25
   d->f5( ); // 26
   d->f6( ); // 27
   d->foo0( ); // 28
   d->foo1( ); // 29
   d->foo2( ); // 30
}
