#ifndef DUCK_H_
#define DUCK_H_
#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include "LaysEggs.h"

class Duck {
public:
   Duck( );
   virtual void setFlyBehavior(FlyBehavior*);
   virtual void setQuackBehavior(QuackBehavior*);
   virtual void performQuack ( );
   virtual void performFly ( );
   virtual void performEggLaying ( );
   virtual void swim( );
   virtual void display( )=0;
protected:
   QuackBehavior* quackBehavior;
   FlyBehavior* flyBehavior;
   LaysEggs* laysEggs;
};
#endif /* DUCK_H_ */
