#include "player.h"
#include "map.h"

Player::Player() {
	x = 1;
	y = 1;
	c = 0x01;
}

Player::~Player() {}

void Player::render(int off_x, int off_y) {
	gotoxy(x+off_x, y+off_y);
	cout << c;
}

void Player::move(int rel_x, int rel_y, Map& m) {
	if ( !m.isSolid( x+rel_x, y+rel_y) ) {
		x += rel_x;
		y += rel_y;
	}
}

void Player::teleport(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

int Player::getX() { return x; }

int Player::getY() { return y; }