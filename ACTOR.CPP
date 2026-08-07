#include "actor.h"
#include "map.h"

Actor::Actor() {
	x = 1;
	y = 1;
	c = 0x01;
}

Actor::Actor(int new_x, int new_y, char new_c) {
	x = new_x;
	y = new_y;
	c = new_c;
}

Actor::~Actor() {}

void Actor::render(int off_x, int off_y) {
	gotoxy(x+off_x, y+off_y);
	cout << c;
}

void Actor::move(int rel_x, int rel_y, Map& m) {
	if ( !m.isSolid( x+rel_x, y+rel_y) ) {
		x += rel_x;
		y += rel_y;
	}
}

void Actor::teleport(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

int Actor::getX() { return x; }

int Actor::getY() { return y; }
