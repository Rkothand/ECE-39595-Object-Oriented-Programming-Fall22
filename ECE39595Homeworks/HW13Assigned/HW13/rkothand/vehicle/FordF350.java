package vehicle;

public class FordF350 extends Vehicle {

   private String color;

   public FordF350(String _color) {
      super("Ford F350");
      color = _color;
      System.out.println(" built");
   }

   public String getModel( ) { 
      return model;
   }

   public String getColor( ) { 
      return color;
   }

   public String getEngine( ) {
      return "7.3L V8";
   }

   public String getTransmission( ) {
      return "10 speed automatic";
   }

   public int getNumPassengers( ) {
      return 3;
   }

   public String getWarranty( ) {
      return "3/36,000 + 5/60,000 Powertrain";
   } 
}
