#include <string>
#include <iostream>
#include "Automobile.h"

int main(int argc, char* argv[ ]) {
   Automobile* auto1 = new Automobile(12345678, 1024.3, 06, 13, 2020);
   Automobile* auto2 = new Automobile(12345679, 1025.3, 07, 13, 2020);

   std::cout << "Auto1:" << std::endl;
   std::cout << "   VIN: " << auto1->getVIN( ) << std::endl;
   std::cout << "   mileage: " << auto1->getMileage( ) << std::endl;
   std::cout << "   last maintenance: " << auto1->getMaintenanceDate( ) << std::endl << std::endl;

   std::cout << "Auto2:" << std::endl;
   std::cout << "   VIN: " << auto2->getVIN( ) << std::endl;
   std::cout << "   mileage: " << auto2->getMileage( ) << std::endl;
   std::cout << "   last maintenance: " << auto2->getMaintenanceDate( ) << std::endl;
}
