// Taylor Series 3.cpp : Defines the entry point for the console application.
// Developed by Charles Stirens for the purpose of calculated Taylor Series for Assignment 6, questions 2iii. Licensed to Creative Commons 0, utilize code as necessary.
// Version 1.2 - Updated to calculated and output analytical answer. Reduced number of X iterations

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;


double factorial(double n); // Our factorial function

int main()
{
	double x0 = 0.0; //Initial X Value
	double y0 = .5; //Initial Y Value (y(0) = 0.5
	double Taylor = 0; //Our estimate achieved from Taylor Series
	double yPrime = 0; //The current value of the derivative
	int iteration = 10; //N element of Taylor Series
	double xStepSize = 1; 
	double analytical;

	ofstream myfile;

	myfile.open("Tayler3.csv"); // Creates or opens file
	myfile << "X,Y,Analytical\n"; // starts columns for csv for excel

	for (double x = 1; x <= 5; x) {
		double h = (x - x0);

		//cout << "Stepsize = " << iteration << " \n";
		yPrime = (y0 - pow(x0,2) + 1.0);
		Taylor = y0 + (yPrime*h); //Initial value + first derive y'*h
		//cout << "Taylor = " << Taylor << "\nStep = " << 1 << "\nYprime = " << yPrime << "\n\n";

		yPrime = (yPrime - (2 * 0));
		Taylor = Taylor + ((yPrime)*(pow(h, 2))) / factorial(2); //+ next value y''=-2-y' * h^2 / 2!
		//cout << "Taylor = " << Taylor << "\nStep = " << 2 << "\nYprime = " << yPrime << "\n\n";

		yPrime = (yPrime - 2);
		Taylor = Taylor + ((yPrime)*(pow(h, 3))) / factorial(3);

		for (int n = 4; n <= 10; n++) {
			Taylor = Taylor + (((yPrime)*(pow(h, n))) / factorial(n));
			//cout << "Taylor = " << Taylor << "\nStep = " << n << "\nYprime = " << yPrime << "\n\n";
		}
		analytical = (pow((x + 1), 2) - ((0.5) * exp(x)));
		cout << "Y Estimate = " << Taylor << " X = " << x << "\n\n\n\n";
		myfile << x << "," << Taylor << "," << analytical << "\n"; //output to file the values of X and Y(estimated).
		x = x + xStepSize;
	}
	myfile.close();

	system("pause");
	return 0;
}

double factorial(double fact)
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