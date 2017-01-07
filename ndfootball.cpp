// Connor Green
// Asses aspects of the ND football record since 1900
// sept 23

// Libraries
#include  <iostream>
#include <iomanip>
#include "winloss.h"
using namespace std;

int count = sizeof(wins); // size of the data
int yearCur = 2016; // current year
//fucntions included
void yearWinLoss(); // record given a year
void winsYear(); // years with so many wins
void lossYear(); // years with so many losses
void bestYear(); // choses number x, gives top x years
void worstYear(); // choses number y, gives worst y years

int main()
{
	while (1 == 1) // create infinite loop, unitl the user wants to exit the program
	        {
	         int choice; // user pick
	         cout << "Pick a Function" << endl << "1 for team record in a given year"; 
	         cout << endl << "2 for years with 'n' wins" << endl;
	         cout << "3 for years with 'n' losses" << endl << "4 for record in top 'n'  years" << endl;
	         cout << "5 displays our 'n' worst years" << endl << "6: exit" << endl;
	         cout << "Enter here: ";
	         cin >>  choice;
	         cout << endl;
	         // exit command
	         // Check if user wants to exit
	          if (choice == 6)
	             {
	             cout << "goodbye";
	             cout << endl;
	             return 0;// kills the loop 
                 }
          if (choice == 1)
          {
          yearWinLoss();
          }
          else if (choice == 2)
          {
          winsYear();
          }
          else if (choice == 3)
          {
          lossYear();
          }
          
         else if(choice == 4)
         {
         bestYear();
         }
         else if (choice == 5)
         {
         worstYear();
         }
           } 
           
}

void yearWinLoss()
{
cout << "Enter a year between 1900 and present day: " ;
int year;
cin >> year;
cout << endl;
int refYear = year - 1900;
cout << "The in year " << year <<" we went " <<wins[refYear]<<" - "<<losses[refYear];
cout << endl; 

}

void winsYear()
{
cout << "Enter the numbers of wins we should search: ";
int victory;
cin >> victory;
cout << "We won that many games in: " << endl;
int i = 0;
while (i+1900 <= yearCur)
	{
	if (wins[i] == victory)
		{
		cout << 1900 + i<< endl;
		}
		i++;
	}
}
void lossYear()
{
cout << "Enter the number of losses we should search; ";
int defeat;
cin >> defeat;
cout << "We lost that many games in: " << endl;
int i =0;
while (i+1900 <=yearCur)
	{
	if (losses[i] == defeat)
		{
		cout << 1900 + i << endl;
		}
		i++;
	}
}
void bestYear()
{
cout << " How many top years should we consider?: " << endl;
int timeframe;
cin >> timeframe;
int j = 0, perfect = 12;

while (j<timeframe)
	for (int i= 0; i<count; i++)
			{
			if (wins[i] == perfect)
				{
				cout << 1900 + i << endl;
				j++;
				}
			}
		perfect = perfect - 1;
}
void worstYear()
{
cout << 4;
}
