/*
Lab 7B

1. Please create a file contains 10 sets of a pair of two numbers.

Note: Please print the contents of the file.

2. Then, your program should get the file name entered by a user and

subsequently produces a table containing 3 columns (first number, second

Note: Please print the table that the program produced.
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace  std;

void fileAvg(ifstream &file);
void prntFile(ifstream &file);
int main() {
	int choice = 0;
	do {
		// ask user file name to handle
		ifstream file;
		string fiName;
		cout << "What is the filename? ('DIR' for file list) : ";
		cin >> fiName;
		if (fiName == "dir") {
			cout << "==== Local directory files: ====";
			system("dir");
			cout << "Filename: ";
			cin >> fiName;
		}
		file.open(fiName);
		if (file.fail()) {
			cout << "Sorry unknown or incorrect file, please try again." << endl;
		}
		else {
			cout << "Choose how to handle file " << fiName << " : " << endl << "(1) Print contents, (2) Contents + Average, (3) QUIT: ";
			cin >> choice;
			if (choice == 1)
				prntFile(file);
			else if (choice == 2)
				fileAvg(file);
			else {
				cin.clear();
				cin.ignore();
				cout << "Unknown response, please try again." << endl;
			}
		}

	} while (choice != 3);
	return 0;
}
void  prntFile(ifstream &f) {
	double a[10][2];
	for (size_t i = 0; i < 10; i++) {
		for (size_t k = 0; k < 2; k++) {
			if (!f.eof()) {
				f >> a[i][k];
				cout << a[i][k] << " ";
			}
		}
		cout << endl;
	}
}
void fileAvg(ifstream &f) {
	double a[10][2];
	for (size_t i = 0; i < 10; i++) {
		for (size_t k = 0; k < 2; k++) {
			if (!f.eof()) {
				f >> a[i][k];
				cout << a[i][k] << " ";
				if (k == 1)
					cout << "Avg. = " << (a[i][0] + a[i][1])/2;
			}
		}
		cout << endl;
	}
}