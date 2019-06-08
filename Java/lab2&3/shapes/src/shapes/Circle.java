//student name: Bo Dai
//student number: 132954173
//workshop:3, June7,2019

package shapes;

public class Circle implements Shape{
	private double r;

	 public Circle() {
		r=0.0;
	}
	 public Circle(double r) throws CircleException {
		 if(r>0) {
			this.r=r;
		 }else {
		 throw new CircleException("Invalid radius!");
		 }
	} 

	 @Override
	 public String toString() {
		 return String.format("Circle {r=%.1f} perimeter = %g", 
				 getR(),getPerimeter());
	 }
	 @Override
	 public double getPerimeter() {
		 return 2*Math.PI*getR();
	 }
	 
	 public void setR(double r) throws CircleException {
		 if(r>0) {
			 this.r=r;
		 }
		 else {
			 throw new CircleException("Invalid radius!");
		 }
	 }
	 
	public double getR() {
		return r;
	}
}
