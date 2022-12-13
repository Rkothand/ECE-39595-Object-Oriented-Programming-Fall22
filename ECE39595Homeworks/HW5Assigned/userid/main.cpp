#include <iostream>

#include "TwoTuple.h"
#include "Map.h"

int main(int argc, char *argv[]) {

   std::string names[5] = {"Bob", "Ralph", "Mary", "Lou", "Sam"};

   Map* map = new Map( );

   for (int i=0; i<5; i++) {
      map->insert(i, new TwoTuple(names[i], i*10));
   }

   for (int i=0; i<5; i++) {
      TwoTuple* tt = map->lookUp(i);
      std::cout << "key: " << i << ", "; tt->displayTuple( ); std::cout << std::endl;  
   }

   TwoTuple* tt = map->lookUp(5);
   if (tt == nullptr) {
      std::cout << "key 6, nullptr" << std::endl;
   } else {
      std::cout << "key: 6, "; tt->displayTuple( ); std::cout << std::endl;  
   }
}
