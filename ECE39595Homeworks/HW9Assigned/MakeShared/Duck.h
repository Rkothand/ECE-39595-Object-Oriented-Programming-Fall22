#ifndef DUCK_H_
#define DUCK_H_
#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include <memory>
using namespace std;
class Duck {
public:
   Duck( );
   virtual void setFlyBehavior(shared_ptr <FlyBehavior>);
   virtual void setQuackBehavior(shared_ptr <QuackBehavior>);
   virtual void performQuack ( );
   virtual void performFly ( );
   virtual void swim( );
   virtual void display( )=0;
protected:
   shared_ptr<QuackBehavior> quackBehavior;
   shared_ptr<FlyBehavior> flyBehavior;
};
#endif /* DUCK_H_ */
