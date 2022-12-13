#include <iostream>
#include "Array2D.h"

int main() {
   Array2D a1(5, 4);
   Array2D a2(5, 5);
   Array2D a3(5, 5, 6);
   Array2D a4(5, 5, 6);
   Array2D a5(5, 5, 7);

   if (a3 == a4) std::cout << "op== ok" << std::endl;
   else std::cout << "op== bad" << std::endl;

   if (a3 == a5) std::cout << "op== bad" << std::endl;
   else std::cout << "op== ok" << std::endl;

   Array2D& assgn = (a2 = a1);
   if (assgn == a2) std::cout << "op= ok" << std::endl;
   else std::cout << "op= bad" << std::endl;

   if (a1(1,1) == 1) std::cout << "op( ) const ok" << std::endl;
   else std::cout << "op( ) const bad" << std::endl;

   a1(1,1) = 100;
   if (a1(1,1) == 100) std::cout << "op( ) ok" << std::endl;
   else std::cout << "op( ) bad" << std::endl;

   if (assgn(1,1) == 100) std::cout << "op= bad" << std::endl;
   else std::cout << "op= ok" << std::endl;


   Array2D a6(2, 3, 1);
   Array2D a7(3, 2, 1);
   Array2D res = a6 * a7;
   if ((res(0,0) == 3) && (res(0,1) == 3) && (res(1,0) == 3) && (res(1,1) == 3)) {
      std::cout << "op* ok" << std::endl;
   } else {
      std::cout << "op* bad" << std::endl;
   }
   std::cout << "res:" << std::endl;
   std::cout << res << std::endl;

   Array2D res2 = a1*a7;
   if (res2(1,1) == -1) {
      std::cout << "op* with mismatched arrays ok" << std::endl;
   } else {
      std::cout << "op* with mismatched arrays bad" << std::endl;
   }

   Array2D a8(a6);
   a8(1,1) = 900;
   if (a8(1,1) != a6(1,1)) {
      std::cout << "Array2D(Array2D&) ok" << std::endl;
   } else {
      std::cout << "Array2D(Array2D&) bad" << std::endl;
   }
}
