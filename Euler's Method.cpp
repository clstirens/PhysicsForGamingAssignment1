// Euler's Method.cpp : Defines the entry point for the console application.
// Developed by Charles Stirens for the Euler Method and problem 3i for Physics 2
// Version 1.2 - Included support for analytical calculations. Note issues have occured regarding sin and cos

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>

#define PI 3.14159265
using namespace std;


int main()
{
	int y0 = 1; //initial y value for y(0) = 1
	double t = 0; //initial x value, represented with t for time
	double h = 0.25; // step size for estimation
	double euler; //Y value estimated at each step
	double analytical;

	ofstream myfile;

	myfile.open("Euler1.csv"); // Creates or opens file
	myfile << "X,Y,Analytical\n"; // starts columns for csv for excel

	euler = y0;		//set Euler to y0 so the algorithm makes sense at yn (n=0)
	for (int i = 0; i <= 4; i++) { 
		euler = euler + (cos(2 * t) + sin(3 * t))*h; //euler's method, in one line
		cout << "Y estimate = " << euler << " t = " << t << "\n"; //output to console
		//analytical = t;
		analytical = (sin(2 * t) / 2) - (cos(2 * t) / 3) + (4 / 3);
		myfile << t << "," << euler << "," << analytical << "\n"; //output to file the values of X and Y(estimated).
		t = t + h; //iterate x(n+1) = x + h
	}
	myfile.close();
	system("pause");
    return 0;
}
