#include <iostream>
#include "Vector3D.h"
#include <fstream>
#include <string>

using namespace std;

void main()
{
	Vector3D v1(30, 20, 50);
	ofstream write("Result.txt");


	cout << "Vector v1:\n" + v1.information() << "\n";
	write << "Vector v1:\n" + v1.information() << "\n";
	
	v1 * 2;		//умножили на 2
	cout << "\n\n\n";
	write << "\n\n\n";

	cout << "After v1*2:\n" + v1.information();
	write << "After v1*2:\n" + v1.information();

	v1 * (1.00/2.00);
	cout << "\n\n\n";
	write << "\n\n\n";
	cout << "After v1*1/2:\n" + v1.information();
	write << "After v1*1/2:\n" + v1.information();

	Vector3D v2 = v1;
	cout << "\n\n\n";
	write << "\n\n\n";
	cout << "Vector v2:\n" + v1.information() << "\n";
	write << "Vector v2:\n" + v1.information() << "\n";



	write.close();
	
}