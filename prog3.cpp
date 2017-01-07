// create a program that models the area of a trapezoid, that can accept non-interger values
// return a notice if the data entry is invalid

// set up
#include <iostream>
using namespace std;

main()
{


// intialize values using float to account for non intergers
float b1; // side 1
float b2; // side 2
float h; // height
float area; // surface area of the shape
// Pull in the values from the user


cout<< "How long is the B1 side of the trapezoid? ";
cin >> b1;
cout << "How long is the B2 side of the trapezoid? ";
cin >> b2;
cout << "How tall is the trapezoid? ";
cin >> h;

// Check values are postive, can't have negative lengths
if( b1<0 || b2<0 || h<0)
{
cout << "Error, check sign";
}
else
{
// calculate area given the dimensions

area = (b1+b2)*h/2;

// Display the area 
cout << "The area of the trapeziod is " <<area<< " in your respective units";
}
}

