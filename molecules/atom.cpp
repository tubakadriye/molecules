#include "atom.h"

Atom::Atom()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
	e = "_";
}

Atom::~Atom()
{

}

Atom::Atom(string el, double x_a, double y_a, double z_a)
{
	e = el;
	x = x_a;
	y = y_a;
	z = z_a;
}

void Atom::printAtom()
{
	//cout << "element name: " << e << endl;
	//cout << "coordinates: " << "(" << x << "," << y << "," << z << ")" << endl;

	cout << "<" << e << "> <" << x << "> <" << y << "> <" << z << ">" << endl;
}

void Atom::rotX(double radVal)
{
	x = x;
	y = cos(radVal) * y + sin(radVal) * z;
	z = -sin(radVal) * y + cos(radVal) * z;
}

void Atom::rotY(double radVal)
{
	x = cos(radVal) * x - sin(radVal) * z;
	y = y;
	z = sin(radVal) * x + cos(radVal) * z;
}

void Atom::rotZ(double radVal)
{
	x = x * cos(radVal) + y * sin(radVal);
	y = y * cos(radVal) - x * sin(radVal);
	z = z;
}


