
import java.rmi.Naming;

public class CarsServer {
	public CarsServer() {
		try {	
			Car car=new CarImpl();
			Naming.rebind("rmi://localhost:8000/CarsService", car);
				
			System.out.println("\n### Server: register this car for plate registration:\n" + car);
        } catch (Exception e) {
			System.err.println("Problem: " + e);
			System.exit(1);
		}
	}
	
	
	public static void main(String[] args) {
		
		System.out.println("*** this server is going to register the cars ***");
		new CarsServer();	
		System.out.println("CarsService is running...");

	}
}

