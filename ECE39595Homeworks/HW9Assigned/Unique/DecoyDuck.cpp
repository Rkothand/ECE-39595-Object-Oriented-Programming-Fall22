#include <iostream>
#include "DecoyDuck.h"
#include "FlyNoWay.h"
#include "MuteQuack.h"
#include <memory>
using namespace std;

DecoyDuck::DecoyDuck( ) {
   flyBehavior = unique_ptr<FlyNoWay>(new FlyNoWay( ));
   quackBehavior = unique_ptr<MuteQuack>(new MuteQuack( ));
}

void DecoyDuck::display( ) {
   std::cout << "I’m a decoy duck" << std::endl;
}
