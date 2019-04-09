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
	if(b.y <= this->y + 5 && b.y >= this->y - 5)
		return 'i';
	else
		return 'o';
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
			if(i >= (this->y + 5) || i <= (this->y - 5))
				mvwaddch(this->win, i, k, '#'); 
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
