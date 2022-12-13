#include <iostream>
#include "Staticy.h"

int main(int argc, char** args) {
   for (int i=0; i < 101; i++) {
      Staticy* sp = Staticy::makeStaticy(i);
   }
   std::cout << "number of calls to Static(int) with even args is " << Staticy::getEvenCount( ) << std::endl;
}
