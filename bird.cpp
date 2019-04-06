#include <ncurses.h>
#include "bird.hpp"

bird::bird(WINDOW* win, char symbol, int x)
{
	this->symbol = symbol;
	this->win = win;
	getmaxyx(win, this->y, this->x);
	this->x = x;
	this->y /= 2;
	this->gravity = 1;
	this->dir = gravity;
};

void bird::draw()
{
	mvwaddch(this->win, this->y, this->x, this->symbol);
}

void bird::act()
{
	this->y += dir/5;
	this->dir += gravity;
}
void bird::jump()
{
	this->dir = -10;
}
