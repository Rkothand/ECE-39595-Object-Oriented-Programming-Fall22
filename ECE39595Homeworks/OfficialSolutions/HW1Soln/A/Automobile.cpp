#include <iostream>
#include <string>

#include "Automobile.h"


Automobile::Automobile(int v, double miles, int mm, int dd, int yy) {
   vin = v;
   mileage = miles;
   maintenanceDate = ""+std::to_string(mm)+"/"+std::to_string(dd)+"/"+std::to_string(yy);
}

int Automobile::getVIN( ) {
   return vin;
}

double Automobile::getMileage( ) {
   return mileage;
}

std::string Automobile::getMaintenanceDate( ) {
   return maintenanceDate;
}
