#include <ncurses.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <vector>
#include "pipe.hpp"
#include "bird.hpp"

WINDOW* initWindow()
{
	srand(time(NULL));
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(0);
	timeout(75);
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
	WINDOW* stdscr = initWindow();
	char *f = (char*)malloc(1024);
	size_t l = 0;
	int height, width;
	getmaxyx(stdscr, height, width); 
	bird player(stdscr, '@', 5);	
	while(true)
	{
		clear();
		int i = 0;
		player.draw();
		int ch = getch();
		if(ch == KEY_UP)
		{	
			player.jump();
			l += sprintf(f + l, "Y:%d\n", player.y);
			player.act();
		}
		if(ch == 'q')
			break;
	}
	endwin();
	char c;
	printf("%s", f);
}
