// Graph using ASCII
// colaborated with Ryan Green


#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
using namespace std;


int main()
{
// Lable the plot that we want to create
cout << "Plot of 20+15cos(x) from x=0 to x=20";
cout << endl;
// create vairables to use 
float x=0;
float y=0;
float xmin = 0;
float xmax = 0;
float ymin = 10000000;
float ymax = 0;
int d=0;// need later on to make  an integer of the output for for loop

printf("X         Y       "); // set up print line with x and y lables 
cout << endl;// enter down before starting the graph

for( int i=0;i <= 200 ; i++ ) // for loop creates values
{
x = i*0.1; // 0.1 delta x
y = 20+15*cos(x);
d = (int)y;
if (y>ymax)
{
	ymax = y;
	xmax = x;
}

if (y < ymin )
{
	ymin = y;
	xmin = x;
}
printf("%6.2f   %6.2f",x,y);// 6 characters of width,2 points of precision, and float
cout << setw(8); // stops the loops of values to the limit of the int y which is d
	for (int l=0; l<=d ; l++){
	cout <<"&"; // symbol chosen to create graph with
	}
cout << endl; // enter down for each line

}
cout << " The minimum value is at y = "<<ymin<<" at x = "<<xmin<< endl;;
cout << " The maximum value is at y = "<<ymax<<" at x = "<< xmax<< endl;;



}
