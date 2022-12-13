public class PekinDuck extends Duck{
    public PekinDuck(){
        quackBehavior = new MuteQuack();
        flyBehavior = new FlyPoorly();
        laysEggsBehavior =new LaysEggsNotBroody();

    }

    public void display(){
        System.out.println("I am a Pekin Duck");
    }
}
