#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>

class Address {
public:
   Address(std::string _street, std::string _city, std::string _state, int _zip);

   virtual int getZipCode( );
   virtual std::string getAddress( );

private:
   const std::string street;
   const std::string city;
   const std::string state;
   const int zip;
};
#endif /* ADDRESS_H_ */
