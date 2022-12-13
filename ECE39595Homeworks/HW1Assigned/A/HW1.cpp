#include <iostream>
#include "Address.h"

int main(int argc, char* argv[]) {
   Address* address1 = new Address("465 Northwestern Ave, EE 310, Purdue University", "West Lafayette", "IN", "47907");
   std::cout << address1->toString( );    

   Address* address2 = new Address("490 Northwestern Ave, MSEE 300, Purdue University", "West Lafayette", "IN", "47907", 
                                   "United States of America");
   std::cout << address2->toString( );    
}
