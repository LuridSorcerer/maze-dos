#include "map.h"

Map::Map() {
	for (int row = 0; row < map_h; row++) {
		for (int col = 0; col < map_w; col++) {
			map[(row*map_w) + col].c = '-';
			map[(row*map_w) + col].solid = false;
		}
	}

	/* let's make a test wall */
	createWall( 0,0, 1,1, 0xC9, true); /* top left corner */
	createWall( 1,0, map_w-2,1, 0xCD, true); /* top wall */
	createWall( map_w-1,0, 1,1, 0xBB, true); /* top right corner */
	createWall( 0,1, 1,map_h-2, 0xBA, true); /* left wall */
	createWall( 0,map_h-1, 1,1, 0xC8, true); /* bottom left corner */
	createWall( 1,map_h-1, map_w-2,1, 0xCD, true); /* bottom wall */
	createWall( map_w-1,map_h-1, 1,1, 0xBC, true); /* bottom right corner */
	createWall( map_w-1,1, 1,map_h-2, 0xBA, true); /* right wall */
	createWall( 3,3, 6,2, 0xDB, true); /* random block */
	createWall( map_w-20,map_h-4, 10,2, 0xDB, true); /* random block */
}

Map::~Map() {}

void Map::render(int x, int y) {
	for (int row = 0; row < map_h; row++) {
		gotoxy(x, y+row);
		for (int col = 0; col < map_w; col++) {
			cout << map[(row*map_w) + col].c;
		}
	}
}

int index(int x,int y) { return x + (y*map_w); }

bool Map::isSolid(int x, int y) {
	/* automatically solid if outside the bounds */
	if ( x < 0 || x >= map_w || y < 0 || y >= map_h) { return true; }
	return map[x + (map_w*y)].solid;
}

void Map::createWall(int x, int y, int w, int h, char c, bool solid) {
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			map[ index(x+col,y+row) ].c = c;
			map[ index(x+col,y+row) ].solid = solid;
		}
	}
}