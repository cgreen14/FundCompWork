// lifeboard.h
// class to communicate with board
// Connor Green

class Board{

public:
  // methods that can be used in class and library to be drawin in .cpp and main
  Board();
  ~Board();
  int getValue(int,int); // find if value is alive or dead
  int placeValue(int,int,int);
  void killPlace(int,int); // make cell dead if not already
  void livePlace(int,int); // make cell alive if not already
  int liveAround(int,int); // check how many alive members a cell has
private: // data only accessed through the class
   int board[42][42]; // board is given extra place outside of 40 by 40
            // this place can't be accessed but makes life calculation easy
};
