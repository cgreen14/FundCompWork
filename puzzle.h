// puzzle.h

#include <array>
#include <vector>
#include <fstream>
#include <string>

#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
	friend std::ostream& operator<<(std::ostream&, Puzzle&); // overloaded operator <<
	
	public:
	Puzzle(); // default constructor
	Puzzle(char); // constructor with one parameter -  customizable board letters
	~Puzzle(); // destructor
	void setBoard(char, int, int); // method to fill in a certain element of puzzleboard
	void addWord(std::string); // method to add word to list of words stored in class
	std::string getWord(int); // method to get word from list
	void displayWords(); // method to display the list the user enters
	void placeWords(); // method to put first word in ordered list onto the solution board
	void placeSpaces(); // method to generate the user board
	void generateClues(); // method to generate clues
	void generateClues(std::ofstream&); // method to generate clues through ofstream
	
	private:
	void sortWordsByLength(); // method to sort list of words into descending order by length
	void placeHorizontal(int, int, int, int); // method to place word horizontally
	void placeVertical(int, int, int, int); // method to place word vertically
	int checkOrientation(int, int, int); // method to check orientation of word
	int orientation(int, int, int, int); // method to check for vertical or horizontal space
	std::array< std::array<char, 15>, 15> board{}; // 15x15 array to represent solution to board
	std::vector<std::string> words; // vector to store list of words
};

#endif
