// Connor Green
// Make a set of functions to change cordinate to polar 
// Sept 16th

// libraries 
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;
#include "polarfn.h"

int main()
	{
	// Bring in cordinates 
	float x;
	float y;

	// Grab the  Cartesian cordinates 
	cout << "What is the  x cordinate? ";
	cin >> x;
	cout << "What is the y cordinate? ";
	cin >> y;

	// Calculate the radius of the polar cordinate
	float radius  = polarR(x,y);

	// Calculate the angle of  the polar cordinate
	float  theta = polarC(x,y,radius);
	cout << setprecision(3) << "The conversion is at point ("<< radius <<","<< theta << ")";
	cout << endl;
	
	// Return a value of the quadrant 
	char rep = polarACheck(x, y);
	cout << rep;
	cout << endl;
	
	}



