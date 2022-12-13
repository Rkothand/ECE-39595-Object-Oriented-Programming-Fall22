#ifndef DOTPRODUCT_H_
#define DOTPRODUCT_H_

#include <iostream>
#include <string>

#include "Command.h"

class DotProduct : public Command {
private:

   int* a;
   int* b;
   int len, total;

public:
   void DotProductCalc();
   DotProduct();
   DotProduct(int numElements);

   void execute();
   void identify();

   friend std::ostream& operator<<(std::ostream& os, const DotProduct qs);
};

#endif