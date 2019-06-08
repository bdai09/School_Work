//student name: Bo Dai
//student number: 132954173
//workshop:3, June7,2019

package shapes;

public class Square extends Rectangle {

	 public Square() {
		super();
	}
	 public Square(double a)throws ParallelogramException {
			super(a,a);

	} 
	 @Override
	 public void setA(double a)throws ParallelogramException {
		 if(a>0) {
		   setA(a);
		   setB(a);
		 }
		 else {
			 throw new ParallelogramException("Invalid side!");
		 }
	 }
	 @Override
	 public void setB(double b)throws ParallelogramException {
		 if(b>0) {
			 setA(b);
		     setB(b);
		 }
		 else
			 throw new ParallelogramException("Invalid side!");		 
	 } 
	 
	 @Override
	 public double getPerimeter() {
		 return getA()*4;
	 }
	 @Override
	 public String toString() {
		 return String.format("Square {s=%s} perimeter = %g",
				 getA(),getPerimeter());
	 }
}
