//student name: Bo Dai
//student number: 132954173
//workshop:3, June7,2019

package shapes;

public class Rectangle extends Parallelogram{
	 public Rectangle() {
		super();
	}
	 public Rectangle(double a, double b)throws ParallelogramException  {
		 super(a,b);
	} 
	 @Override
	 public String toString() {
		 return String.format("Rectangle {w=%.1f, h=%.1f} perimeter = %g", 
				 getA(),getB(),getPerimeter());
	 }

}
