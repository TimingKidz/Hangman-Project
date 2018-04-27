#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

vector<string> v;

struct Player{
	bool win;
	bool turn;
	int tries;
	string guesses;
	int score;
};

void gotoxy(int x, int y){
 	COORD coord;
 	coord.X = x;
 	coord.Y = y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MaximizeWindow(void){
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}

void Color(int i=15){ // set color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   	SetConsoleTextAttribute(hConsole,i);
}

void Logo(){ //Dot Logo
	cout << endl;
	Color(15);cout << "\t\t\t\t\t";Color(9);cout << "::::::::::";Color(15);cout << "  ";Color(13);cout << "::::::";Color(15);cout << "  ";Color(11);cout << "::::::";Color(15);cout << " ";Color(10);cout << "::";Color(15);cout << "  ";Color(10);cout << "::::";Color(15);cout << " ";Color(14);cout << "::";Color(15);cout << "    ";Color(14);cout << "::";Color(15);cout << " ";Color(12);cout << "::";Color(15);cout << "      ";Color(12);cout << "::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(9);cout << "::";Color(15);cout << "     ";Color(13);cout << "::";Color(15);cout << "    ";Color(13);cout << "::";Color(15);cout << "   ";Color(11);cout << "::";Color(15);cout << "   ";Color(10);cout << "::";Color(15);cout << " ";Color(10);cout << "::";Color(15);cout << "    ";Color(14);cout << "::";Color(15);cout << "    ";Color(14);cout << "::";Color(15);cout << " ";Color(12);cout << ":::";Color(15);cout << "    ";Color(12);cout << ":::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(9);cout << "::";Color(15);cout << "     ";Color(13);cout << "::::::::";Color(15);cout << "   ";Color(11);cout << "::";Color(15);cout << "   ";Color(10);cout << "::::";Color(15);cout << "     ";Color(14);cout << "::";Color(15);cout << "    ";Color(14);cout << "::";Color(15);cout << " ";Color(12);cout << "::";Color(15);cout << " ";Color(12);cout << ":";Color(15);cout << "  ";Color(12);cout << ":";Color(15);cout << " ";Color(12);cout << "::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(9);cout << "::";Color(15);cout << "     ";Color(13);cout << "::";Color(15);cout << "    ";Color(13);cout << "::";Color(15);cout << "   ";Color(11);cout << "::";Color(15);cout << "   ";Color(10);cout << "::";Color(15);cout << " ";Color(10);cout << "::";Color(15);cout << "    ";Color(14);cout << "::";Color(15);cout << "    ";Color(14);cout << "::";Color(15);cout << " ";Color(12);cout << "::";Color(15);cout << "  ";Color(12);cout << "::";Color(15);cout << "  ";Color(12);cout << "::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(9);cout << "::";Color(15);cout << "     ";Color(13);cout << "::";Color(15);cout << "    ";Color(13);cout << "::";Color(15);cout << " ";Color(11);cout << "::::::";Color(15);cout << " ";Color(10);cout << "::";Color(15);cout << "  ";Color(10);cout << "::::";Color(15);cout << "  ";Color(14);cout << "::::::";Color(15);cout << "  ";Color(12);cout << "::";Color(15);cout << "  ";Color(12);cout << "::";Color(15);cout << "  ";Color(12);cout << "::";Color(15);cout << "\n\n";
}

/*void Logo(){ //Logo
	cout << endl;
	Color(15);cout << "\t\t\t\t\t";Color(153);cout << "::::::::::";Color(15);cout << "  ";Color(221);cout << "::::::";Color(15);cout << "  ";Color(187);cout << "::::::";Color(15);cout << " ";Color(238);cout << "::";Color(15);cout << "  ";Color(238);cout << "::::";Color(15);cout << " ";Color(170);cout << "::";Color(15);cout << "    ";Color(170);cout << "::";Color(15);cout << " ";Color(204);cout << "::";Color(15);cout << "      ";Color(204);cout << "::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(153);cout << "::";Color(15);cout << "     ";Color(221);cout << "::";Color(15);cout << "    ";Color(221);cout << "::";Color(15);cout << "   ";Color(187);cout << "::";Color(15);cout << "   ";Color(238);cout << "::";Color(15);cout << " ";Color(238);cout << "::";Color(15);cout << "    ";Color(170);cout << "::";Color(15);cout << "    ";Color(170);cout << "::";Color(15);cout << " ";Color(204);cout << ":::";Color(15);cout << "    ";Color(204);cout << ":::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(153);cout << "::";Color(15);cout << "     ";Color(221);cout << "::::::::";Color(15);cout << "   ";Color(187);cout << "::";Color(15);cout << "   ";Color(238);cout << "::::";Color(15);cout << "     ";Color(170);cout << "::";Color(15);cout << "    ";Color(170);cout << "::";Color(15);cout << " ";Color(204);cout << "::";Color(15);cout << " ";Color(204);cout << ":";Color(15);cout << "  ";Color(204);cout << ":";Color(15);cout << " ";Color(204);cout << "::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(153);cout << "::";Color(15);cout << "     ";Color(221);cout << "::";Color(15);cout << "    ";Color(221);cout << "::";Color(15);cout << "   ";Color(187);cout << "::";Color(15);cout << "   ";Color(238);cout << "::";Color(15);cout << " ";Color(238);cout << "::";Color(15);cout << "    ";Color(170);cout << "::";Color(15);cout << "    ";Color(170);cout << "::";Color(15);cout << " ";Color(204);cout << "::";Color(15);cout << "  ";Color(204);cout << "::";Color(15);cout << "  ";Color(204);cout << "::";Color(15);cout << "\n";
	Color(15);cout << "\t\t\t\t\t    ";Color(153);cout << "::";Color(15);cout << "     ";Color(221);cout << "::";Color(15);cout << "    ";Color(221);cout << "::";Color(15);cout << " ";Color(187);cout << "::::::";Color(15);cout << " ";Color(238);cout << "::";Color(15);cout << "  ";Color(238);cout << "::::";Color(15);cout << "  ";Color(170);cout << "::::::";Color(15);cout << "  ";Color(204);cout << "::";Color(15);cout << "  ";Color(204);cout << "::";Color(15);cout << "  ";Color(204);cout << "::";Color(15);cout << "\n\n";
}*/

void PrintOver(){ // print if you lose
	Color(4);
	cout << "\t\t\t\t  :::::::: :::::::: ::      :: ::::::  :::::::: ::    :: :::::: ::::::"<<"\n";
	cout << "\t\t\t\t  ::   ... ::    :: :::    ::: ::....  ::    ::  ::  ::  ::.... ::...:"<<"\n";
	Color(12);
	cout << "\t\t\t\t  ::    :: :::::::: :: :  : :: ::      ::    ::   ::::   ::     ::::  "<<"\n";
	cout << "\t\t\t\t  :::::::: ::    :: ::  ::  :: ::::::  ::::::::    ::    :::::: :: :::"<<"\n\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " X X "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  M  \n";
		Color(0); cout << "\t\t\t\t\t\t\t          "; Color(32); cout << "---\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(17); cout << "  "; Color(17); cout << "     "; Color(17); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(17); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(17); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(136); cout << "     "; Color(255); cout << "  \n"; 	
	
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(68); cout << "   "; Color(0); cout << " "; Color(68); cout << "   ";
	}

void PrintWin(){ // print if you win
	Color(3);
	cout << "\t\t\t\t\t            ::   :   :: :::::::: :::   ::"<<"\n";
	cout << "\t\t\t\t\t            ::  : :  ::    ::    :: :  ::"<<"\n";
	Color(11);
	cout << "\t\t\t\t\t             :::   :::     ::    ::  : ::"<<"\n";
	cout << "\t\t\t\t\t              ::   ::   :::::::: ::   :::"<<"\n";
		Color(0); cout << "\n";
		Color(0); cout << "\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(240); cout << " ^ ^ "; Color(255); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(240); cout << "    U    \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(0); cout << "  "; Color(255); cout << " "; Color(0); cout << "  "; Color(255); cout << "  \n";
		
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(17); cout << "  "; Color(17); cout << "     "; Color(17); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(0); cout << "  "; Color(17); cout << "     "; Color(0); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(0); cout << "  "; Color(17); cout << "     "; Color(0); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(0); cout << "  "; Color(136); cout << "     "; Color(0); cout << "  \n"; 	
	
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(68); cout << "   "; Color(0); cout << " "; Color(68); cout << "   ";
}

void PrintDraw(){ // print if your friend and you draw
	Color(8);
	cout << "\t\t\t\t\t        ::::::::  :::::: :::::::: ::   :   ::"<<"\n";
	cout << "\t\t\t\t\t        ::      : ::...: ::    :: ::  : :  ::"<<"\n";
	Color(15);
	cout << "\t\t\t\t\t        ::      : ::::   ::::::::  :::   ::: "<<"\n";
	cout << "\t\t\t\t\t        ::::::::  :: ::: ::    ::   ::	 ::  "<<"\n";
}

void PrintScore(int &score){ // function print score
	cout  << score<<"\n";
}

void PrintEnter(){ //function print enter
	cout  <<"\n\n\n\n";
}

void PrintMessage(string message, bool printTop = true, bool printBottom = true,int Col=15){ //function print message in box
	
	if(printTop){
		Color(14);
		cout  << "\t\t\t\t   +---------------------------------------------------------------+" << endl;
		cout  << "\t\t\t\t   |";
	}else{
		Color(14);
		cout  << "\t\t\t\t   |";
	}
	Color(Col);
	bool front = true;
	for(int i = message.length(); i < 63; i++){
		if (front){
			message = " " + message;
		}else{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();
	if(printBottom){
		Color(14);
		cout <<  "|" << endl;
		cout <<"\t\t\t\t   +---------------------------------------------------------------+" << endl;
	}else{
		Color(14);
		cout <<"|" << endl;
	}
}

void PrintLetters(string input, char from, char to){ //function find letter that used
	string s;
	for (char i = from; i <= to; i++)
	{
		if (input.find(i) == string::npos){
			s += "  ";
		}else{
			s += i;
			s += " ";
		}	
	}
	PrintMessage(s, false,true,13);
}

void PrintAvailableLetters(string taken){ // function print letter that uesd
	PrintMessage("Used Letter",false);
	PrintLetters(taken, 'A', 'Z');
}

void DrawHangman(int guessCount = 0){ //draw hangman
	if (guessCount == 1){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(32); cout << " / / \n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(32); cout << "/"; Color(0); cout << "     "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(32); cout << "/"; Color(0); cout << "     "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(32); cout << " / / \n";
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
	}
		
	else if (guessCount == 2){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(32); cout << " / / \n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(32); cout << "/"; Color(0); cout << "     "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(32); cout << "/"; Color(0); cout << "     "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(32); cout << " / / \n";
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
	}
	
	else if (guessCount == 3){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " @ @ "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  U  \n";
		Color(0); cout << "\t\t\t\t\t\t\t           "; Color(255); cout << " \n";
		cout << "\n\n\n\n\n\n\n\n\n";
	}
	else if (guessCount == 4){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " @ @ "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  U  \n";
		Color(0); cout << "\t\t\t\t\t\t\t           "; Color(255); cout << " \n";

		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(255); cout << "     \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(255); cout << "     \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(255); cout << "     \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(221); cout << "     \n";
		cout << "\n\n\n\n\n";
	}
	
	else if (guessCount == 5){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " @ @ "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  U  \n";
		Color(0); cout << "\t\t\t\t\t\t\t           "; Color(255); cout << " \n";
		
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(221); cout << "     \n";
		cout << "\n\n\n\n\n";
	}
	else if (guessCount == 6){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " @ @ "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  U  \n";
		Color(0); cout << "\t\t\t\t\t\t\t           "; Color(255); cout << " \n";
		
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(221); cout << "     "; Color(255); cout << "  \n"; 
		cout << "\n\n\n\n\n";
	}
	else if (guessCount == 7){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " @ @ "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  U  \n";
		Color(0); cout << "\t\t\t\t\t\t\t           "; Color(255); cout << " \n";
		
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(255); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(221); cout << "     "; Color(255); cout << "  \n"; 
	
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(221); cout << "  "; Color(0); cout << " "; Color(221); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(255); cout << "  "; Color(0); cout << " "; Color(255); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(255); cout << "  "; Color(0); cout << " "; Color(255); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(255); cout << "   "; Color(0); cout << " "; Color(255); cout << "   \n";
		cout << "\n";
	}
	else  if (guessCount == 8){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " @ @ "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  U  \n";
		Color(0); cout << "\t\t\t\t\t\t\t           "; Color(255); cout << " \n";
		
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(17); cout << "  "; Color(17); cout << "     "; Color(17); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(17); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(17); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(221); cout << "     "; Color(255); cout << "  \n"; 	
		
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(221); cout << "  "; Color(0); cout << " "; Color(221); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(255); cout << "  "; Color(0); cout << " "; Color(255); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(255); cout << "  "; Color(0); cout << " "; Color(255); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(255); cout << "   "; Color(0); cout << " "; Color(255); cout << "   \n";
		cout << "\n";
	}

	else if (guessCount >= 9){
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		Color(0); cout << "\t\t\t\t\t\t\t\t   "; Color(32); cout << "/\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t\t"; Color(68); cout << "       \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "   "; Color(255); cout << "   "; Color(68); cout << "   \n";
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(68); cout << "  "; Color(240); cout << " O O "; Color(68); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(240); cout << "  A  \n";
		Color(0); cout << "\t\t\t\t\t\t\t          "; Color(32); cout << "---\n";
		
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(17); cout << "  "; Color(17); cout << "     "; Color(17); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(17); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(17); cout << "     "; Color(255); cout << "  \n"; 
		Color(0); cout << "\t\t\t\t\t\t\t       "; Color(255); cout << "  "; Color(136); cout << "     "; Color(255); cout << "  \n"; 	
	
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t         "; Color(136); cout << "  "; Color(0); cout << " "; Color(136); cout << "  \n";
		Color(0); cout << "\t\t\t\t\t\t\t        "; Color(68); cout << "   "; Color(0); cout << " "; Color(68); cout << "   \n";
	}
	else
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		
}



bool PrintWordAndCheckWin(string word, string guessed){ //show the answer and check win
	bool won = true;
	string s;
	for (int i = 0; i < word.length(); i++){
		
		if (guessed.find(word[i]) == -1)
		{
			Color(15);
			won = false;
			s += "_ ";
		}
		else
		{
			Color(15);
			s += word[i];
			s += " ";
			
		}
	}
	PrintMessage(s, false,true,13);
	return won;
}

string LoadRandomWord(string path){ //random word
	int lineCount = 0;
	string word;
	
	ifstream reader(path.c_str());
	if (reader.is_open())
	{
		while (getline(reader, word)){
			for(int i = 0; i < word.length(); i++){
				word[i] = toupper(word[i]);
			}
			v.push_back(word);
		}

		int randomLine = rand() % v.size();

		word = v.at(randomLine);
		reader.close();
	}
	return word;
}

int TriesLeft(string word, string guessed){ 
	int error = 0;
	for (int i = 0; i < guessed.length(); i++)
	{
		if (word.find(guessed[i]) == -1)
			error++;
	}
	return error;
}

int score(string word, string guessed){ //show score
	int score = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (guessed.find(word[i]) != -1)
			score++;
	}
	return score;
}


int main(){
	MaximizeWindow();
	srand(time(0));
	string wordToGuess;
	int worduse;
	do{	
		v.clear();
		Player P;
	 	string key="\0";
		string select="\0";
		string mode="\0";
	 	do{
		 
		system("cls");
		Logo();
		int c = 0;
		PrintMessage("Press a number to select option.");
		cout << "\n";
		Color(9);	
		cout << "\t\t\t\t\t\t       |    "; Color(15); cout << "1 for One Player."; Color(9); cout << "   |" << endl;
		cout << "\t\t\t\t\t\t       |    "; Color(15); cout << "2 for Two Player."; Color(9); cout << "   |" << endl;
		cout << "\t\t\t\t\t\t       |    "; Color(15); cout << "3 Exit."; Color(9); cout << "             |" << endl;
		
		cout << "\n";
		Color(14);
		cout << "\t\t\t\t   ================================================================="<<"\n";
		Color(12);
		cout << "\n\t\t\t\t\t\t\t  >> ";
		Color(8);
		cout << "Enter a number";
		Color(12);
		cout << " <<\n\t\t\t\t\t\t\t\t   ";
		Color(15);
		        
		getline(cin,key);
		
		}while(key !="1" and key!="2" and key!="3");
		if(key == "3") break;
		
		do{
		
		system("cls");
		Logo();
		PrintMessage("Press a number to select category.");
		cout << "\n";	
		Color(1);cout << "\t\t\t\t\t\t       |    1 Normal Words      |" << endl;
		Color(9);cout << "\t\t\t\t\t\t       |    2 Marvel            |" << endl;
		Color(5);cout << "\t\t\t\t\t\t       |    3 DC                |" << endl;
		Color(13);cout << "\t\t\t\t\t\t       |    4 BNK48             |" << endl;
		Color(11);cout << "\t\t\t\t\t\t       |    5 Brand             |" << endl;
		Color(2);cout << "\t\t\t\t\t\t       |    6 Games             |" << endl;
		Color(10);cout << "\t\t\t\t\t\t       |    7 Artist            |" << endl;
		Color(14);cout << "\t\t\t\t\t\t       |    8 Famous People     |" << endl;
		Color(12);cout << "\t\t\t\t\t\t       |    9 Countries         |" << endl;
		Color(4);cout << "\t\t\t\t\t\t       |    10 Animal           |" << endl;
		Color(14);
		cout << "\n";
		cout <<"\t\t\t\t   ================================================================="<<"\n";
		Color(12);
		cout << "\n\t\t\t\t\t\t\t  >> ";
		Color(8);
		cout << "Enter a number";
		Color(12);
		cout << " <<\n\t\t\t\t\t\t\t\t   ";
		Color(15);
		
		
		getline(cin,select);
		
		}while(select!="1" and select!="2" and select!="3" and select!="4" and select!="5" and select != "6" and select != "7" and select != "8" and select != "9" and select != "10");
		
		if(select == "1") {
			wordToGuess = LoadRandomWord("words.txt");
			mode="Normal words";
		}
		else if(select == "2"){
			wordToGuess = LoadRandomWord("marvel.txt");
			mode="Marvel";
		} 
		else if(select == "3"){
			wordToGuess = LoadRandomWord("DC.txt");
			mode="DC";
		}
		else if(select == "4"){
				wordToGuess = LoadRandomWord("BNK48.txt");
				mode="BNK48";
		} 
		else if(select == "5"){
			wordToGuess = LoadRandomWord("brand.txt");
			mode="Brand";
		}
		else if(select == "6"){
			wordToGuess = LoadRandomWord("Games.txt");
			mode= "Games";
		}
		else if(select == "7"){
			wordToGuess = LoadRandomWord("Artist.txt");
			mode="Artist";
		}
		else if(select == "8"){
			wordToGuess = LoadRandomWord("Famous People.txt");
			mode="Famous People";
		}
		else if(select == "9"){
			wordToGuess = LoadRandomWord("Countries.txt");
			mode="Countries";
		}
		else if(select == "10"){
			wordToGuess = LoadRandomWord("Animal.txt");
			mode="Animal";
		}
		else cout << "Invalid Input.";
		
		if(key == "1"){ //One Player
		    P.tries = 0;
	 		P.win = false;
			P.guesses = "\0";
			P.score =0;
 		 	char t[100];
 		 	int space=0;
 		 	for (int i = 0; i < wordToGuess.length(); i++)
			{
				if(wordToGuess[i]==' '){
					P.guesses+=" ";
					space++;
				} 
				
				
			}
			do{
				
				system("cls");
			    Logo();
			    PrintMessage(mode,true,false);
				sprintf(t,"%d",P.score);
				PrintMessage("Score",true,false);
				PrintMessage(t,false,true,11);
				DrawHangman(P.tries);
				PrintMessage("GUESS THE WORD");
				P.win = PrintWordAndCheckWin(wordToGuess,P.guesses);
				
				PrintAvailableLetters(P.guesses);
			
				if(P.win) break;
				//PrintMessage(wordToGuess); baikum
				

				string x;
				Color(12);
				cout << "\n\t\t\t\t\t\t      >> ";
				Color(8);
				cout << "Enter alphabet or word";
				Color(12);
				cout << " <<\n\t\t\t\t\t\t\t\t   ";
				Color(15);
				getline(cin,x);
				for(int i = 0; i < x.length(); i++){
					x[i] = toupper(x[i]);
				}
				if(P.guesses.find(x) == -1) P.guesses += x;
				P.score=score(wordToGuess,P.guesses)-space;
				
				P.tries = TriesLeft(wordToGuess,P.guesses);
			}while (P.tries < 10);
			if(P.win){
				system("cls");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS",true,true,7);
				PrintMessage(wordToGuess,false,true,15);
				PrintEnter();
				cout << "\t\t\t\t\t\t      Press Enter to go back Menu\n\t\t\t\t\t\t\t\t   ";
				getchar();
			}else{
				system("cls");
				PrintEnter();
				PrintOver();
				PrintEnter();
				PrintMessage("THE WORD IS",true,true,7);
				PrintMessage(wordToGuess,false,true,15);
				PrintEnter();
				cout << "\t\t\t\t\t\t      Press Enter to go back Menu\n\t\t\t\t\t\t\t\t   ";
				getchar();
			}
		}else if(key == "3"){
			break;
			system("pause");
		}else if(key == "2"){ //2 player
			Player P1,P2;
			int space=0;
			int P1turn = 0, P2turn = 0;
			P1.tries = 0; P2.tries = 0;
			P1.score = 0; P2.score = 0;
			P1.win = false; P2.win = 0;
			P1.guesses = "\0"; P2.guesses = "\0";
			P1.turn = true; P2.turn = true;
			for (int i = 0; i < wordToGuess.length(); i++){
				if(wordToGuess[i] == ' '){
					P1.guesses += " ";
					P2.guesses += " ";
					space++;
				}
			}
			char t1[100];
			char t2[100];
			do{
				do{
					system("cls");
					Logo();
					PrintMessage(mode,true,false);
					sprintf(t1,"%d",P1.score);
					PrintMessage("Score",true,false);
					PrintMessage(t1,false,true,11);
					DrawHangman(P1.tries);
					PrintMessage("Player 1");
					
					
					P1.win = PrintWordAndCheckWin(wordToGuess,P1.guesses);
					P1turn++;
					if(P1turn%2==0){
						P1.turn = false;
						continue;	
					}
					PrintAvailableLetters(P1.guesses);
			        if(P2.win == true) break;
					if(P1.win == true) break;
					if(P1.tries >= 10) break;
					
					//PrintMessage(wordToGuess); baikum
					string x;
					Color(12);
					cout << "\n\t\t\t\t\t\t      >> ";
					Color(8);
					cout << "Enter alphabet or word";
					Color(12);
					cout << " <<\n\t\t\t\t\t\t\t\t   ";
					Color(15);
					getline(cin,x);
					for(int i = 0; i < x.length(); i++){
						x[i] = toupper(x[i]);
					}
					if(P1.guesses.find(x) == -1) P1.guesses += x;
					P1.score=score(wordToGuess,P1.guesses)-space;
					P1.tries = TriesLeft(wordToGuess, P1.guesses);
				}while(P1.tries < 10 && P1.turn == true && P1.win == false);
					
				do{
					
					system("cls"); 
					Logo();
					PrintMessage(mode,true,false);
					sprintf(t2,"%d",P2.score);
					PrintMessage("Score",false);
					PrintMessage(t2,false,true,11);
					DrawHangman(P2.tries);
					PrintMessage("Player 2");
					P2.win = PrintWordAndCheckWin(wordToGuess,P2.guesses);
					P2turn++;
					if(P2turn%2==0){
						P2.turn = false;
						continue;	
					}
					PrintAvailableLetters(P2.guesses);
			        if(P1.win == true) break;
					if(P2.win == true) break;
					if(P2.tries >= 10) break;
                    
					string y;
					Color(12);
					cout << "\n\t\t\t\t\t\t      >> ";
					Color(8);
					cout << "Enter alphabet or word";
					Color(12);
					cout << " <<\n\t\t\t\t\t\t\t\t   ";
					Color(15);
					getline(cin,y);
					for(int i = 0; i < y.length(); i++){
						y[i] = toupper(y[i]);
					}
					if(P2.guesses.find(y) == -1) P2.guesses += y;
					P2.score=score(wordToGuess,P2.guesses)-space;
					P2.tries = TriesLeft(wordToGuess, P2.guesses);
				}while(P2.tries < 10 && P2.turn == true && P2.win == false);
				
				if(P1.tries >= 10 && P2.tries >= 10) break;
				
			}while(P1.win == false && P2.win == false);
		
		if(P1.win){
				system("cls");
				PrintMessage("player 1");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS",true,true,7);
				PrintMessage(wordToGuess,false,true,15);
				PrintEnter();
				cout << "\t\t\t\t\t\t      Press Enter to go back Menu\n\t\t\t\t\t\t\t\t   ";
				getchar();
		}else if(P2.win){
				system("cls");
				PrintMessage("player 2");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS",true,true,7);
				PrintMessage(wordToGuess,false,true,15);
				PrintEnter();
				cout << "\t\t\t\t\t\t      Press Enter to go back Menu\n\t\t\t\t\t\t\t\t   ";
				getchar();
		}else if(P1.score > P2.score){
				system("cls");
				PrintMessage("player 2");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS",true,true,7);
				PrintMessage(wordToGuess,false,true,15);
				PrintEnter();
				cout << "\t\t\t\t\t\t      Press Enter to go back Menu\n\t\t\t\t\t\t\t\t   ";
				getchar();
		}else if(P1.score < P2.score){
				
				system("cls");
				PrintMessage("player 1");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS",true,true,7);
				PrintMessage(wordToGuess,false,true,15);
				PrintEnter();
				cout << "\t\t\t\t\t\t      Press Enter to go back Menu\n\t\t\t\t\t\t\t\t   ";
				getchar();
			
		}else if(P1.score == P2.score){
				system("cls");
				PrintEnter();
				PrintDraw();
				PrintEnter();
				PrintMessage("THE WORD IS",true,true,7);
				PrintMessage(wordToGuess,false,true,15);
				PrintEnter();
				cout << "\t\t\t\t\t\t      Press Enter to go back Menu\n\t\t\t\t\t\t\t\t   ";
				getchar();
		}
		}
	}while(true);
	
		} 

