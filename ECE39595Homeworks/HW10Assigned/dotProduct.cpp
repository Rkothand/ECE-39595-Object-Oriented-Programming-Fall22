#include <iostream>
#include <string>
#include <stdlib.h>
#include "dotProduct.h"

DotProduct::DotProduct(int numElements) : len(numElements) {

   float total = 0;

   int i;

   a = new int[len];

   for (i = 0; i < len; i++) {
      a[i] = rand( ) % 100;
   }

   b = new int[len];

   for (int i=0; i<len; i++) {
      b[i] = rand( ) % 100;
   }
}

DotProduct::DotProduct( ) {
   DotProduct(0);
}

void DotProduct::DotProductCalc(){
   int i;

   for (i = 0; i < len; i++){
      total += a[i] * b[i];
   }
}

void DotProduct::execute( ) {
   this->DotProductCalc();

}

std::ostream& operator<<(std::ostream& outstream, const DotProduct dot) {

   outstream << "inner product of array length " << dot.len << ", is " << dot.total << "\n\n" << std::endl;
   return outstream;
}

void DotProduct::identify() {
   std::cout << *this;
}