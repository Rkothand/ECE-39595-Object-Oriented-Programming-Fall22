#include <iostream>
#include "MallardDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include <memory>
using namespace std;

MallardDuck::MallardDuck( ) {
   quackBehavior = shared_ptr<Quack>(new Quack( ));
   flyBehavior = shared_ptr<FlyWithWings>(new FlyWithWings( ));
}

void MallardDuck::display( ) {
   std::cout << "I’m a real mallard duck" << std::endl;
}
