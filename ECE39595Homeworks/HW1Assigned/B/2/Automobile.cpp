#include "Automobile.h"
#include <string>

automobile::automobile(int _vehicleID, float _milesDriven, int _mm, int _dd, int _yyyy){
    vehicleID = _vehicleID;
    milesDriven = _milesDriven;
    mm = _mm;
    dd = _dd;
    yyyy = _yyyy;
}

std::string automobile::toString(){
    return std::to_string(vehicleID) + "\n" + std::to_string(milesDriven) + "\n" + std::to_string(dd) + "/" + std::to_string(mm)+ "/" +std::to_string(yyyy);
}