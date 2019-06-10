#include <iostream>
#include <ctime>

using namespace std;

unsigned int factorial (unsigned int n);
double power (double base, unsigned int n);
unsigned int fibonacci (unsigned int n);
void fibonacciTime(unsigned int n);


double power1(double base, unsigned int n);
double power2(double base, unsigned int n);
double power3(double base, unsigned int n);
double power4(double base, unsigned int n);
void powerTime();




int main(){
	
	cout << "factorial(5): " << factorial(5) << endl;
 	cout << "power(2,4): " << power(2,4) << endl; 
        cout << "fibonacci(9): " << fibonacci(9) << endl; 

	//For Section B, Question b
	//Q3.Modify the file w3_lab.cpp to get a timing of running the fibonacci function 
	//with the following values for n: 35,36,37,38,39,40,41.
		/*
		fibonacciTime(35);
		fibonacciTime(36);
		fibonacciTime(37);
		fibonacciTime(38);
		fibonacciTime(39);
		fibonacciTime(40);
		fibonacciTime(41);
		*/

		powerTime();
		//cout << "power3(2,1): " << power(2, 0) << endl;

   
	return 0;

}

//define recursive function factorial here...
unsigned int factorial(unsigned int n) {
	unsigned int temp = 1;
	if (n > 1) {
		temp = n * factorial(n - 1);
	}
	return temp; 
}


//define recursive function power here...
double power(double base, unsigned int n) {
	double temp = 1.0;
	if (n > 0) {
		temp = base * power(base, n - 1);
	}
	return temp; 
}


double power1(double base, unsigned int n) {
	double temp = 1.0;
	for (unsigned int i = 1;i <= n;i++) {
		temp = temp * base;
	}
	return temp;
}

double power2(double base, unsigned int n) {
	double temp = 1.0;
	if (n > 0) {
		temp = base * power(base, n - 1);
	}
	return temp;
}
//odd even
double power3(double base, unsigned int n) {
	double temp = 1.0;
	if (n > 0) {
		if (n % 2 == 0) {
			double half=power(base, n / 2);
			temp = half * half;
		}
		else {
			temp = base * power(base, n - 1);
		}
	}
	return temp;
}



//define recursive function fibonacci here...
unsigned int fibonacci(unsigned int n) {
	unsigned int f0 = 0;
	unsigned int f1 = 1;
	unsigned int fnext = 0;
	if (n == 0) return 0;
	if (n == 1) return 1; //for f0 and f1
	if (n > 1) {
		fnext = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return fnext;
}

//For Section B, Question b
//Q3.Modify the file w3_lab.cpp to get a timing of running the fibonacci function 
//with the following values for n: 35,36,37,38,39,40,41.

void fibonacciTime(unsigned int n) {

	clock_t startTime = clock();
	fibonacci(n);
	clock_t endTime = clock();
	cout << "Time of running for Fibonacci("<< n <<"): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}


//test recurssive
void powerTime() {

	clock_t startTime1 = clock();
	power1(11111, 40);
	clock_t endTime1 = clock();

	clock_t startTime2 = clock();
	power2(11111,40);
	clock_t endTime2 = clock();

	clock_t startTime3 = clock();
	power3(11111,40);
	clock_t endTime3 = clock();

	/*clock_t startTime4 = clock();
	power4(2,1000);
	clock_t endTime4 = clock();

	clock_t startTime5 = clock();
	power5(2, 1000);
	clock_t endTime5 = clock();*/

	cout << "Time of running for iteration"  << double(endTime1 - startTime1) * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 *10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 / CLOCKS_PER_SEC << " s" << endl;
	cout << "Time of running for recursive: " << double(endTime2 - startTime2) * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 / CLOCKS_PER_SEC << " s" << endl;
	cout << "Time of running for oddeven: " << double(endTime3 - startTime3) * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 * 10000000000000 / CLOCKS_PER_SEC << " s" << endl;
	//cout << "Time of running for store: " << double(endTime4 - startTime4) / CLOCKS_PER_SEC << " s" << endl;
	//cout << "Time of running for store+oddeven: " << double(endTime5 - startTime5) / CLOCKS_PER_SEC << " s" << endl;

}