#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
using namespace std;


//n^2:: Selection Sort: loop entire arr, 2 layer loop
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n;i++) {
		int minIndex = i;  
		for (int j = i + 1;j < n;j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j; //pick up minimum value from i+1 to the end
			}
		}
		swap(arr[i], arr[minIndex]); //switch i with the min value from i+1 to end
	}
}

//n^2:: Insertion Sort: if nearly ordered array, will have high efficiency even higher than nlogn
template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 0;i < n;i++) {
		//look right position for arr[i] to be inserted
		T ele = arr[i];
		int j;
		for (j = i;j > 0 && arr[j - 1] > ele;j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = ele;
	}
}

//arr[l...mid] and arr[mid+1...r]
template<typename T>
void __merge(T arr[], int l, int mid,int r) {
	T aux[r - l + 1]; //temperate space
	for (int i = l;i <= r;i++) //copy arry to aux
		aux[i - l] = arr[i]; 
	int i = l, j = mid + 1; //2 index points to child array start place
	for (int k = l;k <= r;k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[j - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k]=aux[i-l]'
				i'
		}
	}

	
}

//[l....r] range
template<typename T>
void __mergeSort(T arr[], int l, int r) {
	if (l >= r) //means 1 or no data
		return;
	int mid = (l + r) / 2; 
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1,r);
	__merge(arr, l, mid,r);
}

//nlogn:: Merge Sort: divide into 2 and order,--loop to bottom, then merge from bottom to top
template<typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n - 1);//private fuc called by mergeSort
	
}





int main() {
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);

	delete[] arr;
	delete[] arr2;
	return 0;
}