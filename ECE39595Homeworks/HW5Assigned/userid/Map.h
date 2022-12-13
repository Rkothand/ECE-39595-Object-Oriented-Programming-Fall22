#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <map>

#include "TwoTuple.h"

class Map {
public:
   virtual void insert(int key, TwoTuple* _data);
   virtual TwoTuple* lookUp(int key);
private:
   // declare a std::map here that takes an int and a TwoTuple*
   std::map<int, TwoTuple*> map;
};
#endif /* MAP_H_ */
