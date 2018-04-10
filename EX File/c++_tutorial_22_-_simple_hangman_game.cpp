#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;


struct Player{
	bool win = false;
	int tries = 0;
	string guesses;
	int score;
};

void PrintMessage(string message, bool printTop = true, bool printBottom = true){
	
	if(printTop){
		cout  << "+---------------------------------------------------------------+" << endl;
		cout  << "|";
	}else{
		cout  << "|";
	}
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
		cout <<  "|" << endl;
		cout <<"+---------------------------------------------------------------+" << endl;
	}else{
		cout <<"|" << endl;
	}
}

void PrintLetters(string input, char from, char to){
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
	PrintMessage(s, false);
}

void PrintAvailableLetters(string taken){
	PrintMessage("Used Letter",false);
	PrintLetters(taken, 'A', 'Z');
}

void DrawHangman(int guessCount = 0){
	if (guessCount >= 1)
		PrintMessage("|", false, false);
	else
		PrintMessage("", false, false);

	if (guessCount >= 2)
		PrintMessage("|", false, false);
	else
		PrintMessage("", false, false);

	if (guessCount >= 3)
		PrintMessage("O", false, false);
	else
		PrintMessage("", false, false);

	if (guessCount == 4)
		PrintMessage("/  ", false, false);
	
	if (guessCount == 5)
		PrintMessage("/| ", false, false);

	if (guessCount >= 6)
		PrintMessage("/|\\", false, false);
	else
		PrintMessage("", false, false);

	if (guessCount >= 7)
		PrintMessage("|", false, false);
	else
		PrintMessage("", false, false);

	if (guessCount == 8)
		PrintMessage("/", false, false);

	if (guessCount >= 9)
		PrintMessage("/ \\", false, false);
	else
		PrintMessage("", false, false);
}



bool PrintWordAndCheckWin(string word, string guessed){
	bool won = true;
	string s;
	
	for (int i = 0; i < word.length(); i++)
	{
		if (guessed.find(word[i]) == -1)
		{
			won = false;
			s += "_ ";
		}
		else
		{
			s += word[i];
			s += " ";
		}
	}
	PrintMessage(s, false);
	return won;
}

string LoadRandomWord(string path){
	int lineCount = 0;
	string word;
	vector<string> v;
	ifstream reader(path.c_str());
	if (reader.is_open())
	{
		while (getline(reader, word))
			v.push_back(word);

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


int main(){
	srand(time(0));
	string wordToGuess;
	int worduse;
	do{	
		Player P;
	 	string key;
		P.guesses = "\0";
		system("cls");
		//bool win = false;
		wordToGuess = LoadRandomWord("words.txt");
		cout << "Press a number to select option." << endl;
		cout << "1 for One Player." << endl;
		cout << "2 for Two Player." << endl;
		cout << "3 Exit." << endl;
		getline(cin,key);
		if(key == "1"){ 
 		 	//One Player
			do{
				system("cls"); 
				PrintMessage("HANGMAN");
				DrawHangman(P.tries);
				PrintMessage("QQQQQQQQ");
				P.win = PrintWordAndCheckWin(wordToGuess,P.guesses);
				for(int i = 0; i < P.guesses.length(); i++){
					P.guesses[i] = toupper(P.guesses[i]);
				}
				PrintAvailableLetters(P.guesses);
				for(int i = 0; i < P.guesses.length(); i++){
					P.guesses[i] = tolower(P.guesses[i]);
				}
			
				if(P.win) break;

				string x;
				cout << ">"; 
				getline(cin,x);
				if(P.guesses.find(x) == -1) P.guesses += x;
				P.tries = TriesLeft(wordToGuess,P.guesses);
			}while (P.tries < 10);
		if(P.win){
			PrintMessage("YOU WON!");
			cout << "Press Enter to go back Menu";
			getchar();
		}else{
			PrintMessage("GAME OVER");
			cout << "Press Enter to go back Menu";
			getchar();
			}
		}else if(key == "3"){
			break;
			system("pause");
		}else if(key == "2"){
			Player P1,P2;
			do{
					system("cls"); 
					PrintMessage("HANGMAN");
					DrawHangman(P1.tries);
					PrintMessage("1");
					
					P1.win = PrintWordAndCheckWin(wordToGuess,P1.guesses);
					for(int i = 0; i < P1.guesses.length(); i++){
						P1.guesses[i] = toupper(P1.guesses[i]);
					}
					PrintAvailableLetters(P1.guesses);
					for(int i = 0; i < P1.guesses.length(); i++){
						P1.guesses[i] = tolower(P1.guesses[i]);
					}
			
					if(P1.win == true) break;
					

					string x;
					cout << ">"; 
					getline(cin,x);
					
					if(P1.guesses.find(x) == -1) P1.guesses += x;
					P1.tries = TriesLeft(wordToGuess, P1.guesses);
				
					//P2
				
					system("cls"); 
					PrintMessage("HANGMAN");
					DrawHangman(P2.tries);
					PrintMessage("2");
					P2.win = PrintWordAndCheckWin(wordToGuess,P2.guesses);
					for(int i = 0; i < P2.guesses.length(); i++){
						P2.guesses[i] = toupper(P2.guesses[i]);
					}
					PrintAvailableLetters(P2.guesses);
					for(int i = 0; i < P2.guesses.length(); i++){
						P2.guesses[i] = tolower(P2.guesses[i]);
					}
			
					if(P2.win == true) break;

					string y;
					cout << ">"; 
					getline(cin,y);
					if(P2.guesses.find(y) == -1) P2.guesses += y;
					P2.tries = TriesLeft(wordToGuess, P2.guesses);
				
			}while(P1.win == false || P2.win == false);
		
		if(P1.win){
			PrintMessage("Player 1 WON!");
			cout << "Press Enter to go back Menu";
			getchar();
		}else if(P2.win){
			PrintMessage("Player 2 WON!");
			cout << "Press Enter to go back Menu";
			getchar();
		}else{
			PrintMessage("GAME OVER");
			cout << "Press Enter to go back Menu";
			getchar();
			}
		}
	}while(true);
	
		} 


/*
+---------------------------------+
|             HANG MAN            |
+---------------------------------+
|               |                 |
|               |                 |
|               O                 |
|              /|\                |
|               |                 |
|              / \                |
|         +----------+            |
|         |          |            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|      |
+---------------------------------+
|         
Guess the word  
        |
+-------------------------------
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |--+
+---------------------------------+
>  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/
