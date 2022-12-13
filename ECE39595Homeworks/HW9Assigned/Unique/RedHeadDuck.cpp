#include <iostream>
#include "RedHeadDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
using namespace std;



RedHeadDuck::RedHeadDuck( ) {
   quackBehavior = unique_ptr<Quack>(new Quack( ));
   flyBehavior = unique_ptr<FlyWithWings>(new FlyWithWings( ));

}

void RedHeadDuck::display( ) {
   std::cout << "I’m a real redheaded duck" << std::endl;
}
