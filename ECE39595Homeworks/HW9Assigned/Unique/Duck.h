#ifndef DUCK_H_
#define DUCK_H_
#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include <memory>
using namespace std;
class Duck {
public:
   Duck( );
   virtual void setFlyBehavior(unique_ptr<FlyBehavior>);
   virtual void setQuackBehavior(unique_ptr<QuackBehavior>);
   virtual void performQuack ( );
   virtual void performFly ( );
   virtual void swim( );
   virtual void display( )=0;
protected:
   unique_ptr<QuackBehavior> quackBehavior;
   unique_ptr<FlyBehavior> flyBehavior;
};
#endif /* DUCK_H_ */
