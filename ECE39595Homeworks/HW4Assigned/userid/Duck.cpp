#include <iostream>
#include "Duck.h"

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

void Duck::performEggLaying(){
   laysEggs->layEggs( );
}

void Duck::setFlyBehavior(FlyBehavior* fb) {
   flyBehavior = fb;
}
   
void Duck::setQuackBehavior(QuackBehavior* qb) {
   quackBehavior = qb;
}
