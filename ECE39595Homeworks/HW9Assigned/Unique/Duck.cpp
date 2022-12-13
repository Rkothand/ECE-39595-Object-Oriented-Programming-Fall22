#include <iostream>
#include "Duck.h"
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

void Duck::setFlyBehavior(unique_ptr<FlyBehavior> fb) {
   flyBehavior = move(fb);
}
   
void Duck::setQuackBehavior(unique_ptr<QuackBehavior> qb) {
   quackBehavior = move(qb);
}

