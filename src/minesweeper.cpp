#include <string>
#include <vector>
#include <ncurses.h>

#include "field.h"

int main(int argc, char** argv)
{
	field f(12, 60, 65);

	while(f.loop()){}

	f.end();

	return 0;
}
