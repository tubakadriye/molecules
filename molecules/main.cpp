#include <iostream>
#include "atom.h"
#include "cell.h"
#include "molecule.h"

using namespace std;

int main() {

	Molecule M = Molecule("16fuCyt.xyz");
	M.assignCell("cell_file");
	M.printCell();
	M.calcTotMass();
	M.calcDensity();
	//M.printMol();
	for (int i = 0; i < 628; i++)
	{
		M.rotZ(0.01);
		M.writeMol("rotated.xyz");
	}
	cout << "\nvolume = " << M.getVolume() << endl;
	cout << "density = " << M.getDensity() << endl;
	cout << "center: " << endl;
	M.findCenter();
	M.center2origin();
	M.findCenter();
	

	









	//Molecule M = Molecule("16fuCyt.xyz");

	//M.assignCell("cell_file");
	////M.printMol();
	//M.rotX(90);
	////M.printMol();
	//cout << "print cell" << endl;
	//M.printCell();
	//cout << "get volume" << endl;
	//cout << M.getVolume() << endl;
	//cout << "total mass" << endl;
	//cout << M.calcTotMass() << endl;
	//cout << "density" << endl;
	//M.calcDensity();
	//cout << M.getDensity();
	////M.writeMol("rotated.xyz");
	///*M.calcDensity();
	//cout << "volume = " << M.getVolume() << endl;
	//cout << "density = " << M.getDensity() << endl;
	//M.printCell();
	//M.calcTotMass();
	//M.printMol();
	//M.findCenter();
	//M.center2origin();
	//M.printMol();
	//for (int i = 0; i < 628; i++) {
	//	M.rotZ(0.01);
	//	M.writeMol("rotated.xyz");
	//}*/

	//
	//Cell S=Cell();
	//for (int i = 0; i < 3; i++) cout << S.a1[i] << endl;
	//Cell T = Cell("cell_file");
	//cout << "printcell" << endl;
	//T.printCell();
	////cout << T.calculateVolume() << endl;
	////cout << S.calculateVolume() << endl;

	//T.calculateVolume();
	//S.calculateVolume();
	//cout << "getvolume" << endl;
	//cout<<T.getVolume()<<endl;
	//cout<<S.getVolume()<<endl;
	//
	/*Atom A = Atom();
	A.printAtom();
	A.rotZ(0.01);
	A.printAtom();

	Atom B = Atom("cytosine", 2, 2, 2);
	B.printAtom();
	B.rotX(0.01);
	B.printAtom();*/


	return 0;
}
