#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

// Function Library
 void dispAll(vector<string>);
 void enterNew(vector<string>&);
 void findW(vector<string>);
 void save(vector<string>);


// Main
int main(){
	string name;
	cout << "What file are your sayings in? ";
	cin >> name; // store name of the file that we need
	// getfile
	ifstream myfile;// file then referned as myfile
	myfile.open(name);
	if (!myfile){    // checks to see if there was an error opening file
		cout << "error opening file, please run again" << endl;
		return 0;
	}
	// move file to a vector
	string saying1;
	vector<string> mysayings; // vector that stores all my sayings
	getline(myfile, saying1); // grabs first saying
		while (! myfile.eof()){         // while there is still text on a line
			mysayings.push_back(saying1);
			getline(myfile, saying1);	// grab the line
		}
	// prompt user for the action they want to do
	int cond = 1; // truth value for while loop
	while (cond){
		int choice;
		cout << "Chose the action:" << endl << "(1) Display All" << endl << "(2) Enter new saying" << endl;
		cout << "(3) List sayings containing phrase" << endl << "(4) Save in new file" << endl << "(5) quit" << endl;
		cin >> choice;
		if (choice > 5 || choice < 1){
			cout << "invalid choice, please run again using 1-5" << endl;
		}	
			switch (choice){
				case 1:
					dispAll(mysayings);
					cout << endl;
					break;
				case 2: 
					enterNew(mysayings);
					cout << endl;
					break;
				case 3:
					findW(mysayings);
					cout << endl;
					break;
				case 4:
					save(mysayings);
					cout << endl;
					break;
				case 5:
					cond = 0;
					cout << "Goodbye" << endl;;
			}
	}
}
  

void dispAll(vector<string> file){
	cout << endl << "We have: " << endl;
	for (string line : file){
		cout << line << endl;
	}
}


void enterNew(vector<string>& file){
	string newsay;
	cout << "what saying should be added to the list?: ";
	cin.ignore();
	getline(cin,newsay);
	
	file.push_back(newsay);
}

void findW(vector<string> file){
	string search;
	cout << "what does the saying you are looking for contain?: ";
	cin.ignore();
	getline(cin,search);
	int found = 0;
	cout << endl << "The sayings that contain this are: " << endl;
	for(string line :file){
		if (line.find(search) != string::npos){
			cout << line << endl;
			found = 1;
		}
	}
	if (found == 0){
		cout << "no match" << endl;
	}
}	

void save(vector<string> file){
	string name;
	cout << "what is the new file called?(inlcude .txt): ";
	cin.ignore();
	getline(cin, name);
	
	ofstream output;
	output.open(name);

	for (string line:file){
		output << line << endl;
	}

	output.close();
	cout << "new file: "<< name<< "is created";
}
