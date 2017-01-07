// life.cpp
// Connor Green
// Runs simulation of conways game of life

// libraries
#include "lifeboard.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <unistd.h>
using namespace std;


// functions
int dispMenu();
void dispKey();
void advOne(Board &);
void playL(Board &);
void dispBoard(Board);
int checkBounds(int, int);

//main
int main(int argc, char *argv[]){
system("clear"); // clear screen in prep for game
Board playPlace; // create a board playPlace
dispBoard(playPlace); // display the blank board
ifstream ifs;  // create stream in
char option; // create an option for user to pick action
if (argc == 1){ // if argc = 1 from the start then they haven't used file name
  dispKey();  // give them the key to work interactive move and take option
  cin >> option;
}
else if(argc == 2){
  ifs.open(argv[1]);
  if (!ifs) { // check if file is able to be opened
    cout << "bad file name: " << endl;
    cout << "please run again" << endl;
    return 1;
  }
  ifs >> option; // pull from file or line take in r or a plus cordinates
}
  int x,y; // cordinates
  while(option != 'q'){  // q is the quit
    switch(option){
      case 'a':
        if (argc == 1){  // depending on arguements, use cin or ifs
          cin >> x >> y;
        }
        else if (argc == 2){
          ifs >> x >> y;
        }
        if (checkBounds(x,y)==1){  // make sure the points are in range
          cout << "invalid point, try again" << endl;
          break;
        }
        playPlace.livePlace(x,y);  // create life in place identified
        dispBoard(playPlace);  // display board with this new life
        break;
      case 'r':
        if (argc == 1){
          cin >> y >> x;
        }
        else if (argc == 2){
        ifs >> y >> x;
        }
        if (checkBounds(x,y)==1){
          cout << "invalid point, try again" << endl;
          break;
        }
        playPlace.killPlace(x,y);  // similiar to a, just kills cell where indicated
        dispBoard(playPlace);
        break;
      case 'n':
        advOne(playPlace); // only apply rules once
        break;
      case 'p':
        playL(playPlace);  // play until control c
        break;
      default:
        cout << "invalid type, try agiain" << endl;
       // if not valid indicated and grab again
    }
    dispKey();
  if (argc == 1){ // draw in new values to continue loop
    cin >> option;
  }
  if (argc == 2){
    ifs >> option;
  }
}
}


void dispKey(){  // gives user options if in interactive mode
  cout << "***** This is the key to playing the game of life ***** \n";
  cout << "       ***** The origin is in the top left *****        \n";
  cout << "a followed by a row (1-40) and column (1-40) creates life there\n";
  cout << "r followed by a row(1-40) and column (1-40) kill life there\n";
  cout << "n advances the simulation one step\n";
  cout << "p plays the game continuously\n";
  cout << "q quits the program\n";
}

void advOne(Board &x){
  Board temp; // create a temparary board
  temp = x; // give that board qualities of actual board to temp
  int count; // count of nieghbors to be used
  for(int i = 1; i < 41; i++){
    for(int j = 1; j < 41; j++){
      count = x.liveAround(i,j);  // count neighbors in x apply changes to temp
      //kill the cell due to overcrowding or underpopulation, if alive
      if (x.getValue(i,j) == 1 && count != 3 && count != 2){
        temp.killPlace(i,j);
      }
			//cell with 3 neighbors that isnt alive, is now risen
      else{
        if (count == 3){
          temp.livePlace(i,j); // count from x applied to temp
            }
      }
    }
  }
    x = temp; // after loop apply qualities of temp to x
dispBoard(x); // print x
}
void playL(Board &x){
  while (1){
    advOne(x); // advances board continuously
    usleep(65000);  // wait time to make results visually accessable
  }
}
void dispBoard(Board x){
  system("clear");  // each time clears screen (board) to disp new values
  for (int k = 1;k <43; k++){  // top formatting
    cout << "-";
  }
  cout << endl;
	for(int j = 1; j < 41; j++){
    cout << "|"; // adds a side wall on left
 		for(int i = 1; i < 41; i++){
			if(x.getValue(i,j) == 1){
				cout << 'X'; // if x has a 1 value (alive), disp as x
      }
      else{
        cout << ' '; // if x has a 0 (dead), disp as 0
      }
    }
		cout << "|" << endl; // left boarder
  }
  for (int l = 1; l<43; l++){
    cout << "-"; // bottom boarder
  }
  cout << endl;
 }

 int checkBounds(int x, int y){  // used to check valid x and y
   if (x<1 || x > 40){
     return 1;
   }
   if (y<1 || y > 40){
     return 1;
   }
   else{
     return 0;
   }
 }
