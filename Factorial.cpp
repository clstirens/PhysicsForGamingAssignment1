// Factorial.cpp : Defines the entry point for the console application.
// Designed by Charles Stirens. Updated to be more flexible for larger numbers

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double mult;
	double factorial = 1;
	bool cont = true;

	while(cont){
		cout << "\nPlease type an integer to calculate factorial (type a negative to end) ";
	cin >> mult;

	for (double i = 1; i <= mult; i++) {
		if (i == 1)
			factorial = 1;
		else
			factorial = factorial * i;
	}

if (mult < 0) {
	cont = false;
	return 0;
}
	cout.flush();
	cout << "\n" << mult << "! =  " << factorial << "\n";
	system("pause");
	}
    return 0;
}

