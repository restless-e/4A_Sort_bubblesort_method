// TestCh7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

double replace_if_greater(double* p, double x);

int _tmain(int argc, _TCHAR* argv[])
{
	double xval;
	double yval;
	double *ptr = &yval;

	cout << "Give X a value: ";
	cin >> xval;
	cout << endl;

	cout << "Give Y a value: ";
	cin >> yval;
	cout << endl;


	cout << "Old *p value is: " << replace_if_greater(ptr, xval);
	cout << endl;

	system("pause");
	return 0;
}

double replace_if_greater(double* p, double x)
{
	double temp;
	temp = *p;
	if (*p < x) {
		cout << "X is greater than *p, replacing." << endl;
		*p = x;
	}
	else {
		cout << "*p (Y) value is greater than X, no replacing." << endl;
	}
	return temp;
}