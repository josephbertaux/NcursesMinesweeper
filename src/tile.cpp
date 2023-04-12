#include "tile.h"

void tile::init(tile** _grid, int const& _rows, int const& _cols, int const& _row, int const& _col)
{
	row = _row;
	col = _col;
	int d_row = 0;
	int d_col = 0;

	mines = 0;
	for(int i = 0; i < 8; ++i)
	{
		get(i % 3, d_col);
		get(i / 3, d_row);

		if(row + d_row < 0)		continue;
		if(row + d_row >= _rows)	continue;
		if(col + d_col < 0)		continue;
		if(col + d_col >= _cols)	continue;

		neighbors[i] = &(_grid[row + d_row][col + d_col]);
		if(neighbors[i]->mine)mines++;
	}
}

void tile::get(int const& i, int& d)
{
	switch(i)
	{
		case 0:
			d = -1;
			break;
		case 1:
			d = 1;
			break;
		case 2:
			d = 0;
			break;	
	}
}

void tile::set(int& i, int const& d)
{
	switch(d)
	{
		case -1:
			i = 0;
			break;
		case 0:
			i = 2;
			break;
		case 1:
			i = 1;
			break;	
	}
}

void tile::flag()
{
	if(revealed)return;

	if(!flagged)	disp_char = 'F';
	if(flagged)	disp_char = '#';

	flagged = !flagged;
}

void tile::reveal()
{
	if(flagged)return;

	revealed = true;
	if(mine)
	{
		disp_char = 'X';
		return;
	}

	disp_char = std::to_string(mines).c_str()[0];
	if(disp_char == '0')disp_char = ' ';

	if(mines == 0)
		for(int i = 0; i < 8; ++i)
			if(neighbors[i] and !(neighbors[i]->revealed))neighbors[i]->reveal();
}


tile* tile::down()
{
	return neighbors[5];
}

tile* tile::up()
{
	return neighbors[2];
}

tile* tile::left()
{
	return neighbors[6];
}

tile* tile::right()
{
	return neighbors[7];
}
