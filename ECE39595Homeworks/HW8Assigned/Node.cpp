#include <iostream>
#include "Int.h"
#include "Node.h"

Node::Node( ) { }

Node::Node(const Int& val) {
   data = val;
}

void Node::print( ) const {
   if (this->left != nullptr) {
      this->left->print( );
   }
   std::cout << data << " ";
   if (this->right != nullptr) {
      this->right->print( );
   }
}

Node* Node::insertNode(const Int& n) {
   if (this->data == n) return this;
   if (n < this->data) {
      if (left != nullptr) return left->insertNode(n); 
      else {
         left = new Node(n);
         return left;
      }
   }
   if (n > this->data) {
      if (right != nullptr) return right->insertNode(n); 
      else {
         right = new Node(n);
         return left;
      }
   }
   return nullptr;
}
