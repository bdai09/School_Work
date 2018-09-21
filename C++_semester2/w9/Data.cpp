// OOP244 Workshop 9: Function Templates
// File: Data.CPP
// Name			Date
// Bo Dai        2018/07/26
//Student number : 132954173
///////////////////////////////////////////////////
#include "Data.h"
using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Population change from " << min(year, n) << " to " << max(year, n) << " is "
			<<static_cast<double>(population[n - 1] - population[0])/ 1000000 << " million" << endl;


		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		if (violentCrime[n - 1] > violentCrime[0]) {
			cout << "Violent Crime trend is up" << endl;
		}
		else {
			cout << "Violent Crime trend is down" << endl;
		}


		// Q3 print the GTA number accurate to 0 decimal places
		double ave;
		cout << "There are ";
		ave=average(grandTheftAuto, n) / 1000000;
		cout<<ave<< " million Grand Theft Auto incidents on average a year" << endl;
		cout.unsetf(ios::fixed);
		cout.precision(6);
		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;

	}
}