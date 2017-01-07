// Connor Green
// Lab 6 10/14/16
//
#include <iostream>
#include <list>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <stdio.h>
#include <array> 
using namespace std;

// functions
void results(int, int, int, int, int);

// main
int main(){

// prompt user for file
	string filechoice;
	cout << "Ready to get a lot better at scrabble?" << endl << "What textfile should we use?(include .txt): ";
	getline(cin,filechoice);
// open file, and check for error in the file
	ifstream file;
	file.open(filechoice);
	if(!file){
		cout << "Please run again, error opening file";
		return 0;
	}
// open file
	float space;
	float punt;
	float letter;
	float characters;
	char c;
	int  freq[26] = {0};

	file.get(c); // get the first char
	while (! file.eof()){ // while we arent at the end of the file, take action 	
		if( isspace(c)){ // count if space
			space++;	
		}
		if( isalpha(c) ){ //count through for ever letter value
			c = tolower(c);
			freq[c-'a']++; // iterate up in the corrisponding part of the array for each letter, c-a gets correct value
			letter++;
		} 
		characters++; // keep track off all that passes
		file.get(c); // grab next character
	} 
// display results
// 	Letter by letter
	char point;
	int width = 0;
	for (int i=0;i<26;i++){
		point = i+ 97;
		cout << setw(6) << setprecision(0) << fixed << point << ": " << freq[i] << " "; 
		width++;
		if (width == 6){ 
			cout << endl;
			width = 0;
		}
	}
	float perc;
	perc = 100* space/characters;
	cout << endl;
	cout << "There were "<< letter << " total letters" << endl;
	cout << "There were "<< characters << " total characters"<< endl;
	cout << "There were "<< space << " white spaces"<< endl;
	cout << "The white space percentage is: "<< setprecision(1) << fixed << perc << "%"<< endl;
	
}









