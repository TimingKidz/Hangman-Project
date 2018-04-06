#include <iostream>
#include <fstream>
using namespace std;

string Words[] = {}

void OnePlayer(){
	int key;
	cout << "Select Catagories" << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C" << endl;
	cout << "4. D" << endl;
	cout << "5. Random" << endl;
	cin << key;
	switch(key){
		case '1':
			
		case '2':
			
		case '3':
			
		case '4':
			
		case '5':
			rand()%5+1;
	}
}

void TwoPlayer(){
	
}

void Help(){
	
}

void Menu(){
	int key;
	cout << "Press a number to select option." << endl;
	cout << "1 for One Player." << endl;
	cout << "2 for Two Player." << endl;
	cout << "3 for Help/Info." << endl;
	cout << "4 for Exit." << endl;
	cin >> key;
	switch(key){
		case '1':
			OnePlayer();
			break;
		case '2':
			TwoPlayer();
			break;
		case '3':
			Help();
			break;
		case '4':
			exit = true;
			break;
		default:
			cout << "Invalid Input.";
			continue;
	}
}

int main(){
	bool exit = false;
	Menu();
}
