#include "pipe.hpp"
#include "bird.hpp"
#include <ncurses.h>

pipe::pipe(WINDOW* win, int width, int height)
{
	this->win = win;
	this->width = width;
	this->height = height;
};

char pipe::birdIn(bird b)
{
	if(b.y <= this->y + 4 && b.y >= this->y - 4)
		return 1;
	else
		return 0;
}

void pipe::setPos(int x, int y, int size)
{
	this->x = x;
	this->y = y;
	this->size = size;
}

void pipe::increment()
{
	this->x--;
}

void pipe::drawPipe()
{
	for(int i = 0; i < height; i++)
	{
		for(int k = this->x; k < this->size + this->x; k++)
		{
			if((k == this->x || k == this->size + this->x - 1) && !(i <= this->y + 5 && i >= this->y - 5))
				mvwaddch(this->win, i, k, ACS_VLINE);
			if(i == (this->y - 5))
			{
				mvwaddch(this->win, i, k, ACS_HLINE);
				if(k == this->x)
					mvwaddch(this->win, i, k, ACS_LLCORNER);
				if(k == this->x + this->size - 1)
					mvwaddch(this->win, i, k, ACS_LRCORNER);
			}
			if(i == (this->y + 5))
			{
				mvwaddch(this->win, i, k, ACS_HLINE);
				if(k == this->x)
					mvwaddch(this->win, i, k, ACS_ULCORNER);
				if(k == this->x + this->size - 1)
					mvwaddch(this->win, i, k, ACS_URCORNER);
			}
		}
	}
	/*
	for(int h = 0; i < height; i++)
	{
		mvwaddch(this->win, i, this->x, '!');
		for(int w = this->x; w < this
	}*/
}
int pipe::getX()
{
	return this->x;
}
