#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

// Function Library
 void dispAll(list<string>);
 void enterNew(list<string>&);
 void findW(list<string>);
 void save(list<string>);
 void deleteline(list<string>&);
 void alpha(list<string>&,string);
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
	list<string> mylist; // vector that stores all my sayings
	getline(myfile, saying1); // grabs first saying
		while (! myfile.eof())	{         // while there is still text on a line
			alpha(mylist,saying1);   // run through the to alphabetize funciton
			getline(myfile, saying1);	// grab the line
		}
	// prompt user for the action they want to do
	int cond = 1; // truth value for while loop
	while (cond){
		int choice;
		cout << "Chose the action:" << endl << "(1) Display All" << endl << "(2) Enter new saying" << endl;
		cout << "(3) List sayings containing phrase" << endl << "(4) Save in new file" << endl << "(5) delete a line";
		cout << endl << "(6) quit"<< endl;
		cin >> choice;
		if (choice > 6 || choice < 1){
			cout << "invalid choice, please run again using 1-6" << endl;
		}	
			switch (choice){
				case 1:
					dispAll(mylist);
					cout << endl;
					break;
				case 2: 
					enterNew(mylist);
					cout << endl;
					break;
				case 3:
					findW(mylist);
					cout << endl;
					break;
				case 4:
					save(mylist);
					cout << endl;
					break;
				case 5:
					deleteline(mylist);
					cout << endl;
					break;
				case 6:
					cond = 0;
					cout << "Goodbye" << endl;
					break;
			}
	}
}
  

void dispAll(list<string> file){
	int dispVal = 1;
	cout << endl << "We have: " << endl;
	for (string line : file){
		
		cout << "(" << dispVal << ") " <<  line << endl;  // dispval, just displays number next to each phrase for reference
		dispVal++;
	}
}


void enterNew(list<string>& file){
	string newsay;
	cout << "what saying should be added to the list?: ";
	cin.ignore();
	getline(cin,newsay);
	
	alpha(file,newsay); // make sure that a new saying added correctly and display  will still be alphabetic 
}

void findW(list<string> file){
	string search;
	cout << "what does the saying you are looking for contain?: ";
	cin.ignore();
	getline(cin,search);
	int found = 0; // lets us know when we find the search
	cout << endl << "The sayings that contain this are: " << endl;
	for(string line :file){
		if (line.find(search) != string::npos){  // uses double negative to find a point where the phrase exists
			cout << line << endl;
			found = 1;
		}
	}
	if (found == 0){
		cout << "no match" << endl; // if no point is found, then returns no match
	}
}	

void save(list<string> file){
	string name;
	cout << "what is the new file called?(inlcude .txt): ";
	cin.ignore();
	getline(cin, name);
	
	ofstream output;
	output.open(name);// uses output refernece to open up the new file

	for (string line:file){
		output << line << endl;  // throws in line by line into the new file
	}

	output.close();
	cout << "new file: "<< name<< "is created"; // closes and confirms with the user
}
void deleteline(list<string>& file){
	dispAll(file);  // uses diplay to remind the user of the choices
	auto it = file.begin();
	int reference; // users pick
	cout << endl << "Which one should we get rid of?: ";
	cin >> reference;

	while(reference > file.size() || reference < 1){
		cout << " out of range, please put in another: ";
		cin >> reference;
	}
	advance (it,reference-1); // -1 so that it goes to the right place in the list
	file.erase(it);
	cout << "phrase is deleted";

}

void alpha(list<string>& mylist,string saying){
	int placeholder = 0; // lets it know if the place has been found
	auto it = mylist.begin();
	if(mylist.size() == 0){
		mylist.push_back(saying); // if the file is empty just push the saying in
	}
	else{
		while(placeholder == 0 ){
			if((saying.compare(*it) == 0) || (it == mylist.end())){ // checks ASCII and if 0 (same phrase)or at then end then its found its place
				mylist.insert(it,saying);
				placeholder = 1;
			}
			else if ((saying.compare(*it) > 0) && (it != mylist.end())){  // greater than means too soon alphabetically, so move it up 1, double check end
				it++;
			}
			else{
				mylist.insert(it,saying); // if not greater, or file at end, then you are at place for phrase
				placeholder = 1;
			}
		}
	}

}


