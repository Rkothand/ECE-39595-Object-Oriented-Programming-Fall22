#include <iostream>
#include "Automobile.h"

int main(int argc, char* argv[]) {
   automobile* automobile1 = new automobile(101,5,1,1,2022);
   std::cout << automobile1->toString( )<<std::endl;    

   automobile* automobile2 = new automobile(102,5,9,1,2022);
   std::cout << automobile2->toString( )<<std::endl;     
}
