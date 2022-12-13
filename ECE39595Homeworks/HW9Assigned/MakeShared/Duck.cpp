#include <iostream>
#include "Duck.h"
#include <memory>
using namespace std;
Duck::Duck( ) { }

void Duck::swim( ) {
   std::cout << "All ducks float" << std::endl;
}

void Duck::performQuack ( ) {
   quackBehavior->quack( );
}

void Duck::performFly( ) {
   flyBehavior->fly( );
}

void Duck::setFlyBehavior(shared_ptr<FlyBehavior> fb) {
   flyBehavior = fb;
}
   
void Duck::setQuackBehavior(shared_ptr<QuackBehavior> qb) {
   quackBehavior = qb;
}
