//Nhan Bui
//Lab 2 in
//Simulates dice roll
#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
void getDiceCount(int* noDice);
void rollDice(int* dice, int noDice);
void computeScore(int* dice, int noDice, int* score);
void displayResults(int* dice, int noDice, int score);

int main()
{
	//Variable Declaration/Initialization
	int noDice = 0;
	const int MAX_DICE = 5;
	int dice[MAX_DICE] = { 0 };
	int score = 0;
	char repeat;
	do {
		//Initialize random number generator 
		srand(time(0));
		//Display Graphics
		displayGraphics();

		//1. Get the number of dice to roll
		getDiceCount(&noDice);

		//2. Roll the Dice (i.e., generates a random number for each dice

		rollDice(dice, noDice);
		//3. Compute the score

		computeScore(dice, noDice, &score);
		//4. Display the dice and results
		displayResults(dice, noDice, score);
	//repeat program?
		cout << "Repaeat program? (y/n) ";
		cin >> repeat;
		clearGraphics();
		system("cls");
	} while (repeat == 'y' || repeat == 'Y');
		return 0;
}

//Functions
void getDiceCount(int* noDice)
{
	//Prompts for the number of Dice to display and stores in the noDice variable
	//User input should be between 1 and 5 inclusively – reprompt if not within range
	do {
		cout << "Enter # of dice to roll (between 1 and 5 inclueisvely): ";
			cin >> *noDice;
			if (*noDice < 1 || *noDice>5) {
				cout << "Error: Value must be between 1 and 5 inclusively. Please Re-enter! " << endl;
			}
	} while (*noDice < 1 || *noDice>5);
}


void rollDice(int* dice, int noDice)
{
	//Generates noDice random numbers corresponding to the rolling of the dice
	for (int i = 0; i < noDice; i++) {
		dice[i] = rand() % 6 + 1;
	}

	//Each random number is stored in the dice parameter
	
	//Each random number should be stored 

}

void computeScore(int* dice, int noDice, int* score)
{
	//Variable Declaration
	int i = 0;
	*score = 0;

	//Adds up each random number stored in the dice array
	for (i = 0; i < noDice; i++) {
		*score += dice[i];
	}
	//Stores the result in the score parameter

}

void displayResults(int* dice, int noDice, int score)
{
	int i = 0;
	int x = 50;
	int y = 100;
	
	//Display each Die starting at 100,100
	for (int i = 0; i < noDice; i++) {
		displayPNG(to_string(dice[i]) + "Die.PNG", x, y);
		x += 120;
	}
	//Each Die has a width of 104
	//Display the Score at (50,225)
	gout << setPos(50, 255) << setColor(255, 0, 0) << "Score " << score << endg;
}
