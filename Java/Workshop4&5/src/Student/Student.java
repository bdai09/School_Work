package Student;

import java.io.Serializable;
import java.util.ArrayList;

public class Student implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int stdID;
	private String firstName;
	private String lastName;
	private ArrayList<String> courses;
	
	/* constructor */
	Student(){
		this.stdID=0;
		this.firstName=null;
		this.lastName=null;
		this.courses=null;
	}
	
	Student(int stdID, String firstName, String lastName, ArrayList<String> courses){
		super();
		this.stdID=stdID;
		this.firstName=firstName;
		this.lastName=lastName;
		this.courses=courses;
	}
	
	/* getters and setters */
	public void setStdID(int stdID) {
		if(stdID>0) {
			this.stdID=stdID;
		}
	}
	
	public int getStdID() {
		return stdID;
	}
	
	public void setFirstName(String firstName) {
		this.firstName=firstName;
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public void setLastName(String lastName) {
		this.lastName=lastName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public void setCourses(ArrayList<String> courses) {
		this.courses=courses;
	}
	
	public ArrayList<String> getCourses(){
		return courses;
	}
	
	/* toString */
	@Override
	public String toString() {
		return "Student ID: "+getStdID()+"\n"
				+"Student First Name: "+ getFirstName()+"\n"
				+"Student Last Name: "+ getLastName()+"\n"
				+"Courses: "+getCourses()+"\n\n";
				
	}
	
}
