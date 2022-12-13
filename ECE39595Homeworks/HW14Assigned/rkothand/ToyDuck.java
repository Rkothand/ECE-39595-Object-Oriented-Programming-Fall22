public class ToyDuck extends Duck{
        public ToyDuck(){
            flyBehavior = new FlyPoorly();
            quackBehavior = new MuteQuack();
            laysEggsBehavior = new DoesNotLayEggs();

        }

        public void display(){
            System.out.println("I am a toy duck");
        }
}
