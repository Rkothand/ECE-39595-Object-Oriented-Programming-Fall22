#include <iostream>
#include "LinkedListNode.h"

int main(int argc, char** args) {
   LinkedListNode* head = nullptr;

   for (int i=0; i < 10; i++) {
      head = new LinkedListNode(head, i, i+10);
   }

   LinkedListNode* traverseHead = head;
   for (int i=0; i < 10; i++) {
      std::cout << "visiting node " << traverseHead->getDatum1( ) << ", " << traverseHead->getDatum2( ) << std::endl;
      traverseHead = traverseHead->getNext( );
   }

   delete head;
}
