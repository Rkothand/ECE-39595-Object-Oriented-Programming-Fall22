#include <iostream>
#include "Int.h"
#include "Node.h"
#include "float.h"


int main(int argc, char** args) {
   const int values[ ] {5, 1, 7, 15};
   Node<Int>* rootInt = new Node(Int(10));
   for (int i = 0; i < 4; i++) {
      rootInt->insertNode(Int(values[i])); 
   }

   rootInt->print( );
   std::cout<<"\n" << std::endl;

//double
   const double values2[ ] {5.0, 1.0, 7.0, 15.0};
   Node<double>* rootDouble = new Node <double>(10.0);
   for (int i = 0; i < 4; i++) {
      rootDouble->insertNode((double)(values2[i])); 
   }

   rootDouble->print( );
   std::cout<<"\n" << std::endl;

//float
   const Float values3[ ]{{5.0, 1.0, 7.0, 15.0};
   Node<Float>* rootFloat = new Node <Float>(10.0);
   for (int i = 0; i < 4; i++) {
      rootFloat->insertNode((Float)(values3[i])); 
   }

   rootFloat->print( );
   std::cout<<"\n" << std::endl;

   const float values4[ ]{{5.0, 1.0, 7.0, 15.0};
   Node<float>* rootfloat = new Node <float>(10.0);
   for (int i = 0; i < 4; i++) {
      rootfloat->insertNode((float)(values4[i])); 
   }

   rootfloat->print( );
   std::cout<<"\n" << std::endl;
/*
   Node<double>* rootDouble = new Node<double>(10.0);
   for (int i = 0; i < 4; i++) {
      rootDouble->insertNode((double) values[i]); 
   }
   rootInt->print( );
   std::cout << std::endl;
*/
}
