#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include<cassert>
using namespace std;

namespace SortTestHelper {

	//generate random array
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0;i < n;i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	//print array
	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0;i < n;i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	//check if sort right
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0;i < n - 1;i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
		return true;
	}

	//test running time
	template<typename T>
	void testSort(const char* sortName, void(*sort)(T[], int), T arr[],int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(isSorted(arr,n)); //check if work well
		cout <<sortName << " " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		return;
	}

	int* copyIntArray(int a[],int n) {
		int*arr = new int[n];
		copy(a, a + n, arr);  //first place, last place, first in destination
		return arr;
	}

}


#endif
