/*
Question:  Given an array arr[] of n integers, output a Product Array (of the same size) such that it is equal to the product of all the elements of arr[] except arr[i].
Example:
Input: arr[]  = {10, 3, 5, 6, 2}
Output: {180, 600, 360, 300, 900}
*/

#include <iostream>
using namespace std;
void multiplier(int data[], int size)
{
	cout << "[";
	for (int i = 0; i < size; i++) {
		int product = 1;
		for (int j = 0; j < size; j++) {
			if (data[i] != data[j]) {
				product = product * data[j];
			}
		}
		cout << product;
		if (i < size - 1) {
			cout << ",";
		}
	}
	cout << "]";
}
int main()
{
	//Input any numbers with proper commas into the below given array.
	int arr[] = {10, 3, 5, 6, 2};
	int arraysize = sizeof(arr) / sizeof(arr[0]);
	multiplier(arr, arraysize);
}