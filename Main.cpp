#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void ReadFile(){
	ifstream file("dictionary.txt");
	string textline;
	vector<string> dic;
	while(getline(file,textline)){
		dic.push_back(textline);
	}
}

void DrawHangman(int quessCount){
	
}

void OnePlayer(){
	int key;
	cout << "Select Catagories" << endl;
	cout << "1. A" << endl;
	cout << "2. B" << endl;
	cout << "3. C" << endl;
	cout << "4. D" << endl;
	cout << "5. Random" << endl;
	cin >> key;
	if(key == 1){
		
	}else if(key == 2){
		
	}else if(key == 3){
		
	}else if(key == 4){
		
	}else{
		
	}
}

void TwoPlayer(){
	
}

void Help(){
	
}

void Exit(){
	
}

void Menu(){
	int key;
	cout << "Press a number to select option." << endl;
	cout << "1 for One Player." << endl;
	cout << "2 for Two Player." << endl;
	cout << "3 for Help/Info." << endl;
	cout << "4 for Exit." << endl;
	cin >> key;
	if(key == 1){
		OnePlayer();
	}else if(key == 2){
		TwoPlayer();
	}else if(key == 3){
		Help();
	}else{
		Exit();
	}
}

int main(){
	srand(time(0));
	ReadFile();
	Menu();
}
