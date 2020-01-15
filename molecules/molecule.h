#pragma once
#include "atom.h"
#include <string>
#include "cell.h"

class Molecule : public  Cell, public  Atom {
private:
	int nAtom;
	Atom* atoms;
	string comment;
	double* center;
	Cell cell;
	double volume; 
	
	double density;

public:
	double totalMass;
	Molecule(string fileName);
	~Molecule();
	//Cell assignCell(string fileName);
	void assignCell(string fileName);
	void printMol();
	void writeMol(string fileName);
	double* findCenter();
	void center2origin();
	void rotX(double radVal);
	void rotY(double radVal);
	void rotZ(double radVal);
	void printCell();
	double getVolume();
	double calcTotMass();
	void calcDensity();
	double getDensity();
};
