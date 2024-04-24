/*
Question:
Given an array arr[] of N+2 elements. All elements of the array are in the range of 1 to N. And all elements occur once except two numbers which occur twice. Find the two repeating numbers.
Example:
Input: arr = [4, 2, 4, 5, 2, 3, 1]
Output: 4 2
*/

#include <iostream>;
using namespace std;
void repeaters(int data[], int size)
{
	cout << "The repeating numbers in the given array are : " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = i; j<size; j++) {
			if ((data[i] == data[j])&&(i!=j)) {
				cout << data[i] << endl;
			}
		}
	}
}
int main() {
	//Input any numbers with proper commas into the below given array.
	int arr[] = { 4, 2, 4, 5, 2, 3, 1 };
	int sizeofarray = sizeof(arr) / sizeof(arr[0]);
	repeaters(arr, sizeofarray);
}
