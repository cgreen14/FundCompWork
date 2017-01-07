// Create times table
// troubleshot with Ryan Green

#include <iostream>
using namespace std;
#include <iomanip>

int main()
{
// intialize numbers
int num1;
int num2;
// prompt for the table values
cout << "First number of table is? ";
cin >> num1;  // width
cout << "The second number of the table is? ";
cin >> num2;  // height


// make counts
int i = 1;
int l = 1;
// first row of the table
cout << setw(3) << "*" << setw(3);
	while (i <= num1){
		cout << i << setw(3);
		i++;
	
}
cout << endl;
// make other rows

while ( l <= num2 ){
	cout << l << setw(3);
		for (int k = 1 ; k <= num1;k++){
		cout << l*k << setw(3);
		}
	cout << endl;
l++;
}
	

}
