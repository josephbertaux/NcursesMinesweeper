#ifndef FIELD_H
#define FIELD_H

//#include <iostream>

#include <string>
#include <map>
#include <random>
#include <ncurses.h>

#include "tile.h"

class field
{
protected:
	std::map<int, void(field::*)()> keybinds; 
	std::map<int, std::pair<int, int>> colors;

	int mines;
	int rows;
	int cols;
	int scr_rows;
	int scr_cols;

	int ch;
	std::map<int, void(field::*)()>::iterator itr;

	tile* t;
	tile** grid;

public:
	field(int const&, int const&, int const&);
	~field();

	void down();
	void up();
	void left();
	void right();

	void flag();
	void reveal();

	void draw();
	void resize();
	void end();

	bool loop();
};

#endif
