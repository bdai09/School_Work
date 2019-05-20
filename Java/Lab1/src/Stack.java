public class Stack {
   private int index; //record index moving state
   private int size;
   private char[] stack;
   
   //constructor
   public Stack(int length) {
	   size=length;
	   index=0;
	   stack=new char[size];//create string obj with fixed size
	   
   }
   //push method, operate char by char
   public void push(char c) {
	   if(index==(size-1)) { //if move to last index, no need to increase index
		   stack[index]=c;
	   }else {
		   stack[index++]=c;
	   }   
   }
   
   //pop method, char by char
   public char pop() {
	   return stack[index--];
   }
   


//think about whitespace & isFull& isEmpty
   //palindrome include space?comma?capital??
}
