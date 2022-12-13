public class Main1 {

   public static void main(String[ ] args) {
   
      int maxDucks = 4;
   
      Duck ducks[ ] = new Duck[maxDucks];

      ducks[0] = new MallardDuck( );
      ducks[1] = new RedHeadDuck( );
      ducks[2] = new DecoyDuck( );
      ducks[3] = new PekinDuck( );
   }
}
