#include <iostream>
#include <string>

#include "Automobile.h"


Automobile::Automobile(int v, double miles, int mm, int dd, int yy) {
   vin = v;
   mileage = miles;
   maintenanceMonth = mm;
   maintenanceDay = dd;
   maintenanceYear = yy;
}

int Automobile::getVIN( ) {
   return vin;
}

double Automobile::getMileage( ) {
   return mileage;
}

std::string Automobile::getMaintenanceDate( ) {
   return ""+std::to_string(maintenanceMonth)+"/"+std::to_string(maintenanceDay)+"/"+std::to_string(maintenanceYear);
}
