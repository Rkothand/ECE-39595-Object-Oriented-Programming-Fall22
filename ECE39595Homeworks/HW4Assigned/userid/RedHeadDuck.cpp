#include <iostream>
#include "RedHeadDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "LaysBroodyEggs.h"

RedHeadDuck::RedHeadDuck( ) {
   quackBehavior = new Quack( );
   flyBehavior = new FlyWithWings( );
   laysEggs = new LaysEggsBroody();
}

void RedHeadDuck::display( ) {
   std::cout << "I’m a real redheaded duck" << std::endl;
}
