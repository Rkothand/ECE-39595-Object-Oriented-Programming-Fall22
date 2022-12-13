#include <string>
#include "Address.h"

Address::Address(std::string _street, std::string _city, std::string _state, std::string _postalCode) {
   street = _street;
   city = _city;
   state = _state;
   postalCode = _postalCode;
}

Address::Address(std::string _street, std::string _city, std::string _state, std::string _postalCode, std::string _country) {
   street = _street;
   city = _city;
   state = _state;
   postalCode = _postalCode;
   country = _country;
}

std::string Address::toString( ) {
   std::string address = street+"\n";
   address += city+"\n";
   address += state+"\n";
   address += country+"\n";
   address += postalCode+"\n";
   return address;
}
