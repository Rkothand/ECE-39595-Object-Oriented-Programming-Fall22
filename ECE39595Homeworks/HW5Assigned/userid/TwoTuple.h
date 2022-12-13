#ifndef TWOTUPLE_H_
#define TWOTUPLE_H_

#include <string>

class TwoTuple {
public:
   TwoTuple(std::string _name, int _age);
   void displayTuple( );
private:
   std::string name;
   int age;
};
#endif /* TWOTUPLE_H_ */
