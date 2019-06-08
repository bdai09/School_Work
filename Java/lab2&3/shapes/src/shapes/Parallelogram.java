//student name: Bo Dai
//student number: 132954173
//workshop:3, June7,2019

package shapes;

public class Parallelogram implements Shape{
	private double sideA;
	private double sideB;
	
	 public Parallelogram() {
		sideA=0.0;
		sideB=0.0;
	}
	 
	 public Parallelogram(double a, double b) throws ParallelogramException {
		 if(a>0&&b>0) {
			this.sideA=a;
			this.sideB=b;
		 }else {
			 throw new ParallelogramException("Invalid side(s)!");
		 }
	} 
	 @Override
	 public String toString() {
		 return String.format("Parallelogram {w=%.1f, h=%.1f} perimeter = %g"
	 ,getA(),getB(),getPerimeter());
	 }
	 @Override
	 public double getPerimeter() {
		 return (getA()+getB())*2;
	 }
	 
	 public void setA(double a)throws ParallelogramException {
		 if(a>0) {
		   this.sideA=a;
		 }
		 else {
			 throw new ParallelogramException("Invalid side!");
		 }
	 }
	 
	 public void setB(double b)throws ParallelogramException {
		 if(b>0) 
		  this.sideB=b;
		 else
			 throw new ParallelogramException("Invalid side!");		 
	 }
	 
	public double getA() {
		return sideA;
	}
	
	public double getB() {
		return sideB;
	}
	
}
