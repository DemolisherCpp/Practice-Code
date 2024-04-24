/*
Question:

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.*/

#include <iostream>
using namespace std;

void sorter(int data[][2], int m) {
	int swapper = 0;
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			if ((data[k][0] < data[i][0]) && (data[k][1] < data[i][1])) {
				swapper = data[k][0];
				data[k][0] = data[i][0];
				data[i][0] = swapper;
				swapper = data[k][1];
				data[k][1] = data[i][1];
				data[i][1] = swapper;
				}
		}
	}

}

void russiandolls(int data[][2], int m) {
	int counter = 1;
	for (int i = 0; i < m; i++) {
			if ((data[i][0] < data[i+1][0]) && (data[i][1] < data[i+1][1])) {
				counter++;
			}
	}
	cout << "The number of envelopes aranged as russian dolls are : " << counter;
}


int main() {
	// input the number of envelopes (rows of array) over here
	const int x = 4;

	//input the respective widths and heights over here as required per the input number of envelopes
	int envelope[x][2]= { { 5,4 }, { 6,4 }, { 6,7 }, { 2,3 } };
	sorter(envelope, x);
	russiandolls(envelope,x);
}
