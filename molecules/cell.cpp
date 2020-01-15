#include "cell.h"
#include <iostream>
#include<fstream>
using namespace std;

Cell::Cell()
{
	a1 = new double [3];
	a2 = new double[3];
	a3 = new double[3];

	for (int i = 0; i < 3; i++)
	{
		a1[i] = 0.0;
		a2[i] = 0.0;
		a3[i] = 0.0;
	}
	volume = 0.0;
}

Cell::Cell(string fileName)
{

	double line1a,line1b,line1c;

	double line2a,line2b,line2c;

	double line3a,line3b,line3c;
	
	ifstream infile(fileName);

	a1 = new double[3];
	a2 = new double[3];
	a3 = new double[3];

	infile >> line1a >> line1b >> line1c;

	a1[0] = line1a;
	a1[1] = line1b;
	a1[2] = line1c;

	//a1 = { line1a,line1b,line1c };
	//////cout << line1a << " " << line1b << " " << line1c << endl;
	/*cout << line1a << " " << line1b << " " << line1c << endl;
	double c[] = { line1a, line1b,line1c };
	for (int i = 0; i < 3; i++) cout << c[i] << endl;*/


	infile >> line2a >> line2b >> line2c;

	a2[0] = line2a;
	a2[1] = line2b;
	a2[2] = line2c;

	infile >> line3a >> line3b >> line3c;

	a3[0] = line3a;
	a3[1] = line3b;
	a3[2] = line3c;


}

Cell::~Cell()
{
	cout << "deconstructor" << endl;
		delete []a1;
		delete []a2;
		delete[]a3;
		
}

void Cell::printCell()
{
	cout << "a1: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << a1[i] << " ";
	}
	cout<<endl;

	cout << "a2: " << endl;

	for (int i = 0; i < 3; i++) {
		cout << a2[i] << " ";
	}
	cout<<endl;
	cout << "a3: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << a3[i] << " ";
	}
	cout << endl;
}

void Cell::calculateVolume()
{
	double cross[3];
	//cross = (a2[2] * a3[3] - a2[3] * a3[2]) + (a2[1] * a3[3] - a2[3] * a3[1]) + (a2[1] * a3[1] - a2[2] * a3[1]);
	cross[0] = a2[1] * a3[2] - a2[2] * a3[1];
	cross[1] = -a2[0] * a3[2] + a2[2] * a3[0];
	cross[2] = a2[0] * a3[1] - a2[1] * a3[0];

	volume= a1[0] * cross[0] + a1[1] * cross[1] + a1[2] * cross[2] ;
	//return (a1[0] * cross[0] + a1[1] * cross[1] + a1[2] * cross[2]) ;
}

double Cell::getVolume()
{
	return volume;
}
