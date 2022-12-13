#include "Staticy.h"

int Staticy::count = 0;

Staticy::Staticy(int arg) {
   if ((arg % 2) == 0) count++;
}

Staticy* Staticy::makeStaticy(int arg) {
   return new Staticy(arg);
}

int Staticy::getEvenCount( ) {
   return count;
}
