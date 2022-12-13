#ifndef LAYSTOYEGGS_H_
#define LAYSTOYEGGS_H_
#include "LaysEggs.h"
#include <iostream>

class LaysToyEggs: public LaysEggs {
    public:
        void layEggs(){
            std::cout << "Lays toy eggs." << std::endl;
        }
};

#endif