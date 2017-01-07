// Connor Green
// Create a simple calculate that perfroms operations on two numbers until user prompts exit
// Sept 16

// Libraries
#include <iostream>
#include <iomanip>

using namespace std;

// Declare fucntions to be used
float addition(float, float);
float subtraction(float, float);
float multiplication(float, float);
float division(float, float);

int main()
{
	while (1 == 1) // create infinite loop, unitl the user wants to exit the program
	{
	int choice; // user pick
	float output; // display to user
	cout << "Pick a Function" << endl << "1 for addition" << endl << "2 for  subtraction" << endl;
	cout << "3 for multiplication" << endl << "4 for division" << endl << "5 for exit" << endl;
	cout << "Enter here: ";
	cin >>  choice;
	cout << endl;
	
	// Check if user wants to exit
		if (choice == 5)
			{
			cout << "goodbye";
			cout << endl;
			return 0;// kills the loop 
			}
	// if user wants to compute get input
		float a, b;
		char function[1];  // allows for operator to be displayed based on function 
		cout << "Input the two numbers that you want to work with seperate by a space: ";
		cin >> a >> b;
	
		if (choice == 1)
		{
			output = addition(a,b);
			function[1] = '+';
		}
		else if (choice == 2)
		{
			output = subtraction(a,b);
			function[1] = '-';
		}
		else if (choice == 3)
		{
			output = multiplication(a,b);
			function[1] = '*';
		}
		else if (choice == 4)
		{
			output = division(a,b);
			function[1] = '/';
		}
		cout << "The results of your choice:";
		cout << endl;
		cout << fixed <<setprecision(4)<< "("<< a << ") "<<function[1]<<" ("<<b<<") = " ;
						// set precision to 4 for a, b , and output
		cout << output;
		cout << endl << endl;
		

	}
}

// Define the functions that are used above 

float addition(float a,float b)
	{
	return  a+b;
	}
	
float subtraction(float a, float b)
	{
	return  a-b;
	}

float multiplication(float a, float b)
	{
	return  a*b;
	}
	
float division(float a, float b)
	{
	return   a/b;
	}
