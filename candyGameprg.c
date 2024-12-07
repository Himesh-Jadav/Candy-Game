/*
			Author       : Jadav Himesh.
			Project      : Candy Game.

*/
#include <stdio.h>
#include <conio.h>

void main() {

	int life = 3;
	int score = 0;
	int level = 1;
	int xCord = 40, yCord = 3;
	int boxXcord = 40, boxYcord = 25;
	int x = 200;
	char key;


	start:

	clrscr();
	//code of Heading and essential information
	gotoxy(32, 1);
	printf("Score : %d", score);
	gotoxy(32, 2);
	printf("Life  : %d", life);
	gotoxy(70, 1);
	printf("Level: %d", level);

	gotoxy(xCord, yCord);
	printf("0");
	gotoxy(boxXcord, boxYcord-1);
	printf("*");
	gotoxy(boxXcord+6, boxYcord-1);
	printf("*");
	gotoxy(boxXcord, boxYcord);
	printf("*******");


	yCord++;

	if (kbhit()) {
	delay(0);
		key = getch();

		switch(key) {
			case 'a': 	if(boxXcord > 3) {
						boxXcord-=3;
					}
				break;

			case 'A': 	if(boxXcord > 3) {
						boxXcord-=3;
					}
				break;
			case 'd': 	if(boxXcord < 70) {
						boxXcord+=3;
					}
				break;

			case 'D': 	if(boxXcord < 73) {
						boxXcord+=3;
					}
				break;
		}
	}


	if (yCord == 25) {



		if(xCord - boxXcord >=1 && xCord - boxXcord <= 6) {
			score++;
			if (score % 5 == 0) {
				level++;
				x-=5;
			}
		}
		else {
			life--;
			if (life == 0) {
				clrscr();
				gotoxy(35, 12);
				printf("!!Game Over!!");
				getch();
				exit(0);
			}
		}
		xCord = (rand() % 60) + 10;
		yCord = 3;

	}

	delay(x);
	goto start;
}
