#include "Automobile.h"
#include <string>

automobile::automobile(int _vehicleID, float _milesDriven, int _mm, int _dd, int _yyyy){
    vehicleID = _vehicleID;
    milesDriven = _milesDriven;
    dateOfLastMaintainence = std::to_string(_mm)+"/"+std::to_string(_dd)+"/"+std::to_string(_yyyy);
}

std::string automobile::toString(){
    return std::to_string(vehicleID) + "\n" + std::to_string(milesDriven) + "\n" + dateOfLastMaintainence;
}