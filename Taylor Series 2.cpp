// Taylor Series 2.cpp : Defines the entry point for the console application.
// Developed by Charles Stirens for the purpose of calculated Taylor Series for Assignment 6, questions 2ii. Licensed to Creative Commons 0, utilize code as necessary.
// version 1.2 - Added analytical calculation and reduced number of X iterations

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;


double factorial(double n); // Our factorial function

int main()
{

	double x0 = 0; //Initial X value
	double y0 = 1; //Initial Y value (in this case, Y(0) = -1
	double Taylor = 0; //Our estimate achieved from Taylor Series
	double yPrime = 0; //The current value of the derivative
	int iteration = 15; //N element of Taylor series
	double analytical;

	ofstream myfile;

	myfile.open("Tayler2.csv"); // Creates or opens file
	myfile << "X,Y,Analytical,\n"; // starts columns for csv for excel

	for (double x = 1; x <= 5; x++) { //For the number of X iterations, do taylor series
		double h = x - x0;

		//cout << "Stepsize = " << iteration << " \n";
		yPrime = (y0);
		Taylor = y0 + (yPrime*h); //Initial value + first derive y'*h
		//cout << "Taylor = " << Taylor << "\nStep = " << 1 << "\nYprime = " << yPrime << "\n\n";

		yPrime = (1 + yPrime);
		Taylor = Taylor + ((yPrime)*(pow(h, 2))) / factorial(2); //+ next value y''=-2-y' * h^2 / 2!
		//cout << "Taylor = " << Taylor << "\nStep = " << 2 << "\nYprime = " << yPrime << "\n\n";

		for (int n = 3; n <= 10; n++) {
			Taylor = Taylor + (((yPrime)*(pow(h, n))) / factorial(n));
			//cout << "Taylor = " << Taylor << "\nStep = " << n << "\nYprime = " << yPrime << "\n\n";
		}
		analytical = ((2 * (exp(x)) - x - 1));
		cout << "Y Estimate = " << Taylor << " X = " << x << "\n\n\n\n"; //output to console
		myfile << x << "," << Taylor << "," << analytical << "\n"; //output to file the values of X and Y(estimated).
	}
	myfile.close();

	system("pause");
	return 0;
}

double factorial(double fact) //Calculates factorial based on input
{
	double total = 1;
	for (int i = 1; i <= fact; i++) {
		if (fact <= 1)
			return 1;
		else
			total = total * i;
	}
	return total;
}
