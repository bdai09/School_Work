
public class Palindrome {

	public boolean ispalindrom(String str) {
		int length=str.length();
		Stack stack=new Stack(length);
		//put string into stack char by char
		for(int i=0;i<length;i++) {
			stack.push(new Character(str.charAt(i)));
			System.out.print(str.charAt(i));
		}
		System.out.println();
		//pop char by char to check if palindrome
		for(int j=0;j<length;j++) {
		System.out.print(str.charAt(j));
		if(stack.pop()!=str.charAt(j)) return false;
	    }
		return true;
	}
	public static void main(String[] args) {
		Palindrome test=new Palindrome();
		System.out.printf(test.ispalindrom(args[0])?"\nThe string is Palindrome":"\nString is not Palindrome");			
	}

}
