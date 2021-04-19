// ---------------------------------------------------------------
// Programming Assignment:	CIS170C Lab 7
// Developer:			Ezeniel Rios
// Date Written:		4/17/2021
// Purpose:			Store and retrieve names and addresses in a
//				sequential text file in CSV format. 
// ---------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu(void);
void writeData(void);
void readData(void);

const char FileName[] = "TestAddress.txt";

int main() {

	menu();

	return 0;
}

void menu(void) {

	char userChoice = '-';
	do {

		cout << "\n(A)ppend Records, (S)how Records, (E)xit\n";
		cout << "choose and option: ";
		cin >> userChoice;
		userChoice = toupper(userChoice);

		switch (userChoice) {
		case 'A':
			cout << "\nAppend Records\n";
			writeData(); break;
		case 'S':
			cout << "\nShow Records\n";
			readData(); break;
		case 'E':
			cout << "\nExisting Program\n"; break;
		default:
			cout << "\n**Incorrect Menu option!**\n"; break;
		}
	} while (userChoice != 'E');
}

void writeData(void) {
	//Write the Adress Info to a File
	ofstream outMyStream(FileName, ios::app);
	if (outMyStream.is_open()) {
		string name = "";
		string street = "";
		string city = "";
		string state = "";
		string zip = "";
		char OK = 'Y';
		//discard any newline character in keyboard buffer
		cin.ignore(1, 'n');

		do {
			//get the data
			cout << "\nEnter Your Name...";
			getline(cin, name);
			cout << "Enter Street.....";
			getline(cin, street);
			cout << "\nEnter Your City...";
			getline(cin, city);
			cout << "\nEnter Your State...";
			getline(cin, state);
			cout << "\nEnter Your zip code...";
			getline(cin, zip);

			//write the data to disk
			outMyStream << name << "#";
			outMyStream << street << "#";
			outMyStream << city << "#";
			outMyStream << state << "#";
			outMyStream << zip << "#";

			cout << "Enter another Record? (Y/N) ";
			cin >> OK;
			//discard any newline character in keyboard buffer
			cin.ignore(1, '\n');
		} while (OK == 'Y' || OK == 'y');

		outMyStream.close();
	}
	else cout << "File error: Open Failed";
}

void readData(void) {
	//read data to file

	ifstream inMyStream(FileName);

	if (inMyStream.is_open()) {

		//set character to use as a line between record displays
		string recBreaks = "";
		recBreaks.assign(20, '-');

		int fieldCount = 0; //keep track of the number of fields reas
		int recordCount = 1; //Keep track of the number of records read

		//read the first field
		fieldCount = 1;
		string fieldBuffer;
		getline(inMyStream, fieldBuffer, '#');

		while (!inMyStream.eof()) {

			//display the field 
			switch (fieldCount) {
			case 1:
				cout << recBreaks << endl;
				cout << "record # " << recordCount << endl;
				cout << "Name...." << fieldBuffer << endl; break;
			case 2:
				cout << "Street.." << fieldBuffer << endl; break;
			case 3:
				cout << "City...." << fieldBuffer << endl; break;
			case 4:
				cout << "State..." << fieldBuffer << endl; break;
			case 5:
				cout << "Zip....." << fieldBuffer << endl;
				fieldCount = 0;
				recordCount++; break;
			}

			//read the next field
			getline(inMyStream, fieldBuffer, '#');

		}
		cout << recBreaks << endl;

		inMyStream.close();
	}
	else cout << "File Error: Open Failed";

}



