#include <iostream>
#include "MallardDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "LaysBroodyEggs.h"

MallardDuck::MallardDuck( ) {
   quackBehavior = new Quack( );
   flyBehavior = new FlyWithWings( );
   laysEggs = new LaysEggsBroody();
}

void MallardDuck::display( ) {
   std::cout << "I’m a real mallard duck" << std::endl;
}
