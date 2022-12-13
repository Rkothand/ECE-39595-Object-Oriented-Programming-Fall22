#include <iostream>
#include <string>
#include <stdlib.h>

#include "QuickSort.h"

QuickSort::QuickSort(int numElements) : length(numElements) {
   arr = new int[length];
   for (int i=0; i<length; i++) {
      arr[i] = rand( ) % 100;
   }
}

QuickSort::QuickSort( ) { // this is a delegating constructor!
   QuickSort(0);
}

void QuickSort::sort( ) {
   quickSort(0, length-1);
   srand(0); // init with a fixed seed so that it always generates the same 
             // random sequence to make debugging easier.
}

std::ostream& operator<<(std::ostream& os, const QuickSort qs) {
   int stride = 1;
   if (qs.length > 32) {
      stride = qs.length / 32;
   }
   os << "num elements sorted: " << qs.length << "\n";
   for (int i=0; i<qs.length; i+=stride) {
      os << qs.arr[i] << " "; 
   }
   os << "\n\n";
   return os;
}

void QuickSort::quickSort(int low, int high) {
   if (low < high) {
      int partitionIndex = partition(low, high);
      quickSort(low, partitionIndex-1);
      quickSort(partitionIndex+1, high);
   }
}

int QuickSort::min(int v1, int v2) {
   return v1<v2 ? v1 : v2;
}

int QuickSort::partition(int low, int high) {
   int pivot = arr[(low+high)/2]; 
   
   int pos = low-1;

   for (int j=low; j<high; j++) {
      if (arr[j] <= pivot) {
         pos++;
         int swapTemp = arr[pos];
         arr[pos] = arr[j];
         arr[j] = swapTemp;
      }
   }
   int swapTemp = arr[pos+1];
   arr[pos+1] = arr[high];
   arr[high] = swapTemp;

   return pos+1;
}
