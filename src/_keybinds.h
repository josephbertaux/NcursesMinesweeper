#ifndef _KEYBINDS_H
#define _KEYBINDS_H

#include "field.h"

void _keybinds(std::map<int, void(field::*)()>& m)
{
	m.clear();

	m['k']		= &field::up;
	m['j']		= &field::down;
	m['h']		= &field::left;
	m['l']		= &field::right;

	m['f']		= &field::flag;
	m['a']		= &field::reveal;

	m[KEY_RESIZE]	= &field::resize;
};

#endif
