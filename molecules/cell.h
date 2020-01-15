#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Cell {
private:
	/*double *a1;
	double* a2;
	double* a3;*/
	
protected:
	double volume; // molecule class will inherit
	
public:
	/*double a1[3];
	double a2[3];
	double a3[3];*/

	double* a1;
	double* a2;
	double* a3;
	
	Cell();
	Cell(string fileName);
	~Cell();
	void virtual printCell();
	void calculateVolume();
	double virtual getVolume();

};