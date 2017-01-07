// statemain.cpp
// Connor Green
// use the methods made in the state class to read and work with a set of data
// data containing information about all 50 states
// 10/30/16

// libraries
#include "state.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

// functions
int dispMenu(); // dont need inut to run it, since just returning choice
void dispAll(vector<State>); // prep functions to take in vector
void findCap(vector<State>);
void findPop(vector<State>);
void findYearAfter(vector<State>);
void stateReps(vector<State>);
void abvSearch(vector<State>);

// main
int main(){
  // set up stream and variables to put into the vector
    ifstream ifs; // stream setup
    string file; // file name to ascess
    string stateAbv,stateName, statePop, stateCapital, yearOrigin, repCongress; // parts of state data
    int Pop,yearO,repC; // interger values of string numbers
    vector<State> states; // create vector to store states
    State st;  // individual state to push into vector

    cout << "enter data file name (with .txt): ";
    cin >> file;
    ifs.open(file);
    if (!ifs) { // check if file is able to be opened
      cout << "bad file name: " << file << endl;
      cout << "please run again" << endl;
      return 1;
    }

    char c = ifs.peek();
    while(c != EOF) { // assuming perfect data file for the limiters and such
      getline(ifs, stateAbv , ','); // getline(stream,label,limiter)
      getline(ifs, stateName , ',');
      getline(ifs, stateCapital, ',');
      getline(ifs, statePop, ',');
      getline(ifs, yearOrigin, ',');
      getline(ifs, repCongress , '\n');
      Pop = stoi(statePop); // convert to int so usable in class
      yearO = stoi(yearOrigin);
      repC = stoi(repCongress);
      st = State(stateAbv, stateName, stateCapital, Pop, yearO,repC); // place in class object
      states.push_back(st); // push into list
      c = ifs.peek(); // check next character
    }
  // while condition to keep choices in a loop
  int cond = 1;
  while(cond){ // stay in loop until user wants to exit
    int choice;
    choice = dispMenu(); // run menu function
			switch (choice){ // case through options and break out when completed
				case 1:
				dispAll(states);
					cout << endl;
					break;
				case 2:
					findCap(states);
					cout << endl;
					break;
				case 3:
          findPop(states);
					cout << endl;
					break;
				case 4:
			    findYearAfter(states);
					cout << endl;
					break;
				case 5:
			    stateReps(states);
					cout << endl;
					break;
				case 6:
          abvSearch(states);
          cout << endl;
					break;
        case 7:
  				cond = 0;
  				cout << "Goodbye" << endl;
  				break;
        default:
          cout << "invalid choice, please run again using 1-7" << endl; // make sur choice is in bounds
			}
  }

}

int dispMenu(){ // choices user can have
  cout << "What would you like to know about the states?" << endl;
  cout << "type in the value of you selection" << endl;
  cout << "(1) List All" <<endl<<"(2) Find capital"<<endl;
  cout << "(3) Find population"<<endl<<"(4) List states founded after year"<<endl;
  cout << "(5) Give the population per Represenative in a state" << endl;
  cout << "(6) Find abbrevation" << endl;
  cout << "(7) quit"<< endl << "Choice: ";
  int choice;
  cin >> choice;
  while(cin.good() !=1){  // if user tries to type out option it corrects
    cin.clear();  // clears cin
    cin.ignore(numeric_limits<streamsize>::max(),'\n');  // ignores only to limiter
    cout << "Invalid Entry try again" << endl; // gives user another shot
    cin >> choice;
  }
  return choice;
}
void dispAll(vector<State> st){  // uses vector st to refernece states
  int count = 1;
  // legend
  cout << "   Abreviation | Name | Capital | Population | Year | Founded | Reps";
  cout << endl;
  // run through and use member functions to display all the data
  for (int it{0}; it < st.size(); ++it) {
    cout << "(" << setw(2) << count << ")  " ;
    cout << st[it].getstateABV() << " | " ;
    cout << st[it].getstateName() << " | ";
    cout << st[it].getstateCapital() << " | ";
    cout << st[it].getstatePop() << " | ";
    cout << st[it].getyearOrigin() << " | ";
    cout << st[it].getrepCongress() << endl;
    count++;
  }
}
void findCap(vector<State> st){
  cout << "what state should we find the capital of?: ";
  string name;
  int stateF = 0; // found switch
  cin.ignore(); // use this and getline to take on two word states
  getline(cin,name);
  for (int it{0}; it < st.size(); ++it){  // run through vector
    if (name == st[it].getstateName()){ // look for the name of the state
      cout << "The captial is: " << st[it].getstateCapital() << endl;
      stateF = 1;
    }
  }
  if(stateF == 0){ // if no state is found let user know
    cout << "no state found, be sure to check spelling and capitalization" << endl;
  }
}
void findPop(vector<State> st){  // similiar process to up, different member function used
  cout << "what state should we find the population of?: ";
  string name;
  int stateF = 0;
  cin.ignore();
  getline(cin,name);
  for (int it{0}; it < st.size(); ++it){
    if (name == st[it].getstateName()){
      cout << "The population is: " << st[it].getstatePop() << endl;
      stateF = 1;
    }
  }
  if(stateF == 0){
    cout << "no state found with that name, be sure to check spelling and capitalization" << endl;
  }
}
void findYearAfter(vector<State> st){
  cout << "States founded after what year?: ";
  int year;
  int count = 0;
  int stateF = 0;
  cin >> year;
  cout << endl;
  for (int it{0}; it < st.size(); ++it){
    if (year <= st[it].getyearOrigin()){ // check if their year limiter is less than states year
      cout << st[it].getstateName() << endl;
      count++;
      stateF = 1;
    }
  }
  cout << "There are " << count << " total" << endl; // counts through
  if(count == 0){
    cout << "no states founded after that time" << endl;
  }
}
void stateReps(vector<State> st){
  cout << "what state should we find the ratio of?: ";
  string name;
  int stateF = 0;
  cin.ignore();
  getline(cin,name);
  for (int it{0}; it < st.size(); ++it){
    if (name == st[it].getstateName()){
      int ratio; // can declare as int since you cant have part of a person
      ratio = st[it].getstatePop()/st[it].getrepCongress();  // grab values and divide
      cout << "There are "<< ratio << " people per congressperson" << endl;
      cout << "There are "<< st[it].getrepCongress() << "congressman" << endl;
      // give refernce to total number of cogress for context
      stateF = 1;
    }
  }
  if(stateF == 0){
    cout << "no state found with that name, be sure to check spelling and capitalization" << endl;
  }
}
void abvSearch(vector<State> st){
  cout << "what state should we find the abreviation of?: ";
  string name;
  int stateF = 0;
  cin.ignore();
  getline(cin,name);
  for (int it{0}; it < st.size(); ++it){ // search through loop
    if (name == st[it].getstateName()){  // find a match for state name
      cout << "The abreviation is: " << st[it].getstateABV() << endl;
      stateF = 1; // let comp no match was found
    }
  }
  if(stateF == 0){
    cout << "no state found, be sure to check spelling and capitalization" << endl;
  }
}
