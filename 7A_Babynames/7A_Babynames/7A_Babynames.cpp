// 7A_Babynames.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

void process_name(ifstream &in_file, double& total, ofstream &out);

int main()
{
	ifstream in_file;
	ofstream fout;

	//in_file.open("babynames.txt");
	//if (in_file.fail()) {
	//	cout << "Error opening babynames file." << endl;
	//	cin.get();
	//	return 0;
	//} // Check for failure after opening

	//double boy_total = 50;
	//double girl_total = 50;

	//fout.open("output.txt");
	//if (fout.fail()) {
	//	cout << "Error opening output file" << endl;
	//}

	//while (boy_total > 0 || girl_total > 0) {
	//	int rank;
	//	in_file >> rank;
	//	if (in_file.fail()) {
	//		cout << "Error processing babynames.txt" << endl;
	//		cin.get();
	//		return 0;
	//	}
	//	
	//	fout << rank << " ";
	//	cout << rank << " ";

	//	process_name(in_file, boy_total, fout);
	//	process_name(in_file, girl_total, fout);
	//	fout << endl;
	//	cout << endl;
	//}
	//in_file.close();
	//fout.close();

	in_file.open("output.txt");
	if (in_file.fail()) {
		cout << "Error opening babynames file." << endl;
		cin.get();
		return 0;
	}
	else {
		int r;
		string fname, sname;
		while (!in_file.eof())
		{
		/*	in_file >> r >> fname;
			if (in_file.peek() != '\n')
				in_file >> sname;
			cout << r << fname;
			if (!sname.empty())
				cout << sname;
		*/
			getline(in_file, fname);
			cout << fname << endl;
		}
	}
	in_file.close();
	cin.get();
	return 0;
}

void process_name(ifstream& in_file, double& total, ofstream &out)
{
	string name;
	int count;
	double percent;
	in_file >> name >> count >> percent;
	if (in_file.fail()) {
		cout << "Error processing name." << endl;
		cin.get();
		return;
	} // Check for failure after each input
	if (out.fail()) {
		cout << "Error process_name writing to file";
	}
	if (total > 0) {
		cout << name << " ";
		out << name << " ";
	}
	total = total - percent;
}