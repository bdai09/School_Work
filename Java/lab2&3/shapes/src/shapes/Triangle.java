//student name: Bo Dai
//student number: 132954173
//workshop:3, June7,2019

package shapes;

public class Triangle implements Shape {
	private double sideA;
	private double sideB;
	private double sideC;
	
	 public Triangle() {
		sideA=0.0;
		sideB=0.0;
		sideC=0.0;
	}
	 
	 public Triangle(double a, double b, double c) throws TriangleException{
		 if(a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a) {
				this.sideA=a;
				this.sideB=b;
				this.sideC=c;
		 }else {
			 throw new TriangleException("Invalid side(s)!");
		 }
	} 
	 @Override 
	 public String toString() {
		 return String.format("Triangle {s1=%.1f, s2=%.1f, s3=%.1f} perimeter = %g"
	  , getA(),getB(),getC(),getPerimeter());
	 }
	 
	 @Override
	 public double getPerimeter() {
		 return getA()+getB()+getC();
	 }
	 
	 public void setA(double a)throws TriangleException {
		 if(a>0&&a+sideB>sideC&&a+sideC>sideB&&sideB+sideC>a)
		 this.sideA=a;
		 else
			 throw new TriangleException("Invalid side!");
	 }
	 
	 public void setB(double b)throws TriangleException {
		 if(b>0&&sideA+b>sideC&&sideA+sideC>b&&b+sideC>sideA)
		  this.sideB=b;
		 else
			 throw new TriangleException("Invalid side!");
	 }
	 
	 public void setC(double c) throws TriangleException{
		 if(c>0&&sideA+sideB>c&&sideA+c>sideB&&sideB+c>sideA)
		  this.sideC=c;
		 else
			 throw new TriangleException("Invalid side!");
	 }
	 
	public double getA() {
		return sideA;
	}
	
	public double getB() {
		return sideB;
	}
	
	public double getC() {
		return sideC;
	}
}
