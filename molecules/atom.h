#pragma once
#include <iostream>
#include <string>
using namespace std;


class Atom {
protected:
	//string e;
	//double x;
	//double y;
	//double z;
public:
	string e;
	double x;
	double y;
	double z;
	Atom();
	~Atom();
	Atom(string el, double x_a, double y_a, double z_a);
	void printAtom();
	void virtual rotX(double radVal);
	void virtual rotY(double radVal);
	void  virtual rotZ(double radVal);
};
