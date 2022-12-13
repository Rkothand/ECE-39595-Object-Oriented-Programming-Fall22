#ifndef DERIVED_H_
#define DERIVED_H_
#include "Base.h"

class Derived : public Base {
public:
   void f2( );
   void f3( );
   virtual void f6( );
private:
   void f1( );
   void f5( );
};
#endif /* DERIVED_H_ */
