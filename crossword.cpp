// crossword.cpp
// Daniel Burns - Connor Green
// Lab 9 - Crossword Anagram
// November 14, 2016

#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <cstdlib>
#include "puzzle.h"
using namespace std;

int main(int argc, char* argv[]) {
	ofstream ofs;
	ifstream ifs;
	system("clear");
	cout << "Anagram Crossword Puzzle Generator\n" << "----------------------------------\n";
	Puzzle solutionboard, userboard, referenceboard; // declare three objects of class Puzzle
	int wordsinlist{0};
	string newword;
	if (argc == 1) {
		cout << "\nEnter a list of words:" << endl;
		cin >> newword;
		while (newword.length() > 15) {
			cout << "Words may not be longer than 15 letters, please re-enter: ";
			cin >> newword;
		}
		for (int n{0}; n < newword.length(); n++) {
			if ((newword[n] > 122 || newword[n] < 65) && newword != ".") {
				cout << "Only letters A-Z are allowed: Please re-enter word: ";
				cin >> newword;
				break;
			}
		}
	}
	if (argc == 3) {
		ofs.open(argv[2]);
		ofs << "Anagram Crossword Puzzle Generator\n" << "----------------------------------\n";
	}
	if (argc == 2 || argc == 3) {
		cout << "\nWords:" << endl;
		ifs.open(argv[1]);
		ifs >> newword;
		cout << newword << endl;
		if (argc == 3) {
			ofs << "\nWords:" << endl;
			ofs << newword << endl;
		}
	}
	while (newword != "." && wordsinlist < 15) {
		solutionboard.addWord(newword);
		wordsinlist++;
		if (argc == 1) {
			if (wordsinlist < 20) {
				cin >> newword;
				while (newword.length() > 15) {
					cout << "Words may not longer than 15 letters, please re-enter: ";
					cin >> newword;
				}
				for (int n{0}; n < newword.length(); n++) {
					if ((newword[n] > 122 || newword[n] < 65) && newword != ".") {
						cout << "Only letters A-Z are allowed: Please re-enter word: ";
						cin >> newword;
						break;
					}
				}
			}
		}
		if (argc == 2 || argc == 3) {
			ifs >> newword;
			cout << newword << endl;
			if (argc == 3) {
				ofs << newword << endl;
			}
		}
	}
	solutionboard.placeWords();
	userboard = solutionboard;
	referenceboard = solutionboard;
	userboard.placeSpaces();
	cout << "\nSolution:\n\n" << solutionboard << endl;
	cout << "\nCrossword puzzle:\n\n" << userboard << endl;
	solutionboard.generateClues();
	if (argc == 3) {
		ofs << "\nSolution:\n\n" << solutionboard << endl;
		ofs << "\nCrossword puzzles:\n\n" << userboard << endl;
		referenceboard.generateClues(ofs);
	}
}
