#ifndef LAYSBROODYEGGS_H_
#define LAYSBROODYEGGS_H_
#include "LaysEggs.h"
#include <iostream>
class LaysEggsBroody : public LaysEggs {
    public:
        void layEggs(){
            std::cout << "Lays eggs, but will fight you for them." << std::endl;
        }
};
#endif /* LAYSEGGSBROODY_H_ */