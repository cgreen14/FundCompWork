// lifeboard.cpp
// Connor Green
// class implementation for the lifeboard class
// array[row][column]

// relevant libraries
#include "lifeboard.h"
// member functionsm
Board::Board(){
  for(int j = 0; j < 42; j++){
    for(int i = 0; i < 42; i++){
      board[i][j] = 0;
    }
  }
};
Board::~Board(){};
int Board::getValue(int a,int b){  // find if value is alive or dead
  int c;
  c = board[a][b];
  return c;
}
int Board::placeValue(int a,int b,int c){ // place a desired value on board
  board[a][b] = c;
}

void Board::killPlace(int a,int b){ // make cell dead if not already
  board[a][b] = 0;
}
void Board::livePlace(int a,int b) {  // make cell alive if not already
  board[a][b] = 1;
}
int Board::liveAround(int a,int b){ //check how many alive nieghbors a cell has
  int count = 0;
				count = board[a-1][b] +
        board[a-1][b-1] +
        board[a][b-1] +
        board[a+1][b-1] +
        board[a+1][b] +
        board[a+1][b+1] +
        board[a][b+1] +
        board[a-1][b+1];
  return count;
  // since board is 42 x 42, can just calc around pre disp 40 x 40 board
}
