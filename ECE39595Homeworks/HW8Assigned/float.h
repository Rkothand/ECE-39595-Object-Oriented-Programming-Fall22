#ifndef FLOAT_H_
#define FLOAT_H_
#include <iostream>

class Float {
private:
   float data;
public:
   Float( );
   Float(float _data);
   bool operator==(const Float& other) const;
   bool operator<(const Float& other) const;
   bool operator>(const Float& other) const;
   friend std::ostream& operator<<(std::ostream& os, const Float& toPrint);
};
#endif