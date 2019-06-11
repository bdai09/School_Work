package Student;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

public class StudentWrite {
	
	public static void inputStudent() {
		int stdID=0;
		String lastName=null;
		String firstName=null;
		ArrayList<String> courses = new ArrayList<>();
		
		//ask user to enter student information 
		try {
			//ask user for student ID
			Scanner scanner=new Scanner(System.in);
			System.out.print("Please enter a student ID: ");
			String input=scanner.nextLine();
			stdID=Integer.parseInt(input);
			
			//ask user for student name
			System.out.print("Please enter student first name: ");
			firstName=scanner.nextLine();
			System.out.print("Please enter student last name: ");
			lastName=scanner.nextLine();
			
			//ask user for student courses
			System.out.print("Please enter student courses, seperate by ',': ");
			String[] courseList=scanner.nextLine().split(",");
			for(int i=0;i<courseList.length;i++) {
				courses.add(courseList[i]);
			}
			
			Student student=new Student(stdID, firstName, lastName, courses);
			FileOutputStream f=new FileOutputStream(new File("Student.file"));
			ObjectOutputStream o=new ObjectOutputStream(f);
			
			o.writeObject(student);
			o.close();
			f.close();
			
		}catch(IOException e) {
			e.printStackTrace();
		}catch(NumberFormatException n) {
			System.out.println("Input error");
		}
		
	}

}
