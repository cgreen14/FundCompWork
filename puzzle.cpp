// puzzle.cpp

#include <ctime>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <array>
#include <iomanip>
#include <string>
#include "puzzle.h"
using namespace std;

// default constructor
Puzzle::Puzzle() {
	for (int i{0}; i < 15; i++) {
		for (int j{0}; j < 15; j++) {
			setBoard('.', i, j);
		}
	}
}

// constructor with one parameter - customizable board letters
Puzzle::Puzzle(char letter) {
	for (int i{0}; i < 15; i++) {
		for (int j{0}; j < 15; j++) {
			setBoard(letter, i, j);
		}
	}
}

// destructor
Puzzle::~Puzzle() {}

// overloaded operator <<
ostream& operator<<(ostream& output, Puzzle& theboard) {
	output << " ";
	for (int i{0}; i < 15; i++) { output << "-"; }
	output << endl;
	for (int i{0}; i < 15; i++) {
		output << "|";
		for (int j{0}; j < 15; j++) {
			output << theboard.board[i][j];
		}
		output << "|" << endl;
	}
	output << " ";
	for (int i{0}; i < 15; i++) { output << "-"; }
	return output;
}

// method to set element of board
void Puzzle::setBoard(char fillcharacter, int row, int column) {
	board[row][column] = fillcharacter;
}

// method to add word to list of words
void Puzzle::addWord(string newword) {
	for (int i{0}; i < newword.length(); i++) {
		newword[i] = toupper(newword[i]);
	}
	words.push_back(newword);
	sortWordsByLength();
}

// method to return the word from the list of words
string Puzzle::getWord(int i) {
	return words[i];
}

// method to sort the list of words into descending length
void Puzzle::sortWordsByLength() {
	string tempword;
	for (int i{1}; i < words.size(); i++) {
		for (int j{0}; j < i; j++) {
			if (words[i].size() > words[j].size()) {
				tempword = words[j];
				words[j] = words[i];
				words[i] = tempword;
			}
		}
	}
}

// method to display list user enters
void Puzzle::displayWords() {
	cout << "\nWords:\n\n";
	for (string s : words) {
		cout << s << endl;
	}
	cout << endl;
}

// method to put words onto solution board
void Puzzle::placeWords() {
	int wordplaced{0};
	int iterator{0};
	int row{0};
	int column{0};
	int startingcolumn = (15 - words[0].length()) / 2;
	for (int a{startingcolumn}; a < startingcolumn + words[0].length(); a++) { // method to put longest word on board
		board[7][a] = words[0][iterator];
		iterator++;
	}
	for (int i{1}; i < words.size(); i++) {
		int placedword{0};
		int k{0};
		while (k < words[i].length() && placedword == 0) {
			row = 0;
			while (row < 15 && placedword == 0) {
				column = 0;
				while (column < 15 && placedword == 0) {
					if (board[row][column] == words[i][k]) {
						int m = orientation(i, k, row, column);
						if (m == 1) {
							placeHorizontal(i, k, row, column);
							placedword = 1;
						}
						if (m == 2) {
							placeVertical(i, k, row, column);
							placedword = 1;
						}
					}
					column++;
				}
				row++;
			}
			k++;
		}
	}
}

// method to put word horizontally on board
void Puzzle::placeHorizontal(int i, int k, int row, int column) {
	int iterator{0};
	for (int n{column-k}; n < ((column-k) + words[i].length()); n++) {
		board[row][n] = words[i][iterator];
		iterator++;
	}
}

// method to put word vertically on board
void Puzzle::placeVertical(int i, int k, int row, int column) {
	int iterator{0};
	for (int n{row-k}; n < ((row-k) + words[i].length()); n++) {
		board[n][column] = words[i][iterator];
		iterator++;
	}
}

// method to check for vertical or horizontal space
int Puzzle::orientation(int i, int k, int row, int column) {
	int horizontalspace{1};
	int verticalspace{1};
	for (int n{column-k}; n <= ((column-k) + words[i].length()); n++) {
		if (n < 0 || n > 14) { horizontalspace = 0; }
		if ((board[row][n] != '.') && (n != column)) { horizontalspace = 0; }
		if ((board[row-1][n] != '.') && (n != column)) { horizontalspace = 0; }
		if ((board[row+1][n] != '.') && (n != column)) { horizontalspace = 0; }
	}
	for (int n{row-(k+1)}; n <= ((row-k) + words[i].length()); n++) {
		if (n < 0 || n > 14) { verticalspace = 0; }
		if ((board[n][column] != '.') && (n != row)) { verticalspace = 0; }
		if ((board[n][column-1] != '.') && (n != row)) { verticalspace = 0; }
		if ((board[n][column+1] != '.') && (n != row)) { verticalspace = 0; }
	}
	if (horizontalspace == 1) {
		return 1;
	}
	if (verticalspace == 1) {
		return 2;
	}
	return 0;
}

// method to generate user board
void Puzzle::placeSpaces() {
	for (int row{0}; row < 15; row++) {
		for (int column{0}; column < 15; column++) {
			if (board[row][column] == '.') { board[row][column] = '#'; }
			else { board[row][column] = ' '; }
		}
	}
}

// method to display clues
void Puzzle::generateClues() {
	cout << "\nClues:\n\n";
	int foundword{0};
	int row{0};
	int column{0};
	srand(unsigned(time(0)));
	for (int i{0}; i < words.size(); i++) {
		foundword = 0;
		row = 0;
		while (row < 15 && foundword == 0) {
			column = 0;
			while (column < 15 && foundword == 0) {
				if (board[row][column] == words[i][0]) {
					if (checkOrientation(row, column, i) == 2) {
						random_shuffle(words[i].begin(), words[i].end());
						cout << setw(2) << column << "," << setw(3) << row << " " << "Across " << words[i] << endl;
						foundword = 1;
					}
					else if (checkOrientation(row, column, i) == 3) {
						random_shuffle(words[i].begin(), words[i].end());
						cout << setw(2) << column << "," << setw(3) << row << " " << "Down   " << words[i] << endl;
						foundword = 1;
					}
				}
				column++;
			}
			row++;
		}
	}
}

// method to generate clues through ofstream object
void Puzzle::generateClues(ofstream& ofs) {
	ofs << "\nClues:\n\n";
	int foundword{0};
	int row{0};
	int column{0};
	srand(unsigned(time(0)));
	for (int i{0}; i < words.size(); i++) {
		foundword = 0;
		row = 0;
		while (row < 15 && foundword == 0) {
			column = 0;
			while (column < 15 && foundword == 0) {
				if (board[row][column] == words[i][0]) {
					if (checkOrientation(row, column, i) == 2) {
						random_shuffle(words[i].begin(), words[i].end());
						ofs << setw(2) << column << "," << setw(3) << row << " " << "Across " << words[i] << endl;
						foundword = 1;
					}
					else if (checkOrientation(row, column, i) == 3) {
						random_shuffle(words[i].begin(), words[i].end());
						ofs << setw(2) << column << "," << setw(3) << row << " " << "Down   " << words[i] << endl;
						foundword = 1;
					}
				}
				column++;
			}
			row++;
		}
	}
}

// method to check orientation
int Puzzle::checkOrientation(int row, int column, int i) {
	int horizontal{1};
	int vertical{1};
	int k{0};
	for (k; k < words[i].length(); k++) {
		if (board[row][column+k] != words[i][0+k]) {
			horizontal = 0;
		}
		if (board[row+k][column] != words[i][0+k]) {
			vertical = 0;
		}
	}
	if (board[row][column+k] != '.' && ((column+k+1) < 15)) {
		horizontal = 0;
	}
	if (board[row+k][column] != '.' && ((row+k+1) < 15)) {
		vertical = 0;
	}
	if (board[row][column-1] != '.' && ((column-1) >= 0)) {
		horizontal = 0;
	}
	if (board[row-1][column] != '.' && ((row-1) >= 0)) {
		vertical = 0;
	}
	if (horizontal == 1) { return 2; }
	if (vertical == 1) { return 3; }
	return 1;
}
