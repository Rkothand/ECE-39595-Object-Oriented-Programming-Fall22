#ifndef TOYDUCK_H
#define TOYDUCK_H
#include "Duck.h"
#include "FlyBehavior.h"
#include "DoesNotLayEggs.h"
#include "QuackBehavior.h"
#include "FlyNoWay.h"

class ToyDuck : public Duck {
public:
    ToyDuck();
    void display();
};

#endif