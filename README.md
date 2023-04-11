# Minesweeper

An implentation of Minesweeper in C using [NCURSES](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html).

Minesweeper is the best game ever and C is the best programming language ever, and many implementations exist. This is my implementation. There are many like it, but this one is mine.

This uses vim controls:
* h moves left
* j moves down
* k moves up
* l moves right

You can buffer the number of tiles to move similarly to vim (e.g. 20l, 4h, ..). The characters your are buffering is shown in the buffer line at the botton of the screen.

You can type commands similarly to vim by typing :, and then the command. We'll see what functions I end up implementing; it would be cool to show probabilities on the remaining tiles.

Press 'f' to flag a tile as a mine and press 'a' to reveal a tile as a mine.
