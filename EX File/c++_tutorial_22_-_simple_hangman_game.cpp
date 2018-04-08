#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;


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



bool PrintWordAndCheckWin(string word, string guessed,int worduse){
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
			worduse ++;
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
	 	string key;
		string guesses = "\0";
		system("cls");
		bool win = false;
		wordToGuess = LoadRandomWord("words.txt");
		int tries = 0;
		cout << "Press a number to select option." << endl;
		cout << "1 for One Player." << endl;
		cout << "2 Exit." << endl;
		getline(cin,key);
		if(key == "1"){ 
 		 	//Player1
			do{
				system("cls"); 
				PrintMessage("HANGMAN");
				DrawHangman(tries);
				PrintMessage("QQQQQQQQ");
				win = PrintWordAndCheckWin(wordToGuess, guesses,worduse);
				for(int i = 0; i < guesses.length(); i++){
					guesses[i] = toupper(guesses[i]);
				}
				PrintAvailableLetters(guesses);
				for(int i = 0; i < guesses.length(); i++){
					guesses[i] = tolower(guesses[i]);
				}
			
				if(win) break;

				string x;
				cout << ">"; 
				getline(cin,x);
				if(guesses.find(x) == -1) guesses += x;
				tries = TriesLeft(wordToGuess, guesses);
			}while (tries < 10);
		if(win){
			PrintMessage("YOU WON!");
			cout << "Press Enter to go back Menu";
			getchar();
		}else{
			PrintMessage("GAME OVER");
			cout << "Press Enter to go back Menu";
			getchar();
			}
		}else if(key == "2"){
			break;
			system("pause");
		}
		//Player2
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
