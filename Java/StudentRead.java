package Student;

import java.io.*;
import java.util.ArrayList;

public class StudentRead {
	//read data from file to get students
	public static void readStudent() {
		try {
			ArrayList<Student> students = new ArrayList<Student>();
			FileInputStream fin=new FileInputStream(new File("Student.file"));
			ObjectInputStream oin=new ObjectInputStream(fin);
			
			//readin students
			
			//for(int i=0;i<oin.readInt();i++) {
				Student temp=(Student)oin.readObject();
				//students.add(temp);
				System.out.println(temp.toString());
			//}
			oin.close();
			fin.close();
			//System.out.println(students);
		}
		catch(ClassNotFoundException e) {
			e.printStackTrace();
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}
	}

}
