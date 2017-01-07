// Calculate spending of a mortgage over time, and total payment

#include <iostream>
#include <math.h>
using namespace std;
#include <iomanip>
#include <cmath>

int main(){

// initalize 3 main values
float Prin = 0; // principle of loan
float Irn ; // interest rate payed
float Pay = 0; // monthly payment desired
int month = 1; // month of each payment
float termIrn = 1; // the interest in each term that needs to be paid
float total = 0;
// grab input values

cout << "What was the principle of your loan? ";
cin >> Prin;

cout << "What is your interest rate %? ";
cin >> Irn;
if (Irn <0){
	cout << "Error: Can't have a negative interest. Re-Check Value";
	cout << endl;
	return 0;
	}

cout << "What is your desired monthly payment? ";
cin >> Pay;


// Creat label row
cout << "Month" << setw(20) << "Payment" << setw(20) << "Interest" << setw(20) << 
"Balance";
cout << endl;

// creat interest multiples
Irn = Irn/1200;  //% spread over 12 months

// comupte interest
int deduction; // amount taken from principle each time

while (Prin > 0)
{
	termIrn = Prin*Irn;
	deduction = Pay - (termIrn);
	if (deduction < 0)
	{
	
	cout << "Error: the interest exceededs your payment, so you will never pay of the loan";
	cout << endl;
	return 0;
	}

	Prin = Prin - deduction;
		if (Prin < 0)
		{
		Pay = 300 - abs (Prin);
		Prin = 0;
		}

	total = total + Pay; 
cout << setprecision(2) << fixed;
cout << setw(3) << month <<  setw(15) <<"$"<< Pay << setw(15) <<"$"<< termIrn << setw(15) 
<<"$"<< 
Prin;
cout << endl;
	month++;
}

month = month -1;
cout << "Over "<<month<<" months, you will pay $"<<total;;
cout << endl;







}

