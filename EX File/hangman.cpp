#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;

vector<string> v;

struct Player{
	bool win;
	bool turn;
	int tries;
	string guesses;
	int score;
};

void PrintOver(){
cout << ":::::::: :::::::: ::      :: ::::::  :::::::: ::     :: :::::: ::::::"<<"\n";
cout << "::   ... ::    :: :::    ::: ::....  ::    ::  ::   ::  ::.... ::...:"<<"\n";
cout << "::    :: :::::::: :: :  : :: ::      ::    ::   :: ::   ::     :::"<<"\n";
cout << ":::::::: ::    :: ::  ::  :: ::::::  ::::::::    ::     :::::: :: ::"<<"\n";
}

void PrintWin(){
	cout << "              ::    :    :: :::::::: :::   ::"<<"\n";
	cout << "               ::  : :  ::     ::    :: :  ::"<<"\n";
	cout << "                :::   :::      ::    ::  : ::"<<"\n";
	cout << "                 ::   ::    :::::::: ::   :::"<<"\n";
}

void PrintDraw(){
	cout << "              ::::::::  :::::: :::::::: ::    :    ::"<<"\n";
	cout << "              ::      : ::...: ::    ::  ::  : :  ::"<<"\n";
	cout << "              ::      : :::    ::::::::   :::  :::"<<"\n";
	cout << "              ::::::::  :: ::  ::    ::    ::	::"<<"\n";
}

void PrintScore(int &score){
	cout  << score<<"\n";
}

void PrintEnter(){
	cout  <<"\n\n\n\n";
}

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
	
	for (int i = 0; i < word.length(); i++){
		
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

int score(string word, string guessed){
	int score = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (guessed.find(word[i]) != -1)
			score++;
	}
	return score;
}


int main(){
	srand(time(0));
	string wordToGuess;
	int worduse;
	do{	
		v.clear();
		Player P;
	 	string key;
		string select;
	 	do{
		 
		system("cls");
		 
		PrintMessage("Press a number to select option.");
		cout << "\n";	
		cout << "                |    1 for One Player.   |" << endl;
		cout << "                |    2 for Two Player.   |" << endl;
		cout << "                |    3 Exit.             |" << endl;
		cout << "\n";
		cout <<"================================================================="<<"\n";
		cout <<">";
		        
		getline(cin,key);
		
		}while(key !="1" and key!="2" and key!="3");
		if(key == "3") break;
		
		do{
		
		system("cls");
		PrintMessage("Press a number to select category.");
		cout << "\n";	
		cout << "                |    1 Normal Words      |" << endl;
		cout << "                |    2 Marvel            |" << endl;
		cout << "                |    3 DC                |" << endl;
		cout << "                |    4 BNK48             |" << endl;
		cout << "                |    5 Brand             |" << endl;
		cout << "\n";
		cout <<"================================================================="<<"\n";
		cout <<">";
		
		
		getline(cin,select);
		
		}while(select!="1" and select!="2" and select!="3" and select!="4" and select!="5");
		
		if(select == "1") wordToGuess = LoadRandomWord("words.txt");
		else if(select == "2") wordToGuess = LoadRandomWord("marvel.txt");
		else if(select == "3") wordToGuess = LoadRandomWord("DC.txt");
		else if(select == "4") wordToGuess = LoadRandomWord("BNK48.txt");
		else if(select == "5")wordToGuess = LoadRandomWord("brand.txt");
		else cout << "Invalid Input.";
		
		if(key == "1"){ 
		    P.tries = 0;
	 		P.win = false;
			P.guesses = "\0";
			P.score =0;
 		 	char t[100];//One Player
 		 	int space=0;
 		 	for (int i = 0; i < wordToGuess.length(); i++)
			{
				if(wordToGuess[i]==' ') P.guesses+=" ";
				space++;
				
			}
			do{
				
				system("cls");
			
				PrintMessage("HANGMAN");
				sprintf(t,"%d",P.score);
				PrintMessage("Score",false);
				PrintMessage(t,false);
				DrawHangman(P.tries);
				PrintMessage("GUESS THE WORD");
				P.win = PrintWordAndCheckWin(wordToGuess,P.guesses);
				
				PrintAvailableLetters(P.guesses);
			
				if(P.win) break;
				//PrintMessage(wordToGuess);
				

				string x;
				cout << ">"; 
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
				PrintMessage("THE WORD IS");
				PrintMessage(wordToGuess);
				PrintEnter();
				cout << "Press Enter to go back Menu";
				getchar();
			}else{
				system("cls");
				PrintEnter();
				PrintOver();
				PrintEnter();
				PrintMessage("THE WORD IS");
				PrintMessage(wordToGuess);
				PrintEnter();
				cout << "Press Enter to go back Menu";
				getchar();
			}
		}else if(key == "3"){
			break;
			system("pause");
		}else if(key == "2"){
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
					PrintMessage("HANGMAN");
					sprintf(t1,"%d",P1.score);
					PrintMessage("Score",false);
					PrintMessage(t1,false);
					DrawHangman(P1.tries);
					PrintMessage("1");
					
					
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
					
					//PrintMessage(wordToGuess);
					string x;
					cout << ">"; 
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
					PrintMessage("HANGMAN");
					sprintf(t2,"%d",P2.score);
					PrintMessage("Score",false);
					PrintMessage(t2,false);
					DrawHangman(P2.tries);
					PrintMessage("2");
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
					cout << ">"; 
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
				PrintMessage("THE WORD IS");
				PrintMessage(wordToGuess,false);
				PrintEnter();
				cout << "Press Enter to go back Menu";
				getchar();
		}else if(P2.win){
				system("cls");
				PrintMessage("player 2");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS");
				PrintMessage(wordToGuess,false);
				PrintEnter();
				cout << "Press Enter to go back Menu";
				getchar();
		}else if(P1.score > P2.score){
				system("cls");
				PrintMessage("player 2");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS");
				PrintMessage(wordToGuess,false);
				PrintEnter();
				cout << "Press Enter to go back Menu";
				getchar();
		}else if(P1.score < P2.score){
				
				system("cls");
				PrintMessage("player 1");
				PrintEnter();
				PrintWin();
				PrintEnter();
				PrintMessage("THE WORD IS");
				PrintMessage(wordToGuess,false);
				PrintEnter();
				cout << "Press Enter to go back Menu";
				getchar();
			
		}else if(P1.score == P2.score){
				system("cls");
				PrintEnter();
				PrintDraw();
				PrintEnter();
				PrintMessage("THE WORD IS");
				PrintMessage(wordToGuess);
				PrintEnter();
				cout << "Press Enter to go back Menu";
				getchar();
		}
		}
	}while(true);
	
		} 

