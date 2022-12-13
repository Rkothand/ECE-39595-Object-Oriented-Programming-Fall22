#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

#include "DataBin.h"

class LinkedListNode : public DataBin {
public:
   LinkedListNode(LinkedListNode* _next, int datum1, int datum2); 
   virtual ~LinkedListNode( ); 
   virtual int getDatum1( );
   virtual int getDatum2( );
   virtual LinkedListNode* getNext( );
private:
   int* datum2;
   LinkedListNode* next;
};
#endif /* LINKEDLISTNODE_H_ */
