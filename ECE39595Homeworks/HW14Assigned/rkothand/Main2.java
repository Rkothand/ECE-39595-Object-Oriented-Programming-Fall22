public class Main2 {

   public static void main(String[ ] args) {
      int maxDucks = 5;
   
      Duck ducks[ ] = new Duck[maxDucks];

      ducks[0] = new MallardDuck( );
      ducks[1] = new RedHeadDuck( );
      ducks[2] = new DecoyDuck( );
      ducks[3] = new PekinDuck( );
      ducks[4] = new ToyDuck( );
   
      for (int i=0; i<maxDucks; i++) {
         ducks[i].display( );
         ducks[i].performQuack( );
         ducks[i].performFly( );
         ducks[i].swim( );
         ducks[i].performEggLaying( );
         System.out.println(" "); 
      }
   }
}
