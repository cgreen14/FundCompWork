// Connor Green
// GCD for 20311 Sept 16
#include <iostream>
using namespace std;

// initalize function
int getgcd(int a,int b);

	
int main()
	{
	
	// Initalize variables and call into program
	int num1,num2;
	cout << "What is your first number? ";
	cin >>  num1;
	cout << "What is your second number? ";
	cin >> num2;
	
	
	// Pull numbers into function
	int out; // where we will store the result of the function
	out = getgcd(num1,num2);// call function
	
	// display GCD
	cout << "The greatest common denominator of the two numbers is "<< out;
	cout << endl;
	}

// write function
int getgcd(int a,int b)
{
	return b == 0 ? a : getgcd(b, a % b);
		// one line if, where if the remainer = 0 the fucnction will return a
		// if the remainer is greater than 0, runs division again b/remainer
}

