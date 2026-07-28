#ifndef MAP_H
#define MAP_H

enum bool {false=0, true};

#include <iostream.h>
#include <conio.h>

const int map_w = 60;
const int map_h = 10;

struct tile {
	char c;
	bool solid;
};

class Map {
private:
	tile map[map_w * map_h];

public:
	Map();
	~Map();

	void render(int,int);
	bool isSolid(int,int);
	void createWall(int,int,int,int,char,bool);
};

#endif