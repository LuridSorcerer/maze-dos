#include <iostream.h>
#include <conio.h>

#include "map.h"
#include "actor.h"

const int map_offset_x = 10;
const int map_offset_y = 3;
const int ui_x = 3;
const int ui_y = map_offset_y + map_h + 2;

enum KEY {
	UP=72,
	LEFT=75,
	RIGHT=77,
	DOWN=80
};

int main() {

	/* Variables */
	Map m;
	Player p;
	Player g;

	p.teleport(map_w/2, map_h/2);
	g.teleport(map_w-1, map_h/2);

	/* Game loop */
	char ch;
	while (1) {

		/* Clear screen then render map and player */
		clrscr();
		m.render(map_offset_x, map_offset_y);
		p.render(map_offset_x, map_offset_y);
		g.render(map_offset_x, map_offset_y);

		/* Display instructions for the player */
		gotoxy(ui_x, ui_y);
		cout << "Press the arrow keys to move.";
		gotoxy(ui_x, ui_y+1);
		cout << "Press 'q' to quit.";

		/* get input */
		ch = getch();

		/* quit program on q */
		if (ch == 'q') { break; }

		/* if arrow key is pressed, figure out which one */
		if (ch == 0) {
			ch = getch();
			switch (ch) {
				case UP:
					p.move(0,-1,m);
					break;
				case DOWN:
					p.move(0,1,m);
					break;
				case LEFT:
					p.move(-1,0,m);
					break;
				case RIGHT:
					p.move(1,0,m);
					break;
			}
		}
	}

	/* done, quit */
	return 0;
}
