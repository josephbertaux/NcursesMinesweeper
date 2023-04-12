#ifndef _COLORS_H
#define _COLORS_H

#include "field.h"

void _colors(std::map<int, std::pair<int, int>>& m)
{
	m.clear();

	m[0]	= {COLOR_WHITE,		COLOR_BLACK};	//default

	m[1]	= {COLOR_CYAN,		COLOR_BLACK};	//color based on mines
	m[2]	= {COLOR_GREEN,		COLOR_BLACK};
	m[3]	= {COLOR_MAGENTA,	COLOR_BLACK};
	m[4]	= {COLOR_YELLOW,	COLOR_BLACK};
	m[5]	= {COLOR_BLUE,		COLOR_WHITE};
	m[6]	= {COLOR_RED,		COLOR_WHITE};
	m[7]	= {COLOR_BLACK,		COLOR_WHITE};
	m[8]	= {COLOR_BLACK,		COLOR_WHITE};

	m[9]	= {COLOR_BLACK,		COLOR_YELLOW};	//flagged tile
	m[10]	= {COLOR_WHITE,		COLOR_BLACK};	//unrevealed tile
	m[11]	= {COLOR_BLACK,		COLOR_RED};	//revealed mine

};

#endif
