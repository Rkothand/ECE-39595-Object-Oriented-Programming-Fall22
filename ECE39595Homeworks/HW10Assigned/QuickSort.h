#include <iostream>
#include <string>
#include "Command.h"

class QuickSort {
private:
   int* arr;
   int length;

   void quickSort(int low, int high);
   int min(int v1, int v2);
   int findPivot(int arr[ ], int low, int high);
   int partition(int low, int high);

public:
   QuickSort( );
   QuickSort(int numElements);

   virtual void sort( );

   friend std::ostream& operator<<(std::ostream& os, const QuickSort qs);
};
