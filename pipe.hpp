#ifndef PIPE_H
#define PIPE_H

#include <ncurses.h>
#include "bird.hpp"

class pipe
{
	public:
		pipe(WINDOW* win, int width, int height);
		void setPos(int x, int y, int size);
		char birdIn(bird b);
		void increment();
		void drawPipe();
		int getX();
		bool passed;
	private:
		int x, y, size, width, height;
		WINDOW* win;

};

#endif
