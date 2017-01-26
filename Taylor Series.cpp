// Taylor Series.cpp : Defines the entry point for the console application.
// Developed by Charles Stirens for the purpose of calculated Taylor Series for Assignment 6, questions 2i. Licensed to Creative Commons 0, utilize code as necessary.
// Ver 1.2 - Added Analytical calculation and output, reduced number of X steps

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;


double factorial(double n); // Our factorial function
double yflip(double y); // Flip our y value per the derivative

int main()
{
	float x0 = 0; //Initial X value
	float y0 = -1; //Initial Y value (in this case, Y(0) = -1
	double Taylor = 0; //Our estimate achieved from Taylor Series
	double yPrime = 0; //The current value of the derivative
	int iteration = 15; //N element of Taylor series
	double analytical;
	
	ofstream myfile;

	myfile.open("Tayler1.csv"); // Creates or opens file
	myfile << "X,Y, Analytical\n"; // starts columns for csv for excel

	for (float x = 1; x <= 5; x++) { //For the number of X iterations, do taylor series
		float h = x - x0;

		//cout << "Stepsize = " << iteration << " \n";
		yPrime = (-y0); //initial y value for beginning of T-series
		Taylor = y0 + (yPrime*h); //Initial value + first derive y'*h
		//cout << "Taylor = " << Taylor << "\nStep = " << 1 << "\nYprime = " << yPrime << "\n\n"; //Output current information about T-series. Used for debugging only

		yPrime = (-2.0 - yPrime); //y'
		Taylor = Taylor + ((yPrime)*(pow(h, 2))) / factorial(2); //+ next value y''=-2-y' * h^2 / 2!
		//cout << "Taylor = " << Taylor << "\nStep = " << 2 << "\nYprime = " << yPrime << "\n\n"; //Output current information about T-series. Used for debugging only

		for (int n = 3; n <= iteration; n++) {
			yPrime = yflip(yPrime);
			Taylor = Taylor + (((yPrime)*(pow(h, n))) / factorial(n)); //y''' through y^n prime
			//cout << "Taylor = " << Taylor << "\nStep = " << n << "\nYprime = " << yPrime << "\n\n"; //Output current information about T-series. Used for debugging only
		}
		analytical = (-3 * (exp(-x)) - (2 * x) + 2);
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

double yflip(double y) { //For this problem, flips y value because y^(n+1) = -y^(n)
	y = -y;
	return y;
}