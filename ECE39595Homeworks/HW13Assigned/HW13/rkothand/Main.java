import sift.Sifter;
import vehicle.FordF350;
import vehicle.HondaFit;
import vehicle.Vehicle;

public class Main {

   static void printVehicle(Vehicle vehicle) {
      System.out.print(vehicle.getVehicleModel( ) + ": color: " + vehicle.getColor( ));
      System.out.print(", engine: "+ vehicle.getEngine( )); 
      System.out.print(", transmission: "+ vehicle.getTransmission( )); 
      System.out.print(", setBelts: "+ vehicle.getNumPassengers( )); 
      System.out.println(", warranty: "+ vehicle.getWarranty( ) + "\n"); 
   }

   public static void main(String[ ] args) {
      Vehicle[ ] vehicles = new Vehicle[4];
      vehicles[0] = new vehicle.HondaFit("white"); // I specified this this way just
                                                            // to show it can be done. Doing it
                                                            // like the other packages is fine.
      vehicles[1] = new FordF350("green");
      vehicles[2] = new vehicle.HondaFit("red");
      vehicles[3] = new FordF350("yellow");
      System.out.println();

      for (int i = 0; i < vehicles.length; i++) {
         printVehicle(vehicles[i]);
      }

      Sifter s = new Sifter( );
      HondaFit hondas[ ] = s.getFits(vehicles);
      for (int i = 0; i < hondas.length && hondas[i] != null; i++) {
         printVehicle(hondas[i]);
      }
   }
}
