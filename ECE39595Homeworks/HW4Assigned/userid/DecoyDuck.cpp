#include <iostream>
#include "DecoyDuck.h"
#include "FlyNoWay.h"
#include "MuteQuack.h"
#include "DoesNotLayEggs.h"

DecoyDuck::DecoyDuck( ) {
   flyBehavior = new FlyNoWay( );
   quackBehavior = new MuteQuack( );
   laysEggs = new DoesNotLayEggs( );
}

void DecoyDuck::display( ) {
   std::cout << "I’m a decoy duck" << std::endl;
}
