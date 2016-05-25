/*
Write a function int* read_data(int& size) that reads data from cin until the user
ter minates input by entering Q. The function should set the size reference parameter
to the number of numeric inputs. Return a pointer to an array on the heap. That
array should have exactly size elements. Of course, you won’t know at the outset
how many elements the user will enter. Start with an array of 10 elements, and
double the size whenever the array fills up. At the end, allocate an array of the
correct size and copy all inputs into it. Be sure to delete any intermediate arrays.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

double *read_data(int &size);
double *grow(double a[], int &size);
double *addA(double a[], int &size);
void prntArr(double ar[], int size);

int main()
{
	int size = 3; // starting at 3 for more frequent doubling for testing.
	int iter = 0;
	double *a;

	cout << "Add numbers to array, q to exit: " << endl;
	a = read_data(size);

	cout << "First array input: " << endl;
	prntArr(a, size);

	a = addA(a, size);

	cout << "Finally, all values added into array: " << endl;
	prntArr(a, size);

	delete[] a;

	system("pause");
	return 0;
}

double *read_data(int &size)
{
	string input;
	double *dArr = new double[size];
	int iter = 0;

	// A bunch of magic happens
	do {
		cin >> input;
		if (input != "q") {
			dArr[iter] = stod(input);
			iter++;
			if (iter == size) {
				dArr = grow(dArr, size);
			}
		}
	} while (input != "q");
	input = "";
	size = size - (size - iter);

	return dArr;
}

double *grow(double a[], int &size)
{
	cout << "Growing array" << endl;

	double *g = new double[size * 2];

	for (int i = 0; i < size; i++) {
		g[i] = a[i];
	}

	for (int k = size; k < size * 2; k++) {
		g[k] = 0;
	}

	delete[] a;
	a = g;
	size = size * 2;
	cout << "New temp size is " << size << endl;
	return g;
}

double *addA(double a[], int &size)
{
	cout << "Input integers to add to array, q to exit: " << endl;
	string input;
	int iter = 0;
	iter = size;

	double *addArr = new double[size * 2];
	for (int i = 0; i < size; i++) {
		addArr[i] = a[i];
	}
	for (int k = size; k < size * 2; k++) {
		addArr[k] = 0;
	}
	a = addArr;
	size = size * 2;

	do {
		cin >> input;
		if (input != "q") {
			// for debug //cout << "Add input is: " << input << endl;
			addArr[iter] = stod(input);
			iter++;
			if (iter == size) {
				addArr = grow(addArr, size);
			}
		}
	} while (input != "q");

	input = "";
	size = size - (size - iter);
	return addArr;
}

void prntArr(double ar[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}