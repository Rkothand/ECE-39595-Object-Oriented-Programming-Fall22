#ifndef LAYSNOTBROODYEGGS_H_
#define LAYSNOTBROODYEGGS_H_
#include <iostream>
#include "LaysEggs.h"
class LaysNotBroodyEggs : public LaysEggs {
    public:
        void layEggs(){
            std::cout << "Lays eggs and will give them up if fed." << std::endl;
        }
};
#endif