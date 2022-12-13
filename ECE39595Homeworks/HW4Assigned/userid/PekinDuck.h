#ifndef PEKINDUCK_h
#define PEKINDUCK_h
#include "Duck.h"
#include "LaysEggs.h"
#include "Quack.h"
#include "FlyPoorly.h"
#include "MuteQuack.h"

class PekinDuck : public Duck {
    public:
        PekinDuck();
        void display();
};
#endif