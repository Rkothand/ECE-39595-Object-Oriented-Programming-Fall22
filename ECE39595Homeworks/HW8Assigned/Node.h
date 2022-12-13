#ifndef NODE_H_
#define NODE_H_
#include <iostream>

class Node { 
private:
   Int data;
   Node* left = nullptr;
   Node* right = nullptr;
public:
   Node( );
   Node(const Int& val);
   void print( ) const;
   Node* insertNode(const Int& n);
};

template<class T>Node<T>::Node( ) { } //How do I read this?

template<class T>Node<T>::Node(T val) {
   data = val;
}


#endif /* NODE_H_ */
