#include "Duck.h"
#include "RedHeadDuck.h"
#include "MallardDuck.h"
#include "DecoyDuck.h"
#include "FlyNoWay.h"
#include <memory>
using namespace std;
int main(int argc, char *argv[]) {
   shared_ptr<Duck> red(new RedHeadDuck( ));
   shared_ptr<Duck> mallard(new MallardDuck( ));
   shared_ptr<Duck> decoy(new DecoyDuck( ));

   red->performQuack( );
   red->performFly( );
   red->swim( );
   red->setFlyBehavior(shared_ptr<FlyNoWay>(new FlyNoWay( )));
   red->performFly( );
   decoy->performFly( );
}
