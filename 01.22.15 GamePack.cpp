/*	Made by Peter lam
 	Starting Date: 01.07.15 - Finished 01.22.15
 	Program: Dev C++ 5.7.1
 	Purpose: Game pack with Wordjumble, MazeGame and Tic-Tac-Toe
	------------------------ 
	Data Dictionary:
	
		char mainopt		..................	used to nagivate main menu screen
		string	userenter	..................	used to recieve value from user and change to only the first letter
		
							Maze Game Variables
		int i				..................	holds a number for array level1[i][] to output the level
		int j				..................	holds a number for array level1[[][j] to output the level
		int opt				..................	holds information were the user wants to go form, menu screen
		int move			..................	gets informaiton where player wantrs to move
		int mine			..................	used to generate 15 mines on the map		
		mine1				..................	used to generate a random number to creat the first number in invisblemine[1] to place a mine
		mine2				..................	used to generate a random number to creat the second number in invisblemine[][1] to place a mine
		char1				..................	movement placemnt
		char2	 			..................	movement placemnt
		hitamine 			..................	if user hits a mine
		playagain 			..................	used to check if player wants to play again
	
							Word Jumble Variables	
		int k				..................	used for a for loop that keeps adding a new letter onto the jumbled word
		int l 				..................	used for string manipulation to make user input all lowercase
		int m				..................	used to find how many correct letter in a guess
		int opt2			..................	holds information were the user wants to go from, menu screen of wordjumble
		int whatword		..................	used to gen a number thaat picks what word to jumble from the array "wordbank"
		int guesses			..................	holds how many guesses the user has left		
		int userguess		..................	holds the the users guess of the jubmled word
		string word			..................  used to hold the word that was chosen to jumble
		string jumbledword	..................  holds the jumbled word
		int level			..................	used to determine how many levels were completed by guesses correctly
		int wordjumblelives	..................	used to hold how many lives the user has
		int newlevel		..................	used to determine when to generate a new word when the user runs out of guesses or correctly guesses
		int levelcounter	..................	used to run the game 10 times
		int len				..................	determines the length of the generated word
		int letterscorrect	..................	hold how many letters the user guess correctly in a word
		int randint			..................	generates a random number from the length of the word to jumble it and put it into the jumbled word
		char exit			..................	holds information where the user wants to go after completing wordjumble
		
							Tic-Tac-Toe Variables
		int opt3			..................	holds info on menu selection
		char square			..................	2-D array for gameboard
		char exit2 			..................	holds info on if player wants to exit
		char num1 			..................  holds info on the number that is being picked
		int start 			..................	generates a random number 
		string player		..................  hold information whether the second player is a computer or a real person
		char playerxo 		..................	holds information whether the input is an X or O onto the gameboard
		int n				..................	used as a counter to check for the first [] in the game board array to outp7ut available places on the game board.
		int o 				..................	used as a counter to check for the second [] in the game board array to outp7ut available places on the game board.
		char playagain		..................	use to hold information whether user wants to play again or not
		int owin			.................. 	use to hold information whether O has won, if 1 then O wins
		int xwin			..................	use to hold information whether X has won, if 1 then X wins   	
		int tie				..................	use to hold information whether a tie has occured , if 1 then tie 	
		int start			..................	used hold a number either 1 or 2, to determine which player starts
		char num1			..................  use to hold information on what the player wants to input onto the game board	
*/	 

// including libraries 

#include <iostream> // include masic libraries
#include <iomanip> // setprecision
#include <math.h> // math 
#include <ctype.h> // string manipulation
#include <windows.h> // sleep funciton
#include <stdlib.h> // srand
#include <time.h> // time 
#include <cctype> // used to check if variable is a digit
// calling baisc output values 
using namespace std;

// ----- Mazegame arrays, functions, and global variables ------

// gamboard array
char level [10][10]= {};
char invisiblemine [10][10] = {};

// declaring functions
void mazegamemenu (void);
void firstlevel (void);
void howtoplay(void);
void map1 (void);
void genmines(void);
void canimove(char &move, int& hitamine);

// declaring global var
int char1=9,char2=9,lives=3;

// ----- Wordjumble array and functions ------

// 1-d array for for the 20 possible words that can be jumbled
string wordbank [20] = {"cat", "balloon", "jumble", "dog", "run", "fun","close","mom","wow","sad","happy","joke","poke","hop","roar","star","car","ran","cool","sun"};
// menu screen for word jumble
void jumblemenu (void);
// the main function for wordjumble
void wordjumble (void);
// how to play for wordjumble
void howtoplaywordjumble (void);
// takes in a word from the wordbank array and jumbles it
void jumblemyword (string& jumbledword, string& word, int& len);

// ----- Tic Tac Toe array, functions and global variables ------

// declaring global variables 
string player;
char playerxo;


// declaring arrays
// gamboard array
char square [4][4]= {{'0','0','0','0'},{'0','1','2','3'},{'0','4','5','6'},{'0','7','8','9'}};


// lines for a win. 0 is nothing.  1 is top hirzontal line, 2 is 2nd, 3 is rd. 4 is left most vertical, 5 is middle, 5 is right.
// 7 is diagonal from top left to bottom right, 8 is top right to bottom left
char winline [9];
/* 	1 ---> 	|		|		|		*			*
	2 --->	| 4		| 5		|6		 * 7	   * 8
	3 ---> 	V		V		V		  *		  *
*/

// declaring funntions
void tictactoemenu(void); // menu screen for tic=tac=toe
void rules(void); // output rules
void gameboard(void); // output gameboard
void twoplayer(void); // output two player game
void oneplayer(void); // output one player game
void playerinput(char num1); // takes value from player and inputs X or O into gamebaord
void availableplaces(void); // looks for available places on gameboard and outputs the values
int wincheckx (void); // check if X wins
int winchecko (void); // check if O wins
int tiecheck (void); // check if tie


main()
{	
	// declaring var
	char mainopt;
	string userenter;
	// clear screen
	system("cls");

	// change the colour of the text and background
	system ("color 4f");
	do
	{
		//clear screen
		system("cls");
		cout << "\n\n\t\t  _____                        _____           _    \n";
		cout << "\t\t / ____|                      |  __ \\         | |   \n";
		cout << "\t\t| |  __  __ _ _ __ ___   ___  | |__) |_ _  ___| | __\n";
		cout << "\t\t| | |_ |/ _` | '_ ` _ \\ / _ \\ |  ___/ _` |/ __| |/ /\n";
		cout << "\t\t| |__| | (_| | | | | | |  __/ | |  | (_| | (__|   < \n";
		cout << "\t\t \\_____|\\__,_|_| |_| |_|\\___| |_|   \\__,_|\\___|_|\\_\\\n";
	
		cout << "\n\n--------------------------------------------------------------------------------";
		cout << "\t\t\t";
	 	cout << "\n\t\t\t\t    == Menu ==";
	 	cout << "\n\t\t\t1 ...................... The Maze Game";  
		cout << "\n\t\t\t2 ...................... Word Jumble";
		cout << "\n\t\t\t3 ...................... Tic-Tac-Toe";
		cout << "\n\t\t\t4 ...................... Exit";   
		
		// run this once, if the user inputs something not equal to 1,2,3 or 4; run again
	
			cout << "\n\n\t\t\t    Please select an option: ";
			cin >> userenter;
			mainopt =userenter[0];
			
			// options
			switch (mainopt)
			{
				// if the user is enters 1, go to maze game
				case ('1') :
				// clear screen
				system("cls");
				mazegamemenu();
				break;
				
				// if user enters 2, go to word jumble
				case ('2'):
				// clear screen
				system("cls");
				jumblemenu();	
				break;
				
				// if user enters 3, go to tic tac toe
				case ('3'):
				// clear screen
				system("cls");
				tictactoemenu();
				break;
				
				// if user enters 4, exit game
				case ('4'):
				cout<<"\n\t\t\t\t Have a nice day!";
				break;		
					
				// else say invalid
				default:
				cout << "\t\t\tInvalid Answer, Please Try again";
				// add delay
				Sleep(1000);
				break;
			}
	
		}while ( mainopt!=1 and mainopt!=2 and mainopt!=3 and mainopt!=4);	
	
}
void mazegamemenu (void)
{
	// declaring var
	int opt;
	
	// change the colour of the text and background
	system ("color 3f");
	cout << "\n\n     _____ _            __  __                  ____                      \n";
	cout << "    |_   _| |__   ___  |  \\/  | __ _ _______   / ___| __ _ _ __ ___   ___ \n";
	cout << "      | | | '_ \\ / _ \\ | |\\/| |/ _` |_  / _ \\ | |  _ / _` | '_ ` _ \\ / _ \\\n";
	cout << "      | | | | | |  __/ | |  | | (_| |/ /  __/ | |_| | (_| | | | | | |  __/	";
	cout << "      |_| |_| |_|\\___| |_|  |_|\\__,_/___\\___|  \\____|\\__,_|_| |_| |_|\\___|\n";
	cout << "\n\n--------------------------------------------------------------------------------";
	cout << "\t\t\t";
	system ("pause");
 	cout << "\n\t\t\t\t    == Menu ==";
 	cout << "\n\t\t\t1 ...................... Main Menu";  
	cout << "\n\t\t\t2 ...................... Start";
	cout << "\n\t\t\t3 ...................... How to Play";
	cout << "\n\t\t\t4 ...................... Exit";   
	
	// run this once, if the user inputs something not equal to 1,2,3 or 4; run again
	do
	{
		cout << "\n\n\t\t\t    Please select an option: ";
		cin >> opt;
		
		// options
		switch (opt)
		{
			// if the user is enters 1, return to main menu
			case (1) :
			main();
			break;
			
			// if user enters 2, start game
			case (2):
			// clear screen
			system("cls");
			// output game level
			firstlevel();				
			break;
			
			// if user enters 3, show how to play
			case (3):
			howtoplay();	
			break;
			
			// if user enters 4, exit game
			case (4):
			break;		
				
			// else say invalid
			default:
			cout << "\t\t\tInvalid Answer, Please Try again";
			break;
		}

	}while (opt!=1 and opt!=2 and opt!=3 and opt!=4);



}

// how to play the game
void howtoplay(void)
{
	// clear screen
	system("cls");
	cout << "\t\t\t\t=== How To Play ====\n\n\n";
	cout << "\t\t\t- You are the smiley face";
	cout << "\n\t\t\t- The goal is to get to the heart";
	cout << "\n\t\t\t- Uses 8,6,4,2 to move";
	cout << "\n\t\t\t- Do not hit the mines or you will lose a life";
	cout << "\n\t\t\t- You have 3 lives";
	cout << "\n\n--------------------------------------------------------------------------------\n\t\t\t";
	system("pause");
	system ("cls");
	main();
}
// creating the first map for the first level
void map (void)
{	
	// declaring var
	int i,j; 
	
	// output the game map
	for (i=0;i<10;i++)
	{
		
		for (j=0;j<10;j++)
		{
			cout  << level[i][j] << "\t";
		}
		
		cout << "\n";
	}
	
	cout << "--------------------------------------------------------------------------------";
	cout << "\t\t\t\t\t\t\t\t\tLives: " << lives<< "\n";
}

void genmines()
{
	
	// declaring var
	int mine,mine1,mine2,i,j;
	
	// reseting time
	srand (time(NULL));		

	// loops and clear he whole 2d array of old mines for a new game
	for (i=0;i<10;i++)
	{
		
		for (j=0;j<10;j++)
		{	
			invisiblemine[i][j] = ' ';
		}
	}
	
	// loops 15 times
	for (mine=0;mine<=15;mine++)
	{
		// generate random int to place the mine at least once, and re generate the numbers if the mine is at [0][0] or on the corners of the map to prevent blocking of the player
		do
		{	

			// generate a random number between 1-2 to decide who starts
			mine1 = rand() % 10;
			mine2 = rand() % 10;	
		} while (mine1==0 and mine2==0 or mine1==8 and mine2==9 or mine1==9 and mine2==8 or mine1==0 and mine2==1 or mine1==1 and mine2==0);
		// places a mine at the generated spot
		invisiblemine[mine1][mine2] = 'X';
	}
}

void canimove(char move, int&  hitamine)
{
	// move user inputs 8 check if user can move up
	if (move==8)
	{
		// if the player is on the top of the map, dont move and output saying that you reached the edge of the map
		if (char1==0)
		{
			// clear screen
			system ("cls");
			//output map
			map();	
			cout << "You reached the top of the map! Please pick a different option. ";
			// add a delay
			Sleep(1000);
			
		}
		// if not of the bottom, run normally and move
		else
		{
			// deletes existing position of character
			level[char1][char2] = ' ';
			// sets new position
			char1 = char1 - 1;
			// inputs new position
			level[char1][char2] = 1;
			// clear screen
			system ("cls");
			//output map
			map();	
		}
	}
	
	// move user inputs 2 check if user can move down
	else if (move==2)
	{
		// if the player is on the top of the map, dont move and output saying that you reached the edge of the map
		if (char1==9)
		{
			// clear screen
			system ("cls");
			//output map
			map();	
			cout << "You reached the bottom of the map! Please pick a different option. ";
			// add a delay
			Sleep(1000);
			
		}
		
		// if not of the bottom, run normally and move
		else
		{
			// deletes existing position of character
			level[char1][char2] = ' ';
			// sets new position
			char1 = char1 + 1;
			// inputs new position
			level[char1][char2] = 1;
			// clear screen
			system ("cls");
			//output map
			map();	
		}
	}
	
	// move user inputs 4 check if user can move left
	else if (move==4)
	{
		// if the player is on the top of the map, dont move and output saying that you reached the edge of the map
		if (char2==0)
		{
			// clear screen
			system ("cls");
			//output map
			map();	
			cout << "You reached the edge of the map! Please pick a different option. ";
			// add a delay
			Sleep(1000);
			
		}
		// if not of the edge, run normally and move
		else
		{
			// deletes existing position of character
			level[char1][char2] = ' ';
			// sets new position
			char2 = char2 - 1;
			// inputs new position
			level[char1][char2] = 1;
			// clear screen
			system ("cls");
			//output map
			map();	
		}

	}
	
	// move user inputs 6 check if user can move right
	else if (move==6)
	{
		// if the player is on the top of the map, dont move and output saying that you reached the edge of the map
		if (char2==9)
		{
			// clear screen
			system ("cls");
			//output map
			map();	
			cout << "You reached the edge of the map! Please pick a different option. ";
			// add a delay
			Sleep(1000);
			
		}
		// if not of the edge, run normally and move
		else
		{
			// deletes existing position of character
			level[char1][char2] = ' ';
			// sets new position
			char2 = char2 + 1;
			// inputs new position
			level[char1][char2] = 1;
			// clear screen
			system ("cls");
			//output map
			map();	
		}
	}
	
	// if the user hits a mine, display saying you htia mine
	if (invisiblemine[char1][char2] == 'X')
	{
		cout << "\n\t\tYou hit a mine! :(";
		// add a delay
		Sleep(1000);
		// deletes existing position of character
		level[char1][char2] = ' ';
		// sets new position
		char1 = 9;
		char2 = 9;
		// inputs new position
		level[char1][char2] = 1;
		hitamine=1;		
	} 
	
}
// first level of the game
void firstlevel (void)
{	
	char1=9,char2=9,lives=3;
	// places the player on the board
	level [9][9] = 1;
	level [0][0] = 3;
	// calling for fucniton, create the mines
	genmines();
	// declaring lives above so do while does not reset lives to 3
	int done = 0;
	//declaring var
	char playagain;
	
	// do while lives is not 0 or the player has won
	do
	{
		// clear screen
		system ("cls");
		// output map
		map();
		// declaring var
		int move,hitamine=0;
		// run at least once and keep looping if user does not answer 8,6,4 or 2
		do
		{
			// ask user to input where they want to move and take the var from user
			cout << "Enter a key on the numpad (8-Up, 6-Right, 4-Left, 2-Down): ";
			cin >> move;
			
			if (move !=8 and move!=6 and move!=4 and move!=2)
			{
				system("cls");
				map();
				cout << "Invalid answer, Please try again :(\n";
			}
			
		} while (move!=8 and move!=6 and move!=4 and move!=2);
		
		canimove(move,hitamine);
		
		if (hitamine==1)
		{
			// take away a life
			lives=lives-1;
			// clear screen
			system("cls");
			// output map
			map();
		}
		
		//if player has won, ask user if they want to play again
		if (level[0][0]==1)
		{
			// set done to 1
			done = 1;
			
			cout << "You have won! Would you like to return to the main menu? (Y/N) ";
			cin >> playagain;
		
			// error check for lower case lettering by turning everything to caps
			playagain = toupper(playagain);
			
			// error checking if player does not enter Y or N
			while (playagain != 'Y' and playagain != 'N')
			{		
			cout << "Invalid Answer! Would you like to return to the main menu? (Y/N) ";
			cin >> playagain;
			
			// error check for lower case lettering by turning everything to caps
			playagain = toupper(playagain);			
			}	
			
			// if user inputs Y then exit program, if N restart program, else loop
			if (playagain=='Y')
			{
				// reset position
				level[0][0]= ' ';
				char1 = 9;
				char2 = 9;			
				// clear screen and return to main program
				system("cls");
				main();	
			}
		
			else if (playagain=='N')
			{
				// reset position
				level[0][0]= ' ';
				char1 = 9;
				char2 = 9;	
				// exit program	
			}			
		}
		
		else if (lives == 0)
		{
			// set done to 1
			done = 1;
						
			cout << "You lost! Would you like to return to the main menu? (Y/N) ";
			cin >> playagain;
			
			// error check for lower case lettering by turning everything to caps
			playagain = toupper(playagain);
					
			// error checking
			while (playagain != 'Y' and playagain != 'N')
			{		
			cout << "Invalid Answer! Would you like to return to the main menu? (Y/N) ";
			cin >> playagain;
			
			// error check for lower case lettering by turning everything to caps
			playagain = toupper(playagain);			
			}	
			
			// if user inputs Y then exit program, if N restart program, else loop
			if (playagain=='Y')
			{	
				// reset position
				level[0][0]= ' ';
				char1 = 9;
				char2 = 9;
				// clear screen and return to main program
				system("cls");
				main();	
			}
		
			else if (playagain=='N')
			{
				// exit program	
			}				
		}
	
	}while (lives!=0 and level[0][0]!=1);



}

//  Word Jumble Game

// word jumble menu screen
void jumblemenu(void)
{
	// change the colour of the text and background
	system ("color 9f");
	// declaring var
	int opt2;
	
	//output screen for word jumble 
	cout << "\n";
	cout << "	__        __            _       _                 _     _      \n";
	cout << "	\\ \\      / /__  _ __ __| |     | |_   _ _ __ ___ | |__ | | ___ \n";
	cout << "	 \\ \\ /\\ / / _ \\| '__/ _` |  _  | | | | | '_ ` _ \\| '_ \\| |/ _ \\\n";
	cout << "	  \\ V  V / (_) | | | (_| | | |_| | |_| | | | | | | |_) | |  __/\n";
	cout << "	   \\_/\\_/ \\___/|_|  \\__,_|  \\___/ \\__,_|_| |_| |_|_.__/|_|\\___|\n";
	cout << "\n\n--------------------------------------------------------------------------------";
	cout << "\t\t\t";
	system ("pause");
 	cout << "\n\t\t\t\t    == Menu ==";
 	cout << "\n\t\t\t1 ...................... Main Menu";  
	cout << "\n\t\t\t2 ...................... Start";
	cout << "\n\t\t\t3 ...................... How to Play";
	cout << "\n\t\t\t4 ...................... Exit";   
	
	// run this once, if the user inputs something not equal to 1,2 or 3; run again
	do
	{
		cout << "\n\n\t\t\t    Please select an option: ";
		cin >> opt2;
		
		// options
		switch (opt2)
		{
			// if the user is enters 1, return to the main menu
			case (1) :
			main();
			break;
			
			// if user enters 2, start game
			case (2):
			// clear screen
			system("cls");
			// output game level
			wordjumble();
			break;
			
			// if user enters 3, show how to play
			case (3):
			howtoplaywordjumble();
			break;
			
			// if user enters 4, exit game			
			case (4):
			break;
			
			// else say invalid and loop again
			default:
			cout << "\t\t\tInvalid Answer, Please Try again";
			break;
		}

	}while (opt2!=1 and opt2!=2 and opt2!=3 and opt2!=4);
                                                           
}
// how to play for wordjumble
void howtoplaywordjumble (void)
{
	// clear screen
	system("cls");
	// output rules
	cout << "\t\t\t\t=== How To Play ====\n\n\n";
	cout << "\t\t\t- Unjumble the given word";
	cout << "\n\t\t\t- There is a list of 20 possible words";
	cout << "\n\t\t\t- You are given 10 guess at the start";
	cout << "\n\t\t\t- For every word you get right,\n\t\t\t  you will have one less guess the next round";
	cout << "\n\t\t\t- You have 3 lives";
	cout << "\n\t\t\t- There are 10 levels";
	cout << "\n\t\t\t- If you run out of lives you lose!";
	cout << "\n\n--------------------------------------------------------------------------------\n\t\t\t";
	// press anykey to continue
	system("pause");
	// clear screen
	system ("cls");
	// go back to wordjumble menu
	jumblemenu();
	
}
// the main function for wordjumble
void wordjumble (void)
{	
	//declaring var
	int guesses=10,l,m,level=0, wordjumblelives=3, newlevel=0,levelcounter,len,letterscorrect=0;
	string jumbledword,word,userguess;
	char exit;
	
	// keep looping the game until the game has been played 10 times
	for (levelcounter=1; levelcounter<=10; levelcounter++)
	{
		// set "newlevel" to 0, so when it is 1 it will exit the loop and gen a new word
		newlevel=0;	
		//clear screen
		system ("cls");
		// call funciton to pick a word, jumble it and send the jumbled and non jumbled word back	
		jumblemyword(jumbledword,word,len);
		
		// run at least once and keep looping until the user either loses all of their guesses or guessed correct
		do
		{
			// clear screen
			system ("cls");
			// output game 	
			cout << "\t\t\t\tCurrent Level: " << levelcounter;
			cout << "\n\t\t\t   Number of guesses left: " << guesses;
			cout << "\n\t\t\t   Numbers of letters correct: " << letterscorrect;
			cout << "\n\t\t\t        Number of Lives: " << wordjumblelives;
			cout << "\n\n\t\t\t   Your jumbled word is: " << jumbledword;
			cout << "\n\n\t\t\t\t  Your guess: ";
			cin >> userguess;
			
			// resets j to 0 so when the function loops, it can set all words to lower again
			l = 0;
			
			// error checking, makes the inputed word to lower case
			while (userguess[l])
			{
				userguess[l] = tolower(userguess[l]);
				l++;
			}
			
			// if the guess is equal to the word picked then output a congrats screen
			if (userguess==word)
			{
				cout << "\n\t\t\tYou guessed the word correct! Congrats!";		
				// sets variable level to add 1 as you finish a level
				level = level + 1;
				// resets guesses to 10 and subract by the variable level. Level gets larger as the game goes on
				guesses = 10 - level;
				newlevel=1;	
			}
			
			// if it is not the same as the word, then output incorrect, take away 1 guess
			else
			{
				cout << "\t\t\t   Incorrect :( Try Again!\n";
				// set correct letters to 0
				letterscorrect = 0 ;
				// output how many correct letters the user guessed by comparing length of both words and checking each letter
				for(m = 0 ; m < len ; m++)
			   	{
			   		if (userguess[m]== word[m])
					{
			     		letterscorrect ++ ;   
			  	  	} 
				} 
				
				// take away a guess
				guesses = guesses -1;
				// add a delay
				Sleep(1000);
				// if the user runs out of guesses, rake away a life
				if (guesses == 0)
				{
					cout << "\n\t\t\t\tYou lost a life!";
					// takes away a life
					wordjumblelives = wordjumblelives-1;
					// add a delay
					Sleep(1000);
					// resets guesses to 10 and subract by the variable level. Level gets larger as the game goes on
					guesses = 10 - level;
					newlevel=1;				
				}
				
				// if user runs out of lives, set levelcounter to 10 so it ends the game
				if (wordjumblelives == 0)
				{
		 			levelcounter = 10;
				}	
			}	
		}while (newlevel == 0);
	}
	
	// if user runs out of lives output end screen
	if (wordjumblelives ==0)
	{
		cout << "\nYou have lost the game! Would you like you like to go back to the menu? (Y/N)";
		cin >> exit;
		// error check for lower case lettering by turning everything to caps
		exit = toupper(exit);
				
		// error checking
		while (exit != 'Y' and exit != 'N')
		{		
		cout << "Invalid Answer! Would you like you like to go back to the menu? (Y/N) ";
		cin >> exit;
		// error check for lower case lettering by turning everything to caps
		exit = toupper(exit);		
		}	
		
		// if user inputs Y then exit program, if N restart program, else loop
		if (exit=='Y')
		{	
			// clear screen and return to main program
			system("cls");
			main();	
		}
	
		else if (exit=='N')
		{
			// exit program	
		}		
	}
	
	// else output wining screen
	else
	{
		cout << "\nYou have won the game! Would you like you like to go back to the menu? (Y/N)";
		cin >> exit;
		// error check for lower case lettering by turning everything to caps
		exit = toupper(exit);
				
		// error checking
		while (exit != 'Y' and exit != 'N')
		{		
		cout << "Invalid Answer! Would you like you like to go back to the menu? (Y/N) ";
		cin >> exit;
		// error check for lower case lettering by turning everything to caps
		exit = toupper(exit);		
		}	
		
		// if user inputs Y then exit program, if N restart program, else loop
		if (exit=='Y')
		{	
			// clear screen and return to main program
			system("cls");
			main();	
		}
	
		else if (exit=='N')
		{
			// exit program	
		}		
	}


}

void jumblemyword (string& jumbledword, string& word, int& len)
{
	// declaring var
	int	whatword,randint,k;
	string theword;
	// reseting time
	srand (time(NULL));
	// generate a random number between 0-9 to pick the word
	whatword = rand() % 20;
	cout << whatword;
	// jumble the word at least once, and keep jumbling if the word is the same as the original
	do
	{	
	
		// sets the variable "word" to the variable "theword" which is set to a word that was randomly chosen in the array
		// this is done because "theword" gets later erased
		word = theword = wordbank[whatword];
	

		// sets jumbled word to nothing
		jumbledword = "";	
		// determines length of the original word
		len = theword.length();
		
		//jumbles word
		for (k=0;k<len;k++)
		{
			// generates a random number from the length of the word to jumble it
			randint = rand() % (len-k);
			
			jumbledword+=theword[randint];
			theword.erase(randint,1);
		}		
	}while (jumbledword==word);
	

}

// Tic Tac Toe

// tic tac toe menu
void tictactoemenu(void)
{	
	// resets gameboard array for replay 
	square [1][1] = '1';		
	square [1][2] = '2';
	square [1][3] = '3';
	square [2][1] = '4';		
	square [2][2] = '5';
	square [2][3] = '6';
	square [3][1] = '7';
	square [3][2] = '8';
	square [3][3] = '9';
	// resets win lines so replay
	winline [1]	= ' ';
	winline [2]	= ' ';
	winline [3]	= ' ';
	winline [4]	= ' ';
	winline [5]	= ' ';
	winline [6]	= ' ';
	winline [7]	= ' ';
	winline [8]	= ' ';
	
	// change the colour of the text and background
	system ("color 3f");
	
	// declaring vars
	int opt3;
	char exit2;
	
	cout << "\t\t      ======= Welcome to Tic-Tac-Toe =======\n\n";
	cout << "\t\t\t            |       |			\n";
	cout << "\t\t\t      --X-- | --X-- | --X--		\n";
	cout << "\t\t\t    ________|_______|_______	\n";
	cout << "\t\t\t            |       |			\n";
	cout << "\t\t\t        O   |   O   |   X		\n";					
	cout << "\t\t\t    ________|_______|_______	\n";
	cout << "\t\t\t            |       |			\n";
	cout << "\t\t\t            |       |   O		\n";
	cout << "\t\t\t            |       |			\n";
	
	cout << "\n\t\t\t\t    == Menu ==";
	cout << "\n\t\t\t1 ...................... Main Menu";
	cout << "\n\t\t\t2 ...................... Rules";
	cout << "\n\t\t\t3 ...................... One Player";
	cout << "\n\t\t\t4 ...................... Two Player";
	cout << "\n\t\t\t5 ...................... Exit";
	cout << "\n\n\t\t\t    Please select an option: ";
	cin >> opt3;
	// if user enters 1, return to main menu
	if (opt3==1)
	{
		system ("cls");
		main();
	}
	// if user enters 2, clear screen and run rules function
	else if (opt3==2)
	{
		system ("cls");
		rules();
	}
	
	// if user enters 3, clear screen and run oneplayer function
	else if (opt3==3)
	{
		system("cls");
		oneplayer();
	}
	
	// if user enters 4, clear screen and run twoplayer function	
	else if (opt3==4)
	{
		system("cls");
		twoplayer();
	}

	// if user enters 5, ask if user wants to exit	
	else if (opt3==5)
	{
		// space formatting
		cout << "\n";
		
		// run if at least once, and keep running if user does not input correctly
		do
		{
			// ask user if they want to exit and recieve an input
			cout << "\t\t\tAre you sure you want to exit? (Y/N) ";
			cin >> exit2;
			
			// error check for lower case lettering by turnnign everythign to caps
			exit2 = toupper(exit2);
			
			// if user inputs Y then exit program, if N restart program, else loop
			if (exit2=='Y')
			{
				// exit program		
			}
	
			else if (exit2=='N')
			{
				// clear screen and return to main program
				system("cls");
				main();
			}
			
		} while (exit2!='Y' and exit2!='N');
	}	

	// if user inputs anything else, output invalid and ask to input again
	else
	{
		cout << "\n";
		
		// output saying invalid answer and keep looping if user does not input valid answer
		do
		{
			cout << opt3;
			cout << "\t\t\tInvalid Input - Please try again: ";
			cin >> opt3;
			
			// if user enters 1, return to main menu
			if (opt3==1)
			{
				system ("cls");
				main();
			}
			// if user enters 2, clear screen and run rules function
			if (opt3==2)
			{
				system ("cls");
				rules();
			}
			
			// if user enters 3, clear screen and run oneplayer function
			else if (opt3==3)
			{
				system("cls");
				oneplayer();
			}
			
			// if user enters 4, clear screen and run twoplayer function	
			else if (opt3==4)
			{
				system("cls");
				twoplayer();
			}
		
			// if user enters 5, ask if user wants to exit	
			else if (opt3==5)
			{
				// space formatting
				cout << "\n";
				
				// run if at least once, and keep running if user does not input correctly
				do
				{
					// ask user if they want to exit and recieve an input
					cout << "\t\t\tAre you sure you want to exit? (Y/N) ";
					cin >> exit2;
					
					// error check for lower case lettering by turnnign everythign to caps
					exit2 = toupper(exit2);
					
					// if user inputs Y then exit program, if N restart program, else loop
					if (exit2=='Y')
					{
						// exit program	
					}
			
					else if (exit2=='N')
					{
						// clear screen and return to main program
						system("cls");
						main();
					}
					
				} while (exit2!='Y' and exit2!='N');	
			}
							
		} while (opt3!=1 and opt3!=2 and opt3!=3 and opt3!=4 and opt3!=5);
	}


}

// rules function
void rules(void)
{
	cout << "\n\t\t\t\t    == Rules ==";
	cout << "\n\t- X moves first.";
	cout << "\n\t- A piece may be placed on any empty space.";
	cout << "\n\t- A player wins by being the first to connect a line of friendly pieces\n\t  from one side or corner of the board to the other.";
	cout << "\n\t- The game ends when either one player wins or it is no longer possible\n\t  for a player to win (in which case the result is a draw).\n";
	cout << "\n\t\t\t";
	// allows user to input any key to continue
	system ("pause");
	// clear screen
	system ("cls");
	// call for main function, and output main screen again
	tictactoemenu();
}
// gameboard funciton
void gameboard(void)
{
	// output gameboard - winline is for a line to be created when the user wins, square is where the gameboard outputs X O or numbers
	
	cout << "\nPlayer 1: X\t\t\t\t\t\t\t     " << player << ": O\n";
	cout << "\t\t\t      " << winline[7] << " " << winline[4] << "   |   " << winline[5] << "   |   " << winline[6] << "  " << winline[8] << "  \n";
	
	cout << "\t\t\t     " << winline[1] << winline[1] << winline[1] << square[1][1] << winline[1] << winline[1] << winline[1] << "|";
	cout << winline[1] << winline[1] << winline[1] << square[1][2] << winline[1] << winline[1] << winline[1] << "|" << winline[1] << winline[1] << winline[1] << square[1][3];
	cout << winline[1] << winline[1] << winline[1] << "\n";
	
	cout << "\t\t\t    ________|_______|_______		\n";
	cout << "\t\t\t        " << winline[4] << "   | " << winline[7] << " " << winline[5] << " " << winline[8] << " |   " << winline[6] << "   \n";
	cout << "\t\t\t     " << winline[2] << winline[2] << winline[2] << square[2][1]  << winline[2] << winline[2] << winline[2] << "|";
	cout << winline[2] << winline[2] << winline[2] << square[2][2]  << winline[2] << winline[2] << winline[2] <<"|"  << winline[2] << winline[2] << winline[2] << square[2][3];
	cout << winline[2] << winline[2] << winline[2] << "\n";
						
	cout << "\t\t\t    ________|_______|_______		\n";
	cout << "\t\t\t        " << winline[4] << " " << winline[8] << " |   " << winline[5] << "   | " << winline[7] << " " << winline[6] << "   \n";
	cout << "\t\t\t     " << winline[3] << winline[3] << winline[3] << square[3][1]  << winline[3] << winline[3] << winline[3] << "|";
	cout << winline[3] << winline[3] << winline[3] << square[3][2]  << winline[3] << winline[3] << winline[3] << "|" << winline[3] << winline[3] << winline[3] << square[3][3];
	cout << winline[3] << winline[3] << winline[3] << "\n";
	cout << "\t\t\t      " << winline[8] << " " << winline[4] << "   |   " << winline[5] << "   |   " << winline[6] << " " << winline[7] << " \n";
}


void playerinput(char num1)
{
	// if player enters 1 then replace square[1][1] with X
	if (num1=='1')
	{
		// set 1 to X
		square[1][1] = playerxo;
	}
		
	// if player enters 2 then replace square[1][2] with X		
	else if (num1=='2')
	{
		// set 2 to X
		square[1][2] = playerxo;
	}
	
	// if player enters 3 then replace square[1][3] with X		
	else if (num1=='3')
	{
		// set 3 to X
		square[1][3] = playerxo;
	}		
	
	// if player enters 4 then replace square[2][1] with X		
	else if (num1=='4')
	{
		// set 4 to X
		square[2][1] = playerxo;
	}				
	
	// if player enters 5 then replace square[2][2] with X		
	else if (num1=='5')
	{
		// set 5 to X
		square [2][2] = playerxo;
	}
	
	// if player enters 6 then replace square[2][3] with X		
	else if (num1=='6')
	{
		// set 6 to X
		square [2][3] = playerxo;
	}
	
	// if player enters 7 then replace square[3][1] with X		
	else if (num1=='7')
	{
		// set 7 to X
		square [3][1] = playerxo;
	}
	
	// if player enters 8 then replace square[3][2] with X		
	else if (num1=='8')
	{
		// set 8 to X
		square [3][2] = playerxo;
	}		
	
	// if player enters 9 then replace square[3][3] with X		
	else if (num1=='9')
	{
		// set 9 to X
		square [3][3] = playerxo;
	}		
	
	
	// clear screen
	system ("cls");
	// call gameboard function	
	gameboard(); 
}
// function to display available places
void availableplaces(void)
{
	// declaring variables
	int n,o;
	// start i at 0, and as long as it is equal or less than 3, keep looping and add one to i. this makes square[i][j] of the array
	for (n=1; n<=3; n++)
	{
		// start j at 0, and as long as it is equal or less than 3, keep looping and add one to j. this makes square[i][j] of the array
		for (o=1;o<=3; o++)
		{
			// if the element in the gameboard is not an X or O then display the number
			if (square[n][o] != 'X' and square[n][o] != 'O')
			{
		 		cout << square[n][o] << " ";
		 	}
		}
		
	}
}
// checks if game has been won by x
int wincheckx (void)
{
/* 	1 ---> 	|		|		|		*			*
	2 --->	| 4		| 5		|6		 * 7	   * 8
	3 ---> 	V		V		V		  *		  *
*/
	// declaring variables
	int xwin=0;
	char playagain;
	
	// if first horizontal line is all X's then create a line crossing through it
	if (square[1][1]=='X' and square[1][2] == 'X' and square[1][3]=='X')
	{
		winline[1]= '-';
		xwin=1;
	}
	
	// if second horizontal line is all X's then create a line crossing through it
	else if (square[2][1]=='X' and square[2][2] == 'X' and square[2][3]=='X')
	{
		winline[2]= '-';
		xwin=1;
	}
	
	// if third horizontal line is all X's then create a line crossing through it
	else if (square[3][1]=='X' and square[3][2] == 'X' and square[3][3]=='X')
	{
		winline[3]= '-';
		xwin=1;
	}	
	
	// if first vertical line is all X's then create a line crossing through it
	else if (square[1][1]=='X' and square[2][1] == 'X' and square[3][1]=='X')
	{
		winline[4]= '-';
		xwin=1;
	}
	
	// if second vertical line is all X's then create a line crossing through it
	else if (square[1][2]=='X' and square[2][2] == 'X' and square[3][2]=='X')
	{
		winline[5]= '-';
		xwin=1;
	}	
	
	// if third vertical line is all X's then create a line crossing through it
	else if (square[1][3]=='X' and square[2][3] == 'X' and square[3][3]=='X')
	{
		winline[6]= '-';
		xwin=1;
	}
	
	// if first diagonal line is all X's then create a line crossing through it
	else if (square[1][1]=='X' and square[2][2] == 'X' and square[3][3]=='X')
	{
		winline[7]= '-';
		xwin=1;
	}
	
	// if second diagonal line is all X's then create a line crossing through it
	else if (square[1][3]=='X' and square[2][2] == 'X' and square[3][1]=='X')
	{
		winline[8]= '-';
		xwin=1;
	}
	
	// check to see if X wins
	if (xwin==1)
	{
		// clear screen
		system("cls");
		// output gamebard
		gameboard();
		// asks user if they want to play again
		cout << "\n\t\tPlayer 1 has won! Would you like to play again? (Y/N)";
		cin >> playagain;
		// make answer caps
		playagain = toupper(playagain);
		
		// error checking
		while (playagain != 'Y' and playagain != 'N') 
		{	
			cout <<"\n\t\t\tInvalid answer, please try again.";
			cin >> playagain;
			playagain = toupper(playagain);
			
		}
		
		// if user enters y, return to main menu
		if (playagain == 'Y')
		{
			system("cls");
			main();
		}
		
		// if user enters n, end program
		else if (playagain == 'N')
		{
			return (1);
		}
	}		
}
// checks if game has been won by x
int winchecko (void)
{
	// declaring variables
	int owin=0;
	char playagain;
	
/* 	1 ---> 	|		|		|		*			*
	2 --->	| 4		| 5		|6		 * 7	   * 8
	3 ---> 	V		V		V		  *		  *
*/
	// if first horizontal line is all X's then create a line crossing through it
	if (square[1][1]=='O' and square[1][2] == 'O' and square[1][3]=='O')
	{
		winline[1]= '-';
		owin=1;
	}
	
	// if second horizontal line is all X's then create a line crossing through it
	else if (square[2][1]=='O' and square[2][2] == 'O' and square[2][3]=='O')
	{
		winline[2]= '-';
		owin=1;
	}
	
	// if third horizontal line is all X's then create a line crossing through it
	else if (square[3][1]=='O' and square[3][2] == 'O' and square[3][3]=='O')
	{
		winline[3]= '-';
		owin=1;
	}	
	
	// if first vertical line is all X's then create a line crossing through it
	else if (square[1][1]=='O' and square[2][1] == 'O' and square[3][1]=='O')
	{
		winline[4]= '-';
		owin=1;
	}
	
	// if second vertical line is all X's then create a line crossing through it
	else if (square[1][2]=='O' and square[2][2] == 'O' and square[3][2]=='O')
	{
		winline[5]= '-';
		owin=1;
	}	
	
	// if third vertical line is all X's then create a line crossing through it
	else if (square[1][3]=='O' and square[2][3] == 'O' and square[3][3]=='O')
	{
		winline[6]= '-';
		owin=1;
	}
	
	// if first diagonal line is all X's then create a line crossing through it
	else if (square[1][1]=='O' and square[2][2] == 'O' and square[3][3]=='O')
	{
		winline[7]= '-';
		owin=1;
	}
	
	// if second diagonal line is all X's then create a line crossing through it
	else if (square[1][3]=='O' and square[2][2] == 'O' and square[3][1]=='O')
	{
		winline[8]= '-';
		owin=1;
	}
	
	// check to see if O wins
	if (owin==1)
	{
		// clear screen
		system("cls");
		// output gameboard
		gameboard();
		
		// asks user if they want to play again
		cout << "\n\t\t"<< player << " has won! Would you like to play again? (Y/N)";
		cin >> playagain;
		// make answer caps
		playagain = toupper(playagain);
		
		// error checking
		while (playagain != 'Y' and playagain != 'N') 
		{	
			cout <<"\n\t\t\tInvalid answer, please try again.";
			cin >> playagain;
			playagain = toupper(playagain);
			
		}
		
		// if user enters y, return to main menu
		if (playagain == 'Y')
		{
			system("cls");
			main();
		}
		
		// if user enters n, end program
		else if (playagain == 'N')
		{
		 return (1);
		}
	}
}

// check if game has been tied
int tiecheck (void)
{
	// declaring variables
	int tie=0;
	char playagain;
	
	// if all places on the gamebaord is taken, set tie to 1
	if (square [1][1]!='1' and square [1][2]!='2' and square [1][3]!='3' and square [2][1]!='4' and square [2][2]!='5' and square [2][3]!='6'
	and square [3][1]!='7' and square [3][2]!='8' and square [3][3]!='9')
	{
		tie = 1;
	}
	
	// check to see if it is tied
	if (tie==1)	
	{
		// asks user if they want to play again
		cout << "\n\t\tBoth Players have tied! Would you like to play again? (Y/N) ";
		cin >> playagain;
		playagain = toupper(playagain);
		
		// error checking
		while (playagain != 'Y' and playagain != 'N') 
		{	
			cout <<"\n\t\t\tInvalid answer, please try again.";
			cin >> playagain;
			playagain = toupper(playagain);
			
		}
		
		// if Y then return to main
		if (playagain == 'Y')
		{
			system("cls");
			main();
		}
		
		// if N then end program
		else if (playagain == 'N')
		{
			return (1);
		}
	}
}

// function for one player game
void oneplayer(void)
{
	// reseting time
	srand (time(NULL));
	
	// sets the second player as computer for naming purposes
	player = "Computer";
	
	// declaring variables
	int  start, tie=0, xwin=0,owin=0,computernum;
	char num1;
	
	// generate a random number between 1-2 to decide who starts
	start = rand() % 2 + 1;
	
	Sleep (250);			
	cout << "\t\t\t\tTic ";
	Sleep (250);			
	cout << "  Tac "; 
	Sleep (250);			
	cout << "  Toe ";
	Sleep (250);			
	cout << "\n\t\t\t  Give me an X give me an O ";		
	Sleep (500);			
	cout << "\n\t\t\t    Give me three in a row! ";	
	
	//output gameboard
	gameboard();
	
	// if start is 1 then player one starts
	if (start==1)
	{
		// ask user to pick a spot
		cout << "\nPlayer One starts! Please pick a spot from 1-9 --> ";
		cin >> num1;

	
		// if the user doesnt enter an available place, output an error
		while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
		num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
		{
			cout << "Invalid answer please pick a number between 1-9 --> ";
			cin >> num1;
		}
		// sets variable playerxo to X for playerinput function
		playerxo = 'X';
		// call for playerone function to input the number into the gameboard
		playerinput(num1);
		
		// as long as X win, O win or tie has not occured then keep looping 
		do
		{	
	
			// if X win , O win or tie has not occured then keep looping 
			if (tie!=1 and xwin!=1 and owin!=1)
			{	
				// generate random number from 1-9 for computer to pick a spot																								 
				// if the computer has generated a number that has already been taken, generate a new number 
				do	
				{		
					computernum = rand() % 9 + 1;
					// takes the generated number and sets it saat num1. This is done because num1 is a char and you cannot generate 1-9 using a char
					if (computernum == 1)
					{
						num1='1';
					}
					else if (computernum == 2)
					{
						num1='2';
					}	
					else if (computernum == 3)
					{
						num1='3';
					}
					else if (computernum == 4)
					{
						num1='4';
					}
					else if (computernum == 5)
					{
						num1='5';
					}
					else if (computernum == 6)
					{
						num1='6';
					}
					else if (computernum == 7)
					{
						num1='7';
					}
					else if (computernum == 8)
					{
						num1='8';
					}
					else if (computernum == 9)
					{
						num1='9';
					}
					
				}while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3]);
				// output computers choice
				cout << "\nComputer's turn! The computer has picked: " << num1;
	
				// add a delay
				Sleep (1000);

				// sets variable playerxo to O for playerinput function
				playerxo = 'O';
				// add the number to the gamboard as an O 	
				playerinput(num1);
				// check if O has won
				owin = winchecko();
				// check if it is a tie
				tie = tiecheck();
			}
			
			// if X win , O win or tie has not occured then keep looping 							
			if (tie!=1 and xwin!=1 and owin!=1)
			{
				// output what numbers are available to choose from
				cout << "\nPlayer One's turn! Please pick a number (";
				availableplaces();
				cout << ") --> ";
				cin >> num1;	
				
				// error checking
				while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
				{
					cout << "Invalid answer please pick a different number (";
					availableplaces();
					cout << ") --> "; 
					cin >> num1;	
				}
				// sets variable playerxo to X for playerinput function
				playerxo = 'X';
				// add the number to the gamboard as an X
				playerinput(num1);
				// check if X has won
				xwin = wincheckx();
//				cout << xwin;
				// check if tie
				tie = tiecheck();
			}
		} while (xwin!=1 and owin!=1 and tie!=1);	
	}
	// if start is 2, computer starts
	else if(start ==2)
	{
		// generate random number from 1-9 for computer to pick a spot																								 
		// if the computer has generated a number that has already been taken, generate a new number 		
		do
		{
			computernum = rand() % 9 + 1;
			// takes the generated number and sets it as num1. This is done because num1 is a char and you cannot generate 1-9 using a char
			if (computernum == 1)
			{
				num1='1';
			}
			else if (computernum == 2)
			{
				num1='2';
			}	
			else if (computernum == 3)
			{
				num1='3';
			}
			else if (computernum == 4)
			{
				num1='4';
			}
			else if (computernum == 5)
			{
				num1='5';
			}
			else if (computernum == 6)
			{
				num1='6';
			}
			else if (computernum == 7)
			{
				num1='7';
			}
			else if (computernum == 8)
			{
				num1='8';
			}
			else if (computernum == 9)
			{
				num1='9';
			}
			
		}while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
		num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3]);
		
		// sets variable playerxo to O for playerinput function
		playerxo = 'O';
		// add the number to the gamboard as an O 	
		playerinput(num1);
		// output computers choice
		cout << "\nComputer's turn! The computer has picked: " << num1;
	
		
		// as long as X win, O win or tie has not occured then keep looping 
		do
		{	
			// if X win , O win or tie has not occured then keep looping 							
			if (tie!=1 and xwin!=1 and owin!=1)
			{
				// output what numbers are available to choose from
				cout << "\nPlayer One's turn! Please pick a number (";
				availableplaces();
				cout << ") --> ";
				cin >> num1;	
				
				// error checking
				while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
				{
					cout << "Invalid answer please pick a different number (";
					availableplaces();
					cout << ") --> "; 
					cin >> num1;	
				}
				// sets variable playerxo to X for playerinput function
				playerxo = 'X';
				// add the number to the gamboard as an X
				playerinput(num1);
				// check if X has won
				xwin = wincheckx();
//				cout << xwin;
				// check if tie
				tie = tiecheck();
			}
			
			// if X win , O win or tie has not occured then keep looping 
			if (tie!=1 and xwin!=1 and owin!=1)
			{	
				// generate random number from 1-9 for computer to pick a spot																								 
				// if the computer has generated a number that has already been taken, generate a new number 
				do	{		
					computernum = rand() % 9 + 1;
					
					if (computernum == 1)
					{
						num1='1';
					}
					else if (computernum == 2)
					{
						num1='2';
					}	
					else if (computernum == 3)
					{
						num1='3';
					}
					else if (computernum == 4)
					{
						num1='4';
					}
					else if (computernum == 5)
					{
						num1='5';
					}
					else if (computernum == 6)
					{
						num1='6';
					}
					else if (computernum == 7)
					{
						num1='7';
					}
					else if (computernum == 8)
					{
						num1='8';
					}
					else if (computernum == 9)
					{
						num1='9';
					}
				}while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3]);
				// output computers choice
				cout << "\nComputer's turn! The computer has picked: " << num1;
	
				// add a delay
				Sleep (1000);
				// sets variable playerxo to O for playerinput function
				playerxo = 'O';
				// add the number to the gamboard as an O 	
				playerinput(num1);
				// check if O has won
				owin = winchecko();
				// check if it is a tie
				tie = tiecheck();
			}
			

		} while (xwin!=1 and owin!=1 and tie!=1);	
	}
}

// funciton for two player game
void twoplayer(void)
{	
	// reseting time
	srand (time(NULL));
	
	// sets the second player as player2 for naming purposes
	player = "Player 2";
	
	// declaring variables
	int  start, tie=0, xwin=0, owin=0;
	char num1;
	
	// generate a random number between 1-2 to decide who starts
	start = rand() % 2 + 1;	
	
	Sleep (250);			
	cout << "\t\t\t\tTic ";
	Sleep (250);			
	cout << "  Tac "; 
	Sleep (250);			
	cout << "  Toe ";
	Sleep (250);			
	cout << "\n\t\t\t  Give me an X give me an O ";		
	Sleep (500);			
	cout << "\n\t\t\t    Give me three in a row! ";	
	// output gameboard
	gameboard();
	

	// if the number is 1 then hae player on to start	
	if (start == 1)
	{
		// ask player one to pick a spot
		cout << "\nPlayer One starts! Please pick a spot from 1-9 --> ";
		cin >> num1;
		
		// if the user doesnt enter an available place, output an error
		while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
		num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
		{
			cout << "Invalid answer please pick a number between 1-9 --> ";
			cin >> num1;
		}
		// sets variable playerxo to X for playerinput function
		playerxo = 'X';
		// call for playerone function to input the number into the gameboard
		playerinput(num1);
		
		// do while x win, o win, or tie has nto occured
		do
		{	
			// if x win, o win, or tie has not occured ask user
			if (tie!=1 and xwin!=1 and owin!=1)
			{	
				// output what numbers are available to choose from
				cout << "\nPlayer Two's turn! Please pick a number (";
				availableplaces();
				cout << ") --> ";
				cin >> num1;
				
				// error checking
				while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
				{
					cout << "Invalid answer please pick a different number (";
					availableplaces();
					cout << ") --> "; 
					cin >> num1;
					
				}
				// sets variable playerxo to O for playerinput function
				playerxo = 'O';
				// takes the number and inputds and O into the that area in the gameboard
				playerinput(num1);
				// check if O has won
				owin = winchecko();
				// check if tie has occured
				tie = tiecheck();
			}		
										
			if (tie!=1 and xwin!=1 and owin!=1)
			{
				// output what numbers are available to choose from
				cout << "\nPlayer One's turn! Please pick a number (";
				availableplaces();
				cout << ") --> ";
				cin >> num1;	
				
				while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
				{
					cout << "Invalid answer please pick a different number (";
					availableplaces();
					cout << ") --> "; 
					cin >> num1;	
				}
				// sets variable playerxo to X for playerinput function
				playerxo = 'X';
				playerinput(num1);
				xwin = wincheckx();
				tie = tiecheck();
			}					
		} while (xwin!=1 and owin!=1 and tie!=1);
	}
	// if start is 2, player two starts
	else if (start == 2)
	{
		cout << "\nPlayer Two starts! Please pick a spot from 1-9 --> ";
		cin >> num1;
		
		while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
		num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
		{		
			cout << "Invalid answer please pick a number between 1-9 --> ";
			cin >> num1;
		}
		// sets variable playerxo to O for playerinput function
		playerxo = 'O';
		// call for playerone function to input the number into the gameboard
		playerinput(num1);
		// if a tie or win has not occured run this 		
		do
		{	
			// if a tie or win has not occured run this 
			if (tie!=1 and xwin!=1 and owin!=1)
			{
				// output what numbers are available to choose from
				cout << "\nPlayer One's turn! Please pick a number (";
				availableplaces();
				cout << ") --> ";
				cin >> num1;
				
				// error checking	
				while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
				{
					cout << "Invalid answer please pick a different number (";
					availableplaces();
					cout << ") --> "; 
					cin >> num1;
				}
				
				// sets variable playerxo to X for playerinput function
				playerxo = 'X';
				playerinput(num1);
				xwin = wincheckx();
				tie = tiecheck();
			}	
			// if a tie or win has not occured run this 			
			if (tie!=1 and xwin!=1 and owin!=1)
			{
				// output what numbers are available to choose from
				cout << "\nPlayer Two's turn! Please pick a number (";
				availableplaces();
				cout << ") --> ";
				cin >> num1;
				
				// error checking
				while (num1!=square[1][1] and num1!=square[1][2] and num1!=square[1][3] and num1!=square[2][1] and num1!=square[2][2] and 
				num1!=square[2][3] and num1!=square[3][1] and num1!=square[3][2] and num1!=square[3][3] or num1=='X' or num1=='O')
				{
		
					cout << "Invalid answer please pick a different number (";
					availableplaces();
					cout << ") --> "; 
					cin >> num1;
				}
				// sets variable playerxo to O for playerinput function
				playerxo = 'O';
				playerinput(num1);
				owin = winchecko();
				tie = tiecheck();
			}
		
		} while (xwin!=1 and owin!=1 and tie!=1);	
	}
	
}
