#include <iostream>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include "QuickSort.h"
#include "Command.h"
#include "workQueue.h"
#include "dotProduct.h"

#define NUMSORTS 4
#define STARTSIZE 8000

using namespace std::chrono;

/*
Use either the version of worker. 

void worker(WorkQueue& workQ) {
   std::shared_ptr<Command> c(workQ.get( ));
   while (c != nullptr) {
      c->execute( );
      std::lock_guard<std::mutex> lck(outputLock); 
      c->dentify( );
      c = workQ.get( );
   }
}
*/
void worker(WorkQueue* workQ) {
   std::shared_ptr<Command> c(workQ->get( ));
   while (c != nullptr) {
      c->execute( );
      static std::mutex outputLock;
      std::lock_guard<std::mutex> lck(outputLock); 
      (*c).identify( );
      c = workQ->get( );
   }
}


int main(int argc, char** args) {

   int sortSize = STARTSIZE;
   for (int i=0; i<NUMSORTS; i++) {
      QuickSort sort = QuickSort(sortSize);
      auto start = high_resolution_clock::now();
      sort.sort( );
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start).count( );
      std::cout << "Sort of " << sortSize << " ints took " << duration << " microseconds";
      std::cout << "sort: " << sort;
      sortSize *=2;
   }
}
