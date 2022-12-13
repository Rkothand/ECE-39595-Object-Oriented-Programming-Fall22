public class Main {

   public static final int[ ]  values = {5, 1, 7, 15};

   public static void main(String[ ] args) {

      Node<Integer> rootInt = new Node<Integer>(10);
      for (int i = 0; i < values.length; i++) {
         rootInt.insertNode(Integer.valueOf(values[i])); 
      }

      System.out.println(rootInt); 
      Node<Double> rootDouble = new Node<Double>(Double.valueOf((double) 10));
      for (int i = 0; i < values.length; i++) {
         rootDouble.insertNode(Double.valueOf((double) values[i])); 
      }
      System.out.println(rootDouble); 

      Node<TwoTuple<Integer,Integer>> rootTwoTuple = new Node<>(new TwoTuple<Integer, Integer>(values[0],values[1]));
      System.out.println(rootTwoTuple);
      for (int i = 0; i < values.length; i++) {
         rootTwoTuple.insertNode(new TwoTuple<Integer,Integer>(values[i], values[i%values.length])); 
      }
      System.out.println(rootTwoTuple); 

      // These two lines should generate a compile time error when uncommented out. 
      // Leave them in the program -- they will be used for testing.
      // Node<HW12> hw12Node = new Node<>(new HW12( ));  // S1
      // TwoTuple<HW12> hw12TwoTuple = new TwoTuple<>(new HW12( ), new HW12( )); // S2
   }
}
