#include <iostream>

#include "LinkedListNode.h"

LinkedListNode::LinkedListNode(LinkedListNode* _next, int _datum1, int _datum2) : DataBin(_datum1), next(_next) { 
   datum2 = new int(_datum2);
}

int LinkedListNode::getDatum1( ) {
   return getDatum( );
}

int LinkedListNode::getDatum2( ) {
   return *datum2;
}

LinkedListNode* LinkedListNode::getNext( ) {
   return next;
}

