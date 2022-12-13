#include <string>
#include "Address.h"

Address::Address(std::string _street, std::string _city, std::string _state, int _zip) 
   :street(_street), city(_city), state(_state),zip(_zip)
{}

int Address::getZipCode( ) {
   return zip;
}

std::string Address::getAddress( ) {
   return street + "\n" + city + "\n" + state + "\n" + std::to_string(zip) + "\n";
}