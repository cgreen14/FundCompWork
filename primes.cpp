// Connor Green
// Sept 23
// List of all primes numbers from 1 and 1,000

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
	int n = 1000;
	int values[n];
	for ( int i = 2; i < n; i++)
	{
		values[i] = 0; // create an array of 0, representing logic prime 
	}
	// set the values of 1,2,3
	values[0] = 1;
	values[1] = 1;
	values[2] = 0;

	for (int l = 3; l<n ; l++)
	{
		for (int j = 2 ; j<l ; j++)
		{
			if ( l % j == 0) // identify if a remainder is present to indicate prime
			{
				values[l] = 1; // label found numbers as not prime
			    break; // breaks out of loop  once a multiple is found
			}
		}
	}
	// Print primes based on the appearing of a 0 in the array
	cout << " The primes from 1-1000 are:" << endl;
	int c = 0;
	for (int j = 0; j<n ; j++)
	{
		if (values[j] == 0) // search
		{
			cout << setw(3) << j << " "; // print, setw, keep thse col alligned
			c++;
			if (c == 10)// keeps them in rows of 10
			{
				cout << endl;
				c=0;
			}

		}
	}
	cout << endl;
}
