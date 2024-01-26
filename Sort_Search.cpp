// Sort_Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Colin Harding
Sort_Search.cpp
9 / 4 / 21 (last changed)
This module provides a way to:
	sort an array of ints :: selection_sort()
	binary search to find elements of sorted array :: binary_search()
this also contains a main function, but the only purpose of it is to test, not to run.
commenting or removing the main function will not hinder the use of this module.
*/

#include <iostream>
using namespace std;

void swap(int* min, int* low){
	int temp = *min;
	*min = *low;
	*low = temp;
}

void selection_sort(int *low, int *high) {
	//S1: iterates over array increasing low location as sorted and swapping low with min
	for (low; low < high; low++) {
		int *minAdd = low;
		int* next = low;
		//S2: finds min value
		for(next++;next<=high;next++){
			if (*next < *minAdd) {
				minAdd = next;
			}
		}//end S2

		swap(minAdd, low);//swap min with curr essentially
	
	}//end S1

}//end selection_sort




int* binary_search(int* low, int* high, int val) {
	//test to make sure we are in the array
	if (low <= high)  {
		int* mid = low + (high - low) / 2; // find the binary pivot point
		int* pivot = getPtr(low, mid);
		if (*pivot == val)return pivot; // if found return
		if (*pivot > val)return binary_search(low, (pivot--), val);//go left
		if (*pivot < val)return binary_search(getPtr(pivot++), high, val);//go right
	}//end if
	return NULL;//not found

}//end binary_search


 
 
 
 /*sorted array
0: 5
1: 6
2: 8
3: 9
4: 10
5: 12
6: 15
7: 25
8: 28
9: 36
8,9,10,5,6,12,28,15,36,25 */



int main()//i used sugar here because i am assuming you will not be using my main; 
	//or care how it is used
{
	cout << "fake main(modules main)\n";
	int arr[] = { 8,9,10,5,6,12,28,15,36,25 };//5,6,8,9,10,12,15,25,28,36
	selection_sort(&arr[0], &arr[9]);

	for (int i = 0; i <= 9; i++) {
		cout << i << ": " << arr[i] << endl;
	}

	int* x = binary_search(&arr[0], &arr[9], 8);
	if (x == NULL) {
		cout << "Not in array";
	}
	else {
		if(*x == arr[2])cout << "true" << endl;
		
		if(x==&arr[2])cout << "true" << endl;

	}
	
	
}//end main

/*
* 99 little bugs in the code
* 99 little bugs
* take one down, pach it around
* 110 bugs in the code
*/