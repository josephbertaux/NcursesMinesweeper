#include <ncurses.h>

const int DOWN = 'j';
const int UP = 'k';
const int LEFT = 'h';
const int RIGHT = 'l';

const int REVEAL = 'a';
const int FLAG = 'f';

int ch;			//var to store most recently entered character
int rows, cols;		//dimensions of the current terminal
int row, col;		//current cursor position

bool loop()
{
	getmaxyx(stdscr, rows, cols);
	getyx(stdscr, row, col);

	ch = getch();

	switch(ch)
	{
		case DOWN:
			if(row < rows)row++;
			goto label;
		case UP:
			if(row > 0)row--;
			goto label;
		case LEFT:
			if(col > 0)col--;
			goto label;
		case RIGHT:
			if(col < cols)col++;
			goto label;
		case KEY_RESIZE:
			endwin();
			refresh();
			clear();
			goto label;
	}

	return false; //break;

	label:
	move(row, col);
	refresh();
	return true; //continue;
}


int main()
{
	initscr();
	clear();
	noecho();
	cbreak();

	while(loop()){}

	endwin();

	return 0;
}
