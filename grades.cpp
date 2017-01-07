
// Connor Green
// Create a program that when data is read in will compute the
// average and standard devation

// Sept 23rd

// libraries 
# include <iostream>
# include <math.h>
using namespace std;

int main()
{
// Call in the data
	int grades[50];
	int sum = 0,i= 0, values;
	float average, stanDev;
	int sumDev;
	
	cin >> values; // bring in values from file
	
	
	while (values != -1 ) // check for last value in the array, indicated by -1
	{
		grades[i] = values;
		sum = sum + values;
		i++;
		cin >> values;
	}
	average = sum/i;
	cout << "The average values is: " << average;
	cout << endl;
	
	// standard devation
	
	for (int l = 0; l< i; l++)
	{
		sumDev = pow((grades[l] - average), 2);
	}
	    
	int aveDev = sumDev/i; // average devation from the mean^2
	stanDev =sqrt(aveDev);
	cout << " The Standard Devation is: "<< stanDev;
	cout <<  endl;
}

