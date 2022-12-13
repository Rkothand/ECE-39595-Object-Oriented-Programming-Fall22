#include <iostream>
#include "RedHeadDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
using namespace std;

RedHeadDuck::RedHeadDuck( ) {
   quackBehavior = make_shared<Quack>(Quack());
   flyBehavior = make_shared<FlyWithWings>(FlyWithWings());
}

void RedHeadDuck::display( ) {
   std::cout << "I’m a real redheaded duck" << std::endl;
}
