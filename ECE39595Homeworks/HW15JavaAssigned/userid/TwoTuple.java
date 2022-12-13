public class TwoTuple . . . implements Comparable {

   private static final int LESS_THAN = -1;
   private static final int EQUAL = 0;
   private static final int GREATER_THAN = 1;

   public int compareTo(Object tuple) {
      . . .

      // Note use of instanceof to check that the arguemnt to this is a TwoTuple
      // and not some arbitrary object
      if (!(tuple instanceof  TwoTuple)) {
         throw new ClassCastException("object "+tuple+" does not implement Comparable");
      } 
      . . .
   }

   public String toString( ) {
      return "["+i1+","+i2+"]";
   }
}
