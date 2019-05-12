/**********************************************************
// Workshop 7: STL Algorithms
// DataTable.h
///////////////////////////////////////////////////////////
// Name: Bo Dai
// Seneca Student ID:132954173
// Seneca email: bdai09@myseneca.ca
// Date of completion: Nov 6, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H
#include<algorithm>
#include<numeric>
#include<vector>
#include<fstream>


namespace w7 {
template <typename T>
class DataTable {
	std::vector<T> xrecord;
	std::vector<T> yrecord;
	int width; //field width for displaying data
	int decnum; //num of decimals to display
public:
	DataTable() {
		width = 0;
		decnum = 0;
	};
	DataTable(std::ifstream& dataFile, int FW, int ND) {
		width = FW;
		decnum = ND;
		std::string tempstring;
		int cnt=0;
		while (!dataFile.eof()) {
			getline(dataFile, tempstring);
			cnt++;
		}
		dataFile.clear();
		dataFile.seekg(0);
		T temp;
		for (int i = 0;i < cnt-1;i++) {
			dataFile >> temp;
				xrecord.push_back(temp);
				dataFile >> temp;
				yrecord.push_back(temp);
			
		}
	};
	T mean() const {
		T sum = std::accumulate(yrecord.begin(), yrecord.end(), (T)0);
		T mean = sum / yrecord.size();
		return mean;
	};
	T sigma() const {   //standard deviation
		std::vector<T> trans(yrecord.size());
		std::transform(yrecord.begin(), yrecord.end(), trans.begin(), [=](T Z) {return pow(Z - mean(), 2);});
		T sq_sum = std::accumulate(trans.begin(), trans.end(), (T)0);
		return std::sqrt(sq_sum / (yrecord.size()-1));
	};
	T median() const {
		std::vector<T> newy = yrecord;
		std::sort(newy.begin(), newy.end());
		return newy[newy.size() / 2];
	};
	void regression(T& slope, T& y_intercept) const {
		T xsum= std::accumulate(xrecord.begin(), xrecord.end(), (T)0);
		T ysum = std::accumulate(yrecord.begin(), yrecord.end(), (T)0);
		T xxsum = std::inner_product(xrecord.begin(), xrecord.end(), xrecord.begin(), (T)0);
		T xysum = std::inner_product(xrecord.begin(), xrecord.end(), yrecord.begin(), (T)0);
		slope = (getSize() * xysum - xsum * ysum) / (getSize() * xxsum - xsum * xsum);
		y_intercept = (ysum - slope * xsum) / getSize();
	}
	void display(std::ostream&os) const {
		os<< std::setw(8) << "x" << std::setw(8) << "y" << std::endl;
		for (size_t i = 0;i < yrecord.size();i++) {
			os << fixed << std::setprecision(ND);
			os << std::setw(width) << xrecord[i] << std::setw(width) << yrecord[i] << std::endl;
		}
	}
	size_t getSize() const {//return number of pairs
		return yrecord.size();
	};
	//friend std::ostream& operator<<(std::ostream& os, const DataTable& src) {
	//	src.display(os);
	//	os << std::endl;
	//	return os;
	//}
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const DataTable<T>& src) {
	src.display(os);
	os << std::endl;
	return os;
}
}
#endif