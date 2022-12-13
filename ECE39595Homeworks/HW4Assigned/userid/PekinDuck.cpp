#include "PekinDuck.h"
#include "LaysNotBroodyEggs.h"
#include <iostream>

PekinDuck::PekinDuck(){
    quackBehavior = new Quack();
    flyBehavior = new FlyPoorly();
    laysEggs = new LaysNotBroodyEggs();
}

void PekinDuck::display(){
    std::cout<<"Pekin Duck"<<std::endl;
}