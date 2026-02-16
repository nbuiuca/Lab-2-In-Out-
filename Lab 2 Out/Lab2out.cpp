#include <iostream>
#include<ctime>
#include "graph1.h"
#include <chrono>
#include<thread>

using namespace std;
const int MAX_ELE = 5;

int getnocolors();
void displaycolors(int color_nums, int xasis, int yasis, int width, int height, int random_colors[]);
int getdelay();
void game (int colors_num, int &score, int random_colors[],int xasis,int yasis,int width,int height);

int main() {
displayGraphics();
int score = 0;
int random_colors[MAX_ELE] = { 0 };

int no_colors = getnocolors();
srand(time(0));
 int delay_time = getdelay();
 displaycolors(no_colors, 50, 100, 75, 75,random_colors);
 this_thread::sleep_for(chrono::seconds(delay_time));
 clearGraphics();
 game(no_colors, score, random_colors,50,100,75,75);
 gout << setPos(100, 300) << "Game Over!!! " << endg;
 gout << setPos(100, 400) << "Your final score is: " << score << endg;
}
int getnocolors() {

	int no_colors = 0;
	do {
		cout << "Enter number of colors to display (between 2 and 5): " << endl;
		cin >> no_colors;
		if (no_colors < 2 || no_colors > 5) {
			cout << "Invalid number of colors. Please enter a number between 2 and 5." << endl;
		}
		} while (no_colors < 2 || no_colors >5);
	
	
	return no_colors;
}
int getdelay() {
	int delay_time = 0;
	do {
		cout << "Enter delay" << endl;
		cin >> delay_time;
		if (delay_time < 1 || delay_time >3) {
			cout << "Invalid delay time. Try again" << endl;

		}


	} while (delay_time < 1 || delay_time>3);

	return delay_time;

}
void displaycolors(int color_nums, int xasis,int yasis, int width, int height,int random_colors[]) {
	int i = 0;
	
	for ( i = 0; i < color_nums; i++) {
		
		int random_color = rand() % 5;
		random_colors[i] = random_color;
		int rect = drawRect(xasis, yasis, width, height);
		xasis += 100;
			switch (random_color) {
			case 0:
				setColor(rect, 255, 0, 0);
					break;
			case 1:
				setColor(rect, 0, 255, 0);
				break;
			case 2:
				setColor(rect, 0, 0, 255);
				break;
			case 3:
				setColor(rect, 255, 255, 0);
				break;
			case 4:
				setColor(rect, 255, 0, 255);
				break;
			}
			gout << setPos(xasis- 100, 200) << "Color # " << i+1 << endg;
	}




}
void game(int colors_num, int &score, int random_colors[], int xasis,int yasis,int width, int height) {
	int play = 0;

	string a ;

	for (int i = 0; i < colors_num; i++) {
		int answer;
		cout << "Select Color # " << i + 1  << endl;
		cout << "1. Red" << endl;
		cout << "2. Green" << endl;
		cout << "3. Blue" << endl;
		cout << "4. Yellow" << endl;
		cout << "5. Purple" << endl;
		cout << "Enter choice: " << endl;
		cin >> answer;
		if (answer - 1 == random_colors[i]) {
			a = "Correct!";
			gout << setPos(150,  50) << a << endg;
			score += 2;
			int random_color = rand() % 5;
			random_colors[i] = random_color;
			int rect = drawRect(xasis, yasis, width, height);
			xasis += 100;
		
			switch (answer) {
			case 1:
				setColor(rect, 255, 0, 0);
				break;
			case 2:
				setColor(rect, 0, 255, 0);
				break;
			case 3:
				setColor(rect, 0, 0, 255);
				break;
			case 4:
				setColor(rect, 255, 255, 0);
				break;
			case 5:
				setColor(rect, 255, 0, 255);
				break;
			}
			
		}

		else  {
			a = "incorrect";
			gout << setPos(150, 50) << a << endg;
			score -= 2;
			i = i - 1;
		}
		play += 1;
	}
	gout << setPos(100, 350) << "Number of turns: " << play << endg;
}