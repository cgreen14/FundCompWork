#include<iostream>
//set up library
using namespace std
;

main ()
{

// Intialize Varaibles
int touchdown;
touchdown = 0;
int extrap;
extrap = 0;
int safety;
safety = 0;
int fieldg;
fieldg = 0;

// Pull in values


cout <<"How many touchdowns were scored? ";
cin >> touchdown;
cout <<"How many extra points were scored? ";
cin >> extrap;
cout <<"How many safeties were scored? ";
cin >> safety;
cout << "How many field goals were made? ";
cin >> fieldg;



// Initalize and Calculate point values
int score;
score = 0;
touchdown = touchdown * 6;
fieldg = fieldg * 3;
safety = safety * 2;



// total score 
score = touchdown + fieldg + extrap + safety;


cout <<"Team scored "<<score<<" points";
}
 
