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

using namespace std;

int *read_data(int &size);

int *grow(int a[], int &size);

void prntArr(int ar[], int size);

int main()
{
	int size = 3;
	int iter = 0;
	int *a;

	a = read_data(size);

	prntArr(a, size);
	system("pause");
	return 0;
}

int *read_data(int &size)
{
	int input;
	int *dArr = new int[size];
	int iter = 0;

	// A bunch of magic happens
	do {
		cin >> input;
		if (cin.good()) {
			dArr[iter] = input;
			iter++;
			if (iter == size) {
				int *temp = NULL;
				temp = grow(dArr, size);
				//delete[] dArr; // not really sure why these deletes are causign issues.
				dArr = temp;
				//delete[] temp;
			}
		}
	} while (cin.good());
	size = size - (size - iter);
	return dArr;
}

int *grow(int a[], int &size)
{
	cout << "Growing array" << endl;
	int *g = new int[size * 2];
	for (int i = 0; i < size; i++){
		g[i] = a[i];
	}
	for (int k = size; k < size * 2; k++){
		g[k] = 0;
	}
	//delete[] a;
	a = g;
	size = size * 2;
	cout << "New temp size is " << size << endl;
	return g;
}

void prntArr(int ar[], int size)
{
	for (int i = 0; i < size; i++){
		cout << ar[i] << " ";
	}
	cout << endl;
}
//do {
//	cin >> input;
//	if (cin.good()) {
//		*dArr = input;
//		dArr++;
//		/*
//		cout << "dArr = " << dArr << endl
//			<< "*dArr = " << *dArr << endl
//			<< "dArr[iter] = " << dArr[iter] << endl
//			<< "dArr[size] = " << dArr[size] << endl;
//		*/
//		if (dArr == dArr + size) {
//			cout << "Growing array" << endl;
//			int *grow = new int[2 * size];
//			for (int i = 0; i < size; i++) {
//				grow[i] = dArr[i];
//			}
//			delete[] dArr;
//			dArr = grow;
//			size = size * 2;
//			cout << "New temp size is " << size << endl;
//		}
//	}
//} while (cin.good());
//int *temp = new int[iter + 1];
//for (int i = 0; i < iter + 1; i++) {
//	temp[i] = dArr[i];
//}
//delete[] dArr;
//dArr = temp;
//size = iter;