#ifndef INT_H_
#define INT_H_
#include <iostream>

class Int {
private:
   int data;
public:
   Int( );
   Int(int _data);
   bool operator==(const Int& other) const;
   bool operator<(const Int& other) const;
   bool operator>(const Int& other) const;
   friend std::ostream& operator<<(std::ostream& os, const Int& toPrint);
};
#endif /* INT_H_ */
