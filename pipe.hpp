#ifndef PIPE_H
#define PIPE_H

#include <ncurses.h>

class pipe
{
	public:
		pipe(WINDOW* win, int width, int height);
		void setPos(int x, int y, int size);
		bool birdIn(int x, int y);
		void increment();
		void drawPipe();
		int getX();
	private:
		int x, y, size, width, height;
		WINDOW* win;

};

#endif
