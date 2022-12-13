#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

class Address {
private:
   std::string street;
   std::string city;
   std::string state;
   std::string postalCode;
   std::string country = "USA";

public:
   Address(std::string _street, std::string _city, std::string _state, std::string _postalCode);
   Address(std::string _street, std::string _city, std::string _state, std::string _postalCode, std::string _country);
   std::string toString( );
};
#endif /* ADDRESS_H_ */
