#include "field.h"

#include "_colors.h"
#include "_keybinds.h"

field::field(int const& _rows, int const& _cols, int const& _mines):
	rows(_rows),
	cols(_cols),
	mines(_mines)
{
	int row;
	int col;
	int r;
	int i;

	_keybinds(keybinds);
	_colors(colors);

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<> dist(0.0, 1.0);

	//initialize the window
	initscr();
	clear();
	noecho();
	cbreak();

	//initialize color pairs
	start_color();
	for(auto ctr = colors.begin(); ctr != colors.end(); ++ctr)
	{
		init_pair(ctr->first, ctr->second.first, ctr->second.second);
	}
	getmaxyx(stdscr, scr_rows, scr_cols);

	//instantiate the grid
	grid = new tile*[rows];
	for(row = 0; row < rows; ++row)
		grid[row] = new tile[cols];

	//distribute mines

	for(i = 0; i < mines; ++i)
	{
		//random with this as exclusive upper bound
		r = (rows * cols - i) * dist(rng);
 
		row = 0;
		col = 0;
		while(r > 0 or grid[row][col].mine)
		{
			if(!grid[row][col].mine)r--;

			++col;
			if(col >= cols)
			{
				col = 0;
				++row;
			}

			if(row >= rows)
			{
				break;
			}
		}

		if(col < cols and row < rows)grid[row][col].mine = true;
	}

	//link the grid
	for(row = 0; row < rows; ++row)
		for(col = 0; col < cols; ++col)
			grid[row][col].init(grid, rows, cols, row, col);

	t = &(grid[rows / 2][cols / 2]);
	draw();
}

field::~field()
{
	for(int row = 0; row < rows; ++row)
		delete[] grid[row];

	delete[] grid;
}

void field::down()
{
	if(t->down())t = t->down();
}

void field::up()
{
	if(t->up())t = t->up();
}

void field::left()
{
	if(t->left())t = t->left();
}

void field::right()
{
	if(t->right())t = t->right();
}

void field::flag()
{
	if(t)t->flag();
}

void field::reveal()
{
	if(t)t->reveal();
}

void field::draw()
{
	clear();

	int c;
	int row = 0;
	int col = 0;
	int scr_row = 0;
	int scr_col = 0;

	row = 0;
	scr_row = 0;
	while(scr_row < 2 * rows)
	{
		col = 0;
		scr_col = 0;
		while(scr_col < 2 * cols)
		{
			mvaddch(scr_row, scr_col, '+');
			++scr_col;

			mvaddch(scr_row, scr_col, '-');
			++scr_col;
		}
		mvaddch(scr_row, scr_col, '+');
		++scr_row;

		col = 0;
		scr_col = 0;
		while(scr_col < 2 * cols)
		{
			mvaddch(scr_row, scr_col, '|');
			++scr_col;

			if(grid[row][col].flagged)
			{
				c = 9;
				goto jump;
			}

			if(!grid[row][col].revealed)
			{
				c = 10;
				goto jump;
			}

			if(grid[row][col].mine)
			{
				c = 11;
				goto jump;
			}

			c = grid[row][col].mines;

			jump:
			attron(COLOR_PAIR(c));
			mvaddch(scr_row, scr_col, grid[row][col].disp_char);
			attroff(COLOR_PAIR(c));

			grid[row][col].row = scr_row;
			grid[row][col].col = scr_col;	
			++scr_col;
			++col;
		}
		mvaddch(scr_row, scr_col, '|');
		++scr_row;
		++row;
	}

	col = 0;
	scr_col = 0;
	while(scr_col < 2 * cols)
	{
		mvaddch(scr_row, scr_col, '+');
		++scr_col;

		mvaddch(scr_row, scr_col, '-');
		++scr_col;
	}
	mvaddch(scr_row, scr_col, '+');

	refresh();
	move(t->row, t->col);
}

void field::resize()
{
	endwin();
	refresh();
	clear();
}

void field::end()
{
	endwin();
}

bool field::loop()
{
	ch = getch();
	itr = keybinds.find(ch);

	if(itr == keybinds.end())return false;

	(this->*(itr->second))();
	draw();

	return true;
}
