#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include <string>

class Automobile {

private: 
   int vin;
   double mileage;
   std::string maintenanceDate;

public:
   Automobile(int v, double miles, int mm, int dd, int yy);
   virtual int getVIN( );
   virtual double getMileage( );
   virtual std::string getMaintenanceDate( );
};
#endif /* AUTOMOBILE_H_ */
