#ifndef PLAYER_H
#define PLAYER_H

#include <iostream.h>
#include <conio.h>

class Map; /* forward declaration */

class Player {
private:
	int  x;
	int  y;
	char c;

public:
	Player();
	~Player();

	void render(int,int);
	void move(int,int,Map&);
	void teleport(int,int);
	int getX();
	int getY();
};

#endif