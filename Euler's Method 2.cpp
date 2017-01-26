// Euler's Method 2.cpp : Defines the entry point for the console application.
// Developed by Charles Stirens to calculated Euler's Method for problem 3ii
// version 1.2 - added support for calculating and outputting analytical solution.


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;


int main()
{
	int y0 = 1; //found by graphing analytical solution
	double x = 0; //Our first x value (this will change through runtime)
	double h = 0.01; // Stepsize, very small in this program
	double euler; //Y value estimated at each step
	double analytical;

	ofstream myfile;

	myfile.open("Euler2.csv"); // Creates or opens file
	myfile << "X,Y,Analytical\n"; // starts columns for csv for excel

	euler = y0;		//set Euler to y0 so the algorithm makes sense at yn (n=0)
	for (int i = 0; i <= 400; i++) {
		euler = euler + (exp(-4 * x) - ( 2 * euler))*h; // Yn+1 = Yn + (e^(-4x) - 2Yn)h
		cout << "Y estimate = " << euler << " X = " << x << "\n"; //output to console
		analytical = (-exp(-4 * x)/2) + (3*exp(-2*x)/2);
		myfile << x << "," << euler << "," << analytical << "\n"; //output to file the values of X and Y(estimated).
		x = x + h; //iterate x(n+1) = x + h
	}
	myfile.close();
	system("pause");
	return 0;
}
