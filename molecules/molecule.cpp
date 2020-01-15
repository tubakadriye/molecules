#include "molecule.h"
#include "atom.h"
#include <iomanip>
#include <cmath>

Molecule::Molecule(string fileName)
{
	ifstream infile(fileName);

	int atom_nb;
	string cytosine;
	//Atom atom;

	infile >> atom_nb;
	nAtom = atom_nb;

	infile >> cytosine;
	comment = cytosine;

	string el;
	double x;
	double y;
	double z;

	atoms = new Atom[nAtom];

	

	for (int i = 2; i < nAtom+3; i++)
	{
		infile >> el >> x >> y >> z;
		atoms[i-2]=Atom(el, x, y, z);
		
		//atoms[i - 2].printAtom();
	}
	
	//atoms[0].printAtom();
	//atoms[nAtom].printAtom();

}

Molecule::~Molecule()
{
	delete[] atoms;
}

void Molecule::assignCell(string fileName)
{
	double line1a, line1b, line1c;

	double line2a, line2b, line2c;

	double line3a, line3b, line3c;

	ifstream infile(fileName);

	cell.a1 = new double[3];
	cell.a2 = new double[3];
	cell.a3 = new double[3];

	infile >> line1a >> line1b >> line1c;

	cell.a1[0] = line1a;
	cell.a1[1] = line1b;
	cell.a1[2] = line1c;

	//a1 = { line1a,line1b,line1c };
	//////cout << line1a << " " << line1b << " " << line1c << endl;
	/*cout << line1a << " " << line1b << " " << line1c << endl;
	double c[] = { line1a, line1b,line1c };
	for (int i = 0; i < 3; i++) cout << c[i] << endl;*/


	infile >> line2a >> line2b >> line2c;

	cell.a2[0] = line2a;
	cell.a2[1] = line2b;
	cell.a2[2] = line2c;

	infile >> line3a >> line3b >> line3c;

	cell.a3[0] = line3a;
	cell.a3[1] = line3b;
	cell.a3[2] = line3c;
	//cell = Cell(fileName);
	//cell.printCell();
}

void Molecule::printMol()
{
	cout << "\n<" << nAtom << ">" << endl;
	cout << comment << endl;
	for (int i = 0; i < nAtom; i++)
	{
		atoms[i].printAtom();
	}
}

void Molecule::writeMol(string fileName)
{
	ofstream outfile(fileName,ios::binary);
	outfile << "\n<" << nAtom << ">" << endl;
	outfile<< comment << endl;
	
	for (int i = 0; i < nAtom; i++)
	{
		outfile << std::setw(2)<< atoms[i].e << std::setw(12) << atoms[i].x << std::setw(12) << atoms[i].y << std::setw(12) << atoms[i].z << endl;
	}

	//outfile.write(reinterpret_cast<char*>(this), sizeof(this));
		/*for (int i = 0; i < nAtom; i++)
		{
			outfile.put(atoms[i].printAtom())
		};*/
}

double* Molecule::findCenter()
{
	double sum_x, sum_y, sum_z;

	sum_x = 0.0;
	sum_y = 0.0;
	sum_z = 0.0;

	for (int i = 0; i < nAtom; i++)
	{
		if (atoms[i].e == "C")
		{
			sum_x += atoms[i].x * 12.011;
			sum_y += atoms[i].y * 12.011;
			sum_z += atoms[i].z * 12.011;
		}

		else if (atoms[i].e == "H")
		{
			sum_x += atoms[i].x * 1.008;
			sum_y += atoms[i].y * 1.008;
			sum_z += atoms[i].z * 1.008;
		}

		else if (atoms[i].e == "N")
		{
			sum_x += atoms[i].x * 14.007;
			sum_y += atoms[i].y * 14.007;
			sum_z += atoms[i].z * 14.007;
		}

		else if (atoms[i].e == "O")
		{
			sum_x += atoms[i].x * 15.999;
			sum_y += atoms[i].y * 15.999;
			sum_z += atoms[i].z * 15.999;

			
		}
		
	}

	/*cout << sum_x;
			cout << sum_y;
			cout << sum_z;*/

	//cout << center[0] << " " << center[1] << " " << center[2] << endl;
	this->calcTotMass();
	center = new double[3];
	center[0] = sum_x / totalMass;
	center[1] = sum_y / totalMass;
	center[2] = sum_z / totalMass;

	cout << center[0] << " " << center[1] << " " << center[2] << endl;

	return center;

}

void Molecule::center2origin()
{
	//double distance = sqrt(pow((center[0] - 0.0), 2) + pow((center[1] - 0.0), 2) + pow((center[2] - 0.0), 2));
	double x_d = center[0] -0.0;
	double y_d = center[1] - 0.0;
	double z_d = center[2] - 0.0;
	for (int i = 0; i < nAtom; i++)
	{
		atoms[i].x -= x_d;
		atoms[i].y -= y_d;
		atoms[i].z -= z_d;
	}
}




void Molecule::rotX(double radVal)
{
	for (int i = 0; i < nAtom; i++)
	{
		atoms[i].rotX(radVal);
	}
}

void Molecule::rotY(double radVal)
{
	for (int i = 0; i < nAtom; i++)
	{
		atoms[i].rotY(radVal);
	}
}

void Molecule::rotZ(double radVal)
{
	for (int i = 0; i < nAtom; i++)
	{
		atoms[i].rotZ(radVal);
	}
}

void Molecule::printCell()
{
	cell.printCell();
}

double Molecule::getVolume()
{
	/*a1 = cell.a1;
	a2 = cell.a2;
	a3 = cell.a3;*/
	double cross[3];
	//cross = (a2[2] * a3[3] - a2[3] * a3[2]) + (a2[1] * a3[3] - a2[3] * a3[1]) + (a2[1] * a3[1] - a2[2] * a3[1]);
	cross[0] = cell.a2[1] * cell.a3[2] - cell.a2[2] * cell.a3[1];
	cross[1] = -cell.a2[0] * cell.a3[2] + cell.a2[2] * cell.a3[0];
	cross[2] = cell.a2[0] * cell.a3[1] - cell.a2[1] * cell.a3[0];

	volume = cell.a1[0] * cross[0] + cell.a1[1] * cross[1] + cell.a1[2] * cross[2];

	//cell.calculateVolume();
	//volume = cell.getVolume();
	return volume;
}

double Molecule::calcTotMass()
{
	totalMass = 0.0;
	for (int i = 0; i < nAtom; i++)
	{
		if (atoms[i].e == "C")
		{
			totalMass += 12.011;
		}

		else if (atoms[i].e == "H")
		{
			totalMass += 1.008;
		}

		else if (atoms[i].e == "N")
		{
			totalMass += 14.007;
		}

		else if (atoms[i].e == "O")
		{
			totalMass += 15.999;
		}


	}
	
	return totalMass;
}

void Molecule::calcDensity()
{
	density = totalMass / this->getVolume();
	cout << density;
}

double Molecule::getDensity()
{
	return density;
}



//Cell Molecule::assignCell(string fileName)
//{
//
//	return Cell();
//}
