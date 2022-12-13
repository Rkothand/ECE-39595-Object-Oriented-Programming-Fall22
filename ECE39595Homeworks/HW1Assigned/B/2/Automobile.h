#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include <string>

class automobile {
private:
   int vehicleID;
   float milesDriven;
   int mm;
   int dd;
   int yyyy;
   std::string dateOfLastMaintainence; 

public:
   automobile(int _vehicleID, float _milesDriven, int _mm, int _dd, int _yyyy);
   std::string toString( );
};
#endif /* AUTOMOBILE_H_ */