//Student number : 132954173
//Seneca email : BDAI9@myseneca.ca
//Name : Bo Dai
//Lab 1 : May10, 2019

#include <iostream>

using namespace std;

unsigned int factorial (unsigned int n);
double power (double base, unsigned int n);
unsigned int fibonacci (unsigned int n);

int main(){
	
	cout << "factorial(5): " << factorial(5) << endl;
 	cout << "power(2,4): " << power(2,4) << endl; 
        cout << "fibonacci(9): " << fibonacci(9) << endl; 
	return 0;
}

//define function factorial here...
unsigned int factorial(unsigned int n) {
	unsigned int temp = 1;
	for (unsigned int i = n;i >0;i--) {
		temp = i * temp;
	}
	return temp;
}

//define function power here...

double power(double base, unsigned int n) {
	double temp = 1.0;
	for (unsigned int i = 1;i <=n;i++) {
		temp = temp*base;
	}
	return temp;
}


//define function fibonacci here...
unsigned int fibonacci(unsigned int n) {
	unsigned int f0 = 0;
	unsigned int f1 = 1;
	unsigned int fnext = 0;
	if (n == 0) return 0;
	if (n == 1) return 1; //for f0 and f1
	for (unsigned int i = 0;i < n-1;i++) {	//for n>1		
		 fnext= f0+f1;
		 f0 = f1;
		 f1 = fnext;
	}
	return fnext;
}

