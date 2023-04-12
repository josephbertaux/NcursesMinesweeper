#ifndef TILE_H
#define TILE_H

#include <string>

class tile
{
protected:
	tile* neighbors[8] = {nullptr};
	//	+0 (left)	\
	//	+1 (right)	 | get/set has the mapping
	//	+2 (same)	/
	//	+0 (up)		\
	//	+3 (down)	 | get/set has the mapping
	//	+6 (same)	/
	//
	//	00 (base 3)
	//	^^
	//	| \
	//	|  left or right
	//	up or down

	void get(int const&, int&);
	void set(int&, int const&);

public:
	int row = 0;
	int col = 0;

	int mines = 0;
	bool mine = false;
	bool revealed = false;
	bool flagged = false;

	int disp_char = '#';

	void init(tile**, int const&, int const&, int const&, int const& col);
	void count();

	void flag();
	void reveal();

	tile* down();
	tile* up();
	tile* left();
	tile* right();
};

#endif
