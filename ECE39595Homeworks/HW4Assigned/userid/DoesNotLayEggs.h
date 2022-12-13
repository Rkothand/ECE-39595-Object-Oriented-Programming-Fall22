#ifndef DOES_NOT_LAY_EGGS_H_
#define DOES_NOT_LAY_EGGS_H_

#include <iostream>
#include "LaysEggs.h"

class DoesNotLayEggs : public LaysEggs{
    public:
        void layEggs(){
            std::cout << "Not egg layer." <<std::endl;
        }
};

#endif