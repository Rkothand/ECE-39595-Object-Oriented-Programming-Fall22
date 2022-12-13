#include <iostream>
#include "MallardDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include <memory>

MallardDuck::MallardDuck( ) {
   quackBehavior = unique_ptr<Quack>(new Quack( ));
   flyBehavior = unique_ptr<FlyWithWings>(new FlyWithWings( ));
}

void MallardDuck::display( ) {
   std::cout << "I’m a real mallard duck" << std::endl;
}
