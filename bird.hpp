#ifndef BIRD_H
#define BIRD_H

#include <ncurses.h>

class bird
{
	private:
		WINDOW* win;
		char symbol;
	public:
		int y, x, gravity, dir;
		bird(WINDOW* win, char symbol, int x);
		void draw();
		void act();
		void jump();
};

#endif
