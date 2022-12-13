#include "ToyDuck.h"
#include "Quack.h"
#include "QuackBehavior.h"
#include "FlyNoWay.h"
#include "MuteQuack.h"
#include "LaysToyEggs.h"
#include <iostream>

ToyDuck::ToyDuck() {
    quackBehavior = new Quack();
    flyBehavior = new FlyNoWay();
    laysEggs = new LaysToyEggs();
}

void ToyDuck::display() {
    std::cout << "I am a toy duck." << std::endl;
}