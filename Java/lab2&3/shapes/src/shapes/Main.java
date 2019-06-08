//student name: Bo Dai
//student number: 132954173
//workshop:3, June7,2019

package shapes;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;



public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("------->JAC 444 Assignment 1<-------\r\n" + "------->Task 1 ... <-------");
		String tempStore = "";
		
		try (BufferedReader br = new BufferedReader(new FileReader(args[0]))) {
			String s;
			while ((s = br.readLine()) != null) {
				String[] tokens = s.split(",");
				// only select properly formatted and right var number data, store in tempStore
				// string
				switch (tokens[0].toLowerCase()) {
				case "circle":
					if (tokens.length == 2) { // if line does not contain necessary num of values, ignore
						tempStore = tempStore + tokens[0] + "," + tokens[1] + "/";
					}
					break;
				case "parallelogram":
					if (tokens.length == 3) { // if line does not contain necessary num of values, ignore
						tempStore = tempStore + tokens[0] + "," + tokens[1] + "," + tokens[2] + "/";
					}
					break;
				case "rectangle":
					if (tokens.length == 3) { // if line does not contain necessary num of values, ignore
						tempStore = tempStore + tokens[0] + "," + tokens[1] + "," + tokens[2] + "/";
					}
					break;
				case "square":
					if (tokens.length == 2) { // if line does not contain necessary num of values, ignore
						tempStore = tempStore + tokens[0] + "," + tokens[1] + "/";
					}
					break;
				case "triangle":
					if (tokens.length == 4) { // if line does not contain necessary num of values, ignore
						tempStore = tempStore + tokens[0] + "," + tokens[1] + "," + tokens[2] + "," + tokens[3] + "/";
					}
					break;
				default:
					break;
				}
			}

		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
		// now start to pass record to create shapes, if invalid value, throw exception
		String[] records = tempStore.split("/");
		// size of new shape array will be
		int size = records.length; // bc string end with /

		Shape[] shapes = new Shape[size];
		int cnt = 0; // trace num of shapes object created

		for (int i = 0; i < size; i++) {
			String[] record = records[i].split(",");
			if (record[0].equals("Circle")) {
				try {
					shapes[cnt] = new Circle(Double.parseDouble(record[1]));
					cnt++;
				} catch (CircleException e) {
					System.out.println(e.getMessage());
				}
			}
			if (record[0].equals("Parallelogram")){
				try {
					shapes[cnt] = new Parallelogram(Double.parseDouble(record[1]), Double.parseDouble(record[2]));
					cnt++;
				} catch (ParallelogramException e) {
					System.out.println(e.getMessage());
				}
			}
			if (record[0].equals("Rectangle")) {
				try {
					shapes[cnt] = new Rectangle(Double.parseDouble(record[1]), Double.parseDouble(record[2]));
					cnt++;
				} catch (ParallelogramException e) {
					System.out.println(e.getMessage());
				}
			}
			if (record[0].equals("Square")) {
				try {
					shapes[cnt] = new Square(Double.parseDouble(record[1]));
					cnt++;
				} catch (ParallelogramException e) {
					System.out.println(e.getMessage());
				}
			}
			if (record[0].equals("Triangle")) {
				try {
					shapes[cnt] = new Triangle(Double.parseDouble(record[1]), Double.parseDouble(record[2]),
							Double.parseDouble(record[3]));
					cnt++;
				} catch (TriangleException e) {
					System.out.println(e.getMessage());
				}
			}
		}

		System.out.println("\n"+cnt + " shapes were created:");
		for (int j = 0; j < cnt; j++) {
			System.out.println(shapes[j] + "\n");
		}
		
		
		// Task 2:Delete the triangle with the minimum perimeter
		//and the circle with the maximum perimeter from the shapes.
        System.out.println("\n------->Task 2 ... <-------");


        // Find the minimum perimeter for Triangle object
        double minTrianglePerimeter = 99999;
        for (int j = 0; j < cnt; j++) {
            if (shapes[j].getClass().getName().equals("shapes.Triangle")) {
            	minTrianglePerimeter=(shapes[j].getPerimeter() < minTrianglePerimeter)? shapes[j].getPerimeter():minTrianglePerimeter;
            }
        }
        
        // Find the maximum perimeter for Circle object
        double maxCirclePerimeter = 0;
        for (int j = 0; j < cnt; j++) {
            if (shapes[j].getClass().getName().equals("shapes.Circle") ) {
            	maxCirclePerimeter=( shapes[j].getPerimeter() > maxCirclePerimeter)? shapes[j].getPerimeter():maxCirclePerimeter;
            }
        }
        
        Shape[] newShapes = new Shape[cnt];
		int m=0;
        for (int j = 0; j < cnt; j++) {
        	if(!(shapes[j].getClass().getName().equals("shapes.Triangle")&&shapes[j].getPerimeter()==minTrianglePerimeter)
        			&&!(shapes[j].getClass().getName().equals("shapes.Circle")&&shapes[j].getPerimeter()==maxCirclePerimeter)){
        		newShapes[m++]=shapes[j];    	     
        	}		
		}
       
        for (int j = 0; j < m; j++) {
			System.out.println(newShapes[j] + "\n");
		}
        
     // Task 3:Calculate and print the total perimeter of all parallelograms 
     //and the total perimeter of all triangles.
		
        System.out.println("\n\n------->Task 3 ... <-------");
        double totalPerimeterParallelogram=0;
        double totalPerimeterTriangle=0;
        for (int j = 0; j < m; j++) {
            if (newShapes[j].getClass().getName().equals("shapes.Parallelogram") ) {
            	totalPerimeterParallelogram+=newShapes[j].getPerimeter();
            }
            if (newShapes[j].getClass().getName().equals("shapes.Triangle") ) {
            	totalPerimeterTriangle+=newShapes[j].getPerimeter();
            }
        }
        
        System.out.println("Total perimeter of Parallelogram is: " + totalPerimeterParallelogram);
        System.out.println("Total perimeter of Triangle is: "+totalPerimeterTriangle);
        

	}

}
