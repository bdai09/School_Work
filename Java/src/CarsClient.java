
import java.rmi.Naming;
import java.io.IOException;

public class CarsClient {
	public static void main(String[] args)throws IOException {

		Car[] cars = new CarImpl[3];

		cars[0] = new CarImpl("Toyata Corolla", "white", 1000);
		cars[1] = new CarImpl("Honda Civic", "blue", 2000);
		cars[2] = new CarImpl("Volvo S70", "black", 3000);
		
		for (int i = 0; i < 3; i++) {	
			System.out.println("\n### Client: send this car for plate registration:\n" + cars[i]);
		
		try {	
				Car car = (Car) Naming.lookup("rmi://localhost:8000/CarsService");
				cars[i]=car.getRegistered("Plate: " + cars[i].hashCode());
				System.out.println("\n*** Registered an object from on the Server:\n " + cars[i]);
			
		} catch (Exception e) {
			System.err.println(e);
		}
		}
	}
}