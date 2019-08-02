import java.io.Serializable;

//Interface defines Car offered by the server
public class CarImpl extends java.rmi.server.UnicastRemoteObject implements Car, Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String model;
	private String color;
	private String plate;
	private double mileage;
	
	public CarImpl()throws java.rmi.RemoteException  {
		super();
	}
	
	public CarImpl( String brand, String color, double m ) throws java.rmi.RemoteException {
		this.model = brand;
		this.color = color;
		this.mileage = m;
		this.plate = "unregistered";
	}

	public String toString() {
		return "Model: " + model + " color: " + color + 
				" mileage: " +  mileage + 
				" plate: " + plate;
	}

	public Car getRegistered(String plate)throws java.rmi.RemoteException {
		this.plate = plate;
		return this;
	}
}






	
