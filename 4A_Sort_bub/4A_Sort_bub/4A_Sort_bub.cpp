
#include "stdafx.h"
#include <iostream>

using namespace std;

//prototyping
void sort(double, double, double); // bubble sort method.
void swap(double[], int, int);
void printOut(double[]);

int main()
{
	// declare 3 variabels
	double val1, val2, val3;
	// instruct user for input
	cout << "Please input 3 numbers to sort: ";
	cin >> val1 >> val2 >> val3;
	//call sorting function
	cout << "Input order of variables is: { " << val1 << ", " << val2 << ", " << val3 << " }" << endl;
	sort(val1, val2, val3);

	system("pause");
    return 0;
}

//below are function definitions

void sort(double a, double b, double c)
{
	double toSort[3] = { a, b, c };

	// loop to hold outer position for check
	for (int i = 0; i < 3; i++)
	{
		// inner loop to compare with outer position value
		for (int j = 0; j < 3; j++)
		{
			// compares if inner value is greater than outer value
			if (toSort[j] > toSort[i])
			{
				// call swap function if true
				swap(toSort, j, i);
			}
		}
	}
	// Print final sorted order
	printOut(toSort);
}
void swap(double arr[], int jcount, int icount)
{
	// take input locations in array and swap
	// hold one in temp variable due to being copied over by swap
	double temp;
	temp = arr[jcount];
	arr[jcount] = arr[icount];
	arr[icount] = temp;
}
void printOut(double arr[])
{
	// itterate through array to simply print out new order.
	cout << "The input has been sorted as follows: ";
	for (int p = 0; p < 3; p++)
	{
		cout << arr[p] << " ";
	}
	cout << endl;
}