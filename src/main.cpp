#include <ncurses.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <vector>
#include "pipe.hpp"
#include "bird.hpp"
#include <string.h>
#include "menu.hpp"

WINDOW* initWindow()
{
	srand(time(NULL));
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(0);
	timeout(50);
	border(0, 0, 0, 0, 0, 0, 0, 0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	return stdscr;
}

signed char getOff(int height)
{
	char displacement;
	displacement = (rand() % (height/2 + 1)) + height/4;
	return displacement;
}	

int main()
{
	/* Initialize Window */
	WINDOW* stdscr = initWindow();

	/* Variables */
	int score = 0;
	int height, width;
	getmaxyx(stdscr, height, width);
	unsigned char speed = 0;

	/* Menu */
	menu startMenu(stdscr);
	startMenu.setOpts(3, "Easy", "Medium", "Quit");
MENURUN:
	char choice = startMenu.runMenu();
	switch(choice)
	{
		case 0:
			speed = 100;
			break;
		case 1:
			speed = 50;
			break;
		case 2:
			endwin();
			return 0;
			break;
		default:
			printf("Encountered Error In Menu.\n");
			endwin();
			return -1;
	}

	/* Player And Pipes */
	bird player(stdscr, '@', 20);	
	std::vector<pipe> pipes;
	for(int i = 0; i < 5; i++)
	{
		pipes.push_back(pipe(stdscr, width, height));	
		pipes[i].setPos(width + (45*i), getOff(height), 4);
		pipes[i].passed = false;
	}

	/* Game Loop */
	while(true)
	{
		erase();
		timeout(speed - score*2);
		/* Modifify Pipes Appropriately */
		for(int i = 0; i < pipes.size(); i++)
		{
			pipes[i].drawPipe();
			pipes[i].increment();
			if(pipes[i].getX() < -5)
			{
				//delete(pipes[i]);
				pipes.erase(pipes.begin()+i);
				pipes.push_back(pipe(stdscr, width, height));
				pipes.back().setPos(width + 5, getOff(height), 4);
				pipes.back().passed = false;
			}
		}	

		/* If pipes are malfunctioning, exit */
		if(pipes.size() < 1)
			break;

		/* Check If Player Is Hitting Pipe */
		if(pipes[0].getX() <= player.x && pipes[0].getX() + 4 >= player.x)
		{
			if(pipes[0].birdIn(player) && !pipes[0].passed)//pipes[0].birdIn(player))
			{
				score++;
				pipes[0].passed = true;
			}
			else if(!pipes[0].birdIn(player))
			{
				break;
			}	
		}

		/* Draw Bird */
		player.draw();

		/* Get Next Move */
		int ch = getch();
		if(ch == KEY_UP)
			player.jump();
		player.act();
		if(ch == 'q')
			break;
	}
	endwin();
	printf("You got: %d\n", score);
}
